#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10000


long long comparisons = 0;
long long swaps       = 0;


// Swap two integers and record it
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void printArray(int arr[], int n) {
    int i;
	for (i = 0; i < n; i++)
        printf("%d%s", arr[i], i < n - 1 ? ", " : "\n");
}

void copyArray(int src[], int dst[], int n) {
    int i;
	for (i = 0; i < n; i++)
        dst[i] = src[i];
}


// Time complexity: O(n²)

void bubbleSort(int arr[], int n) {
    int i, j;
	for (i = 0; i < n - 1; i++) {
        bool swapped = false;                       // early exit if already sorted
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;                        // no swaps ? list is sorted
    }
}


// Time complexity: O(n²)

void selectionSort(int arr[], int n) {
    int i,j;
	for (i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i)                            // only swap if needed
            swap(&arr[i], &arr[minIdx]);
    }
}


// Time complexity: O(n²)

void insertionSort(int arr[], int n) {
    int i;
	for (i = 1; i < n; i++) {
        int key = arr[i];                           // the card we're placing
        int j   = i - 1;

        // Shift elements that are greater than key one position to the right
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;                            // count each shift as a swap
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;                          // drop key into its correct slot
    }
}


// Time complexity: O(n log n)

void merge(int arr[], int left, int mid, int right) {
    int i = 0, j = 0, k = left;
    int leftSize  = mid - left + 1;
    int rightSize = right - mid;

    // Temporary arrays to hold the two halves
    int* L = (int*)malloc(leftSize  * sizeof(int));
    int* R = (int*)malloc(rightSize * sizeof(int));

    for (i = 0; i < leftSize;  i++) L[i] = arr[left + i];
    for (i = 0; i < rightSize; i++) R[i] = arr[mid + 1 + i];


    while (i < leftSize && j < rightSize) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }

    while (i < leftSize)  arr[k++] = L[i++];
    while (j < rightSize) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;                      // base case: one element, already sorted
    int mid = left + (right - left) / 2;
    mergeSort(arr, left,    mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    srand(time(NULL));                              // seed random number generator

    int n, i;
    printf("How many random integers do you want to generate? ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    int original[MAX], arr[MAX];
    for (i = 0; i < n; i++)
        original[i] = (rand() % 1000) + 1;

    printf("\nGenerated numbers:\n");
    printArray(original, n);

    printf("\nChoose a sorting algorithm:\n");
    printf("  1. Bubble Sort\n");
    printf("  2. Selection Sort\n");
    printf("  3. Insertion Sort\n");
    printf("  4. Merge Sort\n");
    printf("Your choice: ");

    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > 4) {
        printf("Invalid choice.\n");
        return 1;
    }

    copyArray(original, arr, n);
    comparisons = 0;
    swaps       = 0;

    char* algoName;
    switch (choice) {
        case 1: algoName = "Bubble Sort";    bubbleSort(arr, n);        break;
        case 2: algoName = "Selection Sort"; selectionSort(arr, n);     break;
        case 3: algoName = "Insertion Sort"; insertionSort(arr, n);     break;
        case 4: algoName = "Merge Sort";     mergeSort(arr, 0, n - 1); break;
    }

    // -- Step 5: Print results -------------------------------------------------
    printf("\n-- %s Results --\n", algoName);
    printf("\nBefore sorting:\n");
    printArray(original, n);
    printf("\nAfter sorting:\n");
    printArray(arr, n);

    printf("\n-- Statistics --\n");
    printf("Comparisons : %lld\n", comparisons);
    if (choice != 4)
        printf("Swaps       : %lld\n", swaps);
    else
        printf("Swaps       : N/A (Merge Sort copies into temp arrays instead of swapping)\n");

    return 0;
}
