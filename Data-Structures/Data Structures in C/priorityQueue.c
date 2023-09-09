#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int item) {
    if (size == MAX_SIZE) {
        printf("Error: Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    size++;
    int curr = rear;
    int parent = (rear - 1) / 2;
    while (parent >= 0 && queue[parent] > queue[curr]) {
        swap(&queue[parent], &queue[curr]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

int extractMin() {
    if (size == 0) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int min = queue[front];
    queue[front] = queue[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    size--;
    int curr = front;
    int left = 2 * curr + 1;
    int right = 2 * curr + 2;
    int smallest = curr;
    if (left < size && queue[left] < queue[smallest])
        smallest = left;
    if (right < size && queue[right] < queue[smallest])
        smallest = right;
    while (smallest != curr) {
        swap(&queue[curr], &queue[smallest]);
        curr = smallest;
        left = 2 * curr + 1;
        right = 2 * curr + 2;
        if (left < size && queue[left] < queue[smallest])
            smallest = left;
        if (right < size && queue[right] < queue[smallest])
            smallest = right;
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
