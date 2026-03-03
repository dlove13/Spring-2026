/******************************************************************************
 *   Header Includes
 *******************************************************************************/
#include <Arduino.h>
#include <stdint.h>
#include <stdio.h>

#include "eecs_388_lib.h"

/******************************************************************************
 *   Constant definitions
 *******************************************************************************/
#define BMP180_ADDR     (0x77)    // BMP180 I2C address

#define BASE_CAL_ADDR   (0xAA)    // Base address of calibration data
#define ID_REG_ADDR     (0xD0)    // Chip ID register address+
#define CTRL_MEAS_ADDR  (0xF4)    // Measure control register addresss
#define ADC_MSB_ADDR    (0xF6)    // out_msb ADC register addreess

#define CTRL_TEMP_CMND  (0x2E)    // Measure control register command to start temp conversion

#define BMP180_READ     ((BMP180_ADDR << 1) | 1)    // Read from BMP180 register
#define BMP180_WRITE    ((BMP180_ADDR << 1) | 0)    // Write to BMP180 register

/******************************************************************************
 *   Type declarations
 *******************************************************************************/
typedef struct {
  int16_t  cal_AC1;
  int16_t  cal_AC2;
  int16_t  cal_AC3;
  uint16_t cal_AC4;
  uint16_t cal_AC5;
  uint16_t cal_AC6;
  int16_t  cal_B1;
  int16_t  cal_B2;
  int16_t  cal_MB;
  int16_t  cal_MC;
  int16_t  cal_MD;
} bmp180_calibration;

/******************************************************************************
 *   Global Variables
 *******************************************************************************/
bmp180_calibration calib_data;

/******************************************************************************
 *   Function: get_true_temperature() - Get True Temperature
 *      Pre condition: 
 *          None
 *      Post condition: 
 *          Takes raw UT value and converts to tenths of a degree celsius
 *******************************************************************************/
static int32_t get_true_temperature( int16_t ut_val )
{
int32_t ret;

/* Task 1.3 - Use the calib_data values to calculate the temperature from the ut value */

int32_t X1 = ((int32_t)(ut_val - calib_data.cal_AC6) * calib_data.cal_AC5) / 32768;

int32_t X2 = ((int32_t)(calib_data.cal_MC * 2048)) /(X1 + calib_data.cal_MD);

int32_t B5 = X1 + X2;

ret  = (B5 + 8) / 16;


return ret;
}

/******************************************************************************
 *   Function: read_calibration() - Read Calibration
 *      Pre condition: 
 *          Hardware must be properly connected (BMP180 sensors, etc.)
 *          i2c_init() must have been run
 *      Post condition: 
 *          Reads the 11 16-bit calibration data values needed to adjust the 
 *            raw temp ADC UT value
 *******************************************************************************/
static void read_calibration( bmp180_calibration * calib) 
{
  i2c_start();
  i2c_write_address(BMP180_WRITE);        // BMP180 Address + Write mode
  i2c_write(BASE_CAL_ADDR);               // Start at EEPROM base calibration address
  i2c_start();
  i2c_write_address(BMP180_READ);         // BMP180 Address + Read mode

  calib->cal_AC1 = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // Read 0xAA, 0xAB
  calib->cal_AC2 = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // Read 0xAC, 0xAD
  calib->cal_AC3 = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // Read 0xAE, 0xAF
  calib->cal_AC4 = ((uint16_t)i2c_read_ack() << 8) | i2c_read_ack();  // ...
  calib->cal_AC5 = ((uint16_t)i2c_read_ack() << 8) | i2c_read_ack();  // ...
  calib->cal_AC6 = ((uint16_t)i2c_read_ack() << 8) | i2c_read_ack();  // ...
  calib->cal_B1  = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // ...
  calib->cal_B2  = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // ...
  calib->cal_MB  = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // ...
  calib->cal_MC  = ((int16_t)i2c_read_ack()  << 8) | i2c_read_ack();  // ...
  calib->cal_MD  = ((int16_t)i2c_read_ack()  << 8) | i2c_read_nack(); // Last bytes - Read 0xBE, 0xBF

  i2c_stop();

  // verify values - These should stay the same each power cycle
  ser_printf("AC1=%d AC2=%d AC3=%d AC4=%u AC5=%u AC6=%u\n", 
    calib->cal_AC1, calib->cal_AC2, calib->cal_AC3, calib->cal_AC4, calib->cal_AC5, calib->cal_AC6);
  ser_printf("B1=%d B2=%d MB=%d MC=%d MD=%d\n", 
    calib->cal_B1, calib->cal_B2, calib->cal_MB, calib->cal_MC, calib->cal_MD);
}

/******************************************************************************
 *   Function: read_register() - Read Register
 *      Pre condition: 
 *          Hardware must be properly connected (BMP180 sensors, etc.)
 *          i2c_init() must have been run
 *      Post condition: 
 *          Reads the specific register provided by reg_addr 
 *******************************************************************************/
static uint8_t read_register(uint8_t reg_addr) {
    // Send START condition
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));

    // Send secondary device an address with write bit (0xEE = 0x77 << 1)
    TWDR = BMP180_WRITE;
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));

    // Send register address to read from
    TWDR = reg_addr;
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));

    // Send repeated START condition
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));

    // Send secondary device an address with read bit (0xEF = 0x77 << 1 | 1)
    TWDR = BMP180_READ;
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));

    // Receive data byte, NACK (since we're only reading one byte)
    TWCR = (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    uint8_t data = TWDR;

    // Send STOP condition
    TWCR = (1 << TWEN) | (1 << TWSTO) | (1 << TWINT);

    return data;
}

/******************************************************************************
 *   Function: read_temperature_adc() - Read Temperature ADC
 *      Pre condition: 
 *          Hardware must be properly connected (BMP180 sensors, etc.)
 *          i2c_init() must have been run
 *      Post condition: 
 *          Reads the raw UT value for the temperature 
 *******************************************************************************/
static int16_t read_temperature_adc() 
{
uint8_t msb;
uint8_t lsb;

// Start temperature measurement
i2c_start();
i2c_write_address(BMP180_WRITE);      // Write mode
i2c_write(CTRL_MEAS_ADDR);            // Control register
i2c_write(CTRL_TEMP_CMND);            // Start temperature conversion
i2c_stop();

delay_us(4500);                       // Delay: 4.5ms for measurement, from Fig 3 in datasheet

// Read raw temperature value
i2c_start();                          // Start Condition
i2c_write_address(BMP180_WRITE);      // Write mode
i2c_write(ADC_MSB_ADDR);              // Target register: MSB register

delay_us(15); 

i2c_start();
i2c_write_address(BMP180_READ);       // Read mode
msb = i2c_read_ack();                 // Read 0xF6 address, ack to continue reading        
lsb = i2c_read_nack();                // Read 0xF7 address, nack to complete reading
i2c_stop();

/* Task 1.2 - Put together the msb and lsb into a 16-bit ut value to return it */

int16_t ut = (msb << 8 ) | lsb;

return (ut);  
}

/******************************************************************************
 *   Function: setup() - Initializes the Arduino System
 *      Pre condition: 
 *          Hardware must be properly connected (BMP180 sensors, etc.)
 *      Post condition: 
 *          Runs initialization calls one time on power up
 *          UART is initialized for ser_printf()
 *          I2C is initialized for communication with BMP180
 *          calib_data is filled with calibration data from BMP180
 *******************************************************************************/
void setup() 
{
uart_init();     // Initialize UART for serial output
i2c_init();      // Initialize I2C for communication with BMP180

read_calibration( &calib_data );

ser_printf("System Initialized");
ser_printf("BMP180 Interface Ready");
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
/* Task 1.1 - Use the read_register() to test out communication with the BMP180
              Print out the ID and confirm communication, it should be 0x55  */

  ser_printf("%x", read_register(ID_REG_ADDR));

/* Task 1.2 - Complete read_temperature_adc() - See function for details */
int16_t ut = read_temperature_adc();                //raw ut adc value

/* Task 1.3 - Complete get_true_temperature() - See function for details */
int32_t temperature = get_true_temperature( ut );   //tenths of degrees celsius
int32_t temp_f = ((temperature * 9) / 5) + 320;     //convert to tenths of degrees farenheit

ser_printf("Temp: %ld.%ld °C\n", temperature / 10, abs(temperature % 10));
ser_printf("Temp: %ld.%ld °F\n", temp_f / 10, abs(temp_f % 10));

delay_ms(1000); // Sample every second
}
