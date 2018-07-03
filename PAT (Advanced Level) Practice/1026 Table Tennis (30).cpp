#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    int AT;
    int PT;
    int vip;
} array[10001];
bool vis[10001] = {false};
struct TNode{
    int ET;
    int vip;
    int SN;
} table[102];

int cmp(const struct Node & a, const struct Node & b){ return a.AT < b.AT; }
void printTime(int time){ printf("%02d:%02d:%02d ", time/3600, time%3600/60, time%60); }

int main(){
    int N, i, j, x, y, z, len = 0;
    scanf("%d", &N);
    for( i = 0; i < N; i++ ){
        scanf("%d:%d:%d %d %d", &x, &y, &z, &array[len].PT, &array[len].vip);
        if(x >= 21) continue;
        array[len].AT = x*3600 + y*60 + z;
        if(array[len].PT > 120) array[len].PT = 120;
        array[len++].PT *= 60;
    }
    scanf("%d %d", &x, &y);
    for(i = 1; i <= x; i++) table[i] = {28800, 0, 0};
    for(i = 0; i < y; i++){ scanf("%d", &z); table[z].vip = 1; }
    //读入完毕
    sort(array, array+len, cmp);
    for( i = 0; i < len; ){
        if(!vis[i]){
            int early_cus = i, mini, flag = 1, vip = 0, minTime = 123456789, minidx;
            for(j = 1; j <= x; j++){
                if(table[j].ET < minTime){
                    minTime = table[j].ET;
                    minidx = j;
                    if(table[j].vip){ vip = j; flag = 0; }
                    else { vip = 0; flag = 0; }
                }
                else if(flag && table[j].ET == minTime){ flag = 0; vip = j; }
            }//找桌子并且找相同时间的第一个vip桌子没有vip = 0
            if(table[minidx].ET >= 21 * 3600) break;
            
            for(j = i; j < len; j++)
                if(!vis[j]){
                    if(array[j].AT <= minTime && array[j].vip){
                        early_cus = j;
                        break;
                    }
                    else break;
                }//找最早服务的人
            
            if(array[early_cus].vip && vip) minidx = vip;
            for(j = i+1; j < len; j++)
                if(!vis[j]){
                    mini = j;
                    break;
                }
            
            if(array[early_cus].AT >= table[minidx].ET || array[early_cus].AT < 28800 ){
                printTime(array[early_cus].AT);
                printTime(table[minidx].ET);
                printf("%d\n", (table[minidx].ET-array[early_cus].AT+30)/60);
                table[minidx].ET = array[early_cus].AT + array[early_cus].PT;
                table[minidx].SN++;
            }else{//最早服务的来时桌子没闲着要等待
                for(j = 1; j <= x; j++)
                    if(table[j].ET < array[early_cus].AT)
                        table[j].ET = array[early_cus].AT;
                continue;
            }
            for(j = 1; j <= x; j++)
                if(table[j].ET < array[mini].AT)
                    table[j].ET = array[mini].AT;
            vis[early_cus] = true;
        }
        i++;
    }
    for(i = 1; i <= x; i++){
        if( i == 1) printf("%d", table[i].SN);
        else printf(" %d", table[i].SN);
    }
    return 0;
}