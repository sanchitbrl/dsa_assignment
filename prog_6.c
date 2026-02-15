#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//min-Heapify
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

//max-Heapify
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// building  heaps
void buildMinHeap(int arr[], int n) {
    int i;
	for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void buildMaxHeap(int arr[], int n) {
    int i;
	for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

//printing array
void printArray(int arr[], int n) {
    int i;
	for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data1[] = {3, 9, 2, 1, 4, 5};
    int n = sizeof(data1) / sizeof(data1[0]);

    printf("Original Unsorted Array: ");
    printArray(data1, n);

    buildMinHeap(data1, n);
    printf("Min-Heap: ");
    printArray(data1, n);

    //re-initialize to show Max-Heap from unsorted state clearly
    int data2[] = {3, 9, 2, 1, 4, 5};
    buildMaxHeap(data2, n);
    printf("Max-Heap: ");
    printArray(data2, n);

    return 0;
}
