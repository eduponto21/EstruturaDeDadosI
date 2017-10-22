/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "Base.hpp"

using namespace std;

Pessoa criarPessoa()
{
    Pessoa pessoa;
    cout << "Qual o nome?\n";
    cin >> pessoa.nome;
    cout << "Qual o rg?\n";
    cin >> pessoa.rg;
    return pessoa;
}

Pessoa procuraBinaria(Pessoa **lista, int tam, int rg)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    int inf = 0; // limite inferior
    int sup = tam-1; // limite superior
    int meio, cont=0;
    Pessoa pessoa;
    pessoa.rg = rg;
    while (inf <= sup)
    {
        cont++;
        meio = (inf + sup)/2;
        if (rg == lista[meio]->rg)
        {
            pessoa.nome = lista[meio]->nome;

            tf = clock();
            tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

            cout << "Nome: " << pessoa.nome << '\n';
            cout << "RG: " << pessoa.rg << '\n';
            cout << "C(n): " << cont*2 << '\n';
            cout << "M(n): " << cont + 8 << '\n';
            cout << "Posicao: " << meio << '\n';
            cout << "Tempo: " << tempo << '\n';

            return pessoa;
        }

        if (rg < lista[meio]->rg)
            sup = meio-1;
        else
            inf = meio+1;
    }
    cout << "Pessoa nao encontrada!\n";
    return pessoa;   // não encontrado
}
