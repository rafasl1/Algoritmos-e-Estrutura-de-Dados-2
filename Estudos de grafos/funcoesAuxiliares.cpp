#include <stdlib.h>

int** alocaMatriz(int linhas, int colunas, int valor){
    int i, j;
    int** m = (int**)malloc(linhas*sizeof(int*));

    for(i = 0; i < colunas; i++){
        m[i] = (int*)malloc(colunas*sizeof(int));
    }
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            m[i][j] = valor;
        }
    }
    return m;
}