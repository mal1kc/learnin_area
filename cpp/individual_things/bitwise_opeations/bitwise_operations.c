#include <stdio.h>

void printBinSimple(int n)
{
    unsigned int i;
    if (n <= 1)
    {
        if (n == 1)
            printf("1 in binary : 1");
        else if (n == 0)
            printf("0 in binary : 0");
        else
        {
            printf("%d in binary : -", n);
            n = -n;
            for (i = 1; i <= n; i = i << 1)
            {
                if (n & i)
                    printf("1");
                else
                    printf("0");
            }
        }
    }
    else
    {
        printf("%d in binary : ", n);
        for (i = 1; i <= n; i = i << 1)
        {
            if (n & i)
                printf("1");
            else
                printf("0");
        }
    }
    printf("\n");
}

int main()
{

    unsigned int a = 60; /* 60 = 0011 1100 */
    unsigned int b = 13; /* 13 = 0000 1101 */
    int c = 0;

    c = a & b; /* 12 = 0000 1100 */
    printf("Line 1 - Value of c is %d\n", c);

    c = a | b; /* 61 = 0011 1101 */
    printf("Line 2 - Value of c is %d\n", c);

    c = a ^ b; /* 49 = 0011 0001 */
    printf("Line 3 - Value of c is %d\n", c);

    c = ~a; /*-61 = 1100 0011 */
    printf("Line 4 - Value of c is %d\n", c);

    c = a << 2; /* 240 = 1111 0000 */
    printf("Line 5 - Value of c is %d\n", c);

    c = a >> 2; /* 15 = 0000 1111 */
    printf("Line 6 - Value of c is %d\n", c);
    printf("\n");
    return 0;
}