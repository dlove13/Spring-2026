#include <stdio.h>

void update_scale(int new);

void update_scale(int new) 
{ //assume 15 is passed in for new value
   
    int register_val = 0x12345678; //pretend this is a register

    volatile int* reg_addr_ptr = &register_val; //address of register

    printf("Old Value: %x \n", reg_addr_ptr); //print

    //Mask off the lowest 4 bits, then set them to the value passed in by new
    *reg_addr_ptr = (*reg_addr_ptr & 0xFFFFFFF0) | (new & 0xF);

        //0x12345678 & 0xFFFFFFF0 = 0x12345670 | (0xF ie: 0b1111)

    printf("New value: %x \n", *reg_addr_ptr);

    return;
}

int main() {

    update_scale(15);

    return 0;
}

