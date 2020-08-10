#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node{
    string name;
    int Gp, Gm, Gf, G;
}T[10001];
bool cmp(struct Node a, struct Node b){
    if(a.G != b.G)
        return a.G > b.G;
    else
        return a.name < b.name;
}

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int p, m, n;
    scanf("%d %d %d", &p, &m, &n);
    char s[22];
    int score;
    unordered_map<string, int> mp;
    while(p--){
        scanf("\n%s %d", s, &score);
        if(score >= 200) mp[string(s)] = score;
    }
    unordered_map<string, int> mpp;
    while(m--){
        scanf("\n%s %d", s, &score);
        if(mp[string(s)]){
            mpp[string(s)] = score;
        }
    }
    vector<Node> res;
    int cnt = 0;
    while(n--){
        scanf("\n%s %d", s, &score);
        int G = 0;
        if(score < mpp[string(s)])
            G = mpp[string(s)] * 0.4 + score * 0.6 + 0.5;
        else G = score;
        if(mpp[string(s)] == 0) mpp[string(s)] = -1; 
        if(G >= 60 && mp[string(s)] >= 200) res.push_back({string(s), mp[string(s)], mpp[string(s)], score, G});
    }
    sort(res.begin(), res.end(), cmp);
    for(auto it = res.begin(); it != res.end(); ++it)
        printf("%s %d %d %d %d\n", it->name.c_str(), it->Gp, it->Gm, it->Gf, it->G);
    return 0;
}
