# Program 7: Dijkstra's Algorithm for Shortest Path

## Data Structures Used

### Graph Structure
```c
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;
```
- **vertices**: Number of vertices in graph
- **adjMatrix**: 2D array storing edge weights
  - adjMatrix[i][j] = weight of edge between i and j
  - adjMatrix[i][j] = 0 if no edge exists

### Arrays used in Dijkstra's Algorithm
- **dist[]**: Stores shortest distance from source to each vertex
- **visited[]**: Boolean array to track visited vertices
- **parent[]**: Stores parent of each vertex in shortest path tree

## Functions Implemented

### 1. `void initGraph(Graph *g, int vertices)`
- Initializes graph with given number of vertices
- Sets all weights to 0

### 2. `void addEdge(Graph *g, int src, int dest, int weight)`
- Adds weighted edge between two vertices
- Since graph is undirected, adds edge in both directions

### 3. `int minDistance(int dist[], bool visited[], int vertices)`
- Finds vertex with minimum distance value
- Only considers vertices not yet visited
- Returns index of vertex with minimum distance

### 4. `void printPath(int parent[], int vertex)`
- Recursively prints the path from source to given vertex
- Uses parent array to backtrack

### 5. `void dijkstra(Graph *g, int source)`
- **Main algorithm** - finds shortest path from source to all vertices
- Algorithm steps:
  1. Initialize all distances to infinity except source (0)
  2. Mark all vertices as unvisited
  3. For each vertex:
     - Pick unvisited vertex with minimum distance
     - Mark it as visited
     - Update distances of its adjacent vertices if shorter path found
  4. Print results showing distance and path to each vertex

### 6. `void displayGraph(Graph *g)`
- Displays the weighted adjacency matrix

## Main Function Organization

1. Creates a weighted graph with 6 vertices
2. Adds 8 weighted edges to form a connected graph
3. Displays the adjacency matrix
4. Runs Dijkstra's algorithm from vertex 0
5. Shows shortest distances and paths to all vertices
6. Demonstrates algorithm from different source (vertex 2)

## Sample Output

```
Dijkstra's Algorithm - Shortest Path
=====================================

Creating weighted graph with 6 vertices

Adding edges (format: src -- dest [weight]):
0 -- 1 [4]
0 -- 2 [3]
1 -- 2 [1]
1 -- 3 [2]
2 -- 3 [4]
3 -- 4 [2]
4 -- 5 [6]
2 -- 4 [5]

Weighted Graph (Adjacency Matrix):
     0   1   2   3   4   5 
0:   -   4   3   -   -   - 
1:   4   -   1   2   -   - 
2:   3   1   -   4   5   - 
3:   -   2   4   -   2   - 
4:   -   -   5   2   -   6 
5:   -   -   -   -   6   - 

Dijkstra's Shortest Path Algorithm
===================================
Source Vertex: 0

Vertex	 Distance	Path
------	 --------	----
0	 0		0
1	 4		0 -> 1
2	 3		0 -> 2
3	 6		0 -> 1 -> 3
4	 8		0 -> 2 -> 4
5	 14		0 -> 1 -> 3 -> 4 -> 5



Trying from different source vertex:

Dijkstra's Shortest Path Algorithm
===================================
Source Vertex: 2

Vertex	 Distance	Path
------	 --------	----
0	 3		2 -> 0
1	 1		2 -> 1
2	 0		2
3	 3		2 -> 1 -> 3
4	 5		2 -> 4
5	 11		2 -> 4 -> 5
```

## How Dijkstra's Algorithm Works

The algorithm finds the shortest path by always choosing the vertex with minimum distance that hasn't been visited yet.

### Example: Finding shortest path from 0 to 5

1. Start at vertex 0, distance = 0
2. Visit neighbors: 1 (distance 4), 2 (distance 3)
3. Choose vertex 2 (min distance 3)
4. From 2, update: 1 (distance 4 vs 3+1=4), 4 (distance ∞ vs 3+5=8)
5. Choose vertex 1 (distance 4)
6. From 1, update: 3 (distance ∞ vs 4+2=6)
7. Choose vertex 3 (distance 6)
8. From 3, update: 4 (distance 8 vs 6+2=8)
9. Choose vertex 4 (distance 8)
10. From 4, update: 5 (distance ∞ vs 8+6=14)
11. Choose vertex 5 (distance 14)

Final shortest path: 0 → 1 → 3 → 4 → 5 with total distance 14

## Properties

- **Greedy Algorithm**: Makes locally optimal choice at each step
- **Time Complexity**: O(V²) where V is number of vertices
- **Works only with non-negative weights**
- Finds shortest path from single source to all other vertices