#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 6

struct node {
    int key;
    int value;
    struct node **forward;
};

struct skip_list {
    int level;
    struct node *head;
};

struct node *new_node(int level, int key, int value) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->key = key;
    node->value = value;
    node->forward = (struct node **) malloc(level * sizeof(struct node *));
    return node;
}

struct skip_list *create_skip_list() {
    struct skip_list *list = (struct skip_list *) malloc(sizeof(struct skip_list));
    list->level = 0;
    list->head = new_node(MAX_LEVEL, 0, 0);
    for (int i = 0; i < MAX_LEVEL; i++) {
        list->head->forward[i] = NULL;
    }
    return list;
}

int random_level() {
    int level = 1;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

void insert(struct skip_list *list, int key, int value)
{
    struct node *update[MAX_LEVEL];
    struct node *node = list->head;
    for (int i = list->level; i >= 0; i--)
    {
        while (node->forward[i] != NULL && node->forward[i]->key < key)
        {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];
    if (node == NULL || node->key != key)
    {
        int level = random_level();
        if (level > list->level)
        {
            for (int i = list->level + 1; i < level; i++)
            {
                update[i] = list->head;
            }
            list->level = level;
        }
        node = new_node(level, key, value);
        for (int i = 0; i < level; i++)
        {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }
    else
    {
        node->value = value;
    }
}

void delete(struct skip_list *list, int key)
{
    struct node *update[MAX_LEVEL];
    struct node *node = list->head;
    for (int i = list->level; i >= 0; i--)
    {
        while (node->forward[i] != NULL && node->forward[i]->key < key)
        {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];
    if (node != NULL && node->key == key)
    {
        for (int i = 0; i <= list->level; i++)
        {
            if (update[i]->forward[i] != node)
            {
                break;
            }
            update[i]->forward[i] = node->forward[i];
        }
        free(node->forward);
        free(node);
        while (list->level > 0 && list->head->forward[list->level] == NULL)
        {
            (list->level--);
        }
    }
}

    struct node *search(struct skip_list *list, int key)
    {
        struct node *node = list->head;
        for (int i = list->level; i >= 0; i--)
        {
            while (node->forward[i] != NULL && node->forward[i]->key < key)
            {
                node = node->forward[i];
            }
        }
        node = node->forward[0];
        if (node != NULL && node->key == key)
        {
            return node;
        }
        else
        {
            return NULL;
        }
    }


    void print_list(struct skip_list * list)
    {
        for (int i = list->level; i >= 0; i--)
        {
            printf("Level %d: ", i);
            struct node *node = list->head->forward[i];
            while (node != NULL)
            {
                printf("(%d, %d) ", node->key, node->value);
                node = node->forward[i];
            }
            printf("\n");
        }
    }

    int main()
    {
        srand(time(NULL));
        struct skip_list *list = create_skip_list();
        insert(list, 1, 10);
        insert(list, 2, 20);
        insert(list, 3, 30);
        insert(list, 4, 40);
        insert(list, 5, 50);
        printf("Skip list after inserting (1, 10), (2, 20), (3, 30), (4, 40), (5, 50):\n");
        print_list(list);
        delete (list, 4);
        printf("Skip list after deleting (4, 40):\n");
        print_list(list);
        struct node *result = search(list, 3);
        if (result != NULL)
        {
            printf("Found key 3 with value %d\n", result->value);
        }
        else
        {
            printf("Key 3 not found\n");
        }
        return 0;
    }