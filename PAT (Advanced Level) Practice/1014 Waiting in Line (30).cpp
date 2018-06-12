#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int w, cap, cus, k;
    scanf("%d %d %d %d", &w, &cap, &cus, &k);
    queue<int> Q[22];
    int tmp, minidx;
    int Time[1005] = {0};
    int t[22] = {0};
    int sertime[1005] = {0};
    for(int i = 1; i <= cus; i++){
        scanf("%d", &tmp);
        sertime[i] = tmp;
        minidx = 1;
        for(int j = 1; j <= w; j++){
            if(i <= w*cap){
                if(Q[minidx].size() > Q[j].size())
                    minidx = j;
            }
            else if(Q[minidx].front() > Q[j].front())
                minidx = j;
        }
        t[minidx] += tmp;
        Q[minidx].push(t[minidx]);
        Time[i] = t[minidx];
        if(i > w*cap) Q[minidx].pop();
    }
    while(k--){
        scanf("%d", &tmp);
        if((Time[tmp] - sertime[tmp]) >= 540)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", Time[tmp]/60 + 8, Time[tmp]%60);
    }
    return 0;
}
