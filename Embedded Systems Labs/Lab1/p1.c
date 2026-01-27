#include <stdio.h>

    //initialize variables
    char operand;
    int a;
    int b;
    int result;

    //Declare Functions
    void userInput();

    //Define Functions
    void userInput() {
        printf("Choose operand (+, - , *, /, s, c):  ");
        scanf("%c", operand);

        printf("%c", operand); //test
    }



int main() {

        userInput();

    return 0;
}