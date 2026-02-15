#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // Number of vertices in the graph

// function to find the vertex with the minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    int v;
	int min = INT_MAX, min_index;

    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

//function to print the constructed distance array
void printSolution(int dist[], int n) {
    int i;
	printf("Vertex \t Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

//function that implements Dijkstra's single source shortest path algorithm,for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V],i, count,v;     
    bool sptSet[V];  
    //initialize all distances as INFINITE and stpSet[] as false
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    //distance of source vertex from itself is always 0
    dist[src] = 0;

    //find shortest path for all vertices
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        // mark the picked vertex as processed
        sptSet[u] = true;

        //update dist value of the adjacent vertices of the picked vertex.
        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, V);
}

int main() {
    //example weighted graph represented as an adjacency matrix
    int graph[V][V] = {
        { 0, 4, 4, 0, 0, 0 },
        { 4, 0, 2, 0, 0, 0 },
        { 4, 2, 0, 3, 1, 0 },
        { 0, 0, 3, 0, 0, 2 },
        { 0, 0, 1, 0, 0, 3 },
        { 0, 0, 0, 2, 3, 0 }
    };

    printf("Dijkstra's Algorithm (Starting from Vertex 0):\n");
    dijkstra(graph, 0);

    return 0;
}
