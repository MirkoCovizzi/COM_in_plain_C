//
// Created by Mirko on 30-Aug-20.
//

#ifndef COM_EXAMPLE_IEXAMPLE_H
#define COM_EXAMPLE_IEXAMPLE_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 80

struct IExampleStruct;

typedef long SetStringPtr(struct IExampleStruct *, char *);
typedef long GetStringPtr(struct IExampleStruct *, char *, long);

typedef struct {
    SetStringPtr *SetString;
    GetStringPtr *GetString;
} IExampleVtbl;

typedef struct IExampleStruct {
    const IExampleVtbl *lpVtbl;
    unsigned long count;
    char buffer[SIZE];
} IExample;

long SetString(IExample *this, char *str) {
    uint32_t i;

    i = strlen(str);
    if (i > SIZE - 1)
        i = SIZE - 1;
    memcpy(this->buffer, str, i);
    this->buffer[i] = 0;

    return 0;
}

long GetString(IExample *this, char *buffer, long length) {
    uint32_t i;

    i = strlen(this->buffer);
    if (i > length - 1)
        i = length - 1;
    memcpy(buffer, this->buffer, i);
    buffer[i] = 0;

    return 0;
}

static const IExampleVtbl IExample_Vtbl = {SetString, GetString};

#endif //COM_EXAMPLE_IEXAMPLE_H
