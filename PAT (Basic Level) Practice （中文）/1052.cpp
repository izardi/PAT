#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);

    char s[10];
    int cnt = 0;
    char ch, tmp;
    int pre = 0;
    for(int i = 0; i < 3; ++i){
        while((ch = getchar()) != '\n'){
            if(ch == ']') printf("%c", tmp);
            tmp = ch;
        }
        printf("\n");
    }

//    int N, k;
//    scanf("%d", &N);
//    while(N--){
//        for(int i = 0; i < 5; ++i){
//            scanf("%d",&k);
//            if(i < cnt){
//                printf("%c", s[k]);
//            }
//        }
//        printf("\n");
//    }
   // printf("Are you kidding me? @\\\/@");
    return 0;
}
