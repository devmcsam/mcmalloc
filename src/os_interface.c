//
// Created by mcsam on 10/3/26.
//

#include "internal/os_interface.h"
#include <stddef.h>
#include <sys/mman.h>

void *request_mem(const size_t size) {
    void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        return nullptr;
    }
    return mem;
}
