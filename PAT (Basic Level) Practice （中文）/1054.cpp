#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    
    int N, cnt = 0, len, flag;
    scanf("%d\n", &N);
    char s[50], tmp[50];
    double num, res = 0;
    while(N--){
        scanf("%s", s);
        getchar();
        sscanf(s, "%lf", &num);
        sprintf(tmp, "%.2lf", num);
        flag = 0;
        len = strlen(s);
        for(int i = 0; i < len; ++i)
            if(s[i] != tmp[i]){
                flag = 1;
                break;
            }
        if(flag || num < -1000 || num > 1000)
            printf("ERROR: %s is not a legal number\n", s);
        else{
            res += num;
            ++cnt;
        }
    }
    if(cnt == 1) printf("The average of 1 number is %.2lf", res);
    else if(cnt> 1) printf("The average of %d numbers is %.2lf", cnt, res/cnt);
    else printf("The average of 0 numbers is Undefined");
    return 0;
}
