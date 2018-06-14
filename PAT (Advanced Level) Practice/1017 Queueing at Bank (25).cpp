#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int at, pt;
    bool operator < (const Node& b) const{
        return at < b.at;
    }
} cus[10000];

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int h, m, s;
    int cnt = 0;
    int wt = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &cus[cnt].pt);
        cus[cnt].at = h*3600+m*60+s;
        cus[cnt].pt *= 60;
        if(cus[cnt].at > 61200)
            --cnt;
        ++cnt;
    }
    sort(cus, cus+cnt);
    int windows[100] = {0};
    int minidx  = 0;
    for(int i = 0; i < cnt; i++) {
        minidx = 0;
        for (int j = 1; j < K; j++)
            if (windows[minidx] > windows[j])
                minidx = j;
        if (cus[i].at < 28800) {//cus i 太早需等待
            wt += (windows[minidx] + 28800 - cus[i].at);
            windows[minidx] += cus[i].pt;
        }
        else if (cus[i].at - 28800 > windows[minidx]) //cus i 比窗口的要晚
            windows[minidx] = (cus[i].at - 28800 + cus[i].pt);
        else {//cus i 比窗口早需等待
            wt += (windows[minidx] + 28800 - cus[i].at);
            windows[minidx] += cus[i].pt;
        }
    }
    printf("%.1lf\n", wt/60.0/cnt);
    return 0;
}