#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CACHE_SIZE 10

typedef struct node {
  int key;
  int value;
  struct node *prev;
  struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
node *cache[MAX_CACHE_SIZE];

// Function to initialize cache
void initCache() {
  for (int i = 0; i < MAX_CACHE_SIZE; i++) {
    cache[i] = NULL;
  }
  head = NULL;
  tail = NULL;
}

// Function to add a node to the front of the linked list
void addToFront(node *new) {
  new->next = head;
  new->prev = NULL;
  if (head) {
    head->prev = new;
  }
  head = new;
  if (!tail) {
    tail = head;
  }
}

// Function to remove a node from the linked list
void removeNode(node *target) {
  if (!target->prev) {
    head = target->next;
  } else {
    target->prev->next = target->next;
  }
  if (!target->next) {
    tail = target->prev;
  } else {
    target->next->prev = target->prev;
  }
}

// Function to set a key-value pair in the cache
void set(int key, int value) {
  int index = key % MAX_CACHE_SIZE;
  if (cache[index]) {
    node *temp = cache[index];
    temp->key = key;
    temp->value = value;
    removeNode(temp);
    addToFront(temp);
  } else {
    node *new = (node *)malloc(sizeof(node));
    new->key = key;
    new->value = value;
    cache[index] = new;
    addToFront(new);
    if (strlen(cache) > MAX_CACHE_SIZE) {
      node *last = tail;
      removeNode(last);
      cache[last->key % MAX_CACHE_SIZE] = NULL;
      free(last);
    }
  }
}

// Function to get the value of a key from the cache
int get(int key) {
  int index = key % MAX_CACHE_SIZE;
  if (cache[index]) {
    node *temp = cache[index];
    removeNode(temp);
    addToFront(temp);
    return temp->value;
  }
  return -1;
}

int main() {
  initCache();
  set(1, 10);
  set(2, 20);
  set(3, 30);
  printf("%d\n", get(2));
  return 0;
}
