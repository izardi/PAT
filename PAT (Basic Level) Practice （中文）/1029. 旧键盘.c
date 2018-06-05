#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char a[81], b[81], c[81];
    scanf("%s %s", a, b);

    int i = 0, j = 0, k = 0;
    int count = 0, flag = 0;

    for (i =0; i < strlen(a); i++){
        flag =0;
        if((a[i] == b[j]) && j < strlen(b))
            j++;
        else {
            if (islower(a[i]))
                a[i] = toupper(a[i]);
            for (k = 0; k < count; k++) {
                if (a[i] == c[k]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                c[count++] = a[i];
        }
    }

    for(k = 0; k < count; k++)
        printf("%c", c[k]);
    return 0;
}