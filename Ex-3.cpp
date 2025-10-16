/*
-----------------------------------------------------
Exercício 3 — Expressão Vetorial
Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
a) Faça a versão sequencial.
b) Paralelize com #pragma omp parallel for schedule(static).
c) Mostre o tempo total de execução em cada versão.
-----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

int main() {
    const int N = 1000000;
    vector<double> x(N, 1.0), y(N, 2.0), z(N, 3.0), a(N);

    double start, end;

    // Versão SEQUENCIAL
    start = omp_get_wtime();
    for (int i = 0; i < N; i++)
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    end = omp_get_wtime();
    cout << "Tempo Sequencial: " << (end - start) << " segundos" << endl;

    // Versão PARALELA
    start = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++)
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    end = omp_get_wtime();
    cout << "Tempo Paralelo:   " << (end - start) << " segundos" << endl;

    return 0;
}
