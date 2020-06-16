################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := cs-rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Practica-1-SED.hex \

SECONDARY_LIST += \
Practica-1-SED.lst \

SECONDARY_SIZE += \
Practica-1-SED.siz \


# All Target
all: Practica-1-SED.elf secondary-outputs

# Tool invocations
Practica-1-SED.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Windows GCC C Linker'
	arm-none-eabi-gcc -T"C:\Users\usuario_local\Downloads\Practica-1-SED\ram_ice.ld" -nostartfiles -Wl,-Map,Practica-1-SED.map -mcpu=arm7tdmi -g3 -gdwarf-2 -o "Practica-1-SED.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Practica-1-SED.hex: Practica-1-SED.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary Practica-1-SED.elf  "Practica-1-SED.hex"
	@echo 'Finished building: $@'
	@echo ' '

Practica-1-SED.lst: Practica-1-SED.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Create Listing'
	arm-none-eabi-objdump -h -S Practica-1-SED.elf > "Practica-1-SED.lst"
	@echo 'Finished building: $@'
	@echo ' '

Practica-1-SED.siz: Practica-1-SED.elf
	@echo 'Invoking: ARM Sourcery Windows GNU Print Size'
	arm-none-eabi-size  --format=berkeley Practica-1-SED.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) Practica-1-SED.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
