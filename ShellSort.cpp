/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "ShellSort.hpp"

void shellSort(Pessoa **vetor, int tam)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    int i, j, h, cont=0, aux2=0;
    Pessoa *aux;

    for(h=1; h < tam; h = 3*h+1); //Pulo inicial, comparar posições pares e impares.

    while(h > 0)
    {
        aux2++;
        h = (h-1)/3; //Voltando os pulos de h na mesma proporção.
        for(j = h; j < tam; j++)
        {
            aux2 +=2;
            aux = vetor[j];
            i = j;

            while(vetor[i-h]->rg > aux->rg) // Compara elementos de h distancia.
            {
                aux2 += 2;
                vetor[i] = vetor[i-h];
                i = i-h;
                if(i<h)
                    break;
            }
            aux2++;
            vetor[i] = aux;
        }

        //impressao das movimentacoes...
        cout << ++cont << " movimentacao:\n";
        for(i = 0; i < tam; i++)
            cout << vetor[i]->nome << ',' << vetor[i]->rg << '\n';
        cout << "/////////////////\n/////////////////\n";
    }
    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << 0 << '\n';
    cout << "M(n): " << aux2 + 4 << '\n';
    cout << "Tempo: " << tempo << '\n';
}
