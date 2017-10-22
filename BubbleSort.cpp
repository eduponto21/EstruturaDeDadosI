/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "BubbleSort.hpp"

void bubblesort(pessoa **vetor, int tam)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    int fim, i, k=0, aux1=0, aux2=0, l;
    Pessoa *aux;
    for (fim = tam-1; fim > 0; fim--)
    {
        for (i = 0; i < fim; i++)
        {
            aux1++;
            if (vetor[i]->rg > vetor[i+1]->rg)
            {
                aux2++;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;

                //impressao das movimentacoes...
                cout << ++k << " movimentacao:\n";
                for(l = 0; l < tam; l++)
                    cout << vetor[l]->nome << ',' << vetor[l]->rg << '\n';
                cout << "/////////////////\n/////////////////\n";
            }
        }


    }
    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << aux1 << '\n';
    cout << "M(n): " << aux2 + 4 << '\n';
    cout << "Tempo: " << tempo << '\n';
}
