################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../44blib.c \
../8led.c \
../button.c \
../led.c \
../main.c 

ASM_SRCS += \
../44binit.asm \
../init.asm 

OBJS += \
./44binit.o \
./44blib.o \
./8led.o \
./button.o \
./init.o \
./led.o \
./main.o 

C_DEPS += \
./44blib.d \
./8led.d \
./button.d \
./led.d \
./main.d 

ASM_DEPS += \
./44binit.d \
./init.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC Assembler'
	arm-none-eabi-gcc -x assembler-with-cpp -I"C:\Users\usuario_local\Downloads\Practica-1-SED" -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Windows GCC C Compiler'
	arm-none-eabi-gcc -I"C:\Users\usuario_local\Downloads\Practica-1-SED" -O0 -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -mapcs-frame -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=arm7tdmi -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


