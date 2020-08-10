#include <cstdio>
#include <cstring>
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    char s[81];
    int len;
    while(N--){
        scanf("\n%s", s);
        len = strlen(s);
        if(len < 6){ 
            printf("Your password is tai duan le.\n");
            continue;
        }
        int sz = 0, zm = 0;
        int i = 0;
        for(i = 0; i < len; ++i){
            if(s[i] >= '0' && s[i] <= '9')
                sz = 1;
            else if((s[i] >= 'a' && s[i] <= 'z') ||
                    (s[i] >= 'A' && s[i] <= 'Z'))
                zm = 1;
            else if(s[i] != '.'){
                printf("Your password is tai luan le.\n");
                break;
            }
        }
        if(i == len){
            if(sz == 0)
                printf("Your password needs shu zi.\n");
            else if(zm == 0)
                printf("Your password needs zi mu.\n");
            else printf("Your password is wan mei.\n");
        }
    }
    return 0;
}
