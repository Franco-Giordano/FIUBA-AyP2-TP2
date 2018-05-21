################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Acciones.cpp \
../src/Almacen.cpp \
../src/CatalogoDeSemillas_OBSOLETO.cpp \
../src/ConversorDeDatos.cpp \
../src/Cultivo.cpp \
../src/Dado.cpp \
../src/Destino.cpp \
../src/Jugador.cpp \
../src/LectorCSV.cpp \
../src/LeerArchivos_OBSOLETO.cpp \
../src/Monedero.cpp \
../src/Parcela.cpp \
../src/Peon.cpp \
../src/RealizadorDeAcciones.cpp \
../src/TanqueDeAgua.cpp \
../src/Terreno.cpp \
../src/_ImplementacionCatalogoSemillas.cpp \
../src/_ImplementacionDeAlmacen.cpp \
../src/_ImplementacionDeEstructura.cpp \
../src/_ImplementacionDeJugadores.cpp \
../src/main.cpp 

OBJS += \
./src/Acciones.o \
./src/Almacen.o \
./src/CatalogoDeSemillas_OBSOLETO.o \
./src/ConversorDeDatos.o \
./src/Cultivo.o \
./src/Dado.o \
./src/Destino.o \
./src/Jugador.o \
./src/LectorCSV.o \
./src/LeerArchivos_OBSOLETO.o \
./src/Monedero.o \
./src/Parcela.o \
./src/Peon.o \
./src/RealizadorDeAcciones.o \
./src/TanqueDeAgua.o \
./src/Terreno.o \
./src/_ImplementacionCatalogoSemillas.o \
./src/_ImplementacionDeAlmacen.o \
./src/_ImplementacionDeEstructura.o \
./src/_ImplementacionDeJugadores.o \
./src/main.o 

CPP_DEPS += \
./src/Acciones.d \
./src/Almacen.d \
./src/CatalogoDeSemillas_OBSOLETO.d \
./src/ConversorDeDatos.d \
./src/Cultivo.d \
./src/Dado.d \
./src/Destino.d \
./src/Jugador.d \
./src/LectorCSV.d \
./src/LeerArchivos_OBSOLETO.d \
./src/Monedero.d \
./src/Parcela.d \
./src/Peon.d \
./src/RealizadorDeAcciones.d \
./src/TanqueDeAgua.d \
./src/Terreno.d \
./src/_ImplementacionCatalogoSemillas.d \
./src/_ImplementacionDeAlmacen.d \
./src/_ImplementacionDeEstructura.d \
./src/_ImplementacionDeJugadores.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


