# proyecto-final

# **Introducción**

Este proyecto es un videojuego de ajedrez desarrollado en **C++** utilizando la biblioteca **SFML** (*Simple and Fast Multimedia Library*). El juego incluye una interfaz gráfica completa, soporte para las reglas básicas del ajedrez, y una estructura modular que permite un código mantenible y escalable.

---

## **Estructura del Proyecto**

La estructura del proyecto se organiza en carpetas y archivos de la siguiente manera:

PROYECTO-FINAL/  
├── .vscode/  
│   ├── launch.json  
│   ├── tasks.json  
├── bin/  
│   └── main.exe  
├── include/  
│   ├── Board.hpp  
│   ├── Piece.hpp  
│   ├── UI.hpp  
├── resources/  
│   ├── antology/  
│   │   └── Antology.ttf  
│   ├── board.png  
│   ├── board1.png  
│   ├── pieces.png  
├── src/  
│   └── main.cpp  
├── .gitignore  
├── Makefile  
└── README.md  


## **Carpetas y Archivos Principales**

1. **.vscode/**  
   Contiene configuraciones para Visual Studio Code:  
   - **launch.json**: Configuración para depurar el proyecto con GDB.  
   - **tasks.json**: Tareas para compilar los archivos fuente.

2. **bin/**  
   Contiene los ejecutables generados, como `main.exe`.

3. **include/**  
   Incluye los archivos de encabezado:  
   - **Board.hpp**: Lógica del tablero y las reglas del juego.  
   - **Piece.hpp**: Representación de las piezas del ajedrez.  
   - **UI.hpp**: Manejo de la interfaz gráfica del usuario.

4. **resources/**  
   Carpeta de recursos gráficos y tipográficos:  
   - **Antology.ttf**: Fuente utilizada para los mensajes del juego.  
   - **board.png** y **board1.png**: Imágenes del tablero de ajedrez.  
   - **pieces.png**: Imagen con las piezas del ajedrez.

5. **src/**  
   Contiene el archivo principal:  
   - **main.cpp**: Punto de entrada del juego. Coordina la interfaz, los eventos y la lógica del tablero.

6. **.gitignore**  
   Excluye archivos innecesarios del control de versiones, como ejecutables y configuraciones locales.

7. **Makefile**  
 Define reglas para compilar, ejecutar y limpiar el proyecto usando `g++`.  
   - Para compilar el proyecto, usa:  
     ```bash
     make
     ```
     Esto generará los ejecutables en la carpeta `bin/`.  
   - Para ejecutar el juego, usa:  
     ```bash
     make runmain
     ```
   - Para limpiar los archivos generados, usa:  
     ```bash
     make clean
     ```

---

## **Clases Principales**

1. **Board**  
   - **Descripción**: Maneja el tablero y la lógica del juego.  
   - **Funciones clave**:  
     - `Update`: Actualiza el estado del tablero según las interacciones del jugador.  
     - `CheckMove`: Verifica la validez de los movimientos.  
     - `CheckJaque`: Comprueba el estado de jaque o jaque mate.

2. **Piece**  
   - **Descripción**: Representa una pieza individual del ajedrez.  
   - **Funciones clave**:  
     - `SetPosition`: Establece la posición de la pieza.  
     - `ContainPosition`: Verifica si una posición está dentro del área de la pieza.

3. **UI**  
   - **Descripción**: Administra los mensajes de la interfaz gráfica.  
   - **Funciones clave**:  
     - `Update`: Muestra mensajes como "Turno de Blancas" o "Turno de Negras".  
     - `Jaque` y `JaqueMate`: Notifica al usuario sobre estados especiales del juego.

---

## **Requisitos**

- **SFML**: Asegúrate de tener instalada la biblioteca **SFML** y configurada en tu sistema.  
- **Compilador**: Se necesita un compilador como `g++` compatible con **C++11** o superior.


## **Conclusión**

Este videojuego de ajedrez es un proyecto modular que puede ser ampliado fácilmente. Si necesitas agregar nuevas funcionalidades, como inteligencia artificial o un modo multijugador, el código está preparado para adaptarse a dichos cambios.

---

# **Manual de Usuario para el Videojuego de Ajedrez**

## **Introducción**

Este videojuego de ajedrez permite jugar partidas entre dos jugadores utilizando una interfaz gráfica intuitiva. Este manual describe cómo descargar, instalar, ejecutar y utilizar el juego.

---

## **Requisitos del Sistema**

- **Sistema Operativo**: Windows, Linux o macOS.  
- **Bibliotecas necesarias**: SFML (*Simple and Fast Multimedia Library*).  
- **Compilador**: Compatible con C++11 o superior (por ejemplo, `g++`).  
- **Hardware**: Procesador moderno y al menos 512 MB de RAM.

---

## **Instalación**

1. **Descarga del Proyecto**  
   - Clona el repositorio desde GitHub o descarga el proyecto como archivo ZIP:  
     ```bash
     git clone <repositorio>
     ```

2. **Instala SFML**  
   - **En Windows**:  
     - Descarga el paquete de SFML desde su [sitio oficial](https://www.sfml-dev.org/).  
     - Configura las variables de entorno y vincula las bibliotecas en tu IDE o compilador.  
   - **En Linux**:  
     ```bash
     sudo apt-get install libsfml-dev
     ```
   - **En macOS**:  
     ```bash
     brew install sfml
     ```

3. **Configura el Proyecto**  
   - Asegúrate de que los directorios y rutas estén correctos para las texturas, fuentes y archivos fuente.

---

## **Compilación y Ejecución**

1. **Compilación con Makefile**  
   - Navega al directorio del proyecto:  
     ```bash
     cd PROYECTO-FINAL
     ```  
   - Ejecuta el comando `make` para compilar los archivos fuente:  
     ```bash
     make
     ```

2. **Ejecución del Juego**  
   - Una vez compilado, ejecuta el juego desde el directorio `bin`:  
     ```bash
     ./bin/main.exe
     ```

3. **Limpieza de Archivos Generados**  
   - Usa el comando `make clean` para eliminar los ejecutables y otros archivos generados:  
     ```bash
     make clean
     ```

---

## **Uso del Juego**

### **Interfaz Gráfica**

- **Ventana Principal**:  
  - El tablero de ajedrez ocupa la mayor parte de la pantalla.  
  - Los mensajes ("Turno de Blancas", "Jaque", etc.) aparecen debajo del tablero.

- **Controles**:  
  - Selecciona una pieza haciendo clic sobre ella.  
  - Mueve la pieza haciendo clic en una posición válida del tablero.

### **Reglas del Juego**

El juego implementa las reglas básicas del ajedrez:  
- Movimientos legales para cada pieza (rey, reina, torre, caballo, alfil y peón).  
- Detección de jaque y jaque mate.  
- Cambio de turno automático entre blancas y negras.

### **Notificaciones**

- **Turno de Blancas/Negras**: Indica el jugador actual.  
- **Jaque**: Aparece cuando un rey está amenazado.  
- **Jaque Mate**: Aparece cuando un rey no puede escapar del jaque.

---

## **Solución de Problemas**

- **Error al cargar texturas o fuentes**:  
  - Verifica que los archivos `board1.png`, `pieces.png` y `Antology.ttf` estén en la carpeta `resources`.  

- **La ventana no abre o se cierra inmediatamente**:  
  - Asegúrate de que SFML esté correctamente instalado y vinculado.  
  - Revisa que el compilador sea compatible con C++11 o superior.  

- **No se puede compilar**:  
  - Verifica que las rutas de los archivos en el `Makefile` sean correctas.  
  - Confirma que tengas permisos para ejecutar comandos `make`.

---

## **Extensiones Futuras**

Este juego puede extenderse con las siguientes funcionalidades:  
- **Modo de Juego vs IA**: Implementar un oponente controlado por el computador.  
- **Multijugador Online**: Jugar contra otros usuarios a través de internet.  
- **Registro de Partidas**: Guardar y cargar partidas jugadas.

---

# **Información sobre el Proyecto**

Este proyecto está basado en el código original publicado por el canal de YouTube **DitecnoDigital**.

El código fue descargado desde el repositorio oficial en GitHub:  
[https://github.com/DitecnoDigital/Ajedrez.git](https://github.com/DitecnoDigital/Ajedrez.git).

---

## **Modificaciones**

1. **Estructura de Carpetas**  
   - Se creó una carpeta llamada `src` donde se ingresó el archivo `main.cpp`.  
   - Se creó otra carpeta llamada `include`, donde se agregaron los archivos `board.hpp`, `piece.hpp` y `UI.hpp`.  
     - Estos archivos fueron el resultado de fusionar los respectivos archivos originales `.hpp` y `.cpp`.  
       *(Por ejemplo: `board.hpp` y `board.cpp` se combinaron en un único archivo `board.hpp`)*.  
   - Se creó una carpeta `bin` para almacenar el archivo compilado `main.exe`.  
   - Se creó una carpeta `.vscode` que contiene los archivos `tasks.json` y `launch.json` necesarios para la compilación del código en Visual Studio Code.

---

## **Licencia**

### **GNU GENERAL PUBLIC LICENSE**  
**Version 3, 29 June 2007**

Este código fue modificado con fines educativos y sin ningún propósito monetario.  
El código original se encuentra en el canal de YouTube:  
[https://www.youtube.com/@DitecnoDigital](https://www.youtube.com/@DitecnoDigital).  
Y fue descargado desde el repositorio oficial:  
[https://github.com/DitecnoDigital/Ajedrez.git](https://github.com/DitecnoDigital/Ajedrez.git).  

Las modificaciones fueron realizadas para un proyecto escolar con el objetivo de adaptar el código a necesidades educativas específicas.

---

## **Desarrolladores**

- **Gustavo Israel Ramirez Pacas**  
- **Gael Jesús Muños Aviña**

---

## **Bibliotecas Utilizadas**

- **SFML** (*Simple and Fast Multimedia Library*)

---

Gracias por jugar este videojuego de ajedrez. ¡Disfruta la experiencia! ♕♘
