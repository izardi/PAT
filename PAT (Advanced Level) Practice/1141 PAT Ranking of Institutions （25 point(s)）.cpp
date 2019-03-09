#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct Node{
    string name;
    int num;
    double score;
    Node(){
        score = num = 0;
    }
}Sch[100005];

bool cmp(struct Node a, struct Node b){
    if((int)a.score != (int)b.score)
        return (int)a.score > (int)b.score;
    else if(a.num != b.num)
        return a.num < b.num;
    else return a.name < b.name;
}

int main(){
//    freopen("data.in", "r", stdin);
    string id, school;
    int N, score, idx = 1;
    scanf("%d\n", &N);
    map<string, int> mp;
    while(N--){
        cin >> id;
        scanf("%d ", &score);
        cstdion >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if(mp[school] == 0){
            mp[school] = idx++;
            Sch[mp[school]].name = school;
        }

        Sch[mp[school]].num++;
        if(id[0] == 'T')
            Sch[mp[school]].score += score*1.5;
        else if(id[0] == 'A')
            Sch[mp[school]].score += score;
        else Sch[mp[school]].score += score/1.5;
    }

    printf("%d\n", idx-1);
    sort(Sch+1, Sch + idx, cmp);
    int cur = 1;
    printf("1 %s %d %d\n", Sch[1].name.c_str(), (int)Sch[1].score, Sch[1].num);
    for(int i = 2; i < idx; ++i){
        if((int)Sch[i].score == (int)Sch[i-1].score)
            printf("%d ", cur);
        else{
            printf("%d ", i);
            cur = i;
        }
        printf("%s %d %d\n", Sch[i].name.c_str(), (int)Sch[i].score, Sch[i].num);
    }
    return 0;
}
