################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/OLED/control_code.c \
../Drivers/OLED/fonts.c 

OBJS += \
./Drivers/OLED/control_code.o \
./Drivers/OLED/fonts.o 

C_DEPS += \
./Drivers/OLED/control_code.d \
./Drivers/OLED/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/OLED/%.o Drivers/OLED/%.su Drivers/OLED/%.cyclo: ../Drivers/OLED/%.c Drivers/OLED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Ryzen/STM32CubeIDE/workspace_1.10.1/URSiKTM/Drivers/OLED" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-OLED

clean-Drivers-2f-OLED:
	-$(RM) ./Drivers/OLED/control_code.cyclo ./Drivers/OLED/control_code.d ./Drivers/OLED/control_code.o ./Drivers/OLED/control_code.su ./Drivers/OLED/fonts.cyclo ./Drivers/OLED/fonts.d ./Drivers/OLED/fonts.o ./Drivers/OLED/fonts.su

.PHONY: clean-Drivers-2f-OLED

