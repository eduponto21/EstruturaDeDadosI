/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#ifndef BASE_HPP_INCLUDED
#define BASE_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

typedef struct pessoa
{
    string nome;
    int rg;
} Pessoa;

Pessoa criarPessoa();
Pessoa procuraBinaria(Pessoa **lista, int tam, int rg);

#endif // BASE_HPP_INCLUDED
