//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_FREE_H
#define MCMALLOC_FREE_H
#include <defs.h>

typedef struct free_node {
    struct free_node *prev;
    struct free_node *next;
} free_node;

typedef struct free_list {
    free_node *head;
    free_node *tail;
    size_t count;
} free_list;

#endif //MCMALLOC_FREE_H
