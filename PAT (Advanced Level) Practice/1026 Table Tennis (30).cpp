#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
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

int main(){
    int N;
    int i, j, h, m, s;
    scanf("%d", &N);
    int len = 0;
    for( i = 0; i < N; i++ ){
        scanf("%d:%d:%d %d %d", &h, &m, &s, &array[len].PT, &array[len].vip);
        if(h >= 21) continue;
        array[len].AT = h*3600 + m*60 + s;
        if(array[len].PT > 120) array[len].PT = 120;
        array[len].PT *= 60;
        len++;
    }
    int table_num, idx_vip, viptable_num;
    scanf("%d %d", &table_num, &viptable_num);
    for(i = 1; i <= table_num; i++){
        table[i].ET = 28800;
        table[i].vip = 0;
        table[i].SN = 0;
    }
    for(i = 0; i < viptable_num; i++){
        scanf("%d", &idx_vip);
        table[idx_vip].vip = 1;
    }
    //读入完毕
    sort(array, array+len, cmp);
    for(i = 0; i < len ; i++){
        int havevip = 0, minTime = 123456789, minidx;
        for(j = 1; j <= table_num; j++){
            if(table[j].ET < minTime){
                minTime = table[j].ET;
                minidx = j;
                if(table[j].vip) havevip = j;
                else havevip = 0;
            }
            else if(table[j].ET == minTime)
                if(table[j].vip)
                    havevip = j;
        }//找到最早结束的并且判断是否是vip如果有同时结束的找到第一个vip的桌子
        if(table[minidx].ET >= 75600) break;
        int early_cus;
        int flag = 0;
        for(j = 0; j < len ; j++){
            if(vis[j]) continue;
            if(!flag){
                early_cus = j;
                flag = 1;
            }
            if(array[j].AT <= minTime){
                if(array[j].vip){
                    early_cus = j;
                    break;
                }
            }
            else break;
        }//找到最先服务的人
        vis[early_cus] = true;
        printf("%02d:%02d:%02d ", array[early_cus].AT/3600, array[early_cus].AT%3600/60,
               array[early_cus].AT%60);
        if(array[early_cus].vip && havevip){//最先服务的人是vip并且有vip位子
            if(array[early_cus].AT >= table[havevip].ET ){//最早服务的来时桌子闲着
                printf("%02d:%02d:%02d ", array[early_cus].AT/3600, array[early_cus].AT%3600/60,
                       array[early_cus].AT%60);
                printf("0\n");
                table[havevip].ET = array[early_cus].AT + array[early_cus].PT;
            }else{//最早服务的来时桌子没闲着要等待
                printf("%02d:%02d:%02d ", table[havevip].ET/3600, table[havevip].ET%3600/60,
                       table[havevip].ET%60);
                printf("%d\n", (table[havevip].ET-array[early_cus].AT + 30)/60);
                table[havevip].ET += array[early_cus].PT;
            }
            table[havevip].SN++;
        }
        else{//只有上面的一种情况才能用vip 特权剩下的一律平等都坐minidx
            if(array[early_cus].AT >= table[minidx].ET ){//最早服务的来时桌子闲着
                printf("%02d:%02d:%02d ", array[early_cus].AT/3600, array[early_cus].AT%3600/60,
                       array[early_cus].AT%60);
                printf("0\n");
                table[minidx].ET = array[early_cus].AT + array[early_cus].PT;
            }else{//最早服务的来时桌子没闲着要等待
                printf("%02d:%02d:%02d ", table[minidx].ET/3600, table[minidx].ET%3600/60,
                       table[minidx].ET%60);
                printf("%d\n", (table[minidx].ET-array[early_cus].AT+30)/60);
                table[minidx].ET += array[early_cus].PT;
            }
            table[minidx].SN++;
        }
    }
    for(i = 1; i <= table_num; i++){
        if( i == 1) printf("%d", table[i].SN);
        else printf(" %d", table[i].SN);
    }
    return 0;
}