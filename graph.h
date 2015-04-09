#ifndef H_GRAPH
#define H_GRAPH

typedef struct list {
                        int v;
                        int block;
                        int degree;
                        list *next;
                    } List;

typedef struct graph {
                        int V;
                        int E;
                        list *adj;
                     } Graph;

Graph* graph_init();
void add_vertex(Graph *G, int v, int *adj);
int graph_free(Graph *G);

#endif
