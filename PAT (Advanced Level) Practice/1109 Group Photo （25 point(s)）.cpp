#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    string name;
    int height;
    
    bool operator < (Node & b){
        if(height != b.height)
            return height > b.height;
        else
            return name < b.name;
    }
};
int main(){
    int N, K, M;
    Node arr[10005];
    scanf("%d %d", &N, &K);
    // central = m / 2 + 1
    for(int i = 0; i < N; ++i)
        cin >> arr[i].name >> arr[i].height;

    sort(arr, arr+N);
    
    int curRow = K;
    int idx = 0;
    while(curRow){
        if(curRow == K)
            M = N - N/K*(K-1);
        else M = N/K;
        vector<string> ans(M);
        
        int mid = M/2;
        ans[mid] = arr[idx].name;
        int j = mid - 1;
        for(int i = idx+1; i < idx + M; i += 2)
            ans[j--] = arr[i].name;
        j = mid + 1;
        for(int i = idx+2; i < idx + M; i += 2)
            ans[j++] = arr[i].name;

        cout << ans[0];
        for(int i = 1; i < M; ++i)
            cout << " " << ans[i];
        cout << endl;
        curRow--;
        idx += M;
    }
    return 0;
}
