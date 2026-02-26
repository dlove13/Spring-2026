#include <stdio.h>

int main() {


    int array[10] = {500, 1, 255, 7, -12, 40, 42, 999, 50, 227}; //initialize array
    int max = array[0]; 
    int min = array[0]; //initialize values
    char input;

    //find the max    
          for (int i = 0; i < 10; i++)
            {
                if (array[i] > max) 
                {
                    max = array[i];
                }
            }
    //find the min
        for (int i = 0; i < 10; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
    
    //Prompt user for input
    printf("Enter m, n, or b: ");
    scanf("%c", &input);

    switch (input)
    {

        case 'm':
            printf("Max: %d", max);
            break;

        case 'n':
            printf("Min: %d", min);
            break;
        case 'b':
            printf("Max: %d \nMin:%d", max, min);
    }
    return 0;
}