/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "SelectionSort.hpp"

void selectionCrescente(Pessoa **vetor, int tam)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    int i, j, k, menor, menorID;
    Pessoa *ptrPessoa;

    for(i = 0; i < tam; i++)
    {
        menor = vetor[i]->rg;
        menorID = i;

        for(j = i + 1; j < tam; j++)
        {
            if(vetor[j]->rg < menor)
            {
                menor = vetor[j]->rg;
                menorID = j;
            }
        }

        ptrPessoa = vetor[i];
        vetor[i] = vetor[menorID];
        vetor[menorID] = ptrPessoa;

        //impressao das movimentacoes...
        cout << i + 1 << " movimentacao:\n";
        for(k = 0; k < tam; k++)
            cout << vetor[k]->nome << ',' << vetor[k]->rg << '\n';
        cout << "/////////////////\n/////////////////\n";
    }

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << tam * tam << '\n';
    cout << "M(n): " << tam * 3 << '\n';
    cout << "Tempo: " << tempo << '\n';
}
