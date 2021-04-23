#include "./includes/TabelaHash.hpp"

int main()
{
  auto *t = new TabelaHash;
  int keys[] = {2, 12, 22, 32, 42, 52, 62}, tam = sizeof(keys) / sizeof(*keys);
  clock_t tempo; //variável para armazenar tempo

  // for para INSERCAO dos elementos na tabela hash
  for (int i = 0; i < tam; i++)
  {
    tempo = clock(); //armazena tempo
    t->insere(keys[i]);
    tempo = clock() - tempo; //tempo final - tempo inicial
    coutc("INSERCAO: ", fCYAN);
    cout << ((double)tempo) / ((CLOCKS_PER_SEC / 1000)) << "ms" << endl;
    cout << endl;
  }

  // exibe tabela
  t->exibe();

  //exibe número de elementos na tabela
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << endl
       << endl;

  t->busca(32);
  t->busca(0);
  t->busca(22);
  cout << endl;
  t->remove(12);
  t->remove(0);

  // exibe tabela
  t->exibe();
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << endl
       << endl;

  return 0;
}