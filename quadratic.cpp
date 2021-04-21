#include <iostream>
#include <math.h>
using namespace std;

class TabelaHash
{
private:
  int contaElem;
  static constexpr int tam = 10;
  static constexpr int limite = 50;
  int tabela[tam];

public:
  // inicia tabela
  TabelaHash()
  {
    for (int i = 0; i < this->tam; i++)
      this->tabela[i] = -1;
    this->contaElem = 0;
  }

  // verifica se a tabela está cheia
  bool isFull()
  {
    if (this->contaElem >= this->tam)
      return true;
    return false;
  }

  // retorna a posição do elemento
  int hashing(int e)
  {
    return e % this->tam;
  }

  int quadraticProbing(int e, int p)
  {
    int i = 1, novaP = -1;

    while (i <= this->limite)
    { 
      novaP = this->hashing(p + (int)pow(i, 2)); 
      if (this->tabela[novaP] == -1)
        break;
      else
        i++;
        cout << "Ocorreu uma colisão do elemento " << e << " na posição " << novaP << ". Buscando uma nova posição..." << endl;
    }
    return novaP;
  }

  void insere(int e)
  {
    int p;

    if (this->isFull()) 
    {
      cout << "A tabela está cheia" << endl;
      return;
    }

    p = this->hashing(e);

    if (this->tabela[p] == -1)
    {
      this->tabela[p] = e;
      cout << "Elemento " << e << " armazenado na posição " << p << endl;
    }
    else
    {
      cout << "Ocorreu uma colisão do elemento " << e << " na posição " << p << ". Buscando uma nova posição..." << endl;
      p = quadraticProbing(e, p);

      if (p != -1)
      {
        this->tabela[p] = e;
        cout << "Elemento " << e << " armazenado na posição " << p << endl;
      }
    }
    return;
  }

  // função exibe a tabela
  void exibe()
  {
    for (int i = 0; i < this->tam; i++)
    {
      if(this->tabela[i] == -1) cout << " | [" << i <<"] VAZIO";
      else cout << " | [" << i <<"] " << this->tabela[i];
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
  int elem = 0, keys[] = {2, 12, 22, 32, 31}, tam = sizeof(keys) / sizeof(*keys);

  // for para inserção dos elementos na tabela hash
  for(int i = 0; i < tam; i++) {
    t->insere(keys[i]);
      if (!t->isFull())
      {
        elem++;
        t->setConta(elem);
      }
  }

  // exibe tabela
  t->exibe();

  //exibe número de elementos na tabela
  cout << "\n\nO número de elementos na tabela é: " << t->getElementos();

  return 0;
}