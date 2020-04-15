#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE* documento;
    char str[80], c;
    cout << "Entre com um nome para o arquivo: ";
    cin >> str;

    if(!(documento = fopen(str,"w"))){
        cout << "Erro! Impossível abrir o arquivo!" << endl;
        exit(1);
    }

    fprintf(documento, "Escreve essa merda no arquivo aqui rapaz");
    fclose(documento);

    cout << "O que foi escrito no arquivo foi: " << endl;
    documento = fopen(str,"r");
    while(!feof(documento)){
        fscanf(documento,"%c", &c);
        cout << c;
    }
    fclose(documento);

    return 0;
}