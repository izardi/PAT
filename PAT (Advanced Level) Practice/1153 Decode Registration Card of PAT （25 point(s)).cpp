#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node{
    string id;
    int value;  
} Stu[10005];

bool cmp(struct Node & a, struct Node & b){
    if(a.value != b.value)
        return a.value > b.value;
    return a.id < b.id;
}

int main(){
//    freopen("data.in", "r", stdin);
    int N, M, n;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i)
        cin >> Stu[i].id >> Stu[i].value; 
    string str;
    for(int i = 1; i <= M; ++i){
        vector<struct Node> ans;
        cin >> n >> str; 
        printf("Case %d: %d %s\n", i, n, str.c_str());
        int flag = 0;
        if(n == 1){
            for(int i = 0; i < N; ++i)
                if(Stu[i].id[0] == str[0]){
                    ans.push_back(Stu[i]);
                    flag = 1;
                }
        } else if(n == 2){
            int sum = 0, cnt = 0;
            for(int i = 0; i < N; ++i)
                if(Stu[i].id.substr(1, 3) == str){
                    flag = 1;
                    sum += Stu[i].value;
                    ++cnt;
                }
            if(flag) printf("%d %d\n", cnt, sum); 
        } else {
            map<string, int> mp;  
            for(int i = 0; i < N; ++i)
                if(str == Stu[i].id.substr(4,6)){
                    mp[Stu[i].id.substr(1,3)]++;
                    flag = 1;
                }
            for(auto it = mp.begin(); it != mp.end(); ++it) ans.push_back({it->first, it->second});
        }
        if(!flag) printf("NA\n");
        else {
            sort(ans.begin(), ans.end(), cmp);
            for(int i = 0; i < ans.size(); ++i)
                printf("%s %d\n", ans[i].id.c_str(), ans[i].value);
        }
    }
    return 0;
}
