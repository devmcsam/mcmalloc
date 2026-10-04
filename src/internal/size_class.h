//
// Created by mcsam on 10/4/26.
//
#pragma once
#ifndef MCMALLOC_SIZE_CLASS_H
#define MCMALLOC_SIZE_CLASS_H
#include <stddef.h>

// each size class gets a 16 KiB chunk in a small run. This does not coalesce with medium chunks.
static constexpr size_t small_size_classes[] = {
    16, 32, 48, 64, 80, 96, 112, 128,
    144, 160, 176, 192, 208, 224, 240, 256,
    288, 320, 352, 384, 416, 448, 480, 512,
    576, 640, 704, 768, 832, 896, 960, 1024,
    1152, 1280, 1408, 1536, 1664, 1792, 1920, 2048,
    2304, 2560, 2816, 3072, 3328, 3584, 3840, 4096,
    4608, 5120, 5632, 6144, 6656, 7168, 7680, 8192,
    9216, 10240, 11264, 12288, 13312, 14336, 15360, 16384
};

// This CAN NOT be called when size is greater than the largest size class. It must be handled previous to this function
// call.
size_t small_class_index(size_t size);

#endif //MCMALLOC_SIZE_CLASS_H
