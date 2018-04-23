################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/blackfly/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/mnt/sda4/Projects/MSP432/ssd1306_MSP_EXP432P401R_freertos_gcc" -I"/home/blackfly/ti/simplelink_msp432p4_sdk_2_10_00_14/source" -I"/home/blackfly/ti/simplelink_msp432p4_sdk_2_10_00_14/source/third_party/CMSIS/Include" -I"/home/blackfly/ti/simplelink_msp432p4_sdk_2_10_00_14/source/ti/posix/gcc" -I"/home/blackfly/ti/FreeRTOSv10.0.1/FreeRTOS/Source/include" -I"/home/blackfly/ti/FreeRTOSv10.0.1/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/mnt/sda4/Projects/MSP432/freertos_builds_MSP_EXP432P401R_release_gcc" -I"/home/blackfly/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include/newlib-nano" -I"/home/blackfly/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include" -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


