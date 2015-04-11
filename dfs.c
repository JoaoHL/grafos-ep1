#include <stdio.h>
#include "dfs.h"
#include "graph.h"
#include "stack.h"
#define TRUE 1
#define FALSE 0

int *parent, *low, *d, *children, *cutVertex, *degree;
int time = 0, block = 0, cutVertex_counter = 0;

int main() {
    Graph *G;

    G = graph_init(degree);
    DFS_interface(G);
    DFS_result(G);
    graph_free(Graph *G);

    return 0;
}

void DFS_interface(Graph *G) {
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
            u->block[u->block_count] = block;
            u->block_count++;
        }
    }
}

void DFS_visit(Graph *G, int u){
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
            cutVertex_counter++;
            block(G, u);
        }
        f[u] = time++;
}

void block(Graph *G, int u) {
    List* v = pop();
    while (v->vertex != u) {
        v->block[block_count++] = block;
        v = pop();
    }
    v->block[v->block_count++] = block;
    push(v);
    block++;
}

void DFS_result(Graph *G){
    printf("%d\n", G->V);

    for (int i = 0; i < G->V; i++){
        printf("%d", degree[i]);
        
        List *v = G->adj[i]->next_adj;
        for (int j = 0; j < degree[i]; j++){
            printf(" %d", v->block[j]);
            v = v->next_adj;
        }
        printf("\n");
    }
}

