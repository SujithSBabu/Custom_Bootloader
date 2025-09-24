################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Src/gpio.c \
../ECUAL/Src/uart.c 

OBJS += \
./ECUAL/Src/gpio.o \
./ECUAL/Src/uart.o 

C_DEPS += \
./ECUAL/Src/gpio.d \
./ECUAL/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Src/%.o ECUAL/Src/%.su ECUAL/Src/%.cyclo: ../ECUAL/Src/%.c ECUAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/ECUAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/MCAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/BootLoader/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ECUAL-2f-Src

clean-ECUAL-2f-Src:
	-$(RM) ./ECUAL/Src/gpio.cyclo ./ECUAL/Src/gpio.d ./ECUAL/Src/gpio.o ./ECUAL/Src/gpio.su ./ECUAL/Src/uart.cyclo ./ECUAL/Src/uart.d ./ECUAL/Src/uart.o ./ECUAL/Src/uart.su

.PHONY: clean-ECUAL-2f-Src

