#include "mcmalloc.h"
#include <stddef.h>
#include "internal/block.h"
#include "internal/defs.h"
#include "internal/free.h"
#include "internal/os_interface.h"

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
