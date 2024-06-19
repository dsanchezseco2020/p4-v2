CC = g++
CFLAGS = -Wall -g
.RECIPEPREFIX = >

all: mainDashboard

# Compilación de la clase Sensor
mainSensor: mainSensor.o Sensor.o
>$(CC) $(CFLAGS) -o mainSensor mainSensor.o Sensor.o

mainSensor.o: mainSensor.cpp Sensor.h
>$(CC) $(CFLAGS) -c mainSensor.cpp

Sensor.o: Sensor.cpp Sensor.h
>$(CC) $(CFLAGS) -c Sensor.cpp

# Compilación de la clase AirSensor
mainAirSensor: mainAirSensor.o AirSensor.o Sensor.o
>$(CC) $(CFLAGS) -o mainAirSensor mainAirSensor.o AirSensor.o Sensor.o

mainAirSensor.o: mainAirSensor.cpp AirSensor.h Sensor.h
>$(CC) $(CFLAGS) -c mainAirSensor.cpp

AirSensor.o: AirSensor.cpp AirSensor.h Sensor.h
>$(CC) $(CFLAGS) -c AirSensor.cpp

# Compilación de la clase HumSensor
mainHumSensor: mainHumSensor.o HumSensor.o Sensor.o
>$(CC) $(CFLAGS) -o mainHumSensor mainHumSensor.o HumSensor.o Sensor.o

mainHumSensor.o: mainHumSensor.cpp HumSensor.h Sensor.h
>$(CC) $(CFLAGS) -c mainHumSensor.cpp

HumSensor.o: HumSensor.cpp HumSensor.h Sensor.h
>$(CC) $(CFLAGS) -c HumSensor.cpp

# Compilación de la clase LightSensor
mainLightSensor: mainLightSensor.o LightSensor.o Sensor.o
>$(CC) $(CFLAGS) -o mainLightSensor mainLightSensor.o LightSensor.o Sensor.o

mainLightSensor.o: mainLightSensor.cpp LightSensor.h Sensor.h
>$(CC) $(CFLAGS) -c mainLightSensor.cpp

LightSensor.o: LightSensor.cpp LightSensor.h Sensor.h
>$(CC) $(CFLAGS) -c LightSensor.cpp

# Compilación de la clase RGBCamera
mainRGBCamera: mainRGBCamera.o RGBCamera.o Sensor.o
>$(CC) $(CFLAGS) -o mainRGBCamera mainRGBCamera.o RGBCamera.o Sensor.o

mainRGBCamera.o: mainRGBCamera.cpp RGBCamera.h Sensor.h
>$(CC) $(CFLAGS) -c mainRGBCamera.cpp

RGBCamera.o: RGBCamera.cpp RGBCamera.h Sensor.h
>$(CC) $(CFLAGS) -c RGBCamera.cpp

# Compilación de la clase ThermalCamera
mainThermalCamera: mainThermalCamera.o ThermalCamera.o Sensor.o
>$(CC) $(CFLAGS) -o mainThermalCamera mainThermalCamera.o ThermalCamera.o Sensor.o

mainThermalCamera.o: mainThermalCamera.cpp ThermalCamera.h Sensor.h
>$(CC) $(CFLAGS) -c mainThermalCamera.cpp

ThermalCamera.o: ThermalCamera.cpp ThermalCamera.h Sensor.h
>$(CC) $(CFLAGS) -c ThermalCamera.cpp

# Compilación de la clase User
mainUser: mainUser.o User.o
>$(CC) $(CFLAGS) -o mainUser mainUser.o User.o

mainUser.o: mainUser.cpp User.h
>$(CC) $(CFLAGS) -c mainUser.cpp

User.o: User.cpp User.h
>$(CC) $(CFLAGS) -c User.cpp

# Compilación de la clase Admin
mainAdmin: mainAdmin.o Admin.o User.o
>$(CC) $(CFLAGS) -o mainAdmin mainAdmin.o Admin.o User.o

mainAdmin.o: mainAdmin.cpp Admin.h User.h
>$(CC) $(CFLAGS) -c mainAdmin.cpp

Admin.o: Admin.cpp Admin.h User.h
>$(CC) $(CFLAGS) -c Admin.cpp

# Compilación de la clase Employee
mainEmployee: mainEmployee.o Employee.o User.o
>$(CC) $(CFLAGS) -o mainEmployee mainEmployee.o Employee.o User.o

mainEmployee.o: mainEmployee.cpp Employee.h User.h
>$(CC) $(CFLAGS) -c mainEmployee.cpp

Employee.o: Employee.cpp Employee.h User.h
>$(CC) $(CFLAGS) -c Employee.cpp


# Compilacion del Dashboard

mainDashboard: mainDashboard.o Dashboard.o User.o
>$(CC) $(CFLAGS) -o mainDashboard mainDashboard.o Dashboard.o User.o

mainDashboard.o: mainDashboard.cpp Dashboard.h User.h
>$(CC) $(CFLAGS) -c mainDashboard.cpp

Dashboard.o: Dashboard.cpp Dashboard.h User.h
>$(CC) $(CFLAGS) -c Dashboard.cpp

# Clean para eliminar todos los archivos objeto y ejecutables
clean:
>rm -f *.o 
>rm -f mainDashboard mainEmployee mainSensor mainAirSensor mainHumSensor mainLightSensor mainRGBCamera mainThermalCamera mainUser mainAdmin
