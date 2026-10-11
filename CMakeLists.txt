cmake_minimum_required(VERSION 3.16)

project(Taller02_EstructuraDatos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taller02
        src/main.cpp
        src/Persona.cpp
        src/Paciente.cpp
        src/Utilidades.cpp
        src/ColaPacientes.cpp
        src/ArchivoPacientes.cpp
        src/NodoDecision.cpp
        src/ArbolDecision.cpp
        include/NodoAVL.h
        src/NodoAVL.cpp
        include/AVL.h
        src/AVL.cpp
        include/Servicio.h
        src/Servicio.cpp
)

target_include_directories(taller02 PRIVATE include)

configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/pacientes.txt
        ${CMAKE_CURRENT_BINARY_DIR}/pacientes.txt
        COPYONLY
)