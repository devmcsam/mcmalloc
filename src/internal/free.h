//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_FREE_H
#define MCMALLOC_FREE_H
#include <stddef.h>
#include <defs.h>
#include "block.h"

typedef struct free_node {
    struct free_node *prev;
    struct free_node *next;
} free_node;

typedef struct free_list {
    free_node *head;
    free_node *tail;
    size_t count;
} free_list;

static free_node *block_free_node(block_header *block) {
    return block_payload(block);
}

static block_header *free_node_block(free_node *node) {
    return (block_header *)((unsigned char *)node - sizeof(block_header));
}

#endif //MCMALLOC_FREE_H
