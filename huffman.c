#include "commons.h"

struct tree_node {
    struct tree_node *left;
    struct tree_node *right;
    int data;
    char letter;
};

struct tree_node *create_tree(int data, struct tree_node *right,
                              struct tree_node *left)
{
    struct tree_node *root = (struct tree_node *)smalloc(sizeof(struct tree_node *));
    root->left = left;
    root->right = right;
    root->data = data;
    return root;
}

/**
 * Selection sort.
 */
void sort(struct tree_node **trees, int len)
{
    for (int i = 0;i < len-1;i++) {
        for (int j = 0;j < len-1-i;j++) {
            if (trees[j]->data > trees[j+1]->data) {
                struct tree_node temp = *trees[j];
                *trees[j] = *trees[j+1];
                *trees[j+1] = temp;
            }
        }
    }
}

void huffman(struct tree_node **trees, int len)
{
    // Só para quando o primeiro elemento for 100, ou seja, todas as
    // árvores já foram somadas.
    while (trees[0]->data != 100) {
        sort(trees, len);
        struct tree_node *first = trees[0];
        struct tree_node *second = trees[1];

        // Define qual nó vai para direita ou esquerda.
        struct tree_node *left = second;
        struct tree_node *right = first;
        if (first->data >= second->data) {
            struct tree_node *left = first;
            struct tree_node *right = second;
        }

        int new_root_value = first->data + second->data;
        struct tree_node *newTree = create_tree(new_root_value, right, left);
        trees[0] = newTree;
        // Cria uma árvore vazia com um nó 101, ou seja, impossível de
        // ser usado no cálculo.
        // é adicionado nessa posição para "deletar" o valor antigo.
        trees[1] = create_tree(101, NULL, NULL);
    }
}

/**
 * Verifica se o vetor consegue ser transformado em uma árvore de
 * huffman.
 */
bool is_valid_huffman(struct tree_node **trees, int len)
{
    int sum = 0;
    for (int i = 0;i < len;i++) {
        sum += trees[i]->data;
    }

    printf("Soma das árvores: %d\n", sum);
    return sum == 100 ? true : false;
}

void printTree(struct tree_node *node)
{
    if (node != NULL) {
        printf("%d ", node->data);
        printTree(node->left);
        printTree(node->right);
    }
}

int main()
{
    printf("Árvore de Huffman\n\n");

    printf("Valores iniciais: \n");
    int len = 10;
    struct tree_node *trees[len];
    int values[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    for (int i = 0;i < len;i++) {
        trees[i] = create_tree(values[i], NULL, NULL);
        printf("%d ", trees[i]->data);
    }

    puts("");

    if (is_valid_huffman(trees, len)) {
        huffman(trees, len);
    } else {
        printf("Dados inválidos, soma das árvores diferente de 100\n");
        return -1;
    }

    puts("");

    printTree(trees[0]);
    puts("");

    return 0;
}
