#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int W[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2,};
    char s[] = {"10X98765432"};
    char id[18];
    int N;
    int flag = 1;
    scanf("%d", &N);
    while(N--){
        scanf("\n%s", id);
        int sum = 0;
        int i;
        for(i = 0; i < 17; ++i){
            if(id[i] > '9' || id[i] < '0')
                break;   
            sum += (id[i]-'0')*W[i];
        }
        if(i != 17 || id[17] != s[sum%11]){
            printf("%s\n", id);
            flag = 0;
        }
    }
    if(flag) printf("All passed\n");
    return 0;
}
