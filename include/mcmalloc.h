#ifndef MCMALLOC_H_H
#define MCMALLOC_H_H
#include <stddef.h>

void *mcmalloc(size_t size);
void free(void *ptr);

#endif /* MCMALLOC_H_H */
