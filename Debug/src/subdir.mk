################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/HW5.cpp \
../src/Piece.cpp \
../src/Production.cpp \
../src/Tests.cpp 

OBJS += \
./src/Board.o \
./src/HW5.o \
./src/Piece.o \
./src/Production.o \
./src/Tests.o 

CPP_DEPS += \
./src/Board.d \
./src/HW5.d \
./src/Piece.d \
./src/Production.d \
./src/Tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


