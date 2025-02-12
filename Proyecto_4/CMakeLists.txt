#Primero se coloca la version minima requerida del CMakepara que compile el makefile

cmake_minimum_required(VERSION 3.10)

#Luego se coloca el proyecto a realizar y debajo de este, las instruccion de compilacion, dependencias, etc

project(Proyecto_4)

#instrucciones de la compilacion:

#ejecutable que se genera y sus dependencias
add_executable(Proyecto_4 main.cpp rectangulo.cpp)

#cmake compila fuera de su directorio, basicamente desde la carpeta build ejecuto el cmake y los objetos se generan alli, separando los codigos objetos de los .cpp y .h
#es mas prolijo que el makefile convencional. Lo unico, debo ejecutar el archivo del cmake colocando una ruta relativa respecto a mi carpeta build
#ej: Una vez en build, abro la terminal y coloco: cmake .. El .. es porque build es una subcarpeta de Proyecto_1, donde esta el cmakelists.txt. 
#Por ultimo hago make en la carpeta build y me creara el ejecutable alli, junto al makefile y los codigos objetos.