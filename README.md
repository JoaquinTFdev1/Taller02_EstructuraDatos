# Taller 02 - Estructura de Datos

## Información del estudiante

- **Nombre:** Joaquín Esteban Torres Flores
- **RUT:** 21.547.370-8
- **Usuario de GitHub:** JoaquinTFdev1
- **Carrera:** Ingeniería Civil Industrial
- **Paralelo:** C1

## Descripción del proyecto

Este proyecto corresponde al Taller 02 de la asignatura Estructura de Datos.

El programa representa el funcionamiento básico del **Hospital Marmaja**, extendiendo el sistema desarrollado anteriormente mediante el uso de estructuras de datos implementadas manualmente.

El sistema recibe pacientes desde un archivo de texto, los almacena inicialmente en una cola FIFO y posteriormente los procesa uno a uno.

Cada paciente pasa por un árbol de decisión que analiza sus datos clínicos y determina automáticamente el servicio al que debe ser enviado.

Una vez obtenido el servicio, el paciente es almacenado en un árbol AVL propio de ese departamento.

El flujo general del programa es:

```text
Archivo de pacientes
        |
        v
Queue de pacientes
        |
        v
Arbol de decision
        |
        v
Servicio determinado
        |
        v
AVL del servicio
```

El proyecto utiliza estructuras desarrolladas manualmente con nodos y punteros.

No se utilizan estructuras de la STL como `std::queue`, `std::list`, `std::map` o `std::set` para reemplazar las estructuras solicitadas en el taller.

---

## Servicios del hospital

El Hospital Marmaja dispone de ocho servicios:

1. Urgencias
2. Medicina General
3. Cardiologia
4. Neurologia
5. Traumatologia
6. Cirugia
7. Pediatria
8. Hospitalizacion

Cada servicio posee su propio árbol AVL.

Por lo tanto, la estructura general puede representarse de la siguiente forma:

```text
Hospital
|
|-- Urgencias ----------> AVL
|
|-- Medicina General ---> AVL
|
|-- Cardiologia --------> AVL
|
|-- Neurologia ---------> AVL
|
|-- Traumatologia ------> AVL
|
|-- Cirugia ------------> AVL
|
|-- Pediatria ----------> AVL
|
|-- Hospitalizacion ----> AVL
```

Los pacientes son ordenados dentro de cada AVL utilizando su **ID** como clave.

---

## Organización del proyecto

La estructura principal del proyecto es:

```text
Taller02-EstructuraDatos/
|
|-- CMakeLists.txt
|-- README.md
|-- pacientes.txt
|-- .gitignore
|
|-- include/
|   |-- Persona.h
|   |-- Paciente.h
|   |-- Utilidades.h
|   |-- ColaPacientes.h
|   |-- ArchivoPacientes.h
|   |-- NodoDecision.h
|   |-- ArbolDecision.h
|   |-- NodoAVL.h
|   |-- AVL.h
|   |-- Servicio.h
|   `-- Hospital.h
|
`-- src/
    |-- main.cpp
    |-- Persona.cpp
    |-- Paciente.cpp
    |-- Utilidades.cpp
    |-- ColaPacientes.cpp
    |-- ArchivoPacientes.cpp
    |-- NodoDecision.cpp
    |-- ArbolDecision.cpp
    |-- NodoAVL.cpp
    |-- AVL.cpp
    |-- Servicio.cpp
    `-- Hospital.cpp
```

La implementación se encuentra separada en archivos `.h` y `.cpp` para mantener una estructura modular.

---

## Requisitos para compilar

El proyecto utiliza **C++17**.

Se necesita:

- Un compilador compatible con C++17.
- CMake 3.16 o superior.
- Una terminal o entorno capaz de ejecutar CMake.

Compiladores compatibles incluyen, por ejemplo:

```text
g++
clang++
MSVC
MinGW
```

No se requieren librerías externas.

El proyecto puede ejecutarse utilizando:

- CLion.
- Windows.
- Linux.
- macOS.
- GitHub Codespaces.

---

# Compilación utilizando CMake

Desde la carpeta raíz del proyecto ejecutar:

```bash
cmake -S . -B build
```

Luego:

```bash
cmake --build build
```

El archivo `CMakeLists.txt` incluye todos los archivos `.cpp` necesarios para generar el programa.

También se copia automáticamente `pacientes.txt` al directorio de compilación mediante CMake.

---

## Ejecución en Linux

Desde la raíz del proyecto:

```bash
cmake -S . -B build
cmake --build build
```

Después ingresar a la carpeta:

```bash
cd build
```

Ejecutar:

```bash
./taller02
```

---

## Ejecución en macOS

El procedimiento es equivalente a Linux.

```bash
cmake -S . -B build
cmake --build build
cd build
./taller02
```

Se necesita tener instalado un compilador C++ compatible y CMake.

---

## Ejecución en Windows

Desde PowerShell, CMD o una terminal compatible, ubicarse en la carpeta principal del proyecto.

Ejecutar:

```text
cmake -S . -B build
```

Luego:

```text
cmake --build build
```

Si el generador utilizado deja el ejecutable directamente dentro de `build`, ejecutar desde esa carpeta:

```text
cd build
taller02.exe
```

Dependiendo del generador de CMake, especialmente al utilizar Visual Studio, el ejecutable puede encontrarse dentro de:

```text
build/Debug/
```

En ese caso se recomienda mantener como directorio actual `build` y ejecutar:

```text
Debug\taller02.exe
```

De esta forma el programa continúa encontrando correctamente:

```text
pacientes.txt
```

que se encuentra dentro del directorio `build`.

---

## Ejecución en CLion

Abrir la carpeta principal del proyecto en CLion.

CLion debería detectar automáticamente:

```text
CMakeLists.txt
```

El target que se debe ejecutar es:

```text
taller02
```

Si CMake no se actualiza automáticamente:

```text
Tools
-> CMake
-> Reload CMake Project
```

Después seleccionar el target:

```text
taller02
```

y presionar **Run**.

Si se generan problemas debido a configuraciones antiguas, se puede eliminar únicamente la carpeta generada por CLion:

```text
cmake-build-debug
```

y posteriormente volver a realizar:

```text
Reload CMake Project
```

No se deben eliminar:

```text
src/
include/
pacientes.txt
CMakeLists.txt
README.md
.git/
```

---

## Ejecución en GitHub Codespaces

Abrir el repositorio mediante GitHub Codespaces.

Desde la terminal del Codespace ubicarse en la raíz del proyecto.

Ejecutar:

```bash
cmake -S . -B build
```

Luego:

```bash
cmake --build build
```

Ingresar a:

```bash
cd build
```

y ejecutar:

```bash
./taller02
```

El proyecto no utiliza rutas propias de Windows, por lo que puede compilarse también en entornos Linux como GitHub Codespaces.

---

# Archivo de pacientes

El programa utiliza el archivo:

```text
pacientes.txt
```

Cada línea representa un paciente.

El formato utilizado es:

```text
ID;Nombre;Edad;Temperatura;PresionArterial;Dolor;TipoDolor;Trauma;SintomasNeurologicos;RequiereCirugia;DiasHospitalizacion
```

Ejemplo:

```text
001;Juan Perez;25;37.0;120;3;otro;0;0;0;0
```

Cada registro contiene exactamente **11 campos**.

---

## Campos del paciente

### ID

Identificador único del paciente.

Ejemplo:

```text
001
```

El ID también se utiliza como clave para ordenar los pacientes dentro del AVL.

La comparación se realiza utilizando el ID almacenado como texto.

Para mantener un orden intuitivo se recomienda utilizar identificadores con una cantidad uniforme de dígitos:

```text
001
002
003
010
020
```

---

### Nombre

Nombre del paciente.

Ejemplo:

```text
Juan Perez
```

No puede estar vacío.

---

### Edad

Edad del paciente.

Rango utilizado por el programa:

```text
0 a 120
```

---

### Temperatura

Temperatura corporal.

Rango permitido:

```text
30.0 a 45.0
```

---

### PresionArterial

Se representa mediante un valor numérico utilizado por el sistema para evaluar al paciente.

Rango permitido:

```text
40 a 250
```

Para el árbol de decisión se considera una presión elevada cuando:

```text
PresionArterial >= 160
```

---

### Dolor

Escala de dolor:

```text
0 a 10
```

Se considera dolor intenso cuando:

```text
Dolor >= 8
```

---

### TipoDolor

Los valores aceptados son:

```text
pecho
cabeza
abdomen
extremidad
otro
```

---

### Trauma

Debe tener uno de los siguientes valores:

```text
0 = No presenta trauma
1 = Presenta trauma
```

---

### SintomasNeurologicos

Debe ser:

```text
0 = No presenta sintomas neurologicos
1 = Presenta sintomas neurologicos
```

---

### RequiereCirugia

Debe ser:

```text
0 = No requiere cirugia
1 = Requiere cirugia
```

---

### DiasHospitalizacion

Representa la cantidad estimada de días de hospitalización.

Rango aceptado:

```text
0 a 365
```

---

# Validación de datos

Antes de incorporar un paciente a la cola, cada línea es revisada.

Un registro se rechaza cuando:

- No contiene exactamente 11 campos.
- El ID está vacío.
- El nombre está vacío.
- La edad está fuera del rango permitido.
- La temperatura está fuera del rango permitido.
- La presión arterial está fuera del rango permitido.
- El dolor no está entre 0 y 10.
- El tipo de dolor no corresponde a uno permitido.
- Trauma no es 0 o 1.
- SintomasNeurologicos no es 0 o 1.
- RequiereCirugia no es 0 o 1.
- DiasHospitalizacion está fuera del rango permitido.
- El ID se encuentra duplicado.

Cuando una línea es inválida, el programa muestra el número de línea y el motivo del rechazo.

Por ejemplo:

```text
Linea 4 rechazada: el dolor debe estar entre 0 y 10.
```

Los registros inválidos no ingresan a la Queue ni a los AVL.

---

# Manejo de archivo inexistente

Si el programa no puede abrir:

```text
pacientes.txt
```

se mostrará un mensaje similar a:

```text
Error: no se pudo abrir el archivo 'pacientes.txt'.
```

y no se continuará con el procesamiento de pacientes.

Por esta razón, `pacientes.txt` debe permanecer en la raíz del proyecto.

CMake se encarga de copiarlo al directorio de compilación.

---

# Queue de pacientes

Los pacientes válidos ingresan inicialmente a una cola implementada manualmente.

La Queue utiliza nodos enlazados y mantiene:

```text
frente
final
cantidad
```

El comportamiento utilizado es:

```text
FIFO
First In - First Out
```

Esto significa que el primer paciente que entra es el primero que será atendido.

Ejemplo:

```text
Entrada:

001
002
003

Orden de atencion:

001
002
003
```

No se utiliza `std::queue`.

---

## Transferencia de pacientes desde la Queue

Cuando se atiende un paciente:

```text
Queue
  |
  v
pop()
  |
  v
Paciente*
```

El nodo de la Queue es eliminado, pero el paciente continúa existiendo.

Después el paciente pasa al árbol de decisión y finalmente es transferido al AVL del servicio asignado.

---

# Árbol de decisión

El árbol de decisión se implementa manualmente mediante objetos `NodoDecision`.

Cada nodo puede representar:

```text
una pregunta
```

o:

```text
un servicio final
```

Los nodos de decisión poseen dos posibles ramas:

```text
SI
NO
```

El árbol considera distintos atributos del paciente para determinar su servicio.

---

## Criterio de clasificación

La lógica utilizada es:

```text
Edad < 14
|
|-- SI --> Pediatria
|
`-- NO --> Trauma == 1
           |
           |-- SI --> RequiereCirugia == 1
           |          |
           |          |-- SI --> Cirugia
           |          |
           |          `-- NO --> Traumatologia
           |
           `-- NO --> SintomasNeurologicos == 1
                      |
                      |-- SI --> Neurologia
                      |
                      `-- NO --> TipoDolor == pecho
                                 |
                                 |-- SI --> Cardiologia
                                 |
                                 `-- NO --> Condicion de urgencia
                                            |
                                            |-- SI --> Urgencias
                                            |
                                            `-- NO --> DiasHospitalizacion >= 2
                                                       |
                                                       |-- SI --> Hospitalizacion
                                                       |
                                                       `-- NO --> Medicina General
```

---

# Condición de Urgencias

El paciente es enviado a **Urgencias** cuando se cumple al menos una de estas condiciones:

```text
Temperatura >= 38.5
```

o:

```text
Dolor >= 8
```

o:

```text
PresionArterial >= 160
```

En código, conceptualmente:

```text
Temperatura >= 38.5
OR
Dolor >= 8
OR
PresionArterial >= 160
```

---

# Justificación de las decisiones

## Pediatría

La edad se evalúa primero.

Cuando:

```text
Edad < 14
```

el paciente se deriva a:

```text
Pediatria
```

---

## Cirugía y Traumatología

Si el paciente presenta:

```text
Trauma == 1
```

se analiza si requiere cirugía.

Cuando:

```text
RequiereCirugia == 1
```

se deriva a:

```text
Cirugia
```

De lo contrario:

```text
Traumatologia
```

---

## Neurología

Cuando el paciente no presenta trauma pero sí:

```text
SintomasNeurologicos == 1
```

se deriva a:

```text
Neurologia
```

---

## Cardiología

Cuando:

```text
TipoDolor == pecho
```

el paciente se deriva a:

```text
Cardiologia
```

---

## Urgencias

Después de descartar las condiciones anteriores, se analizan temperatura, dolor y presión arterial.

Si uno de esos parámetros alcanza el límite definido, el paciente se envía a:

```text
Urgencias
```

---

## Hospitalización

Cuando el paciente no cumple las condiciones anteriores y:

```text
DiasHospitalizacion >= 2
```

se deriva a:

```text
Hospitalizacion
```

---

## Medicina General

Cuando ninguna de las condiciones anteriores se cumple, el paciente es enviado a:

```text
Medicina General
```

---

# Casos límite

Los valores definidos con `>=` se consideran incluidos.

Ejemplos:

```text
Temperatura = 38.5
-> Urgencias
```

```text
Dolor = 8
-> Urgencias
```

```text
PresionArterial = 160
-> Urgencias
```

```text
DiasHospitalizacion = 2
-> Hospitalizacion
```

En el caso de Pediatría:

```text
Edad = 13
-> Pediatria
```

pero:

```text
Edad = 14
```

continúa evaluándose mediante el resto del árbol.

---

# Ejemplos representativos de clasificación

El archivo de ejemplo incluye pacientes que permiten recorrer los distintos destinos del árbol.

| ID | Paciente | Característica principal | Servicio esperado |
|---|---|---|---|
| 001 | Juan Perez | Sin condición especial | Medicina General |
| 002 | Ana Torres | Edad menor a 14 | Pediatria |
| 003 | Luis Diaz | Trauma sin cirugía | Traumatologia |
| 004 | Maria Soto | Trauma y requiere cirugía | Cirugia |
| 005 | Pedro Rojas | Síntomas neurológicos | Neurologia |
| 006 | Sofia Vega | Dolor de pecho | Cardiologia |
| 007 | Carlos Mena | Temperatura elevada | Urgencias |
| 008 | Elena Silva | Hospitalización estimada de 4 días | Hospitalizacion |
| 011 | Jorge Pinto | Presión arterial elevada | Urgencias |
| 012 | Valentina Cruz | Dolor igual a 8 | Urgencias |

De esta forma existen casos representativos para los ocho servicios.

---

# Recorridos del árbol de decisión

El programa permite mostrar:

```text
Preorden
Inorden
Postorden
```

Los recorridos se realizan manualmente recorriendo los nodos y sus punteros.

Los nodos de decisión se muestran indicando su condición.

Los nodos hoja muestran el servicio correspondiente.

---

# Árbol AVL

Cada servicio contiene un árbol AVL independiente.

Cada nodo almacena:

```text
Paciente*
puntero izquierdo
puntero derecho
altura
```

La clave utilizada para ordenar los nodos es:

```text
ID del paciente
```

---

# Inserción AVL

Al insertar un paciente se sigue primero el comportamiento de un árbol binario de búsqueda.

Si:

```text
ID nuevo < ID actual
```

se continúa por la izquierda.

Si:

```text
ID nuevo > ID actual
```

se continúa por la derecha.

Si:

```text
ID nuevo == ID actual
```

el paciente no se inserta nuevamente.

Después de insertar se actualizan las alturas y se revisa el factor de balance.

---

# Altura

Para la implementación utilizada:

```text
Nodo inexistente = altura 0
```

y:

```text
Nodo hoja = altura 1
```

La altura de un nodo se calcula mediante:

```text
1 + max(
    altura izquierda,
    altura derecha
)
```

---

# Factor de balance

El factor de balance se calcula como:

```text
altura izquierda - altura derecha
```

Un nodo AVL correctamente balanceado debe encontrarse normalmente entre:

```text
-1
0
1
```

---

# Rotaciones AVL

El sistema implementa manualmente las cuatro situaciones principales de balance.

## Caso LL

Ejemplo:

```text
        030
       /
     020
     /
   010
```

Se realiza una rotación hacia la derecha:

```text
       020
      /   \
    010   030
```

---

## Caso RR

Ejemplo:

```text
010
   \
   020
      \
      030
```

Se realiza una rotación hacia la izquierda:

```text
       020
      /   \
    010   030
```

---

## Caso LR

Ejemplo:

```text
      030
      /
    010
      \
      020
```

Se realiza:

```text
rotacion izquierda
+
rotacion derecha
```

Resultado:

```text
       020
      /   \
    010   030
```

---

## Caso RL

Ejemplo:

```text
010
  \
  030
  /
020
```

Se realiza:

```text
rotacion derecha
+
rotacion izquierda
```

Resultado:

```text
       020
      /   \
    010   030
```

---

# Búsqueda por ID

La búsqueda por ID aprovecha el orden del AVL.

Por ejemplo, para buscar:

```text
040
```

la búsqueda puede recorrer una ruta similar a:

```text
020 -> 040
```

El programa registra y muestra la ruta utilizada.

---

# Búsqueda por nombre

El árbol se encuentra ordenado por ID y no por nombre.

Por esta razón, para buscar un nombre es necesario recorrer nodos del árbol hasta encontrar una coincidencia.

La comparación de nombres utiliza las funciones auxiliares desarrolladas en `Utilidades`.

---

# Eliminación de pacientes

El AVL permite eliminar pacientes utilizando su ID.

Se contemplan tres situaciones principales.

## Nodo hoja

Ejemplo:

```text
020
/
010
```

Si se elimina `010`, simplemente se elimina el nodo hoja.

---

## Nodo con un hijo

El hijo toma el lugar del nodo eliminado.

---

## Nodo con dos hijos

Se busca el menor nodo del subárbol derecho.

El paciente sucesor se utiliza para conservar correctamente la estructura del árbol.

Después de eliminar, se vuelven a calcular:

```text
altura
factor de balance
```

y se aplican las rotaciones necesarias.

Por lo tanto, la eliminación mantiene el AVL balanceado.

---

# Recorridos de los AVL

Cada AVL permite realizar:

```text
Inorden
Preorden
Postorden
```

## Inorden

Orden:

```text
Izquierda
Nodo
Derecha
```

Como los pacientes están ordenados por ID, el recorrido inorden permite observar los IDs ordenados.

---

## Preorden

Orden:

```text
Nodo
Izquierda
Derecha
```

---

## Postorden

Orden:

```text
Izquierda
Derecha
Nodo
```

---

# Control de IDs duplicados

El ID de un paciente debe ser único.

Durante la lectura inicial del archivo se evita incorporar dos pacientes con el mismo ID dentro de la cola cargada.

El Hospital también comprueba:

```text
Queue de pacientes pendientes
```

y:

```text
AVL de los ocho servicios
```

antes de incorporar un nuevo paciente.

Si el ID ya existe, el paciente es rechazado.

---

# Administración de memoria

El proyecto utiliza memoria dinámica mediante:

```text
new
delete
```

La propiedad de los pacientes se va transfiriendo entre las estructuras.

---

## Paciente pendiente

Mientras un paciente se encuentra esperando:

```text
Queue
```

la Queue mantiene el puntero al paciente.

Si el programa termina y quedan pacientes pendientes, el destructor de la Queue elimina esos pacientes.

---

## Paciente atendido

Al utilizar:

```text
pop()
```

se elimina solamente el nodo de la Queue.

El `Paciente*` es retornado y continúa existiendo.

Después pasa por:

```text
ArbolDecision
```

y posteriormente se transfiere al:

```text
NodoAVL
```

del servicio correspondiente.

---

## Nodo AVL

Cada `NodoAVL` es responsable del `Paciente*` que almacena.

Cuando un nodo AVL es destruido:

```text
NodoAVL
    |
    v
delete Paciente
```

El AVL libera recursivamente todos sus nodos en su destructor.

---

## Árbol de decisión

`ArbolDecision` recorre y elimina sus nodos de manera recursiva al finalizar el programa.

---

## Servicios

El Hospital crea ocho servicios.

En su destructor elimina cada servicio.

Cada servicio contiene su AVL, cuyo destructor libera los nodos y pacientes almacenados.

---

# Inicio del programa

Al ejecutar el programa se carga automáticamente:

```text
pacientes.txt
```

Si la carga es exitosa se muestra una salida similar a:

```text
Pacientes incorporados: 12
Registros rechazados: 0
```

Después aparece el menú principal.

---

# Menú principal

El menú principal es:

```text
=== HOSPITAL MARMAJA ===
1. Atender pacientes
2. Ver departamentos
3. Buscar paciente
4. Salir
```

---

# Opción 1 - Atender pacientes

Seleccionar:

```text
1
```

El programa retira el primer paciente de la Queue.

Esto respeta el comportamiento FIFO.

Por ejemplo, si la cola contiene:

```text
001
002
003
```

la primera ejecución de la opción 1 atenderá:

```text
001
```

La siguiente ejecución atenderá:

```text
002
```

y luego:

```text
003
```

Al atender se muestran los datos del paciente.

Ejemplo:

```text
=== ATENDIENDO PACIENTE ===

ID: 001
Nombre: Juan Perez
Edad: 25
Temperatura: 37
PresionArterial: 120
Dolor: 3
TipoDolor: otro
Trauma: 0
SintomasNeurologicos: 0
RequiereCirugia: 0
DiasHospitalizacion: 0
```

Después se muestra la ruta seguida en el árbol de decisión.

Finalmente aparece el servicio asignado.

Por ejemplo:

```text
Servicio asignado: Medicina General
```

y posteriormente:

```text
Paciente insertado en el AVL de Medicina General.
```

A partir de ese momento el paciente ya no se encuentra en la Queue.

Se encuentra almacenado en el AVL del servicio correspondiente.

Si no quedan pacientes pendientes se muestra:

```text
No hay pacientes pendientes.
```

---

# Opción 2 - Ver departamentos

Seleccionar:

```text
2
```

El programa muestra los ocho servicios y los pacientes que ya fueron atendidos y almacenados en cada AVL.

Ejemplo:

```text
=== ESTADO DE LOS DEPARTAMENTOS ===

Urgencias
Sin pacientes

Medicina General
Pacientes:
- Juan Perez (001)

Cardiologia
Sin pacientes
```

Solamente aparecen en los departamentos los pacientes que ya fueron procesados mediante la opción:

```text
1. Atender pacientes
```

Los pacientes que todavía están esperando permanecen en la Queue.

Después de mostrar los departamentos se accede al submenú de operaciones de árboles.

---

# Submenú de operaciones de árboles

El submenú es:

```text
=== OPERACIONES DE ARBOLES ===
1. Mostrar recorridos de un AVL
2. Mostrar altura y factores de balance
3. Eliminar paciente por ID
4. Mostrar recorridos del arbol de decision
5. Volver
```

---

# Submenú - Opción 1: Mostrar recorridos de un AVL

Seleccionar:

```text
1
```

El programa muestra:

```text
=== SERVICIOS ===
1. Urgencias
2. Medicina General
3. Cardiologia
4. Neurologia
5. Traumatologia
6. Cirugia
7. Pediatria
8. Hospitalizacion
```

Después solicita:

```text
Seleccionar servicio:
```

Se debe ingresar un número entre:

```text
1 y 8
```

Ejemplo:

```text
2
```

para seleccionar:

```text
Medicina General
```

El programa mostrará:

```text
RECORRIDO INORDEN
RECORRIDO PREORDEN
RECORRIDO POSTORDEN
```

del AVL correspondiente.

Si el árbol está vacío se indicará:

```text
Sin pacientes.
```

---

# Submenú - Opción 2: Mostrar altura y factores de balance

Seleccionar:

```text
2
```

Luego seleccionar uno de los ocho servicios.

El programa mostrará la altura total del AVL.

Ejemplo:

```text
Altura del arbol: 3
```

También mostrará la información de los nodos:

```text
ID: 001 | Altura: 1 | Balance: 0
ID: 004 | Altura: 2 | Balance: -1
```

Esto permite comprobar visualmente que el árbol continúa balanceado.

---

# Submenú - Opción 3: Eliminar paciente por ID

Seleccionar:

```text
3
```

El programa solicita:

```text
ID del paciente a eliminar:
```

Ejemplo:

```text
001
```

Si el paciente existe dentro de uno de los ocho AVL:

```text
Paciente eliminado del AVL de Medicina General.
```

Si no existe:

```text
Paciente no encontrado.
```

La eliminación solamente se realiza sobre pacientes que ya se encuentran almacenados en los AVL.

Un paciente que todavía se encuentre esperando en la Queue no puede eliminarse mediante esta opción.

---

# Submenú - Opción 4: Recorridos del árbol de decisión

Seleccionar:

```text
4
```

El sistema muestra los tres recorridos del árbol de decisión:

```text
Preorden
Inorden
Postorden
```

Los nodos internos muestran las condiciones y los nodos finales muestran los servicios.

Esto permite observar la estructura manual utilizada para clasificar pacientes.

---

# Submenú - Opción 5: Volver

Seleccionar:

```text
5
```

El programa regresa a:

```text
=== HOSPITAL MARMAJA ===
```

---

# Opción 3 - Buscar paciente

Desde el menú principal seleccionar:

```text
3
```

El programa solicita:

```text
Indique el ID o Nombre del paciente:
```

Se puede buscar utilizando el ID.

Ejemplo:

```text
001
```

También se puede utilizar el nombre.

Ejemplo:

```text
Juan Perez
```

Si el paciente es encontrado se muestra información como:

```text
Paciente encontrado:

ID: 001
Nombre: Juan Perez
Edad: 25
Departamento: Medicina General
Temperatura: 37
PresionArterial: 120
Dolor: 3
TipoDolor: otro
Trauma: 0
SintomasNeurologicos: 0
RequiereCirugia: 0
DiasHospitalizacion: 0
```

Cuando la búsqueda es por ID también se muestra la ruta seguida dentro del AVL.

Ejemplo:

```text
Ruta de busqueda:

005 -> 003 -> 001
```

Cuando la búsqueda es por nombre se realiza un recorrido del árbol, debido a que el AVL está ordenado por ID.

### Importante

La búsqueda principal revisa los pacientes que ya se encuentran almacenados en los AVL de los servicios.

Por lo tanto, un paciente que todavía esté esperando en la Queue no será encontrado mediante esta opción.

Para que un paciente ingrese a su servicio primero debe utilizarse:

```text
1. Atender pacientes
```

---

# Opción 4 - Salir

Seleccionar:

```text
4
```

El programa muestra:

```text
Hasta luego.
```

y finaliza.

Al finalizar se ejecutan los destructores de las estructuras y se libera la memoria dinámica asociada.

---

# Ejemplo de uso completo

Al iniciar:

```text
Pacientes incorporados: 12
Registros rechazados: 0

=== HOSPITAL MARMAJA ===
1. Atender pacientes
2. Ver departamentos
3. Buscar paciente
4. Salir
```

Seleccionar:

```text
1
```

El paciente `001` es retirado de la Queue, pasa por el árbol de decisión y se almacena en:

```text
Medicina General
```

Volver al menú y seleccionar:

```text
2
```

Ahora Medicina General mostrará:

```text
Juan Perez (001)
```

Dentro del submenú se pueden revisar los recorridos y el balance de ese AVL.

Volver mediante:

```text
5
```

Después seleccionar:

```text
3
```

y buscar:

```text
001
```

El programa mostrará los datos de Juan Perez y el servicio donde se encuentra.

Posteriormente puede ingresarse nuevamente a:

```text
2
```

y utilizar:

```text
3. Eliminar paciente por ID
```

Ingresando:

```text
001
```

el paciente será eliminado del AVL de Medicina General.

Al volver a buscar:

```text
001
```

el resultado será:

```text
Paciente no encontrado.
```

---

# Ejemplo para procesar todos los pacientes

Los pacientes se atienden individualmente.

Para procesar todo el archivo se debe utilizar repetidamente:

```text
1. Atender pacientes
```

hasta recibir:

```text
No hay pacientes pendientes.
```

Con el archivo incluido en el proyecto se espera que los primeros pacientes lleguen a:

```text
001 -> Medicina General
002 -> Pediatria
003 -> Traumatologia
004 -> Cirugia
005 -> Neurologia
006 -> Cardiologia
007 -> Urgencias
008 -> Hospitalizacion
```

Los restantes permiten continuar probando diferentes condiciones y servicios.

---

# Comportamiento ante opciones incorrectas

Las opciones del menú se leen como texto y se convierten mediante funciones implementadas en `Utilidades`.

Si el valor no representa una opción válida, el programa muestra:

```text
Opcion no valida.
```

No es necesario reiniciar el programa.

El sistema vuelve a mostrar el menú correspondiente.

---

# Consideraciones importantes

- `pacientes.txt` debe existir para iniciar correctamente el programa.
- Cada línea debe contener exactamente 11 campos separados por `;`.
- Los IDs deben ser únicos.
- Los pacientes inicialmente permanecen en la Queue.
- Un paciente solamente entra a un AVL después de ser atendido.
- Cada servicio posee un AVL diferente.
- Los AVL utilizan el ID como clave.
- La búsqueda por nombre no utiliza el orden del AVL, ya que el árbol está ordenado por ID.
- La eliminación desde el menú actúa sobre los AVL y no sobre la Queue.
- Las estructuras Queue, árbol de decisión y AVL se implementan manualmente mediante nodos y punteros.
- Las rotaciones AVL también se implementan manualmente.
- El programa utiliza C++17.
- No se requieren dependencias externas.
- Los directorios generados por CMake o por el IDE no deben subirse al repositorio.
- El código fuente necesario para compilar se encuentra dentro de `src/` e `include/`.

---

# Archivos que deben mantenerse en GitHub

El repositorio debe incluir al menos:

```text
CMakeLists.txt
README.md
pacientes.txt
.gitignore
include/
src/
```

No es necesario subir:

```text
build/
cmake-build-debug/
cmake-build-release/
.idea/
*.exe
*.o
*.obj
```

Estos archivos y carpetas son generados localmente y se encuentran contemplados en `.gitignore`.

---

# Control de versiones

El desarrollo del proyecto se registra mediante Git.

El historial debe representar avances coherentes del desarrollo, incluyendo etapas como:

```text
estructura inicial
modelo Persona y Paciente
validaciones
lectura del archivo
Queue manual
arbol de decision
AVL
rotaciones
busquedas
eliminacion
servicios
integracion Hospital
menu
documentacion
```

Esto permite observar el progreso del proyecto y no solamente una carga final del código completo.

---

# Resumen de estructuras implementadas

## Queue

Implementación manual:

```text
Nodos enlazados
frente
final
FIFO
```

## Árbol de decisión

Implementación manual:

```text
NodoDecision
rama SI
rama NO
hojas con servicios
```

## AVL

Implementación manual:

```text
NodoAVL
izquierda
derecha
altura
```

Operaciones:

```text
Insercion
Busqueda por ID
Busqueda por nombre
Eliminacion
Inorden
Preorden
Postorden
Altura
Factor de balance
Rotacion derecha
Rotacion izquierda
Rotacion LR
Rotacion RL
```

## Integración

Flujo final:

```text
pacientes.txt
      |
      v
Validacion
      |
      v
Queue FIFO
      |
      v
Arbol de decision
      |
      v
Servicio
      |
      v
AVL del servicio
```

---

# Resultado

El proyecto permite representar el proceso completo de ingreso, clasificación y almacenamiento de pacientes del Hospital Marmaja utilizando las estructuras de datos solicitadas.

La Queue mantiene el orden de atención, el árbol de decisión determina el departamento de forma automática y los árboles AVL permiten almacenar, buscar, recorrer y eliminar pacientes manteniendo una estructura balanceada.
