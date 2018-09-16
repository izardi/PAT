#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int i, M, N, K, j;
    scanf("%d%d%d", &M, &N, &K);
    stack<int> st;
    int tmp[N];

    while(K--){
        for(i = 0; i < N; i++)
            scanf("%d", &tmp[i]);
        while(!st.empty())
            st.pop();
        j = 0;
        for(i = 1; i <= N; i++){
            st.push(i);
            if(st.size() > M)
                break;
            while(!st.empty() && st.top() == tmp[j]){
                st.pop();
                j++;
            }
        }
        if(!st.empty()) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
