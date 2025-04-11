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


    char linha[MAX_TAMANHO];
    *qnt = 0;

    fgets(linha, sizeof(linha), arquivo);


    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char *token = strtok(linha, ",{};");
    
    if (token) processos[*qnt].id = atoi(token);
    processos[*qnt].id = atoi(token + (token[0] == '"'));

    token = strtok(NULL, ",{};");
    if (token) strncpy(processos[*qnt].numero, token, sizeof(processos[*qnt].numero));

    token = strtok(NULL, ",{};");
    if (token) strncpy(processos[*qnt].data, token, sizeof(processos[*qnt].data));
    
    token = strtok(NULL, ",{};");
    if (token) processos[*qnt].id_classe = atoi(token);

    // int idx = 0;
    // while (token != NULL && idx < MAX_IDASSUNTO) { // Evita ultrapassar o limite do array
    //     processos[*qnt].id_assunto[idx++] = atoi(token);
    //     token = strtok(NULL, "{},");
    // }
    // if (idx > 1) { // Só armazena se tiver mais de um assunto
    //     processos[*qnt].qnt_assunto = idx; 
    // } else {
    //     processos[*qnt].qnt_assunto = 0; // Ignora se tiver só um
    // }
    token = strtok(NULL, ",{};");
    if (token) processos[*qnt].id_assunto = atoi(token);

    token = strtok(NULL, "{};"); 
    if (token) processos[*qnt].ano = atoi(token);

    printf("%d,",processos[*qnt].id);
    printf("%s,",processos[*qnt].numero);    
    printf("%s,",processos[*qnt].data);
    printf("%d,",processos[*qnt].id_classe);
    printf("%d, %d,",processos[*qnt].id_assunto);
    printf("%d\n",processos[*qnt].ano);

    (*qnt)++;
    }
fclose(arquivo);
}
    

int comparar_id(const void *a, const void *b) {
    Processo *p1 = (Processo *)a;
    Processo *p2 = (Processo *)b;
    return p1->id - p2->id; 
}

int comparar_data(const void *a, const void *b) {
    Processo *p1 = (Processo *)a;
    Processo *p2 = (Processo *)b;
    return p2->data - p1->data;
}

int contarProcessosPorClasse(Processo processos[], int qnt, int id_classe) {
    int contador = 0;
    for (int i = 0; i < qnt; i++) {
        if (processos[i].id_classe == id_classe) {
            contador++;
        }
    }
    return contador;
}

// int contarAssuntosUnicos(Processo processos[], int qnt) {
//     if (qnt == 0) return 0;

//     char **assuntos = malloc(qnt * sizeof(char *));
//     if (assuntos == NULL) {
//         perror("Erro de alocação de memória");
//         return -1;
//     }

//     int total = 0;

//     for (int i = 0; i < qnt; i++) {
//         int encontrado = 0;

//         for (int j = 0; j < total; j++) {
//             if (strcmp(assuntos[j], processos[i].id_assunto) == 0) {
//                 encontrado = 1;
//                 break;
//             }
//         }

//         if (!encontrado) {
//             assuntos[total] = strdup(processos[i].id_assunto); // Copia a string
//             if (assuntos[total] == NULL) {
//                 perror("Erro de alocação de memória");
//                 // Libera memória antes de retornar erro
//                 for (int k = 0; k < total; k++) free(assuntos[k]);
//                 free(assuntos);
//                 return -1;
//             }
//             total++;
//         }
//     }

//     for (int i = 0; i < total; i++) free(assuntos[i]);
//     free(assuntos);

//     return total;
// }

// //==================================CONTAR UM============================================
// int contarAssuntosUnicos(Processo processos[], int qnt) {
//     if (qnt == 0) return 0;

//     char **assuntos = malloc(qnt * sizeof(char *));
//     if (assuntos == NULL) {
//         perror("Erro de alocação de memória");
//         return -1;
//     }

//     int total = 0;

//     for (int i = 0; i < qnt; i++) {
//         int encontrado = 0;

//         for (int j = 0; j < total; j++) {
//             if (strcmp(assuntos[j], processos[i].id_assunto) == 0) { 
//                 encontrado = 1;
//                 break;
//             }
//         }

//         if (!encontrado) {
//             assuntos[total] = strdup(processos[i].id_assunto);
//             if (assuntos[total] == NULL) {
//                 perror("Erro de alocação de memória");
//                 break;
//             }
//             total++;
//         }
//     }

//     for (int i = 0; i < total; i++) {
//         free(assuntos[i]);
//     }
//     free(assuntos);

//     return total;
// }




int dias_em_tramite(Processo processos[], int tot_processos, int id_buscar) {

    for (int i = 0; i < tot_processos; i++) {
        if (processos[i].id == id_buscar) {
            struct tm data = {0};

            // Formato esperado: "2016-04-20 15:03:40.000"
            int ano, mes, dia, hora, min, seg;
            if (sscanf(processos[i].data, "%d-%d-%d %d:%d:%d",
                       &ano, &mes, &dia, &hora, &min, &seg) == 6) {
                data.tm_year = ano - 1900;
                data.tm_mon = mes - 1;
                data.tm_mday = dia;
                data.tm_hour = hora;
                data.tm_min = min;
                data.tm_sec = seg;
                


                time_t t_ajuizamento = mktime(&data);
                time_t t_atual = time(NULL);

                double segundos = difftime(t_atual, t_ajuizamento);
                int dias = (int)(segundos / (60 * 60 * 24));

                printf("Processo ID: %d\n", processos[i].id);
                printf("Data de ajuizamento: %s\n", processos[i].data);
                printf("Dias em tramitacao: %d dias\n", dias);
                return dias;
            } else {
                printf("Erro ao interpretar a data do processo.\n");
                return -1;
            }
        }
    }
    printf("Processo com ID %d não encontrado.\n", id_buscar);
    return -1;
    
}
