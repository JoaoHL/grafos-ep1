#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* graph_init(int *degree){
    Graph *G = malloc(sizeof(Graph));

    scanf("%d", &G->V);
    degree = malloc(G_>V * sizeof(int));
    G->adj = malloc(G->V * sizeof(List *));

    for (int i = 0; i < G->V; i++){
        G->adj[i]->block = NULL;
        G->adj[i]->antiparallel = NULL;
        G->adj[i]->next_adj = NULL;
        G->adj[i]->next_stack = NULL;
    }

    for (int i = 0; i < G->V; i++){
        scanf("%d", &degree[i]);

        for (int j = 0; j < degree[i]; j++){
            List *new = malloc(sizeof(List));
            scanf("%d", &new->vertex);
            new->block = malloc(G->V * sizeof(int));
            new->block_count = 0;
            new->next_stack = NULL;
            new->next_adj = G->adj[i]->next_adj;
            G->adj[i] = new;
        }
    }
}
