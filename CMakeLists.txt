cmake_minimum_required(VERSION 3.16)

project(Taller02_EstructuraDatos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(taller02
        include/Persona.h
        src/Persona.cpp

        include/Paciente.h
        src/Paciente.cpp

        include/Utilidades.h
        src/Utilidades.cpp

        include/ColaPacientes.h
        src/ColaPacientes.cpp

        include/ArchivoPacientes.h
        src/ArchivoPacientes.cpp

        include/NodoDecision.h
        src/NodoDecision.cpp

        include/ArbolDecision.h
        src/ArbolDecision.cpp

        include/NodoAVL.h
        src/NodoAVL.cpp

        include/AVL.h
        src/AVL.cpp

        include/Servicio.h
        src/Servicio.cpp

        include/Hospital.h
        src/Hospital.cpp

        src/main.cpp
)

target_include_directories(taller02 PRIVATE include)

add_custom_command(TARGET taller02 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/pacientes.txt
        $<TARGET_FILE_DIR:taller02>/pacientes.txt
)