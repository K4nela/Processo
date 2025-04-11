#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

int main(){
    Processo processos[MAX_TAMANHO];
    int qnt = 0;

    criarProcesso("Tabela.csv", processos, &qnt);

    // int opcao;
    // do {
    //     printf("\n===== MENU ====\n");
    //     printf("01. Organizado por ID e salvar\n");
    //     printf("02. Organizado por data de ajuizamento e salvar\n");
    //     printf("03. Contagem de processos por classe\n");
    //     printf("04. Contagem de assuntos distintos\n");
    //     printf("05. Alistando processos com mais de um assunto\n");
    //     printf("06. Dias em tramitacao por ID do processo\n");
    //     printf("07. Alistando todos os processos\n");
    //     printf("0. Sair\n");
    //     printf("Escolha uma opcao: ");
    //     scanf("%d", &opcao);
    // switch (opcao) {
    //     case 01:{}
    //qsort(processos,qnt, sizeof(Processo), comparar_id);
    //  for (int i = 0; i < qnt; i++) {
    //      printf("%d, %s, %s,  %d, %d, %d\n", processos[i].id, processos[i].numero, processos[i].data, processos[i].id_assunto, processos[i].id_classe, processos[i].ano);
    //     }          
    //         break;
    //   }

    //     case 02:{}
    //qsort(processos, qnt, sizeof(Processo), comparar_data);
    //  for (int i = 0; i < qnt; i++) {
    //      printf("%d, %s, %s,  %d, %d, %d\n", processos[i].id, processos[i].numero, processos[i].data, processos[i].id_assunto, processos[i].id_classe, processos[i].ano);
    // }
    //         
    //         break;
    //   }
    //     case 03:{}
    // int qntMAX = MAX_TAMANHO;  
    // int classe = 12377;  
    // int resultado = contarProcessosPorClasse(processos, qntMAX, classe); 
    //         
    //         
    //         break;
    //   }
    //     case 04:{}
    //int total = contarAssuntosUnicos(processos, qntMAX);
    //  printf("Quantidade de assuntos unicos %d", total);
    //         
    //         break;
    //   }
    //     case 05:{}
    //         
    //         
    //         break;
    //   }
    //     case 06:{}
    //         
    //         
    //         break;
    //   }
    //     case 07:{}
    //         
    //         
    //         break;
    //   }
    //     case 0:{}
    //         
    //         
    //         break;
    //
    //   default:
    //         printf("");
    //   }
    // } While (opcao != 0);

    // free(processos);
    // return 0;
    // }
    
    
    //  qsort(processos,qnt, sizeof(Processo), comparar_id);
    //       for (int i = 0; i < qnt; i++) {
    //       printf("%d, %s, %s,  %d, %d, %d\n", processos[i].id, processos[i].numero, processos[i].data, processos[i].id_assunto, processos[i].id_classe, processos[i].ano);
    //   }
    //   printf("-----------------------------\n");

    //   qsort(processos, qnt, sizeof(Processo), comparar_data);
    //       for (int i = 0; i < qnt; i++) {
    //       printf("%d, %s, %s,  %d, %d, %d\n", processos[i].id, processos[i].numero, processos[i].data, processos[i].id_assunto, processos[i].id_classe, processos[i].ano);
    //   }
    printf("-----------------------------\n");

    int qntMAX = MAX_TAMANHO;  
    int classe = 12377;  
    int resultado = contarProcessosPorClasse(processos, qntMAX, classe); 

    printf("Quantidade de processos da classe %d: %d\n", classe, resultado); 
    printf("-----------------------------\n");    

    // int total = contarAssuntosUnicos(processos, qntMAX);
    // printf("Quantidade de assuntos unicos %d\n", total);
    // printf("-----------------------------\n"); 
    
    // int comMultiplosAssuntos = contarProcessosComMaisDeUmAssunto(processos, qntMAX);
    // printf("Processos com mais de um assunto: %d\n", comMultiplosAssuntos);


    // int id_procura;
    // printf("Informe o ID do processo para verificação de dias em tramite: ");
    // scanf("%d", &id_procura);

    // int total;
    // dias_em_tramite(processos, total, id_procura);
    

return 0;
} 
