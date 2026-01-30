#include <iostream>
#include <omp.h>

void imprimeArreglo(float *d, int mostrar);

int main()
{
    int N;

    std::cout << "Sumando Arreglos en Paralelo!\n";
    std::cout << "Ingrese el tamaño de los arreglos: ";
    std::cin >> N;

    int chunk = N * .1;
    int mostrar = chunk * .1;
    float a[N], b[N], c[N];
    int i;

    for (int i = 0; i < N; i++) 
    {
        a[i] = (N + i) * .2;
        b[i] = ((N + i) * .1) / 5.0;
    }

    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b, mostrar);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c, mostrar);
}

void imprimeArreglo(float *d, int mostrar)
{
    for (int i = 0; i < mostrar; i++)
        std::cout <<  d[i] << " - ";
    std::cout << std::endl;
}