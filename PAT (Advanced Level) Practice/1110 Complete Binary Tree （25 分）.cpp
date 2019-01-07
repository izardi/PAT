#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

struct Node{
    int lchild;
    int rchild;
}TNode[25];

int main(){
    // freopen("data.in", "r", stdin);
    int N, hash[25] = {0}, tmp;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1[0] != '-'){
            tmp = stoi(s1.c_str());
            hash[tmp] = 1;
            TNode[i].lchild = tmp;
        }
        else TNode[i].lchild = -1;
        if(s2[0] != '-'){
            tmp = stoi(s2.c_str());
            hash[tmp] = 1;
            TNode[i].rchild = tmp;
        }
        else TNode[i].rchild = -1;
    }
    int root;
    for(root = 0; root < N; ++root)
        if(!hash[root])
            break;

    queue<int> Q;
    Q.push(root);
    bool flag = true;
    bool islast = false;
    while(!Q.empty()){
        tmp = Q.front();
        Q.pop();
        if(islast){
            if(TNode[tmp].lchild != -1 || TNode[tmp].rchild != -1){
                flag = false;
                break;
            }
        }else{
            if(TNode[tmp].lchild != -1){
                Q.push(TNode[tmp].lchild);
                if(TNode[tmp].rchild != -1)
                    Q.push(TNode[tmp].rchild);
                else islast = true;
            }else {
                islast = true;
                if(TNode[tmp].rchild != -1){
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag)
        printf("YES %d\n", tmp);
    else printf("NO %d\n", root);
    return 0;
}