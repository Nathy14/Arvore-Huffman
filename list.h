#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <string.h>
#include "tree.h"

struct node {
    const struct tree_t *value;
    struct node *next;
    struct node *prev;
};

struct list_t {
    struct node *head;
    struct node *tail;
    size_t size;
};

void list_instanciate(struct list_t *list);
bool list_is_empty(const struct list_t *list);
void list_append(struct list_t *list, const struct tree_t *value);
void list_remove_first(struct list_t *list);
void list_remove_last(struct list_t *list);
struct node *list_get(struct list_t *list, size_t index);
void list_sort(struct list_t *list);

#endif
