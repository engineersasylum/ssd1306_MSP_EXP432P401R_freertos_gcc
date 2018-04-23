#include <stdint.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>

/* Driver header files */
#include <ti/drivers/GPIO.h>

/* Example/Board Header files */
#include "Board.h"

extern void vTaskLEDA(void *p);
extern void vTaskOled(void *l);

/* Stack size in 16-bit words */
#define THREADSTACKSIZE    768 / sizeof(portSTACK_TYPE)

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initGeneral();
    xTaskCreate((TaskFunction_t)vTaskLEDA, "LEDA", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate((TaskFunction_t)vTaskOled, "Oled", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    GPIO_init();
    vTaskStartScheduler();

    return (0);
}

//*****************************************************************************
//
//! \brief Application defined malloc failed hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************

void vApplicationMallocFailedHook()
{
    /* Handle Memory Allocation Errors */
    while(1)
    {
    }
}

//*****************************************************************************
//
//! \brief Application defined stack overflow hook
//!
//! \param  none
//!
//! \return none
//!
//*****************************************************************************
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    //Handle FreeRTOS Stack Overflow
    while(1)
    {
    }
}
