//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_BLOCK_H
#define MCMALLOC_BLOCK_H
#include <stddef.h>
#define BLOCK_FLAG_ALLOCATED ((size_t)1 << 0)
#define BLOCK_FLAG_PREV_FREE ((size_t)1 << 1)
#define BLOCK_FLAG_MASK ((size_t)0xF)
#define BLOCK_SIZE_MASK (~BLOCK_FLAG_MASK)

typedef struct block_header {
    size_t size_and_flags;
} block_header;

typedef struct block_footer {
    size_t size_and_flags;
} block_footer;

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

static void *block_payload(block_header *block) {
    return (unsigned char *)block + sizeof(block_header);
}

static const void *block_payload_const(const block_header *block) {
    return (const unsigned char *)block + sizeof(block_header);
}

#endif //MCMALLOC_BLOCK_H
