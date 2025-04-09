#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

int main(){
      
    Processo processos[100];
    int qnt = 0;

    criarProcesso("Tabela.csv", processos, &qnt);

    printf("Quantidade de processos: %d\n", qnt);
    
    //  qsort(processos, 100, sizeof(Processo), comparar_id);

    //  for (int i = 0; i < 100; i++) {
    //      printf("%d, %s, %s,  %d, %d, %d\n", processos[i].id, processos[i].numero, processos[i].data_ajuizamento, processos[i].id_assunto, processos[i].id_classe, processos[i].ano_eleicao);
    //  }


return 0;
}

