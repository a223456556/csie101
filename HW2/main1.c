#include<stdio.h>
#include<math.h>
#include <time.h>

int SIZE=7;

void GenerateNumber(int *l_num);

int main()
{
    srand(time(NULL));  
    int n;
    int *l_num;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char wday[7][10] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
    char wmon[12][10] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug","Sep","Oct","Nov","Dec"};
    l_num=(int*)malloc(SIZE*sizeof(int));
    FILE *fp;
    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return -1;
    }
    printf("你要買幾張:");
    scanf("%d", &n);
    
    fprintf(fp, "======== lotto649 =========\n");
 fprintf(fp, "= %s %s %d %d:%02d:%02d %d=\n",  wday[tm.tm_wday],wmon[tm.tm_mon + 1], tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_year + 1900);
    for(int i=0;i<n;i++)
    {
        fprintf(fp, "\n[%d]: ",i+1);
        GenerateNumber(l_num);
        for(int j=1;j<SIZE;j++)
        {
         if(l_num[j]<10)
   {
       fprintf(fp, "0%d ", l_num[j]); 
   }
   else
   {
    fprintf(fp, "%d ", l_num[j]); 
   }
        }
        if(l_num[0]<10)
  {
   fprintf(fp, "0%d ", l_num[0]); 
  }
  else
  {
   fprintf(fp, "%d ", l_num[0]); 
  }
    }
    fprintf(fp, "\n======== CSIE@CGU =========");
    // 關閉檔案
    fclose(fp);
    free(l_num);
    return 0;
} 

void GenerateNumber(int *l_num)
{
    int i,j,duplicate,isNew;
    for (i = 1; i < SIZE; i++) 
    {
        do 
        {
            l_num[i] = rand() % 69 + 1; 
            duplicate = 0;
            for (j = 1; j < i; j++) 
            {
                if (l_num[i] == l_num[j]) 
                {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
    }
    do 
    {
        isNew = 1;
        l_num[0]= rand() % 10+1; 
        for (i = 1; i < SIZE; i++) 
        {
            if (l_num[0] == l_num[i]) 
            {
                isNew = 0;
                break;
            }
        }
    } while (!isNew);
}
