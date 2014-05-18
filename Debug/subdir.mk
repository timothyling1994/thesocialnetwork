################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../friend.cpp \
../main.cpp \
../user.cpp \
../userlist.cpp \
../wall.cpp \
../wallpost.cpp \
../wallpostComment.cpp 

OBJS += \
./friend.o \
./main.o \
./user.o \
./userlist.o \
./wall.o \
./wallpost.o \
./wallpostComment.o 

CPP_DEPS += \
./friend.d \
./main.d \
./user.d \
./userlist.d \
./wall.d \
./wallpost.d \
./wallpostComment.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


