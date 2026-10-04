//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_DATA_H
#define MCMALLOC_DATA_H
#include <stddef.h>

#define ALLOC_ALIGNMENT 16
#define ALLOC_ALIGNMENT_MASK (ALLOC_ALIGNMENT - 1)
#define BLOCK_FLAG_ALLOCATED ((size_t)1 << 0)
#define BLOCK_FLAG_PREV_FREE ((size_t)1 << 1)
#define BLOCK_FLAG_MASK ((size_t)0xF)
#define BLOCK_SIZE_MASK (~BLOCK_FLAG_MASK)
#define ALLOC_NUM_SIZE_CLASSES 16

typedef struct free_node {
    struct free_node *prev;
    struct free_node *next;
} free_node;

typedef struct block_header {
    size_t size_and_flags;
} block_header;

typedef struct block_footer {
    size_t size_and_flags;
} block_footer;

typedef struct free_list {
    free_node *head;
    free_node *tail;
    size_t count;
} free_list;

typedef struct size_class {
    size_t size;
    free_list free_list;
} size_class;

static size_t block_size(const block_header *block) {
    return block->size_and_flags & BLOCK_SIZE_MASK;
}

static bool block_is_allocated(const block_header *block) {
    return (block->size_and_flags & BLOCK_FLAG_ALLOCATED) != 0;
}

static bool block_prev_is_free(const block_header *block) {
    return (block->size_and_flags & BLOCK_FLAG_PREV_FREE) != 0;
}

static void block_set_allocated(block_header *block) {
    block->size_and_flags |= BLOCK_FLAG_ALLOCATED;
}

static void block_set_free(block_header *block) {
    block->size_and_flags &= ~BLOCK_FLAG_ALLOCATED;
}

static void block_set_prev_free(block_header *block) {
    block->size_and_flags |= BLOCK_FLAG_PREV_FREE;
}

static void block_set_prev_allocated(block_header *block) {
    block->size_and_flags &= ~BLOCK_FLAG_PREV_FREE;
}

#endif //MCMALLOC_DATA_H
