################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include STWIN\ -\ Predictive_Maintenance/User/Patch/subdir.mk
-include STWIN\ -\ Predictive_Maintenance/User/subdir.mk
-include STWIN\ -\ Predictive_Maintenance/STM32CubeIDE/subdir.mk
-include Middlewares/json/subdir.mk
-include Middlewares/STM32_USBD_Library/Core/subdir.mk
-include Middlewares/STM32_USBD_Library/Class/CDC/subdir.mk
-include Middlewares/STM32_MotionSP/subdir.mk
-include Middlewares/STM32_BLE_Manager/subdir.mk
-include Middlewares/MetaDataManager/subdir.mk
-include Middlewares/BlueNRG-2/Utils/subdir.mk
-include Middlewares/BlueNRG-2/HCI/hci_tl_patterns/Basic/subdir.mk
-include Middlewares/BlueNRG-2/HCI/Controller/subdir.mk
-include Middlewares/BlueNRG-2/HCI/subdir.mk
-include Drivers/STM32L4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STWIN/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32L4R9ZI-STWIN_PredictiveMaintenance
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32L4R9ZI-STWIN_PredictiveMaintenance.elf \

MAP_FILES += \
STM32L4R9ZI-STWIN_PredictiveMaintenance.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32L4R9ZI-STWIN_PredictiveMaintenance.list \

OBJCOPY_BIN += \
STM32L4R9ZI-STWIN_PredictiveMaintenance.bin \


# All Target
all: main-build

# Main-build Target
main-build: STM32L4R9ZI-STWIN_PredictiveMaintenance.elf secondary-outputs

# Tool invocations
STM32L4R9ZI-STWIN_PredictiveMaintenance.elf STM32L4R9ZI-STWIN_PredictiveMaintenance.map: $(OBJS) $(USER_OBJS) ../STM32L4R9ZITx_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "STM32L4R9ZI-STWIN_PredictiveMaintenance.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32L4R9ZITx_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32L4R9ZI-STWIN_PredictiveMaintenance.map" -Wl,--gc-sections -static -L../../../../../../../Drivers/CMSIS/Lib/GCC --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32L4R9ZI-STWIN_PredictiveMaintenance.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32L4R9ZI-STWIN_PredictiveMaintenance.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32L4R9ZI-STWIN_PredictiveMaintenance.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32L4R9ZI-STWIN_PredictiveMaintenance.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32L4R9ZI-STWIN_PredictiveMaintenance.bin STM32L4R9ZI-STWIN_PredictiveMaintenance.elf STM32L4R9ZI-STWIN_PredictiveMaintenance.list STM32L4R9ZI-STWIN_PredictiveMaintenance.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
