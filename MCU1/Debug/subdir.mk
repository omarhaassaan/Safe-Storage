################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_Motor.c \
../LCD.c \
../MCU1.c \
../Timer0.c \
../UART.c \
../keypad.c 

OBJS += \
./DC_Motor.o \
./LCD.o \
./MCU1.o \
./Timer0.o \
./UART.o \
./keypad.o 

C_DEPS += \
./DC_Motor.d \
./LCD.d \
./MCU1.d \
./Timer0.d \
./UART.d \
./keypad.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


