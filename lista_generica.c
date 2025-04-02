#include <stdio.h>
#include <stdlib.h>

int soma (int A, int B);
int sub (int A, int B);
void exec (int A, int B, int (*func) (int, int));

int main()
{
    int a=1,b=2;
    exec(a,b,soma);
    printf("\n");
    exec(a,b,sub);
    return 0;
}

int soma (int A, int B)
{
    return A + B;
}
int sub (int A, int B)
{
    return A - B;
}
void exec (int A, int B, int (*func) (int, int))
{
    printf("%d",func(A,B));
}