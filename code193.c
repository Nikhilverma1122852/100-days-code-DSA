#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Compare function for sorting meetings by start time
int compareMeetings(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Min Heap structure
typedef struct {
    int *arr;
    int size;
} MinHeap;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->arr[parent] > heap->arr[index]) {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify down
void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[smallest], &heap->arr[index]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap *heap, int value) {
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Remove minimum element
int removeMin(MinHeap *heap) {
    int minVal = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);

    return minVal;
}

// Get minimum element
int getMin(MinHeap *heap) {
    return heap->arr[0];
}

// Function to find minimum meeting rooms
int minMeetingRooms(Meeting meetings[], int n) {
    if (n == 0)
        return 0;

    // Sort meetings by start time
    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    MinHeap heap;
    heap.arr = (int *)malloc(n * sizeof(int));
    heap.size = 0;

    // Add first meeting end time
    insertHeap(&heap, meetings[0].end);

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {

        // If current meeting starts after earliest ending meeting
        if (meetings[i].start >= getMin(&heap)) {
            removeMin(&heap);
        }

        // Add current meeting end time
        insertHeap(&heap, meetings[i].end);

        // Update maximum rooms needed
        if (heap.size > maxRooms)
            maxRooms = heap.size;
    }

    free(heap.arr);

    return maxRooms;
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Meeting meetings[n];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    int result = minMeetingRooms(meetings, n);

    printf("Minimum meeting rooms required = %d\n", result);

    return 0;
}