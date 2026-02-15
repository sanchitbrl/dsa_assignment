# Program 6: Min and Max Heap Implementation

## Data Structures Used

### Array-based Heap
- Heaps are implemented using arrays
- For node at index i:
  - Left child: 2*i + 1
  - Right child: 2*i + 2
  - Parent: (i-1)/2

**Max Heap Property**: Parent node >= all children
**Min Heap Property**: Parent node <= all children

## Functions Implemented

### 1. `void swap(int *a, int *b)`
- Swaps two integer values
- Used during heapify operations

### 2. `void maxHeapify(int arr[], int n, int i)`
- Maintains max heap property for subtree rooted at index i
- Algorithm:
  - Find largest among node, left child, and right child
  - If largest is not current node, swap and recursively heapify

### 3. `void buildMaxHeap(int arr[], int n)`
- Builds max heap from unsorted array
- Starts from last non-leaf node (n/2 - 1) and heapifies backwards
- Time complexity: O(n)

### 4. `void minHeapify(int arr[], int n, int i)`
- Maintains min heap property for subtree rooted at index i
- Algorithm:
  - Find smallest among node, left child, and right child
  - If smallest is not current node, swap and recursively heapify

### 5. `void buildMinHeap(int arr[], int n)`
- Builds min heap from unsorted array
- Same approach as buildMaxHeap but uses minHeapify

### 6. `void printArray(int arr[], int n)`
- Prints array elements in linear format

### 7. `void printHeapTree(int arr[], int n)`
- Prints heap in tree-like structure for better visualization
- Shows level-by-level structure

## Main Function Organization

1. Creates an unsorted array with 10 elements
2. Makes two copies (one for max heap, one for min heap)
3. Builds max heap from first array:
   - Prints array representation
   - Shows tree structure
   - Displays root (maximum element)
4. Builds min heap from second array:
   - Prints array representation
   - Shows tree structure
   - Displays root (minimum element)
5. Verifies heap properties for both heaps

## Sample Output

```
Heap Implementation - Min and Max Heap
======================================

Original unsorted array:
45 12 67 23 89 34 56 8 90 15 

Building MAX HEAP...
--------------------
Max Heap (array representation):
90 89 67 23 45 34 56 8 12 15 

Max Heap (tree structure):
        90 
      89 67 
    23 45 34 56 
  8 12 15 

Root (Maximum element): 90

Building MIN HEAP...
--------------------
Min Heap (array representation):
8 12 34 23 15 67 56 45 90 89 

Min Heap (tree structure):
        8 
      12 34 
    23 15 67 56 
  45 90 89 

Root (Minimum element): 8

Verification:
-------------
In Max Heap, parent >= children: YES
In Min Heap, parent <= children: YES
```

## How Heap Building Works

### Build Max Heap Process:
Original: [45, 12, 67, 23, 89, 34, 56, 8, 90, 15]

Start from index 4 (last non-leaf):
1. Heapify index 4: 89 is already larger than children
2. Heapify index 3: 23 < 90, swap → [45, 12, 67, 90, 89, 34, 56, 8, 23, 15]
3. Heapify index 2: 67 is already larger than children
4. Heapify index 1: 12 < 89, swap and recursively fix
5. Heapify index 0: 45 < 90, swap and recursively fix

Final: [90, 89, 67, 23, 45, 34, 56, 8, 12, 15]

### Build Min Heap Process:
Similar process but we find minimum instead of maximum at each step.

## Heap Properties

**Complete Binary Tree**: All levels filled except possibly last, which is filled left to right

**Max Heap**: Used for:
- Finding maximum element quickly (O(1))
- Priority queue with highest priority first
- Heap sort

**Min Heap**: Used for:
- Finding minimum element quickly (O(1))
- Priority queue with lowest priority first
- Dijkstra's algorithm

Time Complexity:
- Build Heap: O(n)
- Heapify: O(log n)