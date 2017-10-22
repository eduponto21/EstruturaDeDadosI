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
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "BubbleSort.hpp"
#include "ShellSort.hpp"
#include "QuickSort.hpp"
#define TAM_SEQ 12000000

int main()
{
    clock_t t0, tf;
    double tempo;

    int escolha1, escolha2, escolha3;

    do
    {
        cout << "Digite (1) p/ Lista Sequencial ou (2) p/ Lista Encadeada.\n";
        cin >> escolha1;
    }
    while(escolha1 != 1 && escolha1 !=2);

    ListaSequencial principalSeq;
    ListaEncadeada principalEnc;
    if(escolha1 == 1)
    {
        principalSeq.lista = new Pessoa*[TAM_SEQ];
        principalSeq.tam = TAM_SEQ;
    }

    do
    {
        if(escolha1 == 1)
        {
            cout << "Digite: \n1 p/ add\n2 p/ remover\n3 p/ procurar\n4 p/ imprimir\n5 p/ salvar\n6 p/ ler\n7 p/ sair\n8 p/ ordenar\n";
            cin >> escolha2;
            switch(escolha2)
            {
            case 1: // ADICIONAR
            {
                cout << "Digite: \n1 p/ inicio\n2 p/ meio\n3 p/ fim\n";
                cin >> escolha3;
                if(escolha3 == 1)
                    inserirInicioSequencial(&principalSeq, criarPessoa());
                else if(escolha3 == 2)
                {
                    int pos;
                    cout << "Qual a posicao desejada?\n";
                    cin >> pos;
                    inserirMeioSequencial(&principalSeq, criarPessoa(), pos);
                }
                else if(escolha3 == 3)
                    inserirFimSequencial(&principalSeq, criarPessoa());
                else
                    cout << "Opcao invalida\n";
                break;
            }
            case 2: // REMOVER
            {
                cout << "Digite: \n1 p/ inicio\n2 p/ meio\n3 p/ fim\n";
                cin >> escolha3;
                if(escolha3 == 1)
                    removerInicioSequencial(&principalSeq);
                else if(escolha3 == 2)
                {
                    int pos;
                    cout << "Qual a posicao desejada?\n";
                    cin >> pos;
                    removerMeioSequencial(&principalSeq, pos);
                }
                else if(escolha3 == 3)
                    removerFimSequencial(&principalSeq);
                else
                    cout << "Opcao invalida\n";
                break;
            }
            case 3: // PROCURAR
            {
                cout << "Digite: \n1 p/ Busca Sequencial\n2 p/ Busca Binaria\n";
                cin >> escolha3;
                cout << "Qual o RG desejado?\n";
                int rg;
                cin >> rg;
                if(escolha3 == 1)
                    procurarListaSequencial(&principalSeq, rg);
                else
                    procuraBinaria(principalSeq.lista, principalSeq.ultimo+1, rg);
                break;
            }
            case 4: // IMPRIMIR
            {
                imprimirListaSequencial(principalSeq);
                break;
            }
            case 5: // SALVAR
            {
                salvarListaSequencial(&principalSeq);
                break;
            }
            case 6: // LER
            {
                lerListaSequencial(&principalSeq);
                break;
            }
            case 7: // SAIR
                return 0;

            case 8: // ORDENAR
            {
                cout << "Digite: \n1 p/ SelectionSort\n2 p/ InsertionSort\n3 p/ MergeSort\n4 p/ BubbleSort\n5 p/ ShellSort\n6 p/ QuickSort\n";
                cin >> escolha3;

                switch(escolha3)
                {
                case 1:
                    selectionCrescente(principalSeq.lista, principalSeq.ultimo+1); //se adiciona um pelo fato de ultimo ser a pos do ultimo, e nao tamanho da lista.
                    break;
                case 2:
                    insertionCrescente(principalSeq.lista, principalSeq.ultimo+1);
                    break;
                case 3:
                    t0 = clock();

                    mergeSort(principalSeq.lista, 0, principalSeq.ultimo);

                    tf = clock();
                    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

                    cout << "Tempo: " << tempo << '\n';
                    break;
                case 4:
                    bubblesort(principalSeq.lista, principalSeq.ultimo+1);
                    break;
                case 5:
                    shellSort(principalSeq.lista, principalSeq.ultimo+1);
                    break;
                case 6:
                    t0 = clock();

                    quickSort(principalSeq.lista, 0, principalSeq.ultimo);

                    tf = clock();
                    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

                    cout << "Tempo: " << tempo << '\n';
                    break;
                default:
                    cout << "Opcao invalida\n";
                }
                break;
            }
            default:
                cout << "Opcao invalida\n";
            }
        }
        else
        {
            cout << "Digite: \n1 p/ add\n2 p/ remover\n3 p/ procurar\n4 p/ imprimir\n5 p/ salvar\n6 p/ ler\n7 p/ sair\n8 p/ ordenar\n";
            cin >> escolha2;
            switch(escolha2)
            {
            case 1:
            {
                cout << "Digite: \n1 p/ inicio\n2 p/ meio\n3 p/ fim\n";
                cin >> escolha3;
                if(escolha3 == 1)
                    inserirInicioEncadeada(&principalEnc, criarPessoa());
                else if(escolha3 == 2)
                {
                    int pos;
                    cout << "Qual a posicao desejada?\n";
                    cin >> pos;
                    inserirMeioEncadeada(&principalEnc, criarPessoa(), pos);
                }
                else if(escolha3 == 3)
                    inserirFimEncadeada(&principalEnc, criarPessoa());
                else
                    cout << "Opcao invalida\n";
                break;
            }
            case 2:
            {
                cout << "Digite: \n1 p/ inicio\n2 p/ meio\n3 p/ fim\n";
                cin >> escolha3;
                if(escolha3 == 1)
                    removerInicioEncadeada(&principalEnc);
                else if(escolha3 == 2)
                {
                    int pos;
                    cout << "Qual a posicao desejada?\n";
                    cin >> pos;
                    removerMeioEncadeada(&principalEnc, pos);
                }
                else if(escolha3 == 3)
                    removerFimEncadeada(&principalEnc);
                else
                    cout << "Opcao invalida\n";
                break;
            }
            case 3:
            {
                cout << "Digite: \n1 p/ Busca Sequencial\n2 p/ Busca Binaria\n";
                cin >> escolha3;
                cout << "Qual o RG desejado?\n";
                int rg;
                cin >> rg;
                if(escolha3 == 1)
                    procurarListaEncadeada(&principalEnc, rg);
                else
                    procuraBinaria(getListaPessoasEncadeada(&principalEnc), principalEnc.qntNodes, rg);
                break;
            }
            case 4:
            {
                imprimirListaEncadeada(principalEnc);
                break;
            }
            case 5:
            {
                salvarListaEncadeada(&principalEnc);
                break;
            }
            case 6:
            {
                lerListaEncadeada(&principalEnc);
                break;
            }
            case 7:
                return 0;

            case 8:
            {
                Pessoa **listagem;
                listagem = getListaPessoasEncadeada(&principalEnc);

                cout << "Digite: \n1 p/ SelectionSort\n2 p/ InsertionSort\n3 p/ MergeSort\n4 p/ BubbleSort\n5 p/ ShellSort\n6 p/ QuickSort\n";
                cin >> escolha3;

                switch(escolha3)
                {
                case 1:
                    selectionCrescente(listagem, principalEnc.qntNodes);
                    break;
                case 2:
                    insertionCrescente(listagem, principalEnc.qntNodes);
                    break;
                case 3:
                    t0 = clock();

                    mergeSort(listagem, 0, principalEnc.qntNodes-1);

                    tf = clock();
                    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

                    cout << "Tempo: " << tempo << '\n';
                    break;
                case 4:
                    bubblesort(listagem, principalEnc.qntNodes);
                    break;
                case 5:
                    shellSort(listagem, principalEnc.qntNodes);
                    break;
                case 6:
                    t0 = clock();
                    t0 = clock();

                    quickSort(listagem, 0, principalEnc.qntNodes-1);

                    tf = clock();
                    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

                    cout << "Tempo: " << tempo << '\n';
                    break;
                default:
                    cout << "Opcao invalida\n";
                }

                int i = -1;
                Node *aux = new Node;
                aux = principalEnc.primero;

                while (aux != NULL)
                {
                    i++;
                    aux->pessoa = listagem[i];
                    aux = aux->proximo;
                }
            }
            break;

            default:
                cout << "Opcao invalida\n";
            }
        }

    }
    while(escolha2 != 7);

    return 0;
}
