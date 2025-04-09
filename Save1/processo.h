#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct{
    float numero;    
    int id;
    int id_classe;
    int id_assunto;
    int ano_eleicao;
    int data_ajuizamento;
}Processo; 

typedef struct {
    Processo *Array;
    int Tamanho;
    int Capacidade;
    } Lista;

void lerArquivo();

int comparar_id(const void *a, const void *b);

int comparar_data_ajuizamento(const void *a, const void *b);

int contar_processos_por_classe(Processo processos[], int n, int classe);

int contar_assuntos_distintos(Processo processos[], int n);

int contar_dias_tramitacao(const char *data_inicio);

void listar_processos_mais_de_um_assunto(Processo processos[], int n);

#endif