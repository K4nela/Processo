#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "processo.h"


void lerArquivo(char *nomeArquivo, Processo lista[], int *qnt){
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("\n!ERRO! Nao foi possivel encontrar o arquivo: %s\n", nomeArquivo);
        return;
    }

    char linha[20000];
    *qnt = 0;

    fgets(linha, sizeof(linha), arquivo); // Lendo cabeçalho e ignorando

    while (fgets(linha, sizeof(linha), arquivo)) {

        char scanear = sscanf(linha,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,]\n",
            lista[*qnt].id,
            lista[*qnt].numero, 
            lista[*qnt].data_ajuizamento, 
            lista[*qnt].id_classe,
            lista[*qnt].id_assunto,
            lista[*qnt].ano_eleicao
        );

            if(scanear < 6) {
               printf("Linha invalida: %s\n", linha);
               return;
            }

        printf("%s, %s, %s, %s, %s, %s\n",
            lista[*qnt].id,
            lista[*qnt].numero, 
            lista[*qnt].data_ajuizamento, 
            lista[*qnt].id_classe,
            lista[*qnt].id_assunto,
            lista[*qnt].ano_eleicao
        );

    }
        printf("Arquivo lido com sucesso!\n");
    fclose(arquivo);
}


    //     if(sscanf(linha, "%d %s %s %d %d %d", 
    //            &lista[*qnt].id, 
    //            &lista[*qnt].numero, 
    //            &lista[*qnt].data_ajuizamento, 
    //            &lista[*qnt].id_classe, 
    //            &lista[*qnt].id_assunto, 
    //            &lista[*qnt].ano_eleicao) ==6 ){

    //            printf("ID: %d\n", lista[*qnt].id);
    //            printf("Numero: %s\n", lista[*qnt].numero);
    //            printf("Data Ajuizamento: %s\n", lista[*qnt].data_ajuizamento);
    //            printf("ID Classe: %d\n", lista[*qnt].id_classe);
    //            printf("ID Assunto: %d\n", lista[*qnt].id_assunto);
    //            printf("Ano Eleicao: %d\n", lista[*qnt].ano_eleicao);
    //            printf("---------------------\n");
    //     (*qnt)++;

    // }else{
    //     printf("Linha invalida: %s\n", linha);
    //     return;
    // }
