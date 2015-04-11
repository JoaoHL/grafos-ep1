#ifndef H_GRAPH
#define H_GRAPH

typedef struct list {
                        int vertex;
                        int *block;
                        int block_count;
                        list *next_adj;
                        list *next_stack;
                    } List;

typedef struct graph {
                        int V;
                        List **adj;
                     } Graph;

Graph* graph_init();
void graph_free(Graph *G);

#endif
