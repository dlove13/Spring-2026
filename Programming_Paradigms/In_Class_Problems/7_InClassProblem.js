function promptDirection(question) {
    let answer = prompt(question);
    if (answer.toLowerCase() == "left") return "L";
    if (answer.toLowerCase() == "right") return "R";
        throw new Error("Invalid answer: " + answer);
}

function look() {
  if (promptDirection("Which way?") == "L") {
    return "a house";
} else {
    return "two angry bears";
    }
}

try {
  console.log("You see", look());
    } catch (error) {
  console.log("Something’s not right: " + error);
    }
