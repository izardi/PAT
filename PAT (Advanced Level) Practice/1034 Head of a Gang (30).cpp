#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K;
const int LEN = 26*26*26;
vector<int> arr[LEN];
int sum[LEN] = {0};
bool vis[LEN] = {false};
vector<int> linkNode;

struct HeadNum{
    int name;
    int num;
    HeadNum(int _name, int _num){name = _name; num = _num;}

};
int str_to_int(const char* name){
    return (name[0]-'A')*26*26 + (name[1]-'A')*26 + name[2]-'A';
}

void int_to_str(int &n, char *s){
    s[0] = n/(26*26) + 'A';
    s[1] = (n/26)%26 + 'A';
    s[2] = n%26 + 'A';
    s[3] = '\0';
}
void dfs(int head){
    if(vis[head]) return;
    vis[head] = true;
    vector<HeadNum> res;

    int size = arr[head].size();
    for(int i = 0; i < size; i++)
        dfs(arr[head][i]);
    linkNode.push_back(head);
    return ;
}
HeadNum* isGang(const vector<int> & v){
    int s = v.size();
    if(s < 3) return NULL;
    int total = 0;
    int max = 0;
    int head = -1;
    for(int i = 0; i < s; i++){
        total += sum[v[i]];
        if(max < sum[v[i]]){
            max = sum[v[i]];
            head = v[i];
        }
    }
    if(total /2 <= K){
        return NULL;
    }else{
        return new HeadNum(head, s);
    }
}

int cmp (const HeadNum & a, const HeadNum & b){
    return a.name < b.name;
}

int main(){
    int i;
    cin >> N >> K;
    queue<int> node;
    vector<HeadNum> res;
    char name1[4], name2[4];
    int intname1, intname2, time;
    for(i = 0; i < N; i++){
        cin >> name1 >> name2 >> time;
        intname1 = str_to_int(name1);
        intname2 = str_to_int(name2);
        arr[intname1].push_back(intname2);
        arr[intname2].push_back(intname1);
        sum[intname1] += time;
        sum[intname2] += time;
        node.push(intname1);
    }
    HeadNum * head = NULL;
    while(!node.empty()){
        linkNode.clear();
        dfs(node.front());
        node.pop();
        head = isGang(linkNode);
        if(head)
            res.push_back(*head);
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    for(i = 0; i < res.size(); i++){
        int_to_str(res[i].name, name1);
        cout << name1 << ' ' << res[i].num << endl;
    }
    return 0;
}