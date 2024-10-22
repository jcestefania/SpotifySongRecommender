# Analizador de Canciones

Este proyecto presenta una implementación básica de un analizador de canciones en C++. El analizador permite realizar diferentes acciones relacionadas con las canciones, como la recomendación de canciones y artistas, así como la generación de rankings.

Este programa forma parte del Proyecto Final de la asignatura de Proyectos de Programación realizado por los alumnos de 2º Curso de Ingeniería Informática los cuales son: Carlos Arroyo, Gabriel Nassri, Elena Mañueco y Juan Carlos Estefanía.

## Funcionalidades

El analizador de canciones cuenta con las siguientes funcionalidades:

1. **Recomendación de Canciones:** El analizador puede recomendar cinco canciones aleatorias de un género musical específico. El usuario proporciona el género deseado y el analizador selecciona canciones del género correspondiente.

2. **Recomendación de Artistas:** El analizador puede recomendar cinco artistas aleatorios de un género musical específico. El usuario proporciona el género deseado y el analizador selecciona artistas del género correspondiente.

3. **Ranking de Canciones por Cantante:** El analizador muestra el ranking de las canciones más escuchadas de un cantante específico. El usuario proporciona el nombre del cantante y el analizador muestra las canciones más populares del cantante.

4. **Ranking de Canciones por Género:** El analizador muestra el ranking de las canciones más escuchadas de un género musical específico. El usuario proporciona el género deseado y el analizador muestra las canciones más populares del género.

5. **Ranking de Artistas por Género:** El analizador muestra el ranking de los artistas más escuchados de un género musical específico. El usuario proporciona el género deseado y el analizador muestra los artistas más populares del género.

## Uso

El proyecto se compone de los siguientes archivos:

- `analizador.hpp`: Contiene la declaración de la clase `Analizador` y sus funciones.
- `analizador.cpp`: Contiene la implementación de las funciones de la clase `Analizador`.
- `main.cpp`: Archivo principal que crea una instancia de `Analizador` y realiza llamadas a sus funciones.
- `main.hpp`: Contiene la declaración de la estructura `Song`, así como las declaraciones de las funciones `menu` y `cargaDatos`.
- `recomendador.hpp`: Contiene la declaración de la clase `Recomendador` y sus funciones.
- `recomendador.cpp`: Contiene la implementación de las funciones de la clase `Recomendador`.

Para compilar y ejecutar el proyecto, sigue los siguientes pasos:

1. Abre una terminal en el directorio del proyecto.
2. Ejecuta el comando de compilación, por ejemplo:
   ```shell
   g++ -std=c++11 main.cpp analizador.cpp recomendador.cpp -o analizador
