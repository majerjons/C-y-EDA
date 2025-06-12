# CMakeList.txt: proyecto de CMake para eda_plagio_group_4, incluya el origen y defina
# la lógica específica del proyecto aquí.
#

# Agregue un origen al ejecutable de este proyecto.
add_executable (eda_plagio_group_4 "eda_plagio_group_4.cpp" "eda_plagio_group_4.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET eda_plagio_group_4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Agregue pruebas y destinos de instalación si es necesario.
