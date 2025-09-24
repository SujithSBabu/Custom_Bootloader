################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Src/gpio_stm32.c \
../MCAL/Src/peripheral_clock.c \
../MCAL/Src/uart_stm32.c 

OBJS += \
./MCAL/Src/gpio_stm32.o \
./MCAL/Src/peripheral_clock.o \
./MCAL/Src/uart_stm32.o 

C_DEPS += \
./MCAL/Src/gpio_stm32.d \
./MCAL/Src/peripheral_clock.d \
./MCAL/Src/uart_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Src/%.o MCAL/Src/%.su MCAL/Src/%.cyclo: ../MCAL/Src/%.c MCAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/ECUAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/MCAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/BootLoader/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-Src

clean-MCAL-2f-Src:
	-$(RM) ./MCAL/Src/gpio_stm32.cyclo ./MCAL/Src/gpio_stm32.d ./MCAL/Src/gpio_stm32.o ./MCAL/Src/gpio_stm32.su ./MCAL/Src/peripheral_clock.cyclo ./MCAL/Src/peripheral_clock.d ./MCAL/Src/peripheral_clock.o ./MCAL/Src/peripheral_clock.su ./MCAL/Src/uart_stm32.cyclo ./MCAL/Src/uart_stm32.d ./MCAL/Src/uart_stm32.o ./MCAL/Src/uart_stm32.su

.PHONY: clean-MCAL-2f-Src

