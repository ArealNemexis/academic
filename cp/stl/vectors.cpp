#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> v; // cria sempre vazio
    vector<int>::iterator j;
    string vEmpty = (v.empty()) ? "vazio": "não vazio";
    cout << vEmpty << endl;
    
    v.push_back(26);
    v.push_back(9);
    v.push_back(2020);
    
    cout << "Meu vetor: ";
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "Meu vetor: ";
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Meu vetor printado com iterator: ";
    for (j = v.begin(); j != v.end(); j++)
    {
        cout << *j << " ";
    }
    cout << endl;

    v.insert(v.begin()+1, 3);
    v.erase( v.begin() + 1);
    v.clear();

    return 0;
}

/**
 * Vectors são similares a arrays.
 * 
 * 
 * Funções importantes:
 * .empty(): retorna um bool.
 * .push_back(value): adiciona ao fim do vetor a variavel value, value é do tipo passado.
 * .size(): retorna um int.
 * .pop_back(): retira do fim, não retorna nada.
 * .begin(): retorna posição de inicio do vetor
 * .end(): retorna posição de fim do vetor
 * .insert(iteratorPosition, value): insere em uma posição especifica do vetor baseado no iterator.
 * .erase(position): apaga na posição especifica
 * .clear(): apaga todas as posições
 * 
 * 
 * Iterator: Semelhantes ao for in do python, atribuem cada posição a um ponteiro.
 * 
 * lembre-se:
 * int a = 2;
 * int *p = &a;
 * 
 * &p == endereço do ponteiro. // 0x132a1b
 * p == endereço de quem ele aponta. 0x21234
 * *p == conteúdo de quem ele aponta. 2
*/