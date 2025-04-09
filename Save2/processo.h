#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct{
    char id[30];
    char numero[50];
    char data_ajuizamento[30];      
    char id_classe[30];
    char id_assunto[30];
    char ano_eleicao[30];
}Processo; 


void lerArquivo(char *nomeArquivo, Processo lista[],  int *qnt);

int comparar_id(const void *a, const void *b);

int comparar_data_ajuizamento(const void *a, const void *b);

int contar_processos_por_classe(Processo processos[], int n, int classe);

int contar_assuntos_distintos(Processo processos[], int n);

int contar_dias_tramitacao(const char *data_inicio);

void listar_processos_mais_de_um_assunto(Processo processos[], int n);

#endif