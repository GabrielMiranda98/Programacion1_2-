################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PRIMERPARCIALMIRANDA.c \
../src/cliente.c \
../src/informes.c \
../src/prestamo.c \
../src/utn.c 

OBJS += \
./src/PRIMERPARCIALMIRANDA.o \
./src/cliente.o \
./src/informes.o \
./src/prestamo.o \
./src/utn.o 

C_DEPS += \
./src/PRIMERPARCIALMIRANDA.d \
./src/cliente.d \
./src/informes.d \
./src/prestamo.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


