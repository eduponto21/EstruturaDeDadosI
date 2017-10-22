/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "ListaEncadeada.hpp"

Pessoa** getListaPessoasEncadeada(ListaEncadeada *principal)
{
    Pessoa** lista;
    lista = new Pessoa*[principal->qntNodes];
    int i = -1;

    Node *aux = new Node;
    aux = principal->primero;

    while (aux != NULL)
    {
        i++;

        lista[i] = new Pessoa;

        lista[i] = aux->pessoa;
        aux = aux->proximo;
    }

    return lista;
}



int inserirInicioEncadeada(ListaEncadeada *principal, Pessoa pessoa)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    Node *node = new Node;
    node->pessoa = new Pessoa;
    node->pessoa->nome = pessoa.nome;
    node->pessoa->rg = pessoa.rg;

    node->proximo = principal->primero;
    principal->primero = node;
    principal->qntNodes++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): 0\n";
    cout << "M(n): 9\n";
    cout << "Posicao: 0\n";
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int inserirMeioEncadeada(ListaEncadeada *principal, Pessoa pessoa, int pos)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    int i;

    Node *novo = new Node;
    novo->pessoa = new Pessoa;
    novo->pessoa->nome = pessoa.nome;
    novo->pessoa->rg = pessoa.rg;

    Node *aux = new Node;
    aux = principal->primero;

    if(pos == 0)
    {
        inserirInicioEncadeada(principal, pessoa);
        principal->qntNodes++;
        return 0;
    }
    else
    {
        for(i = 1; i < pos && aux != NULL; i++)
            aux = aux->proximo;

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    principal->qntNodes++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): " << i*2 + 1 << '\n';
    cout << "M(n): " << i + 12 << '\n';
    cout << "Posicao: " << pos << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int inserirFimEncadeada(ListaEncadeada *principal, Pessoa pessoa)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    Node *node = new Node;
    node->pessoa = new Pessoa;
    node->pessoa->nome = pessoa.nome;
    node->pessoa->rg = pessoa.rg;

    node->proximo = NULL;
    principal->ultimo->proximo = node;
    principal->ultimo = node;
    principal->qntNodes++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): 0\n";
    cout << "M(n): 10\n";
    cout << "Posicao: " << principal->qntNodes << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerInicioEncadeada(ListaEncadeada *principal)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->qntNodes < 2)
        return -1;

    cout << "Nome: " << principal->primero->pessoa->nome << '\n';
    cout << "RG: " << principal->primero->pessoa->rg << '\n';

    delete(principal->primero);
    principal->primero = principal->primero->proximo;
    principal->qntNodes--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): 1\n";
    cout << "M(n): 5\n";
    cout << "Posicao: 0\n";
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerMeioEncadeada(ListaEncadeada *principal, int pos)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->qntNodes < 2)
        return -1;

    Node *aux = new Node;
    aux = principal->primero;

    if(pos == 0)
        removerInicioEncadeada(principal);
    else
    {
        for(int i = 1; i < pos && aux != NULL; i++)
            aux = aux->proximo;

        Node *aux2 = new Node;
        aux2 = aux->proximo->proximo;

        cout << "Nome: " << aux->proximo->pessoa->nome << '\n';
        cout << "RG: " << aux->proximo->pessoa->rg << '\n';

        delete(aux->proximo);
        aux->proximo = aux2;
    }
    principal->qntNodes--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << pos + 2 << '\n';
    cout << "M(n): " << pos + 10 << '\n';
    cout << "Posicao: " << pos << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerFimEncadeada(ListaEncadeada *principal)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->qntNodes < 2)
        return -1;

    Node *aux = new Node;
    aux = principal->primero;

    while(aux->proximo->proximo != NULL)
        aux = aux->proximo;

    cout << "Nome: " << principal->ultimo->pessoa->nome << '\n';
    cout << "RG: " << principal->ultimo->pessoa->rg << '\n';

    delete(principal->ultimo);
    principal->ultimo = aux;
    principal->ultimo->proximo = NULL;
    principal->qntNodes--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << principal->qntNodes + 1 << '\n';
    cout << "M(n): " << principal->qntNodes + 6 << '\n';
    cout << "Posicao: " << principal->qntNodes + 1 << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

Pessoa procurarListaEncadeada(ListaEncadeada *principal, int rg)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    Pessoa pessoa;
    int i = 0;

    Node *aux = new Node;
    aux = principal->primero;

    while (aux != NULL && aux->pessoa->rg != rg)
    {
        aux = aux->proximo;
        i++;
    }

    if(aux == NULL)
    {
        cout << "RG nao encontrado!Retornando NULL.\n";
        Pessoa a;
        return a;
    }

    pessoa.rg = rg;
    pessoa.nome = aux->pessoa->nome;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): " << i << '\n';
    cout << "M(n): " << i + 6 << '\n';
    cout << "Posicao: " << i - 1 << '\n';
    cout << "Tempo: " << tempo << '\n';

    return pessoa;
}

void imprimirListaEncadeada(ListaEncadeada principal)
{
    while (principal.primero != NULL)
    {
        cout << principal.primero->pessoa->nome << ',' << principal.primero->pessoa->rg << '\n';
//        cout << "proximo ->" << principal.primero->proximo << '\n';
//        cout << "atual ->" << principal.primero << '\n';
        principal.primero = principal.primero->proximo;
    }
}

int salvarListaEncadeada(ListaEncadeada *principal)
{
    string url;
    cout << "Qual o endereco do arquivo?\n";
    cin >> url;
    ofstream myfile (url);
    if (myfile.is_open())
    {
        while (principal->primero != NULL)
        {
            myfile << principal->primero->pessoa->nome << ',' << principal->primero->pessoa->rg << '\n';
            principal->primero = principal->primero->proximo;
        }
        myfile.close();
    }
    else cout << "Unable to open file\n";

    return 0;
}

int lerListaEncadeada(ListaEncadeada *principal)
{
    string line;
    string rg;
    int z=0;


    string url;
    cout << "Qual o endereco do arquivo?\n";
    cin >> url;
    ifstream myfile (url);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            z++;
            Node *novo = new Node;
            novo->pessoa = new Pessoa;
            int pos = line.find(",", 0);
            novo->pessoa->nome = line.substr(0, pos);
            rg = line.substr(pos+1);
            novo->pessoa->rg = stoi(rg);
            novo->proximo = NULL;
            if(z==1)
            {
                principal->primero = novo;
                principal->ultimo = novo;
            }
            else
            {
                principal->ultimo->proximo = novo;
                principal->ultimo = novo;
            }
        }
        principal->qntNodes = z;
        myfile.close();
    }
    else cout << "Unable to open file\n";

    return 0;
}
