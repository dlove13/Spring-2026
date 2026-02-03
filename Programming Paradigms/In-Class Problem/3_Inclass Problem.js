function countChar(string, ch) { //declare a function to count number of characters in a string
    let counted = 0;                //initialize count to zero
    for (let i=0; i < string.length; i++) {  //loop iterated through entire given string
        if (string[i] == ch) {              //if the char at position i is the same as char
             counted += 1;                  //increment count by 1
        }
    }
    return counted;                         //return number of counted char 
}

// function countEs(string)        //declare a function to count number of e's
// {
//     return countChar(string, "E");  //using previous function to count 
// }

//Rewrite countEs as a const

// const countEs = function(string) {
//     return countChar(string, "E");
// }

//Rewrite countEs as an arrow function

const countEs = (string) => {
    return countChar(string, "E");
}

console.log(countEs("EECS"));           //input EECS and using "E" as the default variable, output 2
console.log(countChar("david", "d"));   //input david and specifying "d" as the counted char, output 2

