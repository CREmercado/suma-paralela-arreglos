#include <iostream> // Librería estándar para entrada y salida de datos
#include <omp.h> // Librería para el manejo de hilos y directivas de procesamiento paralelo

// Prototipo de función para mostrar una muestra representativa de los datos
void imprimeArreglo(float *d, int mostrar);

int main()
{
    int N; // Cantidad total de elementos en los arreglos

    std::cout << "Sumando Arreglos en Paralelo!\n";
    std::cout << "Ingrese el tamaño de los arreglos: ";
    std::cin >> N;

    // Configuración de la distribución del trabajo
    int chunk = N * .1; // Tamaño de cada porción (bloque) asignada a los hilos
    int mostrar = 10;   // Cantidad de elementos a imprimir en pantalla para validación

    // Declaración de los arreglos de entrada y salida
    float a[N], b[N], c[N]; // Declaración de los arreglos de entrada y salida
    int i;                  // Variable de iteración para los ciclos

    // Inicialización secuencial de los arreglos con valores de prueba
    for (int i = 0; i < N; i++) 
    {
        a[i] = (N + i) * .2;            // Valores de prueba para el arreglo a
        b[i] = ((N + i) * .1) / 5.0;    // Valores de prueba para el arreglo b
    }

    int pedazos = chunk; // Definición del tamaño de los bloques de trabajo para OpenMP

    // Directiva de OpenMP para paralelizar el ciclo for
    // shared: indica que los arreglos y la variable pedazos son comunes a todos los hilos
    // private: cada hilo tiene su propia copia de 'i' para evitar conflictos de iteración
    // schedule static: divide el trabajo en bloques fijos de tamaño 'pedazos' asignados al inicio
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    // Sección crítica: Suma de arreglos ejecutada en paralelo por múltiples hilos
    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i]; // Suma elemento a elemento

    // Despliegue de resultados para verificación de integridad de datos
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a, mostrar);
    
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b, mostrar);
    
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c, mostrar);
}

// Implementación de la función de impresión
void imprimeArreglo(float *d, int mostrar)
{
    for (int i = 0; i < mostrar; i++)
        std::cout <<  d[i] << " - ";
    std::cout << std::endl;
}