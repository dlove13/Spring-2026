#include <stdio.h>

int main() {
    
    int number; //7 = 0b0111
    int bit; //3

    //Prompt user for input
    printf("Enter Integer: ");
    scanf("%d", &number);

    printf("Enter the bit position to check (0-31): ");
    scanf("%d", &bit);

    //note that shifts are in powers of 2
    // (1 << bit) 0b0010

    if ((( 1 << bit ) & number) == 0 ) //mask is shifted over however many bits requested
    {                                   //then the two binary numbers are compared against each other
        printf("FALSE \n");
    }
    else
    {
        printf("TRUE \n");              //true if the bit is set in the requested position
    }

    return 0;
}