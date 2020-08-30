//
// Created by Mirko on 30-Aug-20.
//

#ifndef COM_EXAMPLE_IEXAMPLE_H
#define COM_EXAMPLE_IEXAMPLE_H

#include <windows.h>

typedef long SetStringPtr(char *);
typedef long GetStringPtr(char *, long);

typedef struct {
    SetStringPtr *SetString;
    GetStringPtr *GetString;
} IExampleVtbl;

typedef struct {
    const IExampleVtbl *lpVtbl;
    DWORD count;
    char buffer[80];
} IExample;

long SetString(char *str) {
    return 0;
}

long GetString(char *buffer, long length) {
    return 0;
}

#endif //COM_EXAMPLE_IEXAMPLE_H
