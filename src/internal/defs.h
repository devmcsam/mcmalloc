//
// Created by mcsam on 10/3/26.
//
#pragma once
#ifndef MCMALLOC_DEFS_H
#define MCMALLOC_DEFS_H
#include <stddef.h>

#define ALLOC_ALIGNMENT (16)
#define ALLOC_ALIGNMENT_MASK (ALLOC_ALIGNMENT - 1)
#define BLOCK_FLAG_ALLOCATED ((size_t)1 << 0)
#define BLOCK_FLAG_PREV_FREE ((size_t)1 << 1)
#define BLOCK_FLAG_MASK ((size_t)0xF)
#define BLOCK_SIZE_MASK (~BLOCK_FLAG_MASK)
#define ALLOC_NUM_SIZE_CLASSES (68)
#define INITIAL_HEAP_SIZE (4194304) // 4 MiB
#define LARGE_ALLOC_THRESHOLD (1u << 20) // 1 MiB
#define SMALL_ALLOC_THRESHOLD (16384) // 16 KiB
#define RUN_SIZE (16384) // 16 KiB

_Static_assert((ALLOC_ALIGNMENT & (ALLOC_ALIGNMENT - 1)) == 0);
_Static_assert(RUN_SIZE % ALLOC_ALIGNMENT == 0);
_Static_assert(INITIAL_HEAP_SIZE % ALLOC_ALIGNMENT == 0);
_Static_assert((RUN_SIZE & (RUN_SIZE - 1)) == 0);

#endif //MCMALLOC_DEFS_H
