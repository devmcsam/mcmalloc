#include "mcmalloc.h"
#include "internal/os_interface.h"
#include "internal/defs.h"
#include <stddef.h>

static void *heap_start = nullptr;

void *mcmalloc(const size_t size) {
    if (heap_start == nullptr) {
        void *mem = request_mem(INITIAL_HEAP_SIZE);
        if (mem == nullptr) {
            return nullptr;
        }
        heap_start = mem;
    }
    return nullptr;
}
