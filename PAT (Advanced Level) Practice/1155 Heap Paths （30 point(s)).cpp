#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
int isHeap = 1;
int isMinH = -1;
int N, arr[10005];

void DFS(int idx){
    if(idx > N){
        int pre = path[0];
        printf("%d", pre);
        for(int i = 1; i < path.size(); ++i){
            printf(" %d", path[i]);
            if(pre < path[i]){
                if(isMinH == -1)
                    isMinH = 1;
                else if(isMinH == 0)
                    isHeap = 0;
            }
            else{
                if(isMinH == -1)
                    isMinH = 0;
                else if(isMinH == 1)
                    isHeap = 0;
            }
            pre = path[i];
        }
        printf("\n");
    }else{
        path.push_back(arr[idx]);
        if(idx*2+1 <= N)
            DFS(idx*2+1);
        DFS(idx*2);
        path.pop_back();
    }
}

int main(){
    // freopen("data.in", "r", stdin);
    fill(arr, arr+10005, -1);
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &arr[i]);
    DFS(1);

    if(isHeap){
        if(isMinH) printf("Min Heap\n");
        else printf("Max Heap\n");
    }
    else printf("Not Heap");

    return 0;
}
