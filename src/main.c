#include <stdio.h>
#include <stdlib.h>

#include "base/oci_base_inc.h"
#include "base/oci_base_inc.c"

typedef struct {
    i32 width;
    i32 height;
} Something;

int main() {
    usize buffer_size = 100;
    void *buffer = malloc(buffer_size);

    oci_Arena arena = {0};
    arena_init(&arena, buffer, buffer_size);

    Something *something = (Something*)arena_alloc(&arena, sizeof(Something));
    something->width = 10;
    something->height = 14;

    printf("Something->width: %d\n", something->width);
    printf("Something->height: %d\n", something->height);

    String8 str = str8_lit("lellele");
    printf("%s\n", str.str);

    arena_free_all(&arena);

    return 0;
}
