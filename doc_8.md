# Program 8: Sorting Algorithms Comparison

## Data Structures Used

### Arrays
- **original[]**: Stores the original unsorted random numbers
- **arr[]**: Working copy used for sorting
- Both are dynamically allocated based on user input

### Global Variables
```c
long long comparisons = 0;
long long swaps = 0;
```
- Used to count operations during sorting
- Reset before each sorting algorithm runs

## Functions Implemented

### 1. `void swap(int *a, int *b)`
- Swaps two integers
- Increments swap counter
- Used by bubble sort, selection sort, and insertion sort

### 2. `void bubbleSort(int arr[], int n)`
- Implements Bubble Sort algorithm
- Compares adjacent elements and swaps if out of order
- Time Complexity: O(n²)
- Algorithm:
  - Repeat n-1 times
  - In each pass, compare adjacent elements
  - Swap if left > right
  - Largest element "bubbles" to end

### 3. `void selectionSort(int arr[], int n)`
- Implements Selection Sort algorithm
- Finds minimum element and places it at beginning
- Time Complexity: O(n²)
- Algorithm:
  - For each position i
  - Find minimum element from i to n
  - Swap it with element at position i

### 4. `void insertionSort(int arr[], int n)`
- Implements Insertion Sort algorithm
- Builds sorted array one element at a time
- Time Complexity: O(n²)
- Algorithm:
  - Start from second element
  - Insert each element into its correct position in sorted part
  - Shift elements as needed

### 5. `void merge(int arr[], int left, int mid, int right)`
- Helper function for Merge Sort
- Merges two sorted subarrays
- Uses temporary arrays

### 6. `void mergeSortHelper(int arr[], int left, int right)`
- Recursive helper for Merge Sort
- Divides array into halves

### 7. `void mergeSort(int arr[], int n)`
- Implements Merge Sort algorithm
- Divide and conquer approach
- Time Complexity: O(n log n)
- Algorithm:
  - Divide array into two halves
  - Recursively sort each half
  - Merge the sorted halves

### 8. `void printArray(int arr[], int n)`
- Prints array elements
- Shows first 10 and last 10 if array is large (>20 elements)

### 9. `void copyArray(int source[], int dest[], int n)`
- Copies one array to another
- Used to preserve original array

## Main Function Organization

1. Prompts user for number of elements (N)
2. Allocates memory for arrays
3. Generates N random integers in range [1, 1000]
4. Displays original unsorted array
5. Shows menu of sorting algorithms
6. Gets user's choice
7. Performs selected sorting algorithm
8. Displays sorted array
9. Shows statistics (comparisons and swaps)
10. Frees allocated memory

## Sample Output

```
Random Number Sorting Program
==============================

Enter the number of random integers to generate (N): 15

Generating 15 random numbers in range [1, 1000]...

Original unsorted array:
456 234 789 123 567 890 345 678 234 901 456 234 678 345 123 


Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort

Enter your choice (1-4): 1

========================================
Sorting using BUBBLE SORT...
========================================

Sorted array:
123 123 234 234 234 345 345 456 456 567 678 678 789 890 901 

========================================
STATISTICS
========================================
Total Comparisons: 105
Total Swaps: 47
========================================
```

## Sample Output (Different Algorithm)

```
Random Number Sorting Program
==============================

Enter the number of random integers to generate (N): 15

Generating 15 random numbers in range [1, 1000]...

Original unsorted array:
456 234 789 123 567 890 345 678 234 901 456 234 678 345 123 


Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort

Enter your choice (1-4): 4

========================================
Sorting using MERGE SORT...
========================================

Sorted array:
123 123 234 234 234 345 345 456 456 567 678 678 789 890 901 

========================================
STATISTICS
========================================
Total Comparisons: 38
Total Swaps: N/A (Merge Sort uses array copying)
========================================
```

## Comparison of Algorithms

| Algorithm | Time Complexity | Space | Swaps | Comparisons | Stable |
|-----------|----------------|-------|-------|-------------|--------|
| Bubble Sort | O(n²) | O(1) | High | High | Yes |
| Selection Sort | O(n²) | O(1) | Low | High | No |
| Insertion Sort | O(n²) | O(1) | Medium | Medium | Yes |
| Merge Sort | O(n log n) | O(n) | N/A | Low | Yes |

**Best for small arrays**: Insertion Sort (simple and efficient for small n)
**Best for large arrays**: Merge Sort (better time complexity)
**Least swaps**: Selection Sort (only n-1 swaps)

## Key Features

- Dynamic memory allocation based on user input
- Random number generation with seed
- Statistics tracking (comparisons and swaps)
- Clean output formatting
- Handles both small and large arrays
- Memory cleanup to prevent leaks