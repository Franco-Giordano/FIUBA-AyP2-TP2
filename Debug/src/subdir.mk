################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Acciones.cpp \
../src/Almacen.cpp \
../src/ConversorDeDatos.cpp \
../src/Cultivo.cpp \
../src/Dado.cpp \
../src/Destino.cpp \
../src/DronAereo.cpp \
../src/EasyBMP.cpp \
../src/EasyBMP_Font.cpp \
../src/EasyBMP_Geometry.cpp \
../src/Jugador.cpp \
../src/LectorCSV.cpp \
../src/Monedero.cpp \
../src/Parcela.cpp \
../src/Peon.cpp \
../src/Secretario.cpp \
../src/TanqueDeAgua.cpp \
../src/Terreno.cpp \
../src/Tiempo.cpp \
../src/main_PROTOTIPO.cpp 

OBJS += \
./src/Acciones.o \
./src/Almacen.o \
./src/ConversorDeDatos.o \
./src/Cultivo.o \
./src/Dado.o \
./src/Destino.o \
./src/DronAereo.o \
./src/EasyBMP.o \
./src/EasyBMP_Font.o \
./src/EasyBMP_Geometry.o \
./src/Jugador.o \
./src/LectorCSV.o \
./src/Monedero.o \
./src/Parcela.o \
./src/Peon.o \
./src/Secretario.o \
./src/TanqueDeAgua.o \
./src/Terreno.o \
./src/Tiempo.o \
./src/main_PROTOTIPO.o 

CPP_DEPS += \
./src/Acciones.d \
./src/Almacen.d \
./src/ConversorDeDatos.d \
./src/Cultivo.d \
./src/Dado.d \
./src/Destino.d \
./src/DronAereo.d \
./src/EasyBMP.d \
./src/EasyBMP_Font.d \
./src/EasyBMP_Geometry.d \
./src/Jugador.d \
./src/LectorCSV.d \
./src/Monedero.d \
./src/Parcela.d \
./src/Peon.d \
./src/Secretario.d \
./src/TanqueDeAgua.d \
./src/Terreno.d \
./src/Tiempo.d \
./src/main_PROTOTIPO.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


