#include <stdio.h>
#include "sales.h"

//Function Definitions

//Displays Month and Sales in order by month
void Display(const char *month[], const float report[]) {
        
        printf("%s\n\n", "Monthly Sales Report for 2026");
        printf("%-12s %s\n", "Month", "Sales");

        for (int i = 0; i < 12; i++) {
                printf("%-12s %.2f\n",month[i], report[i]);
         }
}


//Sorts the report from high to low
void Sort(const char *month[], const float report[])
{
        float s_report[12];
        const char *s_months[12];

        for (int i = 0; i < 12; i++)        //make copies of month and report values
        {
                s_report[i] = report[i];
                s_months[i] = month[i];
        }

        for (int i = 0; i < 11; i++)
        {
                for (int j = 0; j < 11 - 1; j++)
                {
                        if (s_report[j] < s_report[j+1])
                                        {
                                                //Swap sales
                                                float tempSales = s_report[j];
                                                s_report[j] = s_report[j+1];
                                                s_report[j + 1] = tempSales;

                                                //Swap month pointers
                                                const char *tempMonth = s_months[j];
                                                s_months[j] = s_months[j+1];
                                                s_months[j+1] = tempMonth;

                                        }
                }
        }

        printf("\nSales Report (highest to lowest)\n");
        printf("%-12s %s\n", "Month", "Sales");
        for (int i = 0; i < 12; i++)
        {
                printf("%-12s %.2f\n", s_months[i], s_report[i]);
        }
}

//Displays moving average over 6-months
void MovingAverage(const char *month[], const float report[]){
        printf("\n Six-month Moving Average Report\n");
        for (int i = 0; i <= 6; i++) {
                float sum = 0;
                for (int j = i; j < i+6; j ++) {
                        sum += report[j];
                }
                printf("%-12s - %-12s %.2f\n", month[i], month[i+5], sum / 6.0);
        }
}


//Returns the max from the report array
void FindMax(const char *month[], const float report[])
{
        float max = report[0];
        int index = 0;

        for (int i = 0; i < 12; i++) {
                if (report[i] > max ) {
                        max = report[i];
                        index = i;
                }
        }

        printf("Max: %.2f\t(%s)\n", max, month[index]);
}

//Returns the min from the report array
void FindMin(const char *month[], const float report[])
{
  
        float min = report[0];
        int index = 0;
        for (int i = 0; i < 12; i++) {
               if (report[i] < min) {
                        min = report[i];
                        index = i;
                }
        }

        printf("Minimum sales: %.2f\t(%s)\n", min, month[index]);      
} 
        
void FindAvg(const char *month[], const float report[]) 
{   
        float avg = 0;
        float total = 0;
        
        for (int i = 0; i < 12; i++)
        {
                float total = total +  report[i];
        }
        
        avg = total / 12;

        printf("Average Sales: %.2f\n", avg);
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

printf("\nSales Summary Report\n");
FindMax(months, report);
FindMin(months, report);
FindAvg(months, report);

MovingAverage(months, report);

Sort(months, report);
return 0;
}
