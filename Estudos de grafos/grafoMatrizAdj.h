#include "funcoesAuxiliares.cpp"
#define Vertice int
#define Aresta Arco


typedef struct {
    Vertice v;
    Vertice w;
} Arco;

typedef struct Digrafo {
    int nVertices;
    int nArcos;
    int ** matrizAdj;
}Digrafo;

Arco fazArco(Vertice v, Vertice w){
    Arco arco;
    arco.v = v;
    arco.w = w;
    return arco;
}

void fazAresta(Vertice v, Vertice w){
    fazArco(v,w);
    fazArco(w,v);
}

Digrafo* iniciaDigrafo(int nVertices){
    Digrafo* g = (Digrafo*)malloc(sizeof(Digrafo));
    g->nVertices = nVertices;
    g->nArcos = 0; 
    g->matrizAdj = alocaMatriz(nVertices,nVertices,0);
    return g;
}
