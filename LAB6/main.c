#include <stdio.h>

int mul(int i, int j) 
{
    if (i == 9 && j == 9)
        printf("%d*%d=%d\n", i, j, i * j);
    else if (j == 9) {
        printf("%d*%d=%d\n", i, j, i * j);
        mul(i + 1, 1);
    } else {
        printf("%d*%d=%d ", i, j, i * j);
        mul(i, j + 1);
    }
}

int main() 
{
    mul(1, 1);
    return 0;
}
