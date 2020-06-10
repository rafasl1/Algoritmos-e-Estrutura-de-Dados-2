#define Vertice int
#define Aresta Arco
#define digrafo *Digrafo

typedef struct {
    Vertice v;
    Vertice w;
} Arco;

Arco fazArco(Vertice v, Vertice w){
    Arco arco;
    arco.v = v;
    arco.w = w;
    return arco;
}

Aresta fazAresta(Vertice v, Vertice w){
    fazArco(v,w);
    fazArco(w,v);
}

typedef struct Digrafo {
    int nVertices;
    int nArcos;
    int ** matrizAdj;
};
