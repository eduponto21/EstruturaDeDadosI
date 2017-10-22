/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#ifndef QUICKSORT_HPP_INCLUDED
#define QUICKSORT_HPP_INCLUDED

#include "ListaSequencial.hpp"
#include "ListaEncadeada.hpp"

void swap(Pessoa* a, Pessoa* b);
int particionar(Pessoa *arr[], int low, int high);
void quickSort(Pessoa *arr[], int low, int high);

#endif // QUICKSORT_HPP_INCLUDED
