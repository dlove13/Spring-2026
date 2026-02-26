#include <stdio.h>
#include <stdbool.h>

//TODO: Provide option to reenter values

//Declare Functions
float celsius_to_fahrenheit (float celsius);
float fahrenheit_to_celsius (float fahrenheit);
float celsius_to_kelvin (float celsius);
float kelvin_to_celsius (float kelvin);
float fahrenheit_to_kelvin (float fahrenheit);

void categorize_temperature (float celsius);
float user_menu(float temp, int input_scale, int input_target);



//Define Functions
float celsius_to_fahrenheit (float celsius) {
    
    float fahrenheit = ((9.0/5) * celsius) + 32;
    return fahrenheit;
}

float fahrenheit_to_celsius (float fahrenheit) {
    
    float celsius = ((5.0/9) * (fahrenheit - 32.0));
    return celsius;
}

float celsius_to_kelvin (float celsius) {

    float kelvin = celsius + 273.15;
    return kelvin;
}

float kelvin_to_celsius (float kelvin) {
    float celsius = kelvin - 273.15;
    return celsius;
}

void categorize_temperature (float celsius) {
    if (celsius <= 0) 
    {
        printf("Freezing! Bundle Up!\n");
    }
    else if (celsius > 0 && celsius <= 10) 
    {
        printf("Cold! Wear a jacket at least.\n");
    }
    else if  (celsius > 10 && celsius <= 25) 
    {
        printf("Comfortable. Enjoy the day!\n");
    }
    else if (celsius > 25 && celsius <= 35)
    {
        printf("Hot! Make sure to bring water!\n");
    }
    else
    {
        printf("Extreme Heat! Stay indoors as much as possible!\n");
    }
}

float user_menu(float temp, int input_scale, int input_target) 
{
    switch(input_scale) 
    {
        case 1: //Fahrenheit

            switch (input_target)
            {
            case 2: //to Celsius
                
                return fahrenheit_to_celsius(temp);
                break;
            
            case 3: //to Kelvin
                temp = fahrenheit_to_celsius(temp);
                return celsius_to_kelvin(temp);

                break;
            }
        case 2: //Celsius
            
            switch (input_target)
            {
            case 1: //to Farenheit
                return celsius_to_fahrenheit(temp);    

                break;
            
            case 3: //to Kelvin
                return celsius_to_kelvin(temp);
                
                break;
            }

        case 3: //Kelvin

            switch (input_target) 
            {
            case 1: //to Farenheit
                temp = kelvin_to_celsius(temp);
                return celsius_to_fahrenheit(temp);

                break;
                
            case 2: //to Celsius
                return kelvin_to_celsius(temp);    

                break;
            }
    }
}
int main() {

    float temperature_value;
    int user_input;
    int conversion_input;
    bool in_range = false;

    do {
        printf("Input a temperature value: ");                      //Prompt user for a temp
        scanf("%f", &temperature_value);

        printf("\nChoose the temperature scale. Type 1, 2 or 3\n"); //Prompt for the scale
        printf("1) Fahrenheit   2) Celsius    3) Kelvin\n");
        scanf("%d", &user_input);

        printf("Choose the conversion target. Type 1, 2 or 3\n");   //Promp for conversion
        printf("1) Fahrenheit   2) Celsius    3) Kelvin\n");
        scanf("%d", &conversion_input);

        if (user_input == conversion_input)            //Throw error if input and target are the same
        {
            printf("Error: No conversion.\n");
        }
        else if ((temperature_value > 150 || temperature_value < -150) && user_input == 1)             //Check if input temp is between -150 and +150
        {
            printf("Extreme temperatures! Double check input temperature.\n");
        }
        else if ((temperature_value < -101 || temperature_value > 65 ) && user_input == 2)
        {
            printf("Extreme Temperatures! Double Check input temperature.\n");
        }
        else if (temperature_value < 0 && user_input == 3) 
        {
            printf("Cannot have negative Kelvin values.\n");      //Throw error for negative kelvin values
        }

        else if (((temperature_value > 0 && temperature_value < 173) || temperature_value > 339) && user_input == 3)
        {
            printf("Extreme temperatures! Double check input temperature.\n");
        }
        else 
        {
            in_range = true;
        }
    
    } while (!in_range);


    float new_temp = user_menu(temperature_value, user_input, conversion_input);  //store converted temperature

        printf("New temp %.1f\n", new_temp);
    
    //converts within 1/10th of a unit

    //Output weather warnings
    if (conversion_input == 1) 
    {
        new_temp = fahrenheit_to_celsius(new_temp);         //Convert from Farhrenheit to Celsius
        categorize_temperature(new_temp);   
    }
    else if (conversion_input == 2) 
    {
        categorize_temperature(new_temp);
    }
    else
    {
        new_temp = kelvin_to_celsius(new_temp);
        categorize_temperature(new_temp);
    } 
    return 0;
}