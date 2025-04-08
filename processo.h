#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct{
    int numero;    
    int id;
    int id_classe;
    int id_assunto;
    int ano_eleicao;
    int data_ajuizamento;
}Processo;

Processo ordenarIdCrescente(Processo P); //ordenar, em ordem crescente, o conjuntos de dados a partir do  atributo "id"

Processo ordenarAjuizamentoDecrescente(Processo P); //ordenar, em ordem decrescente, o conjunto de dados a partir do atributo "data_ajuizamento"

Processo contarIdClasse(Processo P); //Contar quantos processos estão vinculados a um determinado “id_classe”;

Processo identificarIdAssuntos(Processo P); //Identificar quantos “id_assuntos” constam nos processos presentes na base de dados;

Processo listarAssunto(Processo P); //Listar todos os processos que estão vinculados a mais de um assunto;

Processo indicarQantidadeDias(Processo P); //Indicar a quantos dias um processo está em tramitação na justiça.

#endif