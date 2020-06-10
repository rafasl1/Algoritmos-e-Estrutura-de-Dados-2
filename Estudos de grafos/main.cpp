#include <iostream>
#include "grafoMatrizAdj.h"

using namespace std;

int main(){
    Digrafo* grafao = iniciaDigrafo(6);
    grafao->nArcos = 9;
    grafao->matrizAdj[3][6] = 1;
    grafao->matrizAdj[6][10] = 1;
    grafao->matrizAdj[10][20] = 1;
    grafao->matrizAdj[20][12] = 1;
    grafao->matrizAdj[12][10] = 1;
    grafao->matrizAdj[10][4] = 1;
    grafao->matrizAdj[4][3] = 1;
    grafao->matrizAdj[6][4] = 1;
    grafao->matrizAdj[4][12] = 1;
    
    if(existeCaminho(grafao, 6, 12) == 1) {
        cout << "Existe o caminho de 6 a 12" << endl;
    }else {
        cout << "Não existe caminho de 6 a 12" << endl;
    }

    return 0;
}