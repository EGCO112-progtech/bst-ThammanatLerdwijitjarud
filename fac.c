#include <stdio.h>

int fac(int n)
{
    int fac=1;
    while(n>1)
    {
        fac = fac*n;
        n--;
    }
    return fac;
}

