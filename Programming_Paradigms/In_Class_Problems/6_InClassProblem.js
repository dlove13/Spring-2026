class Rabbit {
	constructor(type) {
		this.type = type;
	}
	speak(line) {
		console.log(`The ${this.type} rabbit says '${line}'`);
	}
}


let killerRabbit = new Rabbit("killer");
killerRabbit.speak = function(line) {
	console.log(`The rabbit of type ${killerRabbit.type} says '${line}'`);
};

killerRabbit.speak("Hello World!");
