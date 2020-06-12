#include <stdlib.h>
#define Vertice int
#define Aresta Arco

typedef struct no* link;

struct no {
    Vertice w;
    link prox;
};

struct digrafoLA{
    int V;
    int A;
    link* adj;
};

typedef struct digrafoLA *DigrafoLA;

link NOVO (Vertice w, link prox){
    link p = (link) malloc(sizeof*p);
    p->w = w;
    p->prox = prox;
    return p;
}

DigrafoLA inicializaDLA(int v){
    DigrafoLA dig = (DigrafoLA)malloc(sizeof(digrafoLA));
    dig->V = v;
    dig->A = 0;
    dig->adj = (link*)malloc(sizeof(link));
    for(Vertice v = 0; v < dig->V; v++){
        dig->adj[v] = NULL;
    }
    return dig;
}

void insereArco(DigrafoLA dig, Vertice v, Vertice w){
    if(v == w) return;
    for (link p = dig->adj[v]; p != NULL; p->prox){
        if(p->w == w) return;
    }
    dig->adj[v] = NOVO(w,dig->adj[v]);
    dig->A++;
}

