//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_DATA_H
#define MCMALLOC_DATA_H
#include <stddef.h>
#include "free.h"

typedef struct size_class {
    size_t size;
    free_list free_list;
} size_class;


#endif //MCMALLOC_DATA_H
