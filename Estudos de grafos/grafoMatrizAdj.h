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

#define maxV 30
static int lbl[maxV];

void caminho(Digrafo* g, Vertice v);
// é O(v^2)
int existeCaminho(Digrafo* g, Vertice s, Vertice t){
    Vertice v;
    for(v = 0; v < g->nVertices; v++){
        lbl[v] = -1;
    }
    caminho(g,s);
    if(lbl[t] == -1) return -1;
    else return 1;
}
// é O(v^2)
void caminho(Digrafo* g, Vertice v){
    Vertice w;
    lbl[v] = 0;
    for(w = 0; w < g->nVertices; w++){
        if(g-> matrizAdj[v][w] == 1){
            if(lbl[w] == -1) {
                caminho(g, w);
            }
        }
    }
}

//segunda versão do "existe caminho"
int caminho2(Digrafo *g, Vertice v, Vertice t);
int existeCaminho2(Digrafo *g, Vertice s, Vertice t){
    Vertice v;
    for(v = 0; v < g->nVertices; v++){
        lbl[v] = -1;
    }
    return caminho2(g,s,t);
}
int caminho2(Digrafo *g, Vertice v, Vertice t){
    Vertice w;
    lbl[v] = 0;
    if(v==t) return 1; // cheguei
    for(w = 0; w < g-> nVertices; w++){
        if(g-> matrizAdj[v][w] == 1 && lbl[w] == -1){
            if(caminho2(g,v,w)){
                return 1;
            }
        }
    }
    return 0; // não chegou no t
}