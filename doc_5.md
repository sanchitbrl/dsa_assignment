# Program 5: Graph Implementation with BFS and DFS

## Data Structures Used

### Graph Structure
```c
typedef struct {
    int vertices;
    int adjMatrix[MAX][MAX];
} Graph;
```
- **vertices**: Number of vertices in the graph
- **adjMatrix**: 2D array representing adjacency matrix
  - adjMatrix[i][j] = 1 if edge exists between vertex i and j
  - adjMatrix[i][j] = 0 if no edge exists

### Queue Structure (for BFS)
```c
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;
```
- Used in BFS to keep track of vertices to visit
- FIFO (First In First Out) structure

## Functions Implemented

### Graph Functions

1. **initGraph(Graph *g, int vertices)**
   - Initializes graph with given number of vertices
   - Sets all matrix values to 0

2. **addEdge(Graph *g, int src, int dest)**
   - Adds an edge between two vertices
   - Since graph is undirected, adds edge in both directions
   - Sets adjMatrix[src][dest] = 1 and adjMatrix[dest][src] = 1

3. **displayMatrix(Graph *g)**
   - Displays the adjacency matrix in readable format

### Queue Functions

1. **initQueue(Queue *q)** - Initialize queue
2. **isQueueEmpty(Queue *q)** - Check if queue is empty
3. **enqueue(Queue *q, int val)** - Add element to queue
4. **dequeue(Queue *q)** - Remove and return element from queue

### Traversal Functions

1. **BFS(Graph *g, int startVertex)**
   - Breadth First Search traversal
   - Algorithm:
     - Start from given vertex, mark it visited
     - Add to queue
     - While queue not empty:
       - Remove vertex from queue, print it
       - Add all unvisited adjacent vertices to queue
   - Visits nodes level by level

2. **DFSUtil(Graph *g, int vertex, int visited[])**
   - Helper function for DFS
   - Recursively visits vertices

3. **DFS(Graph *g, int startVertex)**
   - Depth First Search traversal
   - Algorithm:
     - Start from given vertex, mark it visited
     - Print it
     - Recursively visit all unvisited adjacent vertices
   - Goes as deep as possible before backtracking

## Main Function Organization

1. Creates a graph with 6 vertices (0 to 5)
2. Adds 7 edges to create a connected graph
3. Displays visual representation of the graph
4. Shows adjacency matrix
5. Performs BFS starting from vertex 0
6. Performs DFS starting from vertex 0
7. Demonstrates traversals from different starting vertex (3)

## Sample Output

```
Graph Implementation using Adjacency Matrix
============================================

Creating graph with 6 vertices

Adding edges:
0 -- 1
0 -- 2
1 -- 3
1 -- 4
2 -- 4
3 -- 5
4 -- 5

Graph Structure:
    0
   / \
  1   2
 /|   |
3 4---+
 \|  /
   5

Adjacency Matrix:
   0 1 2 3 4 5 
0: 0 1 1 0 0 0 
1: 1 0 0 1 1 0 
2: 1 0 0 0 1 0 
3: 0 1 0 0 0 1 
4: 0 1 1 0 0 1 
5: 0 0 0 1 1 0 

BFS Traversal starting from vertex 0: 0 1 2 3 4 5 

DFS Traversal starting from vertex 0: 0 1 3 5 4 2 

Trying different starting vertex:
BFS Traversal starting from vertex 3: 3 1 5 0 4 2 
DFS Traversal starting from vertex 3: 3 1 0 2 4 5 
```

## How the Algorithms Work

### BFS (Breadth First Search)
- Level by level traversal
- Uses queue to keep track of vertices
- Example path from vertex 0:
  - Level 0: Visit 0
  - Level 1: Visit 1, 2 (neighbors of 0)
  - Level 2: Visit 3, 4 (neighbors of 1, 2)
  - Level 3: Visit 5 (neighbor of 3, 4)

### DFS (Depth First Search)
- Goes deep into one path before exploring others
- Uses recursion (implicit stack)
- Example path from vertex 0:
  - Visit 0 → go to neighbor 1
  - Visit 1 → go to neighbor 3
  - Visit 3 → go to neighbor 5
  - Visit 5 → backtrack, go to 4
  - Visit 4 → go to 2
  - Visit 2 → done

### Adjacency Matrix
For undirected graph, the matrix is symmetric (adjMatrix[i][j] = adjMatrix[j][i]).
Space complexity: O(V²) where V is number of vertices.