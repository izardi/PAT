#include <cstdio>
#include <cstring>
int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    char arr[100005];
    scanf("%s", arr);
    long res = 0;
    int t[100005]= {0}, p[100005] = {0};
    int len = strlen(arr);
    int pret = 0, prep = 0;
    for(int i = 0; i < len; ++i){
        if(arr[i] == 'P'){
            p[i] = prep+ 1;
            prep = p[i];
        }else p[i] = prep;
        if(arr[len-1-i] == 'T'){
            t[len-1-i] = pret + 1;
            pret = t[len-1-i];
        }else t[len-1-i] = pret;
    }
    for(int i = 1; i < len-1; ++i){
        if(arr[i] == 'A'){
            res += long(p[i]) * t[i];
            res %= 1000000007;
        }
    }
    printf("%ld", res);
    return 0;
}
