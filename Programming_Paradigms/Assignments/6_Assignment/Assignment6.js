/* 
Author: Davina Love
Date: 04-06-2026

Desc: Creates a server that can create a directory, read, write and delete files.

AI Disclaimer: Google Gemini was used in this assignment. 
*/

//Gemini advised to consolidate all imports
const { createServer } = require("http");
const { parse } = require("url");
const { resolve, sep } = require("path");
const { createReadStream, createWriteStream, promises: fs } = require("fs");
const mime = require("mime"); //Gemini advised to downgrade to mime ver 2 so require would be valid

const baseDirectory = process.cwd();
const methods = Object.create(null);

createServer((request, response) => {
  /*Bybass CORS*/
  //Allow all domains
  response.setHeader("Access-Control-Allow-Origin", "*");
  //Allow HTTP methods
  response.setHeader("Access-Control-Allow-Methods", "*");
  //Allow headers
  response.setHeader("Access-Control-Allow-Headers", "*");
  //Handle preflight OPTIONS requests
  if (request.method === "OPTIONS") {
    //End response for OPTIONS immediately
    return response.end();
  }
  //end bypass

  let handler = methods[request.method] || notAllowed;
  handler(request)
    .catch((error) => {
      //throw error if the server failed to load
      if (error.status != null) return error;
      return { body: "Internal Server Error", status: 500 };
    })

    .then(({ body, status = 200, type = "text/plain" }) => {
      response.writeHead(status, { "Content-Type": type });
      if (body && body.pipe) body.pipe(response);
      else response.end(body);
    });
}).listen(8000);

//Alert that the server is listening
console.log("Server is running!");

//Define Errors
async function notAllowed(request) {
  return {
    status: 405,
    body: `Method ${request.method} not allowed.`,
  };
}

//Parse the path URL
function urlPath(url) {
  let { pathname } = parse(url);
  let path = resolve(decodeURIComponent(pathname).slice(1));
  if (path != baseDirectory && !path.startsWith(baseDirectory + sep)) {
    throw { status: 403, body: "Forbidden" };     //doesn't ever throw this error
  }
  return path;
}

//Define GET method
methods.GET = async function (request) {
  let path = urlPath(request.url);
  let stats;

  try {
    stats = await fs.stat(path);
  } catch (error) {
    if (error.code != "ENOENT") throw error;
    else return { status: 404, body: "File Not found" }; //throw if the file doesn't exist
  }
  if (stats.isDirectory()) {
    return { body: (await fs.readdir(path)).join("\n") }; //list out all files in the folder
  } else {
    return { body: createReadStream(path), type: mime.getType(path) }; //read file contents
  }
};

function pipeStream(from, to) {
  return new Promise((resolve, reject) => {
    from.on("error", reject); //will reject if connection to the server is interrupted
    to.on("error", reject);
    to.on("finish", resolve); //method fulfilled
    from.pipe(to);
  });
}

methods.PUT = async function (request) {
  let path = urlPath(request.url);
  await pipeStream(request, createWriteStream(path));
  return { status: 204 };
};

methods.DELETE = async function (request) {
  //translate url into file name
  let path = urlPath(request.url);
  //invoke stat object stats
  let stats;
  //wait for stat to find the file
  try {
    stats = await fs.stat(path);
    //handle non-existent file name
  } catch (error) {
    if (error.code != "ENOENT") throw error;
    else return { status: 204 };
  }
  //if the file name is a directory, remove it
  if (stats.isDirectory()) await fs.rmdir(path);
  //if the file name is not a directory, remove it
  else await fs.unlink(path);
  //report that the file deletion was successful
  return { status: 204 };
};

//Define making a new folder
methods.MKCOL = async function (request) {
  let path = urlPath(request.url); //convert url to path
  let stats;

  try {
    stats = await fs.stat(path);
  } catch (error) {
    //if path doesn't exits, create directory
    if (error.code == "ENOENT") {
      await fs.mkdir(path);
      return { status: 201 }; //successful in creating a new folder
    } else {
      throw error;
    }
  }

  if (!stats.isDirectory()) {
    return { status: 400, body: "Not a directory" }; //throw error if path exists but isn't a directory
  }
  return { status: 204 }; //Already a directory
};


/*
cURL commands to test if the server is working

Server is Responding [PASSED]
curl -i http://localhost:8000/

Make Collection [PASSED]
curl -v -X MKCOL http://localhost:8000/test_dir

Test Already created directory message [PASSED]
curl -v -X MKCOL http://localhost:8000/test_dir

Test 405 Not Allowed  [PASSED]
curl -v -X POST http://localhost:8000/test.txt

Create new file "hello.txt" in new test_dir [PASSED]
curl -v -X PUT -d "Hello world!" http://localhost:8000/test_dir/hello.txt

Read from files from directory [PASSED]
curl -v http://localhost:8000/test_dir

Read file contents  [PASSED]
curl -v http://localhost:8000/test_dir/hello.txt

Delete file "hello.txt" [PASSED]
curl -v -X DELETE http://localhost:8000/test_dir/hello.txt

Delete folder test_dir [PASSED]
curl -v -X DELETE http://localhost:8000/test_dir

Test 403 Forbidden [FAILED]
curl -v http://localhost:8000/.../secrets.txt
*/