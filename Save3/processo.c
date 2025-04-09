#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "processo.h"


void criarProcesso(char *nomeArquivo, Processo processos[], int *qnt){

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("\n!ERRO! Nao foi possivel encontrar o arquivo: %s\n", nomeArquivo);
        return;
    }

    char linha[200]; // Ajuste conforme necessário
    *qnt = 0;

    fgets(linha, sizeof(linha), arquivo);


    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char *token = strtok(linha, ",{};");
    
    if (token) processos[*qnt].id = atoi(token);
    processos[*qnt].id = atoi(token + (token[0] == '"'));
    token = strtok(NULL, ",{};");
    if (token) strncpy(processos[*qnt].numero, token, sizeof(processos[*qnt].numero));
    token = strtok(NULL, ",{};");
    if (token) strncpy(processos[*qnt].data_ajuizamento, token, sizeof(processos[*qnt].data_ajuizamento));
    token = strtok(NULL, ",{};");
    if (token) processos[*qnt].id_classe = atoi(token);
    token = strtok(NULL, ",{};");
    if (token) processos[*qnt].id_assunto = atoi(token);
    token = strtok(NULL, ",{};");
    if (token) processos[*qnt].ano_eleicao = atoi(token);

    printf("%d, %s, %s, %d, %d, %d\n",
        processos[*qnt].id,
        processos[*qnt].numero,
        processos[*qnt].data_ajuizamento,
        processos[*qnt].id_classe,
        processos[*qnt].id_assunto,
        processos[*qnt].ano_eleicao);

    (*qnt)++;
    
    }


fclose(arquivo);
}
    

int comparar_id(const void *a, const void *b) {
    Processo *p1 = (Processo *)a;
    Processo *p2 = (Processo *)b;
    return p1->id - p2->id;
    
}






