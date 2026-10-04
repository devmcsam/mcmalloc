//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_DEFS_H
#define MCMALLOC_DEFS_H
#include <stddef.h>

#define ALLOC_ALIGNMENT 16
#define ALLOC_ALIGNMENT_MASK (ALLOC_ALIGNMENT - 1)
#define BLOCK_FLAG_ALLOCATED ((size_t)1 << 0)
#define BLOCK_FLAG_PREV_FREE ((size_t)1 << 1)
#define BLOCK_FLAG_MASK ((size_t)0xF)
#define BLOCK_SIZE_MASK (~BLOCK_FLAG_MASK)
#define ALLOC_NUM_SIZE_CLASSES 16
#define INITIAL_HEAP_SIZE (4194304) // 4 MiB
#define LARGE_ALLOC_THRESHOLD (1u << 20) // 1 MiB
#define SMALL_ALLOC_THRESHOLD (16384) // 16 KiB

#endif //MCMALLOC_DEFS_H
