#include "./includes/TabelaHash.hpp"

int main()
{
  clock_t tempoExecucao; 
  tempoExecucao = clock(); // Variavel para armazenar tempo inicial de execução do Programa

  auto *t = new TabelaHash;
  int keys[] = {6, 17, 28, 39, 50, 61, 72, 83, 94}, tam = sizeof(keys) / sizeof(*keys); // {2, 12, 22, 32, 42, 52, 62, 72, 82, 92, 102, 202}
  clock_t tempo; //variável para armazenar tempo

  // for para INSERCAO dos elementos na tabela hash
  for (int i = 0; i < tam; i++)
  {
    tempo = clock(); //armazena tempo

    t->insere(keys[i]); // insere

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


  // busca elementos
  t->busca(83);
  t->busca(50);
  t->busca(0);
  
  //remove elementos
  t->remove(83);
  t->remove(0);

  cout << endl;
  
  // exibe tabela
  t->exibe();
  coutc("ELEMENTOS: ", fYELLOWs);
  cout << t->getElementos() << endl
       << endl;

  tempoExecucao = clock() - tempoExecucao; 
  coutc("TEMPO DE EXECUCAO: ", fCYANs);
  cout << ((double)tempoExecucao) / CLOCKS_PER_SEC << " seg" << endl;
  return 0;
}