# Suma Paralela de Arreglos

Programa en C++ que implementa la suma paralela de arreglos utilizando OpenMP (Open Multi-Processing) para aprovechar el procesamiento paralelo.

## Descripción

Este proyecto es parte de la actividad **Tarea 1. Programación de una solución paralela** del módulo 2 de **Cómputo en la Nube** del programa MNA en ITESM. Implementa un algoritmo de suma de arreglos que utiliza paralelización para mejorar el rendimiento.

## Requisitos

- Compilador C++ con soporte para OpenMP (g++ 4.2 o superior)
- macOS o Linux

## Compilación

Para compilar el proyecto, utiliza:

```bash
g++ -g -fopenmp SumaParalelaArreglos.cpp -o SumaParalelaArreglos
```

O utiliza la tarea de build en VS Code.

## Ejecución

```bash
./SumaParalelaArreglos
```

## Contenido

- `SumaParalelaArreglos.cpp` - Código fuente del programa

## Notas

Este proyecto utiliza OpenMP para paralelizar las operaciones de suma de arreglos, demostrando conceptos de computación paralela.
