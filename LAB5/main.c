#include <stdio.h>
int add(int x,int y)
{
    return x+y;
    
}
int sub(int x,int y)
{
   return x-y;
}
int mul(int x,int y)
{
    return x*y;
}
int div(int x,int y)
{
    return x/y;
}
int calc(int(*function_ptr)(int,int),int x,int y)
{
    return function_ptr(x,y);
}
int main()
{
    printf("sum = %d\n",calc(add,4,2));
    printf("dif = %d\n",calc(sub,4,2));
    printf("product = %d\n",calc(mul,4,2));
    printf("quotient = %d\n",calc(div,4,2));

    return 0;
}
