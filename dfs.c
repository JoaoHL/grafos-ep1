#include <stdio.h>
#include "dfs.h"
#include "stack.h"
#define TRUE 1
#define FALSE 0

int *parent, *low, *d, *f, *children, *cutVertex;
int time = 0, block = 0;

int main() {
    Graph *G;

    G = graph_init();
    DFS_interface(G);
    DFS_result(G);
    graph_free(Graph *G);

    return 0;
}

void DFSinterface(Graph *G) {
    for (int v = 0; v < G->V; v++) {
        parent[v] = NULL;
        low[v] = -1;
        d[v] = -1;
        f[v] = -1;
    }
    time = 0;

    for (int v = 0; v < G->V; v++){
        if (parent[v] == NULL){
            parent[v] = v;
            DFS_visit(G, v);
            if (children[v] >= 2)
                block(G, v);
        }
    }

    if (!(stackIsEmpty())){
        while (!(stackIsEmpty())){
            List *u = pop();
            u->block[u->block_index] = block;
            u->block_index++;
        }
    }
}

void DFSvisit(Graph *G, int u){
        d[u] = time++;
        low[u] = d[u];
        
        for (List e = G->adj[u]; e != NULL; e = e->next){
            int v = e->vertex;
            if (parent[v] == NULL){
                parent[v] = u;
                children[u]++;
                DFS_visit(G, v);
                if (low[v] < low[u])
                    low[u] = low[v];
            }
        }
        if (low[u] == d[u]){
            cutVertex[u] = TRUE;
            block(G, u);
        }
        f[u] = time++;
}

void block(Graph *G, int u) {
    List* v = pop();
    while (v->vertex != u) {
        v->block[v->block_index++] = block;
        v = pop();
    }
    v->block[v->block_index++] = block;
    push(v);
    block++;
}



