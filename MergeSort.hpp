/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#ifndef MERGESORT_HPP_INCLUDED
#define MERGESORT_HPP_INCLUDED

#include "ListaSequencial.hpp"
#include "ListaEncadeada.hpp"

void mergeSort(Pessoa *arr[], int esquerda, int direita);
void mergir(Pessoa *arr[], int esquerda, int meio, int direita);

#endif // MERGESORT_HPP_INCLUDED
