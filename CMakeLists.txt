cmake_minimum_required(VERSION 3.16)

project(Taller02_EstructuraDatos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taller02
        src/main.cpp
        src/Persona.cpp
        src/Paciente.cpp
        include/Persona.h
        src/Persona.cpp
        include/Utilidades.h
        src/Utilidades.cpp
        include/ArchivoPacientes.h
        src/ArchivoPacientes.cpp
)

target_include_directories(taller02 PRIVATE include)