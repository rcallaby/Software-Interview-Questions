#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// Initialize graph
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Add an undirected edge
void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices) {
        fprintf(stderr, "Vertex index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // Remove for directed graphs
}

// Print the adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Example usage
int main() {
    Graph graph;
    int vertices = 5;
    initGraph(&graph, vertices);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraph(&graph);

    return 0;
}
