#include "iexample.h"

int main() {
    static const IExampleVtbl IExample_Vtbl = {SetString, GetString};

    IExample *example;

    example = (IExample *) GlobalAlloc(GMEM_FIXED, sizeof(IExample));

    example->lpVtbl = &IExample_Vtbl;
    example->count = 1;
    example->buffer[0] = 0;

    char buffer[80];

    example->lpVtbl->SetString("Some text");
    example->lpVtbl->GetString(buffer, sizeof(buffer));

    return 0;
}
