#include <stdlib.h>
#include <string.h>

void* myRealloc(void* ptr, int size) {
    void* new_ptr = malloc(size);
    if (ptr != NULL) memcpy(new_ptr, ptr, size);
    if (size == 0) free(new_ptr);
    free(ptr);
    return new_ptr;
}
