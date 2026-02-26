#include <stdio.h>

//Declare function
int isPrime(); //checks if an individual number is prime

//Define Function
int isPrime(int n) {
    for (int i = 2; i * i <= n; i++) { //i*i <=n signifies the sqrt(n)
        if (n % i == 0) {               //function checks for primes until the sqrt(n)
            return 0;                   //returns false if current value is not prime
        }
    }
    return 1;                           //returns true if current value is prime
}

int main() {

    int userInput;  

    printf("Enter a value: "); //prompts user to input a single value
    scanf("%d", &userInput);

    for (int i = 2; i <= userInput; i++){
        if (isPrime(i)) {               //starting from 2, loop iterates over every value and checks
            printf("%d ", i);           //if it is prime. if it is prime, then it prints the value to the console
        }
    }

    return 0;
}