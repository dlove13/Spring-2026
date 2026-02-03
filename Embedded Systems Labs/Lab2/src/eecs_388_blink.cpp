#include <Arduino.h>
#include "eecs_388_lib.h"

/******************************************************************************
 *   Timing definitions (milliseconds)
 *******************************************************************************/
#define ONE_SEC        (1000)   /* 1 second     */
#define HALF_SEC       (500)    /* 0.5 second   */
#define SHORT_DELAY    (25)     /* 25 ms        */
#define MID_DELAY       (300) /* 300 ms*/
/******************************************************************************
 *   Function: setup() - Initializes the Arduino System
 *      Pre condition: 
 *          Hardware must be properly connected (sensors, LEDS, etc.)
 *      Post condition: 
 *          Runs initialization calls one time on power up
 *          Input/Output (IO) pins are configured
 *******************************************************************************/
void setup()
{
gpio_mode(GPIO_13, GPIO_OUTPUT);  /* Built-in LED */

/* Task 2.2 - Setup the GPIO_12 and GPIO_11 lines for output */
gpio_mode(GPIO_12, GPIO_OUTPUT);
gpio_mode(GPIO_11, GPIO_OUTPUT);
gpio_mode(GPIO_10, GPIO_OUTPUT);
}

/******************************************************************************
 *   Function: setup() - Main execution loop
 *      Pre condition: 
 *          setup() has been executed and system is initialized
 *      Post condition: 
 *          Performs a single iteration of the system's function
 *          Repeates indefinetely unless the board is reset or powered off
 *******************************************************************************/
void loop() 
{

//RED
gpio_write(GPIO_13, ON);
delay_ms(HALF_SEC);      //Keep on for 500ms
gpio_write(GPIO_13, OFF);
delay(MID_DELAY); //300ms

/* Task 2.2 - Toggle the GPIOs through RED -> Green -> Blue. 
              On for 500ms, off for 300ms */



//BLUE
gpio_write(GPIO_12, ON); //Turn on
delay_ms(HALF_SEC);      //Keep on for 500ms
gpio_write(GPIO_12, OFF); //Turn off 
delay(MID_DELAY); //300ms

//GREEN
gpio_write(GPIO_11, ON); //Turn on
delay_ms(HALF_SEC);      //Keep on for 500ms
gpio_write(GPIO_11, OFF); //Turn off 
delay(MID_DELAY); //300ms
/* Task 2.3 - BONUS: Modify your code to insert white so order will be
              Red -> Green -> Blue -> White */

//WHITE
gpio_write(GPIO_13, ON);
gpio_write(GPIO_12, ON);
gpio_write(GPIO_11, ON);
delay_ms(HALF_SEC);
gpio_write(GPIO_13, OFF);
gpio_write(GPIO_12, OFF);
gpio_write(GPIO_11, OFF);
delay(MID_DELAY);

/* Task 2.4 - BONUS: Use GPIO_10 and create an active-low circuit for a RED LED */

}
