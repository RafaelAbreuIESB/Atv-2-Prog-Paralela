/*
-----------------------------------------------------
Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction é necessária.
-----------------------------------------------------
*/

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 100;
    int v[N];
    int soma_seq = 0, soma_par = 0;

    // Inicializa todos os elementos com 1
    for (int i = 0; i < N; i++)
        v[i] = 1;

    // Soma sequencial
    for (int i = 0; i < N; i++)
        soma_seq += v[i];

    // Soma paralela com reduction
    #pragma omp parallel for reduction(+:soma_par)
    for (int i = 0; i < N; i++)
        soma_par += v[i];

    cout << "Soma Sequencial = " << soma_seq << endl;
    cout << "Soma Paralela   = " << soma_par << endl;

    cout << "\nA diretiva reduction evita condições de corrida, "
         << "garantindo que cada thread some localmente antes de combinar o resultado global." << endl;

    return 0;
}
