#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    string id;
    int arr[3];
    int num;
};
bool cmp(Node a, Node b){
    if(a.arr[0] != b.arr[0])
        return a.arr[0] > b.arr[0];
    else if(a.num != b.num)
        return a.num < b.num; 
    else return a.id < b.id;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    char id[7], s[7];
    int score;
    int cnt = 1;
    double tmp;
    unordered_map<string, int> mp;
    vector<Node> ans;

    while(N--){
        scanf("\n%s %d %s", id, &score, s);
        for(int i = 0; i < strlen(s); ++i)
            s[i] = tolower(s[i]);
        if(!mp[string(s)]){
            mp[string(s)] = cnt++;
            ans.push_back({string(s), {0,0,0}, 0});
        }
        int idx = mp[string(s)]-1;
        ++ans[idx].num;
        if(id[0] == 'B')ans[idx].arr[0] += score;
        else if(id[0] == 'A')ans[idx].arr[1] += score;
        else ans[idx].arr[2] += score;
    }
    for(int i = 0; i < cnt-1; ++i){
        ans[i].arr[0] = ans[i].arr[0]/1.5 + ans[i].arr[1]
            + ans[i].arr[2]*1.5;
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", cnt-1);
    int pre = ans[0].arr[0];
    int prer = 1;
    for(int i = 0; i < cnt-1; ++i){
        if(pre != ans[i].arr[0]){
            pre = ans[i].arr[0];
            prer = i+1;
        }
        printf("%d", prer);
        printf(" %s %d %d\n", ans[i].id.c_str(), 
                ans[i].arr[0], ans[i].num);
    }
    return 0;
}
