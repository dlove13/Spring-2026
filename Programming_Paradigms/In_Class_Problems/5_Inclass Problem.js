let object1 = {value: 10};
let object2 = object1;
let object3 = {value: 10};

console.log(object1 == object2); //objecct 2 is pointing to the same address as object 1
//True

console.log(object1 == object3); //object 3 and 1 have the same contents, but are not the same address
//False

object1.value = 15;             //change the contents in value of object 1
console.log(object2.value);     //object 2 points to object 1
//15

console.log(object3.value);     //object 3 value remains unchanged
//10