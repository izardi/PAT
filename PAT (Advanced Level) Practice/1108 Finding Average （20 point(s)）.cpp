#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int N, cnt = 0;
    char s1[50], s2[50];
    double res = 0, tmp;
    scanf("%d", &N);
    
    for(int i = 0; i < N; ++i){
        scanf("%s", s1);
        sscanf(s1, "%lf", &tmp);
        sprintf(s2, "%.2lf", tmp);
        int flag = 0;
        for(int j = 0; j < strlen(s1); ++j)
            if(s1[j] != s2[j])
                flag = 1;
        if(flag || tmp < -1000 || tmp > 1000){
            printf("ERROR: %s is not a legal number\n", s1);
        }
        else{
            res += tmp;
            ++cnt;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2lf\n", res);
    else if (cnt > 1)
        printf("The average of %d numbers is %.2lf\n", cnt, res/cnt);
    else printf("The average of 0 numbers is Undefined\n");
    return 0;
}
