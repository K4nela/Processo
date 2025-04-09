#include "processo.h"

int main(){
    //chama a função para ler o arquivo
    Processo lista[0]; // Ajusta esse tamanho conforme necessário  
    int qnt = 0; // Inicializa qnt  

    lerArquivo("Tabela.csv", lista, &qnt); // Passa o endereço de qnt

return 0;
}

