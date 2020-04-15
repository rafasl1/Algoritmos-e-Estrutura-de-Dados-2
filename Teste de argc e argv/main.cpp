#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]){
    if (argc > 1){
        cout << "Mais de um no argc caraio" << endl;
    }
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
    }
    cout << "O nro do argc eh: " << argc << endl;

    return 0;
}