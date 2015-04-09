#include <stdio.h>
#include "dfs.h"
#include "stack.h"

int *parent, *low, *d, *f, time, *children;

int main() {

}

void DFSinterface(Graph *G) {
    for (int v = 0; v < G->V; v++) {
        parent[v] = NULL;
        low[v] = 0;
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
    if (!(stackIsEmpty()))

}

void DFSvisit(Graph *G, int u){
        d[u] = time++;
        low[u] = d[u];
        
        for (List e = G->adj[u]; e != NULL; e = e->next){
            int v = e->vertex;
            if (parent[v] == NULL){
                parent[v] = u;
                DFS_visit(G, v);
                if (low[v] < low[u])
                    low[u] = low[v];
            }
        }
        
        if (low[u] == d[u])
            block(G, u);
        f[u] = time++;
}

void block(Graph *G, int u) {
    int v = pop(
    while
}



