/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "MergeSort.hpp"

void mergir(Pessoa *arr[], int esquerda, int meio, int direita)
{
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 =  direita - meio;

    Pessoa *E[n1], *D[n2];

    for (i = 0; i < n1; i++)
        E[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        D[j] = arr[meio + 1+ j];

    i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2)
    {
        if (E[i]->rg <= D[j]->rg)
        {
            arr[k] = E[i];
            i++;
        }
        else
        {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = E[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = D[j];
        j++;
        k++;
    }


}

void mergeSort(Pessoa *arr[], int esquerda, int direita)
{
    int i;
    if (esquerda < direita)
    {
        int meio = (esquerda+direita)/2;

        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio+1, direita);

        mergir(arr, esquerda, meio, direita);

        //impressao das movimentacoes...
        for(i = 0; i < direita; i++)
            cout << arr[i]->nome << ',' << arr[i]->rg << '\n';
        cout << "/////////////////\n/////////////////\n";
    }
}
