#ifndef COMMONS_H
#define COMMONS_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

void *smalloc(const size_t size);
void *scalloc(const size_t nitems, const size_t size);

#endif
