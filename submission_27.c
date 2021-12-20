#include <stdio.h>

int main()
{
    void    *a;
    void    *b;

    a = &b;
    b = &a;
    printf("%p\n", a);
    printf("%p\n", b);
    printf("%p\n", *(void**)b);
    printf("%p\n", *(void**)*(void**)b);
    printf("%p\n", *(void**)*(void**)*(void**)b);
    printf("%p\n", *(void**)*(void**)*(void**)*(void**)b);
    printf("%p\n", *(void**)*(void**)*(void**)*(void**)*(void**)b);
}
