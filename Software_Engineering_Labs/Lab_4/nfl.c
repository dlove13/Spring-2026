#include <stdio.h>

//Declare Function
void FindCombinations(int score, int counts[], int index);

//Declare variables
//Touchdown + conversion, Touchdown + FG, Touchdown, FG, Safety
const int points[] = {8,7,6,3,2};
const int num_points = 5; //length of points array

//Define Function
void FindCombinations(int score, int counts[], int index) 
{   

    if (score == 0) //Exact Score reached
    {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Saftey\n", 
            counts[0], counts[1],counts[2], counts[3], counts[4]);
        return;
    }

    if (score < 0 || index >= num_points)
    {
        return;
    }

    counts[index]++;
    FindCombinations(score - points[index], counts, index);

    counts[index]--;
    FindCombinations(score, counts, index + 1);

}

int main() {
    int target;



    do {
        printf("Enter a score: ");
        scanf("%d", &target);

        if (target < 2)
        {
            printf("Not a valid score.\n");
        }
    }
    while (target < 2);

    int counts[] = {0,0,0,0,0};

    FindCombinations(target,counts,0);

    return 0;
}

