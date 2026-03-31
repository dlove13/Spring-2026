/*
 * Objective: implements a timer interrupt handler. 
 */
#include <stdio.h>
#include <stdint.h>

#include "eecs388_lib.h"

//Counter for number of times the timer interrupt occurs
volatile int intr_count = 0;

#define MAX_INTERRUPTS 16

//Array of function points for interrupts and exceptions
void (*interrupt_handler[MAX_INTERRUPTS])();
void (*exception_handler[MAX_INTERRUPTS])();

//Direct mode trap handler
void handle_trap(void) __attribute((interrupt));
void handle_trap()
{  
    unsigned long mcause = read_csr(mcause);

    if (mcause & MCAUSE_INT) {
        printf("interrupt. cause=%d, count=%d\n", mcause & MCAUSE_CAUSE, (int)intr_count);

        // mask interrupt bit and branch to handler
        interrupt_handler[mcause & MCAUSE_CAUSE] ();
    } else {
        printf("exception=%d\n", mcause & MCAUSE_CAUSE);
        
        // synchronous exception, branch to handler
        exception_handler[mcause & MCAUSE_CAUSE]();
    }
}

void timer_handler()
{
    // YOUR CODE HERE
    /* Task 2.3 Increment the interrupt counter variable*/
    intr_count += 1;

    /* Task 2.3 Set the mtimecmpr register to a correct value to 
       generate an interrupt after 100ms */


    set_cycles(get_cycles() + (MTIME_RATE_HZ_DEF / 10));
    

}

void enable_timer_interrupt()
{
    write_csr(mie, read_csr(mie) | (1 << MIE_MTIE_BIT ));
    /* Task 2.1 - Find the correct bit to set in mie register to enable
        timer interrupts */
    
    
}

void enable_interrupt()
{
    // YOUR CODE HERE
    /* Task 2.2 - Look at the enable_timer_interrupt() function for hints about
       how to write this function */

    write_csr(mstatus, read_csr(mstatus) | (1 << MSTATUS_MIE_BIT));
}

void disable_interrupt()
{
    // YOUR CODE HERE
    /* Task 2.2 - Look at the enable_timer_interrupt() function for hints about
       how to write this function */
    
       write_csr(mstatus, read_csr(mstatus) & ~ (1 << MSTATUS_MIE_BIT));
}

//Register our direct mode trap handler function pointer
void register_trap_handler(void *func)
{
    write_csr(mtvec, ((unsigned long)func));
}

int main (void)
{
    int led_idx = 0;                            /* LED index */
    int led_gpio[] = {BLUE_LED, GREEN_LED};     /* LED array */
    int val = 0;                                /* On/Off value for LED */
    int prev_intr_count = intr_count;           /* previous interrupt count */

    // configure GPIOs for ouput
    for (int i = 0; i < 2; i++) {
        gpio_mode(led_gpio[i], OUTPUT);
    }

    // install timer interrupt handler
    interrupt_handler[MIE_MTIE_BIT] = timer_handler;

    // write handle_trap address to mtvec
    register_trap_handler( handle_trap );

    // enable timer interrupt
    enable_timer_interrupt();

    // enable global interrupt
    enable_interrupt(); 

    // cause timer interrupt for some time in future 
    set_cycles( get_cycles() + 40000 );

    // main loop. 
    while(1) {
        disable_interrupt();

        if (prev_intr_count != intr_count) {
            // toggle led on/off on a new interrupt
            val ^= 1;   

            // turn on/off LED
            gpio_write(led_gpio[led_idx], val);

            // save off the interrupt count
            prev_intr_count = intr_count;

            // reset interrupt counter at every 10+ interrupts
            if (intr_count >= 10) {
                printf("count=%d. reset\n", (int)intr_count);
                intr_count = 0;
                gpio_write(led_gpio[led_idx], OFF);
                led_idx = (led_idx + 1) % 2; 
            }
        }

        enable_interrupt();
    }
    return 0;
}
