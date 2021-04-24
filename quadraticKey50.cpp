#include "./includes/TabelaHash.hpp"


int main()
{ 
  int randKeysQtd = 50;
  srand(time(NULL)); // Semente para criação dos numeros aleatórios

  clock_t tempoExecucao; 
  tempoExecucao = clock(); // Variavel para armazenar tempo inicial de execução do Programa
  auto *t = new TabelaHash;
  clock_t tempo; //variável para armazenar tempo

// for para INSERCAO dos elementos na tabela hash
  for (int i = 0; i < randKeysQtd; i++ ){
    tempo = clock();
    t->insere(rand() % randKeysQtd);
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
  t->busca(50210);
  
  t->remove(12);
  t->remove(0);

  cout << endl;
  
  // exibe tabela
  t->exibe();
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << endl
       << endl;

  tempoExecucao = clock() - tempoExecucao; 
  coutc("TEMPO DE EXECUCAO: ", fCYANs);
  cout << ((double)tempoExecucao) / ((CLOCKS_PER_SEC / 100)) << " seg" << endl;
  return 0;
}