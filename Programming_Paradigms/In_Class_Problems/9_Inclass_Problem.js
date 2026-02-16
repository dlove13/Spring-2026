//This program changes the color of the window when the key "g" is pressed


//While "g" is pressed down, the window is green
window.addEventListener("keydown", event => {
        if (event.key == "g") {
                document.body.style.background = "green";
        }
});

//When the "g" key is released, the window reverts back to being transparent
window.addEventListener("keyup", event => {
        if (event.key == "g" {
                document.body.style.background = "";
        }
});
