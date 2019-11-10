#include "commons.h"

/**
 * Malloc seguro, verifica se alocação ocorreu corretamente.
 *
 * size:
 * Tamanho a ser alocado.
 */
void *smalloc(const size_t size)
{
    if (!size)
        return NULL;

    void *mem = malloc(size);

    if (!mem) {
        fprintf(stderr, "Fatal: Memory allocation error (%zu bytes malloc)\n", size);
        exit(EXIT_FAILURE);
    }

    return mem;
}

/**
 *
 */
void *scalloc(const size_t nitems, const size_t size)
{
    if (!size)
        return NULL;

    void *mem = calloc(nitems, size);

    if (!mem) {
        fprintf(stderr, "Fatal: Memory allocation error (%zu bytes calloc)\n", size);
        exit(EXIT_FAILURE);
    }

    return mem;
}
