#include <stdio.h>
#include <stdlib.h>
#include "iexample.h"

int main() {
    IExample *example;

    example = malloc(sizeof(IExample));

    example->lpVtbl = &IExample_Vtbl;
    example->count = 1;
    example->buffer[0] = 0;

    char buffer[80];

    example->lpVtbl->SetString(example, "Some text");
    example->lpVtbl->GetString(example, buffer, sizeof(buffer));

    printf("%lu\n", example->count);

    free(example);

    return 0;
}
