#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "eecs388_lib.h"

#define BUF_SIZE    (80)
#define UART0       (0)
#define UART1       (1)

int main()
{
	char string_array[BUF_SIZE];
    int  bytes_read;
	
    // initialize UART channels
    ser_setup(0); // uart0 (debug-console on linux machine)
    ser_setup(1); // uart1 (raspberry pi)
    
    printf("Setup completed.\n");
    printf("Begin the main loop.\n");
    
    while (1) {
        if (ser_isready(UART1)) {

            ser_readline(UART1, BUF_SIZE, string_array);
            ser_printline(UART0, string_array);
        }
    }
    return 0;
}
