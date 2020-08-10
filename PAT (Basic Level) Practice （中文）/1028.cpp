#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d/n", &N);
    char tmp[6], oldest[6], youngest[6];
    int cnt = 0;
    int y, m, d, day;
    int today = 20140906;
    int oldday = today;
    int lastday = 18140906;
    int youngday = lastday;
    for(int i = 0; i < N; ++i){
        scanf("%s %d/%d/%d/n", tmp, &y, &m, &d);
        day = y*10000 + m*100 + d;
        if(day <= today && day >= lastday){
            ++cnt;
            if(day >= youngday){
                youngday = day;
                strcpy(youngest, tmp);
            }
            if(day <= oldday){
                oldday = day;
                strcpy(oldest, tmp);
            }
        }
    }
    if(cnt)
        printf("%d %s %s", cnt, oldest, youngest);
    else printf("0");
    return 0;
}
