#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

int main(){
    char linha[20000];
    FILE *arquivo;
    Processo p;
    int i=0;

    // acessando o arquivo para leitura
    arquivo = fopen("Tabela.csv", "r");

    if (arquivo == NULL)
    {
        printf("!DEU ERRO NESSA PORRA! KRL, QUE BOSTA! TOMANOCU, AINDA FALA DE MIM, ATE PARECE QUE E FACIL ASSIM\n");
        exit(1);
    }
  
while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    printf("%d\n", i);
    
char *token = strtok(linha, ",");
while (token != NULL) {
   printf("Campo: %s\n", token);
   token = strtok(NULL, ",");
}

    i++;
}
return 0;


}

//	FILE *arquivo;  
//	int numero = 125;  
//	char palavra[] = "Esta é uma frase que será gravada no arquivo!"; 

//fscanf(arquivo, "%d %s", &numero, palavra); //LENDO OS DADOS DE UM ARQUIVO 
 
