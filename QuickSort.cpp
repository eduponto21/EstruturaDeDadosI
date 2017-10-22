/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "QuickSort.hpp"

void swap(Pessoa* a, Pessoa* b)
{
    Pessoa c = *a;
    *a = *b;
    *b = c;
}

int particionar(Pessoa *arr[], int ini, int fim)
{
    int pivo = arr[fim]->rg;
    int j, l, i = ini - 1;

    for (j = ini; j <= fim-1; j++)
    {
        if (arr[j]->rg <= pivo)
        {
            i++;
            swap(arr[i], arr[j]);

        }
    }
    swap(arr[i + 1], arr[fim]);
    return (i + 1);
}

void quickSort(Pessoa *arr[], int ini, int fim)
{
    int l;
    if (ini < fim)
    {
        int aux = particionar(arr, ini, fim);

        //impressao das movimentacoes...
        for(l = 0; l < fim; l++)
            cout << arr[l]->nome << ',' << arr[l]->rg << '\n';
        cout << "/////////////////\n/////////////////\n";

        quickSort(arr, ini, aux - 1);
        quickSort(arr, aux + 1, fim);
    }
}
