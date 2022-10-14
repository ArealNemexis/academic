#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

using namespace std;

int main()
{
  deque<string> minhaFila;
  deque<string>::iterator w;

  minhaFila.push_back("Alguém");
  minhaFila.push_back("Fulano");
  minhaFila.push_front("Beltrano");

  // sobrescreve o elemento que estava na 2ª posição da fila
  minhaFila[1] = "Ciclano";

  // vai imprimir {Beltrano, Ciclano e Fulano}
  for (w = minhaFila.begin(); w != minhaFila.end(); w++)
    cout << "A fila está assim...: " << *w << endl;

  return 0;
}

/**
 * Deque contêiner sequêncial que fornece recursos de um vector e de uma list em um mesmo objeto.
 * Ele fornece acesso a seus elementos através de iteradores e do operador [] (como um vector), 
 * e permite ler e modificar os elementos da mesma forma que uma list 
 * (no entanto, alguns métodos não estão disponíveis). 
 * 
 * Deques utilizam a estrutura First In First Out(FIFO), e são comumente usadas em filas circulares
 * 
 */