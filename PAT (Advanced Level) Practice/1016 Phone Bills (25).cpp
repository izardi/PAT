#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
    char name[21];
    int month, day, hour, minute;
    int time;
    bool status;
    bool operator < (const Node & b) const{
        if(!strcmp(name, b.name)) {
            if (month != b.month)
                return month < b.month;
            else
                return time < b.time;
        }
        return strcmp(name, b.name) < 0;
    }
} bill[1010];

int main(){
    int rate[24];
    for(int &i : rate)
        scanf("%d", &i);
    int cost[1441] = {0};
    for(int i = 1; i <= 1440; i++)
        cost[i] = cost[i-1] + rate[(i-1)/60];

    int N;
    scanf("%d", &N);
    char tmp[21];
    for(int i = 0; i < N; i++){
        scanf("%s %d:%d:%d:%d %s", bill[i].name, &bill[i].month, &bill[i].day, &bill[i].hour, &bill[i].minute, tmp);
        bill[i].time = bill[i].day*24*60 + bill[i].hour*60 + bill[i].minute;
        bill[i].status = (tmp[1] == 'n') ? true : false;
    }
    sort(bill, bill+N);
    bool flag = true;
    int money = 0, total_money = 0, time = 0;
    for(int i = 1; i < N; i++) {
        if (!strcmp(bill[i].name, bill[i - 1].name)) {
            if (!bill[i].status && bill[i - 1].status) { //匹配成功
                //处理时间 钱
                time = bill[i].time - bill[i-1].time;
                if (bill[i].minute + bill[i].hour*60 > bill[i-1].minute + bill[i-1].hour*60)
                    money = (bill[i].day - bill[i-1].day) * cost[1440] +
                            (cost[bill[i].minute + bill[i].hour*60] -
                             cost[bill[i-1].minute + bill[i-1].hour*60]);
                else
                    money = (bill[i].day - 1 - bill[i - 1].day) * cost[1440] +
                            (cost[1440] + cost[bill[i].minute + bill[i].hour * 60] -
                             cost[bill[i-1].minute + bill[i-1].hour*60]);
                total_money += money;
                if (money != 0) {
                    if (flag)
                        printf("%s %02d\n", bill[i].name, bill[i].month);//打印名字月份
                    flag = false;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02lf\n", bill[i - 1].day, bill[i - 1].hour,
                           bill[i - 1].minute, bill[i].day, bill[i].hour, bill[i].minute, time, money / 100.0);
                }
            }
        } else {
            if (total_money != 0)
                printf("Total amount: $%.02lf\n", total_money / 100.0);
            flag = true;
            total_money = 0;
        }
    }
    if(total_money != 0)
        printf("Total amount: $%.02lf\n", total_money / 100.0);
    return 0;
}
