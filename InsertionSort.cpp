/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "InsertionSort.hpp"

void insertionCrescente(Pessoa **vetor, int tam)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

	int i, j, k;
	Pessoa *aux;

	for(i = 1; i < tam; i++)
	{
		aux = vetor[i];
		j = i-1;
		while(j >= 0 && aux->rg < vetor[j]->rg)
		{
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;

		//impressao das movimentacoes...
        cout << i << " movimentacao:\n";
        for(k = 0; k < tam; k++)
            cout << vetor[k]->nome << ',' << vetor[k]->rg << '\n';
        cout << "/////////////////\n/////////////////\n";
	}

	tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << tam << '\n';
    cout << "M(n): " << tam * tam/2 << '\n';
    cout << "Tempo: " << tempo << '\n';
}
