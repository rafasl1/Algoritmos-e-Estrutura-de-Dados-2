#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE* documento;
    documento = fopen("test.txt","r");
    fseek(documento, 0, SEEK_END);
    cout << "O tamanho do arquivo eh" << ftell(documento);
    return 0;
}

/*
SEEK_END PARA IR PARA O FIM DO ARQUIVO
SEEK_SET PARA IR PARA O COMEÇO DO ARQUIVO
SEEK_CUR PARA IR PARA A POSIÇÃO ATUAL DO PONTEIRO DO ARQUIVO


ftell() fala a posição atual do ponteiro
*/