################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ipmedt5test.lss \

FLASH_IMAGE += \
ipmedt5test.hex \

EEPROM_IMAGE += \
ipmedt5test.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ipmedt5test.elf secondary-outputs

# Tool invocations
ipmedt5test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ipmedt5test.map -mmcu=atmega328p -o "ipmedt5test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ipmedt5test.lss: ipmedt5test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ipmedt5test.elf  >"ipmedt5test.lss"
	@echo 'Finished building: $@'
	@echo ' '

ipmedt5test.hex: ipmedt5test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ipmedt5test.elf  "ipmedt5test.hex"
	@echo 'Finished building: $@'
	@echo ' '

ipmedt5test.eep: ipmedt5test.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ipmedt5test.elf  "ipmedt5test.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ipmedt5test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p ipmedt5test.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ipmedt5test.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm328p -cusbasp -Uflash:w:ipmedt5test.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ipmedt5test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
