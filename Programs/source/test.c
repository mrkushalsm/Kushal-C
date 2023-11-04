#include <stdio.h>

int test()
{
    return 1, 2;
}

void main()
{
    int num = test();
    printf("%d", num);
}