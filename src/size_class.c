//
// Created by mcsam on 10/4/26.
//

#include "internal/size_class.h"
#include <stddef.h>


size_t class_index(const size_t size) {
    size_t low = 0;
    size_t high = sizeof size_classes / sizeof size_classes[0];

    while (low < high) {
        const size_t mid = low + ((high - low) / 2);

        if (size <= size_classes[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
