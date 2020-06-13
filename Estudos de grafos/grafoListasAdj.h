#include <stdlib.h>
#include <iostream>
#define Vertice int
#define Aresta Arco
#define maxV 30
static int lbl[maxV];
static int pai[maxV];

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

void mostraDig(DigrafoLA dig){
    Vertice v;
    link p;
    for(v = 0; v < dig->V; v++){
        printf("%2d:", v);
        for(p = dig->adj[v]; p != NULL; p=p->prox){
            printf("%2d", p->w);
        } printf("\n");
    }
}

// consumo de tempo O(v + a), enquanto que para matriz de adj é O(v^2)
void caminhoLA(DigrafoLA dig, Vertice v){
    link p;
    lbl[v] = 0;
    for(p = dig->adj[v]; p != NULL; p = p->prox){
        if(lbl[p->w] == -1){
            pai[p->w] = v;
            caminhoLA(dig,p->w);
        }
    }
}


//BUSCA EM PROFUNDIDADE
int contador;

void dfsR(DigrafoLA dig, Vertice v){
    link p;
    lbl[v] = contador++;
    for(p = dig->adj[v]; p!= NULL; p=p->prox){
        if(lbl[p->w == -1]){
            dfsR(dig,p->w);
        }
    }
}
// é TETA(V + A)
void DIGRAPHdfs(DigrafoLA dig){
    Vertice v;
    contador = 0;
    for(v = 0; v < dig-> V; v++){
        lbl[v] = -1;
    }
    for(v = 0; v < dig->V; v++){
        if(lbl[v] == -1){
            dfsR(dig,v);
        }
    }
}

// ALGORITMOS DE BUSCA EM PROFUNDIDADE COM DESCOBRIMENTO E FINALIZAÇÃO
static int tempo, descobrimento[maxV], finalizacao[maxV];

void dfsRComPassos(DigrafoLA dig, Vertice v){
    link p;
    descobrimento[v] = tempo++;
    for(p = dig->adj[v]; p ; p=p->prox){
        if(descobrimento[p->w] == -1){
            pai[p->w] = v; // tava errado no slide (?)
            dfsRComPassos(dig,p->w);
        }
    }
    finalizacao[v] = tempo++;
}

void buscaEmProf(DigrafoLA dig){
    Vertice v;
    tempo = 0;
    for(int v = 0; v < dig->V; v++){
        pai[v] = -1;
        descobrimento[v] = -1;
        finalizacao[v] = -1;
    }
    for(v = 0; v < dig->V; v++){
        if(descobrimento[v] == -1){
            dfsRComPassos(dig,v);
        }
    }
}