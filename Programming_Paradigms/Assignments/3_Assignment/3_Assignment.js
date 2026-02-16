class Group {
        constructor() {
                var group = []
        }

        group_add(value) {
            let size - group.length;

            for (let i = 0; i < size; i++) {
                    if (value == this.i) {
                            return "Already in the set!"
                    }
                    else {
                            this.push(value);
                    }
                }
        }


        group_delete(value){}

        group_has(value) {}

        union(argument) {}

        intersection() {}

        difference() {}

}

testGroup = new Group;

testGroup.add(1);

console.log("${testGroup}");
