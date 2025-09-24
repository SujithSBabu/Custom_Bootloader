################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BootLoader/Src/bl_ack_nack_impl.c \
../BootLoader/Src/bl_cmd_handling.c \
../BootLoader/Src/bl_cmd_packets.c \
../BootLoader/Src/bl_crc_verification.c \
../BootLoader/Src/bl_response.c \
../BootLoader/Src/bootloader.c \
../BootLoader/Src/crc_calculation.c \
../BootLoader/Src/serailize_packets.c 

OBJS += \
./BootLoader/Src/bl_ack_nack_impl.o \
./BootLoader/Src/bl_cmd_handling.o \
./BootLoader/Src/bl_cmd_packets.o \
./BootLoader/Src/bl_crc_verification.o \
./BootLoader/Src/bl_response.o \
./BootLoader/Src/bootloader.o \
./BootLoader/Src/crc_calculation.o \
./BootLoader/Src/serailize_packets.o 

C_DEPS += \
./BootLoader/Src/bl_ack_nack_impl.d \
./BootLoader/Src/bl_cmd_handling.d \
./BootLoader/Src/bl_cmd_packets.d \
./BootLoader/Src/bl_crc_verification.d \
./BootLoader/Src/bl_response.d \
./BootLoader/Src/bootloader.d \
./BootLoader/Src/crc_calculation.d \
./BootLoader/Src/serailize_packets.d 


# Each subdirectory must supply rules for building sources it contributes
BootLoader/Src/%.o BootLoader/Src/%.su BootLoader/Src/%.cyclo: ../BootLoader/Src/%.c BootLoader/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/ECUAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/MCAL/Inc" -I"E:/Embedded_Engineer_Projects/Bootloader_Project/Custom_Bootloader/BootLoader/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-BootLoader-2f-Src

clean-BootLoader-2f-Src:
	-$(RM) ./BootLoader/Src/bl_ack_nack_impl.cyclo ./BootLoader/Src/bl_ack_nack_impl.d ./BootLoader/Src/bl_ack_nack_impl.o ./BootLoader/Src/bl_ack_nack_impl.su ./BootLoader/Src/bl_cmd_handling.cyclo ./BootLoader/Src/bl_cmd_handling.d ./BootLoader/Src/bl_cmd_handling.o ./BootLoader/Src/bl_cmd_handling.su ./BootLoader/Src/bl_cmd_packets.cyclo ./BootLoader/Src/bl_cmd_packets.d ./BootLoader/Src/bl_cmd_packets.o ./BootLoader/Src/bl_cmd_packets.su ./BootLoader/Src/bl_crc_verification.cyclo ./BootLoader/Src/bl_crc_verification.d ./BootLoader/Src/bl_crc_verification.o ./BootLoader/Src/bl_crc_verification.su ./BootLoader/Src/bl_response.cyclo ./BootLoader/Src/bl_response.d ./BootLoader/Src/bl_response.o ./BootLoader/Src/bl_response.su ./BootLoader/Src/bootloader.cyclo ./BootLoader/Src/bootloader.d ./BootLoader/Src/bootloader.o ./BootLoader/Src/bootloader.su ./BootLoader/Src/crc_calculation.cyclo ./BootLoader/Src/crc_calculation.d ./BootLoader/Src/crc_calculation.o ./BootLoader/Src/crc_calculation.su ./BootLoader/Src/serailize_packets.cyclo ./BootLoader/Src/serailize_packets.d ./BootLoader/Src/serailize_packets.o ./BootLoader/Src/serailize_packets.su

.PHONY: clean-BootLoader-2f-Src

