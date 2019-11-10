#include "commons.h"
#include "list.h"

/**
 * Inicializa a lista vazia.
 *
 * list:
 * Ponteiro para o lista.
 */
void list_instanciate(struct list_t *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/**
 * Verifica se a lista está vazia.
 *
 * list:
 * Ponteiro para a lista.
 */
bool list_is_empty(const struct list_t *list)
{
    return list->head == NULL;
}

/**
 * Insere um elemento no final da lista.
 *
 * list:
 * Ponteiro para a lista.
 * value:
 * Valor a ser inserido.
 */
void list_append(struct list_t *list, const struct tree_t *value)
{
    struct node *new_node = (struct node *)smalloc(sizeof(struct node *));
    new_node->value = value;
    new_node->next = NULL;

    if (list_is_empty(list)) {
        new_node->prev = NULL;
        list->tail = list->head = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

/**
 * Remove o primeiro elemento da lista.
 *
 * list:
 * Ponteiro para a lista.
 */
void list_remove_first(struct list_t *list)
{
    if (list_is_empty(list)) return;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
    } else {
        struct node *aux = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(aux);
    }
    list->size--;
}

/**
 * Remove o último elemento da lista.
 *
 * list:
 * Ponteiro para a lista.
 */
void list_remove_last(struct list_t *list)
{
    if (list_is_empty(list)) return;

    if (list->head == list->tail) {
        free(list->head);
        list->head = list->tail = NULL;
    } else {
        struct node *aux = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(aux);
    }
    list->size--;
}

struct node *list_get(struct list_t *list, size_t index)
{
    if (index == 0)
        return list->head;

    if (index == list->size - 1)
        return list->tail;

    struct node *aux = list->head;
    size_t i = 0;
    for (;i < index;aux = aux->next, i++);

    return aux;
}

static void swap(struct node *a, struct node *b)
{
    struct node *aux = a;
    a->next = b->next;
    a->prev = b;
    b = aux;
}

void list_sort(struct list_t *list)
{
    for (uint i = 0;i < list->size;i++) {
        for (uint j = 0;j < list->size;j++) {
            struct node *current = list_get(list, i);
            struct node *next = list_get(list, i+1);
            int current_value = current->value->root->data;
            int next_value = next->value->root->data;
            if (current_value > next_value) {
                swap(current, next);
            }
        }
    }
}
