#include <stdio.h>
int main() {
    char Narray[9999];
    int ptr;
    char charOfNum, charOfPtr;
    scanf("%c", &charOfNum);
    char c;
    int i = 0;
    scanf("%c", &c);
    while (c != 'E') {
        if (c != '.')
            Narray[i++] = c;
        scanf("%c", &c);
    }
    scanf("%c", &charOfPtr);
    scanf("%d", &ptr);
// read finished
    if (charOfNum == '-')
        printf("-");
    if (charOfPtr == '+') {
        int j;
        if(ptr < i) {
            for (j = 0; j < ptr + 1; j++)
                printf("%c", Narray[j]);
            if (j < i) {
                printf(".");
                for (int k = j; k < i; k++)
                    printf("%c", Narray[k]);
            }
        }else{
            for(j=0; j<i; j++)
                printf("%c",Narray[j]);
            for(int k=j; k<=ptr;k++)
                printf("0");
        }
    }else {
        if (ptr == 0) {
            printf("%c.", Narray[0]);
            for (int j = 1; j < i; j++) {
                printf("%c", Narray[j]);
            }
        } else {
            int j;
            printf("0.");
            for (j = 1; j < ptr; j++)
                printf("0");
            for (j = 0; j < i; j++)
                printf("%c", Narray[j]);
        }
    }
    return 0;
}
