/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
    int id;
    char name[10];
    int age;
    char phone[12];
    float salary;
}employee_t;

void employee_info(employee_t my_emp)
{
    printf("員工編號 :%d\n",my_emp.id);
    printf("員工姓名 :%s\n",my_emp.name);
    printf("員工年齡 :%d\n",my_emp.age);
    printf("員工手機 :%s\n",my_emp.phone);
    printf("員工薪水 :%f\n",my_emp.salary);
    
}
int main()
{
    employee_t a;
    a.id = 66;
    strcpy(a.name,"Levi");
    a.age = 30;
    strcpy(a.phone,"0912345678");
    a.salary = 3000;
    
    employee_info(a);
    
    return 0;
}
