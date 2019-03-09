#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
struct Node{
    string name;
    int op, GM, GF, G;
    Node(){
        GM = GF = -1;
        G = 0;
    }
}Stu[30006];

bool cmp(struct Node & a, struct Node & b){
    if(a.G != b.G)
        return a.G > b.G;
    return a.name < b.name;
}
int main(){
//    freopen("data.in", "r", stdin);
    int P, M, N;
    scanf("%d %d %d\n", &P, &M, &N);
    string name;
    int score;
    map<string, int> mp;
    int cnt = 1;
    for(int i = 0; i < P; ++i){
        cin >> name;
        scanf(" %d\n", &score);
        if(score >= 200){
            mp[name] = cnt;
            Stu[cnt].name = name;
            Stu[cnt++].op = score;
        }
    }
    for(int i = 0; i < M; ++i){
        cin >> name;
        scanf(" %d\n", &score);
        if(mp[name])
            Stu[mp[name]].GM = score;
    }
    for(int i = 0; i < N; ++i){
        cin >> name;
        scanf(" %d\n", &score);
        int idx = mp[name];
        if(idx)
            Stu[idx].GF = Stu[idx].G = score;
        if(Stu[idx].GM > Stu[idx].GF)
            Stu[idx].G = (Stu[idx].GM*0.4 + Stu[idx].GF*0.6 + 0.5);
    }
    sort(Stu, Stu+cnt, cmp);
    for(int i = 0; i < cnt; ++i)
        if(Stu[i].G >= 60)
            printf("%s %d %d %d %d\n", Stu[i].name.c_str(), Stu[i].op, Stu[i].GM, Stu[i].GF, Stu[i].G);
    return 0;
}
