#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int numVertices;
} Graph;

// Create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

// Add an undirected edge (both directions)
void addEdge(Graph* graph, int src, int dest) {
    // Add dest to src's list
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add src to dest's list
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// O(n) check if edge exists between src and dest
int edgeExists(Graph* graph, int src, int dest) {
    Node* temp = graph->adjList[src];
    while (temp) {
        if (temp->vertex == dest)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d:", i);
        while (temp) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

// Free graph memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        graph->adjList[i] = NULL;
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
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printGraph(&graph);

    // O(n) edge existence checks
    printf("Edge between 0 and 1? %s\n", edgeExists(&graph, 0, 1) ? "Yes" : "No");
    printf("Edge between 1 and 4? %s\n", edgeExists(&graph, 1, 4) ? "Yes" : "No");
    printf("Edge between 4 and 0? %s\n", edgeExists(&graph, 4, 0) ? "Yes" : "No");

    freeGraph(&graph);
    return 0;
}
