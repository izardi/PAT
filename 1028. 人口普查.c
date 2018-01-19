#include <stdio.h>
#include <string.h>

int main(){
    char tmp[6];
    int year, month, day;
    char Old[6], Young[6];
    int N = 0, count = 0;
    int old = 20140907;
    int young = 18140905;
    scanf("%d", &N);

    while(N--){
        scanf("%s %d/%d/%d", tmp, &year, &month, &day);
        int num = year*10000 + month*100 + day;
        if(num >= 18140906 && num <= 20140906){
            if(num < old){
                strcpy(Old, tmp);
                old = num;
            }
            if(num > young){
                strcpy(Young, tmp);
                young = num;
            }
            count++;
        }
    }
    if(count)
        printf("%d %s %s\n", count, Old, Young);
    else
        printf("0\n");
    return 0;
}