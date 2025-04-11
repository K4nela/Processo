#ifndef PROCESSO_H
#define PROCESSO_H

#define MAX_TAMANHO 100
#define MAX_IDASSUNTO 20


//struct------------------------------------------------------------------------
typedef struct {
    int id;
    char numero[50];
    char data[50];//data_ajuizamento
    int id_classe;
    // int id_assunto[20];
    int id_assunto;
    int qnt_assunto;
    int ano;

} Processo;
//funções------------------------------------------------------------------------

void criarProcesso(char *nomeArquivo, Processo processos[], int *qnt);

//funções de Ordenação
int comparar_id(const void *a, const void *b);
int comparar_data(const void *a, const void *b);

//funções para contar
// int contarAssuntosUnicos(Processo processos[], int qnt);
// int contarProcessosComMaisDeUmAssunto(Processo processos[], int qnt);
int contarProcessosPorClasse(Processo processos[], int qnt, int id_classe);

//função para cálculo em dias de tramitação
int dias_em_tramite(Processo processos[], int tot_processos, int id_buscar);


#endif

