/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#ifndef LISTAENCADEADA_HPP_INCLUDED
#define LISTAENCADEADA_HPP_INCLUDED

#include "Base.hpp"

typedef struct node
{
	Pessoa *pessoa;
    struct node *proximo;
}  Node;

typedef struct listaEncadeada
{
    Node *primero;
    Node *ultimo;
    int qntNodes;
} ListaEncadeada;

Pessoa** getListaPessoasEncadeada(ListaEncadeada *principal);

int inserirInicioEncadeada(ListaEncadeada *principal, Pessoa pessoa);
int inserirMeioEncadeada(ListaEncadeada *principal, Pessoa pessoa, int pos);
int inserirFimEncadeada(ListaEncadeada *principal, Pessoa pessoa);

int removerInicioEncadeada(ListaEncadeada *principal);
int removerMeioEncadeada(ListaEncadeada *principal, int pos);
int removerFimEncadeada(ListaEncadeada *principal);

Pessoa procurarListaEncadeada(ListaEncadeada *principal, int rg);
void imprimirListaEncadeada(ListaEncadeada principal);
int salvarListaEncadeada(ListaEncadeada *principal);
int lerListaEncadeada(ListaEncadeada *principal);

#endif // LISTAENCADEADA_HPP_INCLUDED
