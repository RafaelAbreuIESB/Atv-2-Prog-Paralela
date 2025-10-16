#include <iostream>
#include <omp.h>
#include <iomanip> // para formatação opcional
using namespace std;

int main() {
    // Define o número de threads que serão usadas
    omp_set_num_threads(4);

    // Início da região paralela: cada thread executa este bloco
    #pragma omp parallel
    {
        int id = omp_get_thread_num();       // ID da thread atual
        int total = omp_get_num_threads();   // Número total de threads em execução

        // Utiliza uma região crítica para evitar que as saídas se misturem
        #pragma omp critical
        {
            cout << "Olá! Eu sou a thread " 
                 << id << " de " << total << endl;
        }
    }

    return 0;
}
