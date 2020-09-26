#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Pessoa {
    string nome;
    int idade;
    public:
        Pessoa(string no, int id)
        {
            idade = id;
            nome = no;
        }
        string getNome()
        {
            return nome;
        }
        int getIdade()
        {
            return idade;
        }
};

bool ordena_por_nome(Pessoa A, Pessoa B)
{
    if (A.getNome() < B.getNome())
       return true;
    return false;
}

bool ordena_por_idade(Pessoa A, Pessoa B)
{
    if (A.getIdade() < B.getIdade())
       return true;
    return false;
}


int main(){

    vector <Pessoa> VP;
    vector <Pessoa>::iterator ptr;

    VP.push_back(Pessoa("Joao", 25));
    VP.push_back(Pessoa("Maria", 32));
    VP.push_back(Pessoa("Carla", 4));
    VP.push_back(Pessoa("Abel", 30));

    // percorrendo a lista com indices
    for(int i = 0; i < VP.size(); i++)
    {
        cout << "Nome: " << VP[i].getNome();
        cout << " - Idade: " << VP[i].getIdade() << endl;
    }

    cout << "ordenado por idade" << endl;
    sort(VP.begin(), VP.end(), ordena_por_idade);

    for(int i = 0; i < VP.size(); i++)
    {
        cout << "Nome: " << VP[i].getNome();
        cout << " - Idade: " << VP[i].getIdade() << endl;
    }

    cout << "ordenado por nome" << endl;
    sort(VP.begin(), VP.end(), ordena_por_nome);

    for(int i = 0; i < VP.size(); i++)
    {
        cout << "Nome: " << VP[i].getNome();
        cout << " - Idade: " << VP[i].getIdade() << endl;
    }
}


/**
 * sort por classes é interessante, 
 * você passa uma função regra como parametro, 
 * ela pode seguir N critérios e só precisa de uma regra, ser booleana
 */