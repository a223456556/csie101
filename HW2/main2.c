#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_in, *fp_out;
    char ch;
    char func_name[] = "main()";
    int name_length = 6;  // 不包含 null 結尾字元 \0
    int count = 0;

    // 開啟檔案
    fp_in = fopen("main2.c", "r");
    if (fp_in == NULL) {
        printf("無法開啟檔案 main2.c\n");
        return -1;
    }
    fp_out = fopen("main2.txt", "w");
    if (fp_out == NULL) {
        printf("無法開啟檔案 main2.txt\n");
        fclose(fp_in);
        return -1;
    }

    // 讀取文字，直到找到 main() 函式
    while ((ch = fgetc(fp_in)) != EOF) {
        if (ch == func_name[count]) {
            count++;
            if (count == name_length) {
                // 找到 main() 函式，複製文字到檔案
                fprintf(fp_out, "/* main2.c */\n");
                while ((ch = fgetc(fp_in)) != EOF) {
                    fputc(ch, fp_out);
                }
                break;
            }
        } else {
            count = 0;
        }
    }

    // 關閉檔案
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

