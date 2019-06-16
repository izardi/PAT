#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> mp;

struct Node{
    string plate;
    int flag;
    //1 in 2 out
    int time;
} Records[10005];

struct Car{
    string plate;
    int intime, leavetime;
    int staytime;
} Leaves[10005];
bool cmp1(int &a, int &b){
    return Leaves[a].plate < Leaves[b].plate;
}
bool cmp(struct Node & a, struct Node & b){
    return a.time < b.time;
}
//in 必须与out匹配不没有in不out没有out不in
//最后一行输出听的时间最长的所有车牌号

void printTime(int t){
    printf("%02d:%02d:%02d", t / 3600, t%3600/60, t%3600%60);
}

int main(){

    freopen("d.txt", "r", stdin);

    int N, K; //N = records K = queries
    scanf("%d %d\n", &N, &K);

    string plate;
    int h, m, s;
    char status[4];
    for(int i = 1; i <= N; ++i){
        cin >> Records[i].plate;
        scanf("%d:%d:%d ", &h, &m, &s);
        scanf("%s\n", status);
        Records[i].time = h*3600+m*60+s;
        Records[i].flag = (status[0] == 'i' ? 1 : 2);
    }
    sort(Records+1, Records + N + 1, cmp);
    //所有记录都按照时间的向后顺序
    //有一个记录记录paired车的离开时间以及停留时间从而计算结果
    map<string, int> mpL;//标记Leaves对列中出现的便于计算staytime
    int cnt = 1;
    for(int i = 1; i <= N; ++i){
        if(mp[Records[i].plate] == 0){
            if(Records[i].flag == 1) // 如果在mp中没有记录并且是in给分配一个cnt
                mp[Records[i].plate] = i; 
        } else {
            if(Records[i].flag == 1)// 有记录的话要看是这个record是in还是out in覆盖 out直接匹配并且移除待匹配标识
                    mp[Records[i].plate] = i;//覆盖
            else{
                Leaves[cnt].plate = Records[i].plate; //匹配并且填入记录
                Leaves[cnt].leavetime = Records[i].time;
                Leaves[cnt].intime = Records[mp[Records[i].plate]].time;
                Leaves[cnt].staytime = Records[i].time - Records[mp[Records[i].plate]].time;
                if(mpL[Leaves[cnt].plate] != 0){
                    Leaves[cnt].staytime += Leaves[mpL[Leaves[cnt].plate]].staytime;
                }
                mpL[Leaves[cnt].plate] = cnt;
                mp[Records[i].plate] = 0; // 清楚待匹配标识
                ++cnt;
            }
        }
    }
    
    vector<int> vec;
    int maxi = 0;
    while(K--){
        int res = 0;
        scanf("%d:%d:%d", &h, &m, &s);
        int time = h*3600+m*60+s;
        for(int i = 1;  i <= cnt ; ++i){
            if( time >= Leaves[i].intime && time < Leaves[i].leavetime)
                ++res;
        }
        printf("%d\n", res);
    }
    for(int i = 1; i <= cnt; ++i){
        if(maxi <= Leaves[i].staytime){
            if(maxi != Leaves[i].staytime)
                vec.clear();
            maxi = Leaves[i].staytime;
            vec.push_back(i);
        }
    }
    sort(vec.begin(), vec.end(), cmp1);

    printf("%s", Leaves[vec[0]].plate.c_str());
    for(int i = 1; i < vec.size(); ++i)
        printf(" %s", Leaves[vec[i]].plate.c_str());
    printf(" ");
    printTime(maxi);

    return 0;
}
