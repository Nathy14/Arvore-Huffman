#ifndef TREE_H
#define TREE_H

#include "commons.h"

struct tree_node {
    struct tree_node *left;
    struct tree_node *right;
    int data;
};

struct tree_t {
    struct tree_node *root;
};

void tree_insert(struct tree_t *tree, int data);
void tree_remove(struct tree_t *tree, int data);

#endif
