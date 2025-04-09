#include "processo.h"

int main(){
    //chama a função para ler o arquivo
    Processo lista[0];  
    int qnt = 0; 

    lerArquivo("Tabela.csv", lista, &qnt); //passa o endereço de qnt

return 0;
}

