  const {createServer} = require("http");
        const methods = Object.create(null);

        createServer((request, response) => {
            /*Bybass CORS*/
            //Allow all domains
            response.setHeader('Access-Control-Allow-Origin', '*');
            //Allow HTTP methods
            response.setHeader('Access-Control-Allow-Methods', '*');
            //Allow headers
            response.setHeader('Access-Control-Allow-Headers', '*');
            //Handle preflight OPTIONS requests
            if (request.method === 'OPTIONS') {
                //End response for OPTIONS immediately
                return response.end();
            }
            //end bypass
            let handler = methods[request.method] || notAllowed;
            handler(request)
                .catch(error => {
                    if (error.status != null) return error;
                    return {body: String(error), status: 500};
                })

                .then(({body, status = 200, type = "text/plain"}) => {
                    response.writeHead(status, {"Content-Type" : type});
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
                body: `Method ${request.method} not allowed.`
            };
        }


        const {createReadStream, link} = require("fs");
        const {stat, readdir} = require("fs").promises;
        const mime = require("mime");

        const {parse} = require("url");
        const {resolve, sep} = require("path");
        const baseDirectory = process.cwd();

        function urlPath(url) {
            let {pathname} = parse(url);
            let path = 
            resolve(decodeURIComponent(pathname).slice(1));
            if (path != baseDirectory && !path.startsWith(baseDirectory + sep)) {
                throw {status: 403, body: "Forbidden"};
            }
            return path;
        }
        
        methods.GET = async function(request) {
            let path = urlPath(request.url);
            let stats;

            try {
                stats = await stat(path);
            } catch (error) {
                if (error.code != "ENOENT") throw error;
                else return {status: 404, body: "File not found"};
            }
            if (stats.isDirectory()) {
                return {body: (await readdir(path)).join("/n")};
            } else {
                return {body: createReadStream(path),
                        type: mime.getType(path)
                };
            }
        };

        const {createWriteStream} = require("fs");

        function pipeStream(from, to) {
            return new Promise((resolve, reject) => {
                from.on("error", reject);
                to.on("error", reject);
                to.on("finish", resolve);
                from.pipe(to);
            });
        }

        methods.PUT = async function(request) {
            let path = urlPath(request.url);
            await pipeStream(request, createWriteStream(path));
            return {status: 204};
        };

        const {rmdir, unlink} = require("fs").promises;

        methods.DELETE = async function(request) {
            //translate url into file name
            let path = urlPath(request.url);
            //invoke stat object stats
            let stats;
            //wait for stat to find the file
            try {
                stats = await stat(path);
            //handle non-existent file name
            } catch(error) {
                if (error.code != "ENOENT") throw error;
                else return {status: 204};
            }
            //if the file name is a directory, remove it
            if (stats.isDirectory()) await rmdir(path);
            //if the file name is not a directory, remove it
            else await unlink(path);
            //report that the file deletion was successful
            return {status: 204};
        };

        const {mkdir, link}= require("fs").promises;

        methods.MKCOL = async function(request) {
            let path = urlPath(request.url);
            let stats;

            try {
                stats = await stat(path);
            } catch (error) {
                if (error.code != "ENOENT") throw error;
            

            await mkdir(path);
            return {status: 201};  //Using 201 Created status return to differentiate between 204
                                    //when file already exists
            }
            
            if (stats.isDirectory()) {
                return {status:204};
            } else {
                return {status: 400, body: "Not a directory"}
            }
        };
    