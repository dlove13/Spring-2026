#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "eecs388_lib.h"

void auto_brake(int devid)
{
    // Task1 & 2: TODO
    // Your code here (Use Lab 02 - Lab 04 for reference)
    // Use the directions given in the project document

    //Measure Distance TODO

    //LED braking TODO
    /*
    if distance > 200 = LED GREEN
    if distance <= 200 and distance > 100 = LED YELLOW (RED + GREEN)
    if distance <= 100 and distance > 60 = LED RED
    if distance <= 60 = FLASHING RED LED
    */

    
    //Check if TF mini ready to read
    //TODO: Figure out device ID for TFMini Lidar
    uint16_t dist = 0;      //initialize distance to 0

    if (ser_isready(devid) && 'Y' == ser_read(devid) && 'Y' == ser_read(devid)) 
    {
        // uint8_t DIST_L = ser_read(devid);
        // uint8_t DIST_H = ser_read(devid);

        // dist = DIST_H << 8 | DIST_L;      //puts together low 8-bits and high 8-bits of distance data

        // if (dist <= 60) {                   
        //     //Flashing RED
        //     gpio_write(RED_LED, ON);
        //     gpio_write(GREEN_LED, OFF);
        //     gpio_write(BLUE_LED, OFF);
        //     delay(100);
        //     gpio_write(RED_LED, OFF);
        //     gpio_write(GREEN_LED, OFF);
        //     gpio_write(BLUE_LED, OFF);
        //     delay(100);
        // }
        // else if (dist > 60 && dist <= 100) {
        //     //RED
        //     gpio_write(RED_LED, ON);
        //     gpio_write(GREEN_LED, OFF);
        //     gpio_write(BLUE_LED, OFF);
            
        // }
        // else if (dist > 100 && dist <= 200) {
        //     //YELLOW
        //     gpio_write(RED_LED, ON);
        //     gpio_write(GREEN_LED, ON);
        //     gpio_write(BLUE_LED, OFF);
        // }
        // else {
        //     //GREEN
        //     gpio_write(RED_LED, OFF);
        //     gpio_write(GREEN_LED, ON);
        //     gpio_write(BLUE_LED, OFF);
        // }
        
        // //print distance value onto serial monitor
        
    }
}

int read_from_pi(int devid)
{
    // Task-3: 
    // You code goes here (Use Lab 09-option1 for reference)
    // After performing Task-2 at dnn.py code, modify this part to read angle values from Raspberry Pi.
    int angle = 0;

    // clear buffer before reading
    memset(__buf, 0, sizeof(__buf)); 

    int bytes_read = ser_readline(devid, 80, __buf);

    if (bytes_read > 0) {
        if (sscanf(__buf, "%d", &angle) == 1) {
            return angle;
        }
    }

}

void steering(int gpio, int pos)
{
    // Task-4: 
    // Your code goes here (Use Lab 05 for reference)
    // Check the project document to understand the task
    
    //Testing Servo Motor
    uint16_t pwm_on;
    
     if  (pos >= 0 && pos < 30) {
        pwm_on = 544;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio, OFF);
        delay(19);
        delay_usec(456);
     }


    else if (pos >= 30 && pos < 60) {
        pwm_on = 853;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio, OFF);
        delay(19);
        delay_usec(147);
    }
        
    else if (pos >= 60 && pos < 90) {
        
        pwm_on = 1162;
        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio, OFF);
        delay(18);
        delay_usec(838);
    }
        
    else if (pos >= 90 && pos < 120) {
        pwm_on = 1472;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio,OFF);
        delay(18);
        delay_usec(528);
        
    }
    
    else if (pos >= 120 && pos < 150 ) {
        pwm_on = 1781;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio, OFF);
        delay(18);
        delay_usec(219);
    }
        
    else if (pos >= 150 && pos < 180) {
        pwm_on = 2090;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio,OFF);
        delay(17);
        delay_usec(910);
    }
       

    
    else if (pos >= 180) {
        pwm_on = 2400;

        gpio_write(gpio, ON);
        delay_usec(pwm_on);

        gpio_write(gpio,OFF);
        delay(17);
        delay_usec(600);
        
    }
}


int main()
{
    // initialize UART channels
    ser_setup(0); // uart0
    ser_setup(1); // uart1
    int pi_to_hifive = 1; //The connection with Pi uses uart 1
    int lidar_to_hifive = 0; //the lidar uses uart 0
    
    printf("\nUsing UART %d for Pi -> HiFive", pi_to_hifive);
    printf("\nUsing UART %d for Lidar -> HiFive", lidar_to_hifive);
    
    //Initializing PINs
    gpio_mode(PIN_19, OUTPUT);
    gpio_mode(RED_LED, OUTPUT);
    gpio_mode(BLUE_LED, OUTPUT);
    gpio_mode(GREEN_LED, OUTPUT);

    printf("Setup completed.\n");
    printf("Begin the main loop.\n");

    while (1) {

        auto_brake(lidar_to_hifive); // measuring distance using lidar and braking
        int angle = read_from_pi(pi_to_hifive); //getting turn direction from pi
        // int angle = 0;
        printf("\nangle=%d", angle);
        int gpio = PIN_19; 
        for (int i = 0; i < 10; i++){
            // Here, we set the angle to 180 if the prediction from the DNN is a positive angle
            // and 0 if the prediction is a negative angle.
            // This is so that it is easier to see the movement of the servo.
            // You are welcome to pass the angle values directly to the steering function.
            // If the servo function is written correctly, it should still work,
            // only the movements of the servo will be more subtle
            // if(angle>0){
            //     steering(gpio, 180);
            // }
            // else {
            //     steering(gpio,0);
            // }
            
            // Uncomment the line below to see the actual angles on the servo.
            // Remember to comment out the if-else statement above!
            steering(gpio, angle);
        }

    }
    return 0;
}
