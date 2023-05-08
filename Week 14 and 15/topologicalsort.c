//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 18/04/2023

//Objective - Topological Sort

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

// A structure to define the graph
typedef struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// A structure to represent a stack
typedef struct Stack {
    int top;
    int items[MAX_VERTICES];
} Stack;

// Functions for graph and stack operations
Graph* createGraph(int num_vertices);
void addEdge(Graph* graph, int source, int destination);
void topologicalSortUtil(Graph* graph, int v, int visited[], Stack* stack);
void topologicalSort(Graph* graph);

//main function
int main() {

	//declaring graph
    Graph* graph = createGraph(6);

	//adding edges
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological sort of the graph:\n");
    topologicalSort(graph);
    printf("\n");

    return 0;
}

//function to create the graph
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    int i, j;
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }

    return graph;
}

//function to add the edges
void addEdge(Graph* graph, int source, int destination) {
    graph->adj_matrix[source][destination] = 1;
}

void topologicalSortUtil(Graph* graph, int v, int visited[], Stack* stack) {
    visited[v] = 1;

    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        if (graph->adj_matrix[v][i] == 1 && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    stack->items[++stack->top] = v;
}

//function to sort the graph
void topologicalSort(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;

    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack);
        }
    }

    while (stack->top != -1) {
        printf("%d ", stack->items[stack->top--]);
    }
}