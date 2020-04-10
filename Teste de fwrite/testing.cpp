#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    FILE *documento;
    char str[] = "Alguma frase mucho louka por aqui!\n";
    documento = fopen("texto.txt","w");
    fwrite(str, 1, sizeof(str), documento);
    fclose(documento);
    return 0;
}

/*OBS: PARA COMPILAR UM PROGRAMA C++ NO WINDOWS, PRIMEIRO:
       g++ -o <nomedoexecutavel>.exe <nomedoarquivo>.cpp
*/