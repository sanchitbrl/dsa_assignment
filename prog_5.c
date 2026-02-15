#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // Added this

#define V 5 // max no of vertices

// Adjacency Matrix
int adjMatrix[V][V];

// Initialize Matrix
void initializeGraph() {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adjMatrix[i][j] = 0;
}

// connects nodes u and v in both directions
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// breadth-First Search
// visits nodes level by level — first all immediate neighbours,
// then their neighbours, and so on. Uses a queue to track who to visit next.
void BFS(int start) {
    bool visited[V] = {false};
    int queue[V], front = 0, rear = 0, i;
    
    //marks the starting node as visited and add it to the queue
    visited[start] = true;
    queue[rear++] = start;
    
    printf("BFS: ");
    while (front < rear) { // keep going while queue isn't empty
        int curr = queue[front++]; // take the node at the front
        printf("%d ", curr);
        
        //looks at every possible neighbour
        for (i = 0; i < V; i++) {
            if (adjMatrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true; // mark so we don't revisit
                queue[rear++] = i; // add to back of queue
            }
        }
    }
    printf("\n");
}

// dfs function goes as deep as possible down one path before backtracking to try another.
void DFS_helper(int curr, bool visited[]) {
    int i;
    visited[curr] = true;
    printf("%d ", curr);
    
    // Explore every unvisited neighbour before coming back here
    for (i = 0; i < V; i++) {
        if (adjMatrix[curr][i] == 1 && !visited[i])
            DFS_helper(i, visited);
    }
}

// dfs function sets up the visited array and kicks off the recursive helper.
void DFS(int start) {
    bool visited[V] = {false};
    printf("DFS: ");
    DFS_helper(start, visited);
    printf("\n");
}

int main() {
    initializeGraph();  // Fixed from initGraph()
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    
    BFS(0); // expected: 0 1 2 3 4
    DFS(0); // expected: 0 1 2 4 3
    
    return 0;
}
