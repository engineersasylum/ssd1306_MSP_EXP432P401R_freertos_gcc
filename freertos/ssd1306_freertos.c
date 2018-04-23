#include <stdint.h>
#include <unistd.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <timers.h>

/* Driver Header files */
//#include <ti/devices/msp432p4xx/driverlib/gpio.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/I2C.h>

/* Example/Board Header files */
#include "Board.h"

#define SSD1306_LCDWIDTH                128
#define SSD1306_LCDHEIGHT               64
#define SSD1306_SETCONTRAST             0x81
#define SSD1306_DISPLAYALLON_RESUME     0xA4
#define SSD1306_DISPLAYALLON            0xA5
#define SSD1306_NORMALDISPLAY           0xA6
#define SSD1306_INVERTDISPLAY           0xA7
#define SSD1306_DISPLAYOFF              0xAE
#define SSD1306_DISPLAYON               0xAF
#define SSD1306_SETDISPLAYOFFSET        0xD3
#define SSD1306_SETCOMPINS              0xDA
#define SSD1306_SETVCOMDETECT           0xDB
#define SSD1306_SETDISPLAYCLOCKDIV      0xD5
#define SSD1306_SETPRECHARGE            0xD9
#define SSD1306_SETMULTIPLEX            0xA8
#define SSD1306_SETLOWCOLUMN            0x00
#define SSD1306_SETHIGHCOLUMN           0x10
#define SSD1306_SETSTARTLINE            0x40
#define SSD1306_MEMORYMODE              0x20
#define SSD1306_COLUMNADDR              0x21
#define SSD1306_PAGEADDR                0x22
#define SSD1306_COMSCANINC              0xC0
#define SSD1306_COMSCANDEC              0xC8
#define SSD1306_SEGREMAP                0xA0
#define SSD1306_CHARGEPUMP              0x8D
#define SSD1306_EXTERNALVCC             0x1
#define SSD1306_SWITCHCAPVCC            0x2


void vTaskOled(void *l)
{
    I2C_Handle      i2c;
    I2C_Params      i2cParams;
    I2C_Transaction i2cTransaction;


    GPIO_init();
    //GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P6,GPIO_PIN5);
    //GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P6,GPIO_PIN4);
    I2C_init();
    I2C_Params_init(&i2cParams);

    i2cParams.bitRate = I2C_100kHz;
    i2c = I2C_open(Board_I2C_TMP, &i2cParams);

    void ssd_dat(uint8_t data){

            uint8_t txBuffer[2];
            txBuffer[0] = 0x40;
            txBuffer[1] = data;

            i2cTransaction.slaveAddress = 0x3c;
            i2cTransaction.writeBuf   = txBuffer;
            i2cTransaction.writeCount = 2;
            i2cTransaction.readBuf    = NULL;
            i2cTransaction.readCount  = 0;
            I2C_transfer(i2c, &i2cTransaction);
            //I2C_close(i2c);

        }

    void ssd_cmd(uint8_t cmd){

        uint8_t txBuffer[2];
        txBuffer[0] = 0x00;
        txBuffer[1] = cmd;

        i2cTransaction.slaveAddress = 0x3c;
        i2cTransaction.writeBuf   = txBuffer;
        i2cTransaction.writeCount = 2;
        i2cTransaction.readBuf    = NULL;
        i2cTransaction.readCount  = 0;
        I2C_transfer(i2c, &i2cTransaction);
        //I2C_close(i2c);

    }


    ssd_cmd(SSD1306_DISPLAYOFF);                    // 0xAE
    ssd_cmd(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
    ssd_cmd(0x80);                                  // the suggested ratio 0x80
    ssd_cmd(SSD1306_SETMULTIPLEX);                  // 0xA8
    ssd_cmd(0x3F);
    ssd_cmd(SSD1306_SETDISPLAYOFFSET);              // 0xD3
    ssd_cmd(0x0);                                   // no offset
    ssd_cmd(SSD1306_SETSTARTLINE);                  // | 0x0);        // line #0
    ssd_cmd(SSD1306_CHARGEPUMP);                    // 0x8D
    ssd_cmd(0x14);                                  // using internal VCC
    ssd_cmd(SSD1306_MEMORYMODE);                    // 0x20
    ssd_cmd(0x00);                                  // 0x00 horizontal addressing
    ssd_cmd(SSD1306_SEGREMAP | 0x1);                // rotate screen 180
    ssd_cmd(SSD1306_COMSCANDEC);                    // rotate screen 180
    ssd_cmd(SSD1306_SETCOMPINS);                    // 0xDA
    ssd_cmd(0x12);
    ssd_cmd(SSD1306_SETCONTRAST);                   // 0x81
    ssd_cmd(0xff);
    ssd_cmd(SSD1306_SETPRECHARGE);                  // 0xd9
    ssd_cmd(0xF1);
    ssd_cmd(SSD1306_SETVCOMDETECT);                 // 0xDB
    ssd_cmd(0x40);
    ssd_cmd(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
    ssd_cmd(SSD1306_NORMALDISPLAY);                 // 0xA6
    ssd_cmd(SSD1306_DISPLAYON);                     //display panel on



    for(;;){

        uint8_t i=0xb0,j=0;
        uint8_t time = 2;

            while(i <= 0xb7){

                ssd_cmd(0x10);
                ssd_cmd(i);
                ssd_cmd(0x00);
                ssd_cmd(0x10);

                while(j <= 127) {
                    ssd_dat(0xff);
                   j++;
                }
                j=0;
                i=i+0x01;
            }
             sleep(time);
             GPIO_toggle(Board_GPIO_LED0);
    }
 }


void vTaskLEDA(void *p)
{
        uint32_t time = 1;

        GPIO_init();
        for(;;) {

            sleep(time);
            GPIO_toggle(Board_GPIO_LED1);
        }
  }
