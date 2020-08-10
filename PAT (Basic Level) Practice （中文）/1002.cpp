#include <cstdio>
#include <cstring>

int main(){
    freopen("in", "r", stdin);
    char arr[101];
    scanf("%s", arr);
    int sum = 0;
    char num[10][5] = {"ling","yi","er","san","si",
                        "wu","liu", "qi", "ba", "jiu"};
    for(int i = 0; i <(int)strlen(arr); ++i)
        sum += arr[i] - '0';
    char idx[4];
    sprintf(idx, "%d", sum);
    for(int i = 0; i < (int)strlen(idx); ++i){
        if(i != 0) printf(" ");
        printf("%s", num[idx[i] - '0']);
    }
    return 0;
}