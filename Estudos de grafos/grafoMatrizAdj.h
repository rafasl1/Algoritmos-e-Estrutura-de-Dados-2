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

// versão iterativa
int existeCaminhoIterativo(Digrafo *g, Vertice s, Vertice t){
    Vertice v, w;
    Vertice arrayCaminho[maxV];
    int k;
    for(v = 0; v < g->nVertices; v++){
        lbl[v] = -1;
    }
    lbl[s] = 0;
    arrayCaminho[0] = s;

    k = 1;
    v = s;
    w = 0;

    while(k!=1 || w!= g->nVertices){
        if(w == g->nVertices){
            w = v + 1;
            k--;
            v = arrayCaminho[k-1];
        }else if(g->matrizAdj[v][w] == 1 && lbl[w] == -1){
            lbl[w] = 0;
            v = w;
            arrayCaminho[k] = w;
            w = 0;
        }else {
            w++;
        }
    }
    if(lbl[t] == - 1) return 0;
    return 1;
}

// faz o s-t corte
int st_corte(Digrafo *g, Vertice s, Vertice t){
    Vertice v, w;
    if(lbl[s] == -1 || lbl[t] = 0) return 0;
    for(v = 0; v < g->nVertices; v++){
        for(w = 0; w < g-> nVertices; w++){
            if(g->matrizAdj[v][w] == 1 && (lbl[v] = 0 && lbl[w] == -1)) return 0;
        }
    }
    return 1;
}

// verifica se há caminho e devolve junto a arborecência
static int pai[maxV];
void caminhoComArb(Digrafo* g, Vertice v);
int existeCaminhoComArb(Digrafo* g, Vertice s, Vertice t){
    Vertice v;
    for(v = 0; v < g->nVertices; v++){
        lbl[v] = -1;
        pai[v] = -1;
    }
    pai[s] = s;
    caminhoComArb(g,s);
    if(lbl[t] == -1) return 0;
    return 1;
}

//CAMINHO COM ARBORECÊNCIA
void caminhoComArb(Digrafo* g, Vertice v){
    Vertice w;
    for(w = 0; w < g->nVertices; w++){
        if(g->matrizAdj[v][w] == 1){
            if(lbl[w] == -1){
                pai[w] = v;
                caminhoComArb(g,v);
            }
        }
    }
}

int st_caminho(Digrafo * g, Vertice s, Vertice t){
    Vertice v, w;
    if(pai[t] == -1) return 0;
    for(w = t; w!= pai[w]; w=v){
        v = pai[w];
        if(g->matrizAdj[v][w] != 1) return 0;
    }
    if(w!=s) return 0;
    return 1;
}


// BUSCA EM PROFUNDIDADE 

int contador;

void dfsR(Digrafo *dig, Vertice v){
    Vertice w;
    lbl[v] = contador++;
    for(w = 0; w < dig->nVertices; w++){
        if(dig->matrizAdj[v][w] != 0){
            if(lbl[w] == -1){
                dfsR(dig,w);
            }
        }
    }
}
// é TETA(V^2)
void DIGRAPHdfs(Digrafo* dig){
    Vertice v;
    contador = 0;
    for(v = 0; v < dig-> nVertices; v++){
        lbl[v] = -1;
    }
    for(v = 0; v < dig->nVertices; v++){
        if(lbl[v] == -1){
            dfsR(dig,v);
        }
    }
}