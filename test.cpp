#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int tmp[N];
    stack<int> st;
    int i, j;
    while(K--){
        for(i = 0; i < N; i++)
            scanf("%d", &tmp[i]);
        bool flag = true;
        j = 0;
        for(i = 0; i < N; i++){
            st.push(i+1);
            if(st.size() > M){
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == tmp[j]){
                st.pop();
                j++;
            }
        }

