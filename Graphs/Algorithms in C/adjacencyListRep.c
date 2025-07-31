#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define MAX_EDGES    10000

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Memory pool for all nodes to avoid frequent malloc/free
Node nodePool[MAX_EDGES * 2];
int nodePoolIndex = 0;

// Create a node from the memory pool
Node* createNode(int vertex) {
    if (nodePoolIndex >= MAX_EDGES * 2) {
        fprintf(stderr, "Node pool exhausted!\n");
        exit(EXIT_FAILURE);
    }
    Node* newNode = &nodePool[nodePoolIndex++];
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Initialize a graph
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

// Add an undirected edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src); // For undirected graph
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
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
