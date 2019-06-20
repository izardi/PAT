#include <cstdio>
#include <iostream>
using namespace std;

struct Node{
    string data;
    int lc, rc;
} Tree[22];

string DFS(int root){
    if(Tree[root].lc == -1 && Tree[root].rc == -1) return Tree[root].data;
    if(Tree[root].lc == -1 && Tree[root].rc) return "(" + Tree[root].data + DFS(Tree[root].rc) + ")";
    if(Tree[root].lc && Tree[root].rc ) return ("(" + DFS(Tree[root].lc) + Tree[root].data + DFS(Tree[root].rc) + ")");
}
int main(){
    //freopen("d.txt", "r", stdin);
    int N; // N <= 20
    scanf("%d\n", &N);
    int arr[25] = {0};
    for(int i = 1; i <= N; ++i){
        cin >> Tree[i].data;
        scanf("%d %d\n",  &Tree[i].lc, &Tree[i].rc);
        arr[Tree[i].lc] = arr[Tree[i].rc] = 1;
    }
    int root;
    for(int i = 1; i <= N; ++i)
        if(arr[i] == 0){
            root = i;
            break;
        }
    string res = DFS(root);
    if(res[0] == '(') res = res.substr(1, res.size()-2);
    cout << res;
    return 0;
}
