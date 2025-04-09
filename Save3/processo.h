#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct {
    int id;
    char numero[50];
    char data_ajuizamento[30];
    int id_classe;
    int id_assunto;
    int ano_eleicao;
} Processo;

void criarProcesso(char *nomeArquivo, Processo processos[], int *qnt);

int comparar_id(const void *a, const void *b);

#endif