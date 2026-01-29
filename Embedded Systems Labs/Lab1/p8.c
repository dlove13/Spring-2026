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

    if ((( 1 << bit ) & number) == 0 )
    {
        printf("FALSE \n");
    }
    else
    {
        printf("TRUE \n");
    }

    return 0;
}