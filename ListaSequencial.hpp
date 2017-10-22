/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#ifndef LISTASEQUENCIAL_HPP_INCLUDED
#define LISTASEQUENCIAL_HPP_INCLUDED

#include "Base.hpp"

typedef struct listaSequencial
{
    Pessoa **lista;
    int tam;
    int ultimo;

} ListaSequencial;

int aumentarMemoriaSequencial(ListaSequencial *principal);

int inserirInicioSequencial(ListaSequencial *principal, Pessoa pessoa);
int inserirMeioSequencial(ListaSequencial *principal, Pessoa pessoa, int pos);
int inserirFimSequencial(ListaSequencial *principal, Pessoa pessoa);

int removerInicioSequencial(ListaSequencial *principal);
int removerMeioSequencial(ListaSequencial *principal, int pos);
int removerFimSequencial(ListaSequencial *principal);

Pessoa procurarListaSequencial(ListaSequencial *principal, int rg);
void imprimirListaSequencial(ListaSequencial principal);
int salvarListaSequencial(ListaSequencial *principal);
int lerListaSequencial(ListaSequencial *principal);

#endif // LISTASEQUENCIAL_HPP_INCLUDED
