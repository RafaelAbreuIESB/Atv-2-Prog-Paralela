/*
-----------------------------------------------------
Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados.
-----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

void calcular(string tipo, int num_threads, bool dynamic) {
    const int N = 1000000;
    vector<double> x(N, 1.0), y(N, 2.0), z(N, 3.0), a(N);
    omp_set_num_threads(num_threads);

    double inicio = omp_get_wtime();

    if (dynamic) {
        #pragma omp parallel for schedule(dynamic, 1000)
        for (int i = 0; i < N; i++)
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    } else {
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < N; i++)
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }

    double fim = omp_get_wtime();
    cout << tipo << " (" << num_threads << " threads): " << (fim - inicio) << " segundos" << endl;
}

int main() {
    cout << fixed;

    // Testa com diferentes números de threads
    for (int t : {2, 4, 8}) {
        calcular("Static", t, false);
        calcular("Dynamic", t, true);
        cout << "--------------------------------------" << endl;
    }

    cout << "\nStatic é mais eficiente quando as tarefas têm tamanhos semelhantes.\n"
         << "Dynamic é melhor quando há desequilíbrio entre as partes do trabalho (iterações com tempos variados).\n";

    return 0;
}
