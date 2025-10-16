/*
-----------------------------------------------------
Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads.
-----------------------------------------------------
*/

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // Define que o programa usará 4 threads
    omp_set_num_threads(4);

    // Cria uma região paralela
    #pragma omp parallel
    {
        // Cada thread executará este bloco de código
        int id = omp_get_thread_num();      // Número da thread atual
        int total = omp_get_num_threads();  // Total de threads em execução

        // Exibe a mensagem de cada thread
        cout << "Olá! Eu sou a thread " << id << " de " << total << endl;
    }

    return 0;
}
