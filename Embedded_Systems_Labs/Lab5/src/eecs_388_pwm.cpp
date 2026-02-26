/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

#include "eecs_388_lib.h"

#define SERVO_PULSE_MAX (2400)    /* 2400 us */
#define SERVO_PULSE_MIN (544)     /* 544 us */
#define SERVO_PERIOD    (20000)   /* 20000 us (20ms) */

#define MIN_ANGLE       (0)       /* degrees */
#define MAX_ANGLE       (180)     /* degrees */
#define DEGREE_STEP     (30)      /* degrees */

#define RED_LED         (GPIO_13)
#define BLUE_LED        (GPIO_11)
#define GREEN_LED       (GPIO_12)

// Bonus Task - Uncomment and fill out this function if you attempt the bonus task
//           +---------------+ 
//           |   RGB LED     |
//           +---------------+
//           |   |     |     |
//          R   GND    G     B
//          |    |     |     |
//         [--] [---] [--]  [-]
//          |    |     |     |
//         340Ω  |    340Ω  340Ω
//          |    |     |     MCU
//         MCU   |    MCU    Pin
//         Pin  GND   Pin 
//              Pin

//static void led()
//{
//
//return;
//}

/******************************************************************************
 *   Function: servo() - Servo Motor Pulse
 *      Pre condition: 
 *          Assumes GPIO pin used has been configured for output
 *      Post condition: 
 *          Calculates a duty cycle in microseconds for the amount of on time
 *          needed to achieve the angle passed in
 *******************************************************************************/
static void servo (int gpio, int angle)
{
// YOUR CODE HERE
// Basically, you need to take the input angle "angle" and generate the corresponding pwm signal
// To generate the pwm signals, use gpio_write(), delay_us(), and delay_ms().

uint16_t pwm_on;

switch (angle) {
    case 0:
        pwm_on = 544;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6, OFF);
        delay_ms(19);
        delay_us(456);
        break;

    case 30:
        pwm_on = 853;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6, OFF);
        delay_ms(19);
        delay_us(147);

        break;

    case 60:
        pwm_on = 1162;
        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6, OFF);
        delay_ms(18);
        delay_us(838);
        break;

    case 90:
        pwm_on = 1472;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6,OFF);
        delay_ms(18);
        delay_us(528);
        break;

    case 120:
        pwm_on = 1781;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6, OFF);
        delay_ms(18);
        delay_us(219);
        break;


    case 150:
        pwm_on = 2090;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6,OFF);
        delay_ms(17);
        delay_us(910);
        break;
    
    case 180:
        pwm_on = 2400;

        gpio_write(GPIO_6, ON);
        delay_us(pwm_on);

        gpio_write(GPIO_6,OFF);
        delay_ms(17);
        delay_us(600);
        break;
    
    default:
        break;
}
}

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
gpio_mode(GPIO_6, GPIO_OUTPUT);

// Bonus Task - Uncomment and fill out this function if you attempt the bonus task
//gpio_mode(RED_LED, GPIO_OUTPUT);
//gpio_mode(BLUE_LED, GPIO_OUTPUT);
//gpio_mode(GREEN_LED, GPIO_OUTPUT);

return;
}

/******************************************************************************
 *   Function: loop() - Main execution loop
 *      Pre condition: 
 *          setup() has been executed and system is initialized
 *      Post condition: 
 *          Performs a single iteration of the system's function
 *          Repeates indefinetely unless the board is reset or powered off
 *******************************************************************************/
void loop() 
{
int gpio = GPIO_6;

while (1) 
    {
    /**
     * Sweeps through angles 0 -> 180 by 30 to test the 'servo' function 
     * 
     * The inner loop calls the function 50 times, causing each angle
     * to be held on the servo for ~1 second. 
     * 
     * Do you understand why 1 second?
     * 
     */
    for( int angle = MIN_ANGLE; angle <= MAX_ANGLE; angle += DEGREE_STEP ) 
        {
        /* control the servo for 1 sec duration */
        for( int i = 0; i < 50; i++ )
            {
            servo( gpio, angle );
            }
        }
    
    // Bonus Task - Uncomment and fill out this function if you attempt the bonus task
    //            - Comment out the for loops and servo() function if you attempt the bonus task
    //led();
    }


return;
}