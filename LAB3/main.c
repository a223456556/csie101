#include <stdio.h>

typedef struct person
{
    int id;
    char fname[32];
    char lname[32];
    
}per_t;

int main()
{
    FILE *wfp = fopen("person.bin","w");
    per_t p[5]= 
    {
        {1,"IU","LEE"},{2,"IUU","LEE"},{3,"IUUU","LEE"},{4,"IUUUU","LEE"},{5,"IUUUUU","LEE"}    
    };
    for(int j= 0;j<5;j++)
    {
        fwrite(p+j,sizeof(per_t),1,wfp);
    }
    fclose(wfp);
    FILE *rfp = fopen("person.bin","r");
    per_t tmp;
    int i= 0;
    while(i<5)
    {
        fread(&tmp,sizeof(per_t),1,rfp);
        printf("[%d] %d: %s %s\n",i,tmp.id,tmp.fname,tmp.lname);
        i++;
    }
    fclose(rfp);
}
