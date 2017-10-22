/*
Aluno: Eduardo Darrazão, 1906399;
Universidade Tecnológica Federal do Paraná;
Curso: Sistemas de Informação;
Turno: Tarde/Noite;
Matéria: Estrutura de Dados 1;
Professor: Mauro Fonseca;
Trabalho 1 - Lista de Clientes
*/
#include "ListaSequencial.hpp"

int aumentarMemoriaSequencial(ListaSequencial *principal)
{
    int i;
    cout << "Tentando expandir memo.\n";
    Pessoa **aux = new Pessoa*[principal->tam];

    for(i = 0; i < principal->tam; i++)
    {
        aux[i] = new Pessoa;
        aux[i]->nome = principal->lista[i]->nome;
        aux[i]->rg = principal->lista[i]->rg;
    }

    aux = principal->lista;
    int oldTam;

    delete(principal->lista);
    principal->lista = new Pessoa*[principal->tam + 10000];
    oldTam = principal->tam;
    principal->tam = principal->tam + 10000;

    cout << "expandindo memoria...\n";
    //Falha em copiar a lista.
    for(i = 0; i < oldTam; i++)
        principal->lista[i-2] = aux[i];

    cout << "Memoria expandida com sucesso.\n";

    return 0;
}

int inserirInicioSequencial(ListaSequencial *principal, Pessoa pessoa)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->tam == principal->ultimo+1)
        aumentarMemoriaSequencial(principal);

    Pessoa *ppessoa = new Pessoa;
    ppessoa->nome = pessoa.nome;
    ppessoa->rg = pessoa.rg;

    for(int i = principal->ultimo; i>=0; i--)
        principal->lista[i+1] = principal->lista[i];

    principal->lista[0] = ppessoa;
    principal->ultimo++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): " << principal->ultimo << '\n';
    cout << "M(n): " << principal->ultimo + 4 << '\n';
    cout << "Posicao: 0\n";
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int inserirMeioSequencial(ListaSequencial *principal, Pessoa pessoa, int pos)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->tam == principal->ultimo+1)
        aumentarMemoriaSequencial(principal);

    for(int i = principal->ultimo; i>=pos; i--)
        principal->lista[i+1] = principal->lista[i];

    Pessoa *ppessoa = new Pessoa;
    ppessoa->nome = pessoa.nome;
    ppessoa->rg = pessoa.rg;

    principal->lista[pos] = ppessoa;
    principal->ultimo++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): " << principal->ultimo - pos;
    cout << "M(n): " << principal->ultimo - pos + 4 << '\n';
    cout << "Posicao: " << pos << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int inserirFimSequencial(ListaSequencial *principal, Pessoa pessoa)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->tam == principal->ultimo+1)
        aumentarMemoriaSequencial(principal);

    Pessoa *ppessoa = new Pessoa;
    ppessoa->nome = pessoa.nome;
    ppessoa->rg = pessoa.rg;

    principal->lista[principal->ultimo+1] = ppessoa;
    principal->ultimo++;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): 1\n";
    cout << "M(n): 5\n";
    cout << "Posicao: " << principal->ultimo << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerInicioSequencial(ListaSequencial *principal)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->ultimo == 0)
        return -1;

    cout << "Nome: " << principal->lista[0]->nome << '\n';
    cout << "RG: " << principal->lista[0]->rg << '\n';

    for(int i = 0; i < principal->ultimo; i++)
        principal->lista[i] = principal->lista[i+1];

    principal->ultimo--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << principal->ultimo + 2 << '\n';
    cout << "M(n): " << principal->ultimo +4 << '\n';
    cout << "Posicao: 0\n";
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerMeioSequencial(ListaSequencial *principal, int pos)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->ultimo == 0)
        return -1;

    cout << "Nome: " << principal->lista[pos]->nome << '\n';
    cout << "RG: " << principal->lista[pos]->rg << '\n';

    for(int i = pos; i < principal->ultimo; i++)
        principal->lista[i] = principal->lista[i+1];

    principal->ultimo--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): " << principal->ultimo - pos + 2<< '\n';
    cout << "M(n): " << principal->ultimo - pos +4 << '\n';
    cout << "Posicao: " << pos << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

int removerFimSequencial(ListaSequencial *principal)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    if(principal->ultimo == 0)
        return -1;

    cout << "Nome: " << principal->lista[principal->ultimo]->nome << '\n';
    cout << "RG: " << principal->lista[principal->ultimo]->rg << '\n';

    principal->ultimo--;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "C(n): 1\n";
    cout << "M(n): 4\n";
    cout << "Posicao: " << principal->ultimo + 1 << '\n';
    cout << "Tempo: " << tempo << '\n';

    return 0;
}

Pessoa procurarListaSequencial(ListaSequencial *principal, int rg)
{
    clock_t t0, tf;
    double tempo;
    t0 = clock();

    Pessoa pessoa;
    int i;

    for(i = 0; principal->lista[i]->rg != rg; i++);

    pessoa.nome = principal->lista[i]->nome;
    pessoa.rg = rg;

    tf = clock();
    tempo = ((double)(tf - t0))/CLOCKS_PER_SEC;

    cout << "Nome: " << pessoa.nome << '\n';
    cout << "RG: " << pessoa.rg << '\n';
    cout << "C(n): " << i << '\n';
    cout << "M(n): 6\n";
    cout << "Posicao: " << i << '\n';
    cout << "Tempo: " << tempo << '\n';

    return pessoa;
}

void imprimirListaSequencial(ListaSequencial principal)
{
    for(int i = 0; i<=principal.ultimo; i++)
        cout << principal.lista[i]->nome << ',' << principal.lista[i]->rg << '\n';
}

int salvarListaSequencial(ListaSequencial *principal)
{
    string url;
    cout << "Qual o endereco do arquivo?\n";
    cin >> url;
    ofstream myfile (url);
    if (myfile.is_open())
    {
        for(int i = 0; i<=principal->ultimo; i++)
            myfile << principal->lista[i]->nome << ',' << principal->lista[i]->rg << '\n';

        myfile.close();
    }
    else cout << "Unable to open file\n";

    return 0;
}

int lerListaSequencial(ListaSequencial *principal)
{
    string line;
    int i = -1;
    string url;
    cout << "Qual o endereco do arquivo?\n";
    cin >> url;
    ifstream myfile (url);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            i++;
            int pos = line.find(",", 0);
            principal->lista[i] = new Pessoa;
            principal->lista[i]->nome = line.substr(0, pos);
            principal->lista[i]->rg = stoi(line.substr(pos+1), nullptr, 0);

            if(i == principal->tam - 1)
                aumentarMemoriaSequencial(principal);
        }
        principal->ultimo = i;
        myfile.close();
    }
    else cout << "Unable to open file\n";

    return 0;
}
