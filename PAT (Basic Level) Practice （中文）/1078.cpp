#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char ch, pre;
    int cnt = 0;
    scanf("%c\n", &ch);
    pre = getchar();
    if(ch == 'C'){
        cnt = 1;
        do{
            ch = getchar();
            if(ch != pre){
                if(cnt != 1){
                    printf("%d", cnt);
                }
                printf("%c", pre);
                cnt = 1;
            }
            else ++cnt;
            pre = ch;
        }while(ch != '\n');
    }
    else{
        do{
            ch = getchar();
            if(pre >= '0' && pre <= '9')
                cnt = cnt*10 + pre - '0';
            else{
                printf("%c", pre);
                for(int i = 0; i < cnt-1; ++i)
                    printf("%c", pre);
                cnt = 0;
                pre = ch;
            }
            pre = ch;
        }while(ch != '\n');
    }
    return 0;
}
