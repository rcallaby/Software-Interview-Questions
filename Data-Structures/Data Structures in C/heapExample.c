#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

int heap[HEAP_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int data) {
    if (size == HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = data;
    int current = size;
    int parent = (current - 1) / 2;

    while (heap[current] < heap[parent]) {
        swap(&heap[current], &heap[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }

    size++;
}

int extractMin() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int current = 0;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    int smallest = current;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != current) {
        swap(&heap[current], &heap[smallest]);
        current = smallest;
        left = 2 * current + 1;
        right = 2 * current + 2;
    }

    return min;
}

int main() {
    insert(3);
    insert(2);
    insert(1);
    printf("Minimum element: %d\n", extractMin());
    printf("Minimum element: %d\n", extractMin());
    printf("Minimum element: %d\n", extractMin());
    return 0;
}
