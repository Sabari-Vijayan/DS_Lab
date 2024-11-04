#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 // Define maximum number of vertices

int adj[MAX][MAX]; // Adjacency matrix
int vertices;

void addEdge(int edge1, int edge2) {
    adj[edge1][edge2] = 1;
    adj[edge2][edge1] = 1; // Assuming it's an undirected graph
}

// DFS function using adjacency matrix
void dfs(int adj[MAX][MAX], int V, int start) {
    bool visited[MAX] = { false }; // Initialize all vertices as not visited
    int stack[MAX], top = -1; // Stack for DFS

    // Push the starting vertex onto the stack
    stack[++top] = start;

    printf("DFS traversal starting from node %d: ", start + 1);

    while (top != -1) {
        // Pop a vertex from the stack and print it
        int curr = stack[top--];
        
        // If the current vertex is not visited, mark it as visited and print it
        if (!visited[curr]) {
            visited[curr] = true;
            printf("%d ", curr + 1); // Print with 1-based indexing

            // Push all unvisited adjacent vertices onto the stack
            for (int i = V - 1; i >= 0; i--) { // Reverse order for correct traversal
                if (adj[curr][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

void bfs(int adj[MAX][MAX], int V, int start) {
    // Queue for BFS
    int q[MAX], front = 0, rear = 0;
    bool visited[MAX] = { false };

    // Mark the source node as visited and enqueue it
    visited[start] = true;
    q[rear++] = start;

    printf("BFS traversal starting from node %d: ", start + 1);

    // Iterate over the queue
    while (front < rear) {
        // Dequeue a vertex and print it
        int curr = q[front++];
        printf("%d ", curr + 1); // Print with 1-based indexing

        // Get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
    printf("\n");
}
int main() {
    int edges, edge1, edge2, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &edge1, &edge2);

        // Adjust user input to 0-based indexing
        edge1--;
        edge2--;

        // Ensure the edges are within bounds
        if (edge1 >= 0 && edge1 < vertices && edge2 >= 0 && edge2 < vertices) {
            addEdge(edge1, edge2);
        } else {
            printf("Invalid edge: (%d, %d)\n", edge1 + 1, edge2 + 1);
        }
    }

    // Print the adjacency matrix
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
     // Perform BFS
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Adjust the startVertex to 0-based
    startVertex--;

    if (startVertex >= 0 && startVertex < vertices) {
        bfs(adj, vertices, startVertex);
    } else {
        printf("Invalid starting vertex!\n");
    }

    // Perform DFS
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Adjust the startVertex to 0-based
    startVertex--;

    if (startVertex >= 0 && startVertex < vertices) {
        dfs(adj, vertices, startVertex);
    } else {
        printf("Invalid starting vertex!\n");
    }

    return 0;
}
