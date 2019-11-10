#include "tree.h"

static struct tree_node *tree_create_node(int data, struct tree_node *left,
                                          struct tree_node *right);
static void tree_insert_right(struct tree_node *node, int data);
static void tree_insert_left(struct tree_node *node, int data);
static void tree_insert_node(struct tree_node *node, int data);

static struct tree_node *tree_create_node(int data, struct tree_node *left,
                                          struct tree_node *right)
{
    struct tree_node *node = (struct tree_node *)smalloc(sizeof(struct tree_node *));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

static void tree_insert_right(struct tree_node *node, int data)
{
    if (node->right == NULL) {
        node->right = tree_create_node(data, NULL, NULL);
    } else {
        tree_insert_node(node->right, data);
    }
}

static void tree_insert_left(struct tree_node *node, int data)
{
    if (node->left == NULL) {
        node->left = tree_create_node(data, NULL, NULL);
    } else {
        tree_insert_node(node->left, data);
    }
}

static void tree_insert_node(struct tree_node *node, int data)
{
    if (data > node->data)
        tree_insert_right(node, data);
    else if (data < node->data)
        tree_insert_left(node, data);
}


void tree_insert(struct tree_t *tree, int data)
{
    if (tree->root == NULL) {
        tree->root = tree_create_node(data, NULL, NULL);
    } else {
        tree_insert_node(tree->root, data);
    }
}
