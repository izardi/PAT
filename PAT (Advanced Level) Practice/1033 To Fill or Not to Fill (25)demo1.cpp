#include <cstdio>
#include <algorithm>
using namespace std;

double capacity, distances, run_per_unit;
int N;

struct Node{
    double price;
    double dist;
}station[510];

bool cmp(const struct Node & a, const struct Node & b){
    return a.dist < b.dist;
}

int main(){
    scanf("%lf %lf %lf %d", &capacity, &distances, &run_per_unit, &N);
    int i;
    double price, dist;
    int n_station = 0;
    for(i = 0; i < N; i++){
        scanf("%lf %lf", &price, &dist);
        if(dist >= distances)//不读入无用数据
            continue;
        station[n_station].price = price;
        station[n_station++].dist = dist;
    }
    station[n_station].price = 123456789.0;//最后一站不可能加油
    station[n_station].dist = distances;
    
    sort(station, station+n_station+1, cmp);
    if(station[0].dist != 0){//起点没加油站直接输出
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double cost = 0, maxdist = 0;
    double full_dist = capacity*run_per_unit;
    double curr_unit = 0;
    double tempdist;
    i = 0;
    
    while(maxdist < distances){
        double minPrice = station[i].price;
        //当 i= n_station 时maxdist == distances 所以 i < n_station;
        int j = i + 1;
        if((station[j].dist - station[i].dist) > full_dist){//当前加满也走不到下一站
            maxdist += full_dist;//余油能跑的路程记得加上
            break;
        }
        for( ;j <= n_station && (station[j].dist - station[i].dist) <= full_dist; j++)//寻找在当前站加满油后能跑最远的范围内第一个比当前站便宜或相等的加油
            if( minPrice >= station[j].price)
                break;
        if(j > n_station){//到最后也没找到便宜的但是能走出去
            if( (curr_unit * run_per_unit) < (station[j-1].dist- station[i].dist))//余油不能走出去
                cost += ((station[j-1].dist-station[i].dist)/run_per_unit-curr_unit)*station[i].price;//加最少的油
            maxdist = distances;
            break;
        }
        if(station[j].dist - station[i].dist > full_dist){//没找到距离范围内最便宜的或相等的就在当前站加满走到下一站在寻找便宜的或相等的
            tempdist = station[i+1].dist - station[i].dist;
            maxdist += tempdist;
            cost += (capacity - curr_unit)*station[i].price;
            curr_unit = capacity - tempdist/run_per_unit;
            i += 1;
        }
        else{//找到距离范围内便宜的或相等的只加够到的油到j站
            tempdist = station[j].dist - station[i].dist;
            maxdist += tempdist;
            if(curr_unit*run_per_unit + station[i].dist < station[j].dist){//余油不够只加刚好到j的油
                cost += (tempdist/run_per_unit - curr_unit)*station[i].price;
                curr_unit = 0;
            }else
                curr_unit -= tempdist/run_per_unit;
            i = j;
        }
    }
    if( maxdist < distances)
        printf("The maximum travel distance = %0.2lf", maxdist);
    else
        printf("%0.2lf",cost);
    return 0;
}