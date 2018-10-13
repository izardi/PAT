#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int N, i, cnt = 0, tmp, a[100001];
    scanf("%d", &N);

    for(i = 0; i < N; ++i){
        scanf("%d", &tmp);
        a[tmp] = i;
    }

    for(i = 1; i < N; ++i){
        if(i != a[i]){
            while(a[0] != 0){
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if( i != a[i]){
                swap(a[0], a[i]);
                cnt++;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}