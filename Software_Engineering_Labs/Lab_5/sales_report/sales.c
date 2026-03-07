#include <stdio.h>
#include "sales.h"

//Function Definitions

//Displays Month and Sales in order by month
void Display(const char *month[], float  report[]) {
        
        printf("%s\n\n", "Monthly Sales Report for 2026");
        printf("%-12s %s\n", "Month", "Sales");

        for (int i = 0; i < 12; i++) {
                printf("%-12s %.2f\n",month[i], report[i]);
         }
}

//Displays Summary Containing min and max and average
void Summary(const char *month[], float report[]) {}

//Sorts the report from high to low
void Sort(const char *month[], float report[]){}

//Displays moving average over 6-months
void MovingAverage(const char *month[], float report[]){}


//Returns the max from the report array
float FindMax(const char *month[], float report[])
{
        float *max = report[0];          //Init max to the first
        for (int i = 0; i < 12; i++)    //value in report
        {
                if (report[i] < *max) {
                
                        *max = report[i];
                }
        }

}

//Returns the min from the report array
float FindMin(const char *month, float report[]){}
        
        float *min = report[0];          //Init min to the first
        for (int i = 0; i < 12; i++)    //value in report
        {
                if (report[i] > *min) {
                
                        *min = report[i];
                }
        }
//Returns the avg from the report array
float FindAvg(const char *month, float report[], int length){
        
        float total = 0;

        float avg = 0;

        for (int i = 0; i < length; i++) {
                total += report[i];        
        }
}


//Main function
int main() {
//Months of the Year
const char *months[12] = {"January", "February", "March",
                        "April", "May", "June",
                        "July", "August", "September",
                        "October","November", "December"};

//Report values in order of month
const float report[12] = {23458.01, 40112.00, 56011.85,  
        37820.88, 37904.67, 60200.22,
        72400.31, 56210.89, 67230.84,  
        68233.12, 80950.34, 95225.22}; 


Display(months, report);

return 0;
}
