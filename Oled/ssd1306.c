/*
 * ssd1306.c
 *
 *  Created on: 25-Apr-2018
 *      Author: blackfly
 */
#include <stdint.h>
#include <ti/drivers/I2C.h>
#include"Oled/ssd1306.h"

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




