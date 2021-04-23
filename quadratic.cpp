#include <iostream>
#include <math.h>
#include <time.h>
#include "./includes/color.hpp"

using namespace std;
using namespace color;
using namespace style;

class TabelaHash
{
private:
  int contaElem;
  static constexpr int tam = 10;
  static constexpr int limite = 20;
  int tabela[tam];

public:
  // inicia tabela
  TabelaHash()
  {
    for (int i = 0; i < this->tam; i++)
      this->tabela[i] = -1;
    this->contaElem = 0;
  }

  // verifica se a tabela esta cheia
  bool isFull()
  {
    if (this->contaElem >= this->tam)
      return true;
    return false;
  }

  // retorna a posicao do elemento
  int hashing(int e)
  {
    return e % this->tam;
  }

  int quadraticProbing(int e, int p, char op)
  {
    int i = 1, novaP = -1;

    while (i <= this->limite)
    { 
      novaP = this->hashing(p + (int)pow(i, 2));
      if(op == 'I') {
        if (this->tabela[novaP] == -1)
          break;
        else {
          i++;
          if(op == 'I') {
            coutc("COLISAO: ", fRED);
            cout << "Elemento " << e << " na posicao " << novaP << ". Buscando uma nova posicao..." << endl;
          }
        }
      } else if(op == 'B') {
        if (this->tabela[novaP] == e)
          break;
        else
          i++;
      }
    }
    return novaP;
  }

  void insere(int e)
  {
    int p;

    if (this->isFull()) 
    {
      cout << "A tabela esta cheia" << endl;
      return;
    }

    p = this->hashing(e);

    if (this->tabela[p] == -1)
    {
      this->tabela[p] = e;
	  coutc("SUCESSO: ", fGREEN);
      cout << "Elemento " << e << " armazenado na posicao " << p << endl;
    }
    else
    {
      coutc("COLISAO: ", fRED);
      cout << "Elemento " << e << " na posicao " << p << ". Buscando uma nova posicao..." << endl;
      p = quadraticProbing(e, p, 'I');

      if (p != -1 && this->tabela[p] == -1)
      {
        this->tabela[p] = e;
	    coutc("SUCESSO: ", fGREEN);
        cout << "Elemento " << e << " armazenado na posicao " << p << endl;
      }
    }
    return;
  }

  // função exibe a tabela
  void exibe()
  {
    coutc("TABELA: ", fYELLOW);
    for (int i = 0; i < this->tam; i++)
    {
      if(this->tabela[i] == -1) cout << " | [" << i <<"] VAZIO";
      else cout << " | [" << i <<"] " << this->tabela[i];
    }
    cout << " |" << endl;
  }

  int busca(int e) {
    bool match = false;
    int p = this->hashing(e);

    if(this->tabela[p] == e) {
      match = true;
          coutc("BUSCA: ", fBLUE);
          cout << "A posicao do elemento " << e << " na tabela hash: " << p << endl;
      return p;
    } else {
      int novaP = -1;
        novaP = quadraticProbing(e, p, 'B');
        if(this->tabela[novaP] == e) {
          match = true;
          coutc("BUSCA: ", fBLUE);
          cout << "A posicao do elemento " << e << " na tabela hash: " << novaP << endl;
          return novaP;
        }
    }
    coutc("BUSCA: ", fRED);
    cout << "Elemento " << e << " nao pertence a tabela hash." << endl;
    return -1;
  }

  void remove(int e) {
    coutc("(REMOCAO)", fREDs);
    int p = this->busca(e);
    if(p != -1) {
      this->tabela[p] = -1;
      this->contaElem--;
      coutc("REMOCAO: ", fREDs);
      cout << "Elemento " << e << " removido da tabela hash." << endl;
    }
  }

  //
  void setConta(int x)
  {
    this->contaElem = x;
  }

  // retorna o total de elementos da tabela
  int getElementos()
  {
    return this->contaElem;
  }

};

int main()
{
  auto *t = new TabelaHash;
  int elem = 0, keys[] = {2, 12, 22, 32, 42, 52, 62}, tam = sizeof(keys) / sizeof(*keys);
  clock_t tempo; //variável para armazenar tempo

  // for para INSERCAO dos elementos na tabela hash
  for(int i = 0; i < tam; i++) {
    tempo = clock(); //armazena tempo
    t->insere(keys[i]);
    tempo = clock() - tempo; //tempo final - tempo inicial
      if (!t->isFull())
      {
        elem++;
        t->setConta(elem);
      }
    coutc("INSERCAO: ", fCYAN);
    cout << ((double)tempo)/((CLOCKS_PER_SEC/1000)) << "ms" << endl;
    cout << "\n";
  }

  // exibe tabela
  t->exibe();

  //exibe número de elementos na tabela
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << "\n" << endl;

  t->busca(32);
  t->busca(0);
  t->busca(22);
  cout << endl;
  t->remove(12);
  cout << endl;
  t->remove(0);

  // exibe tabela
  t->exibe();
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << "\n" << endl;

  return 0;
}