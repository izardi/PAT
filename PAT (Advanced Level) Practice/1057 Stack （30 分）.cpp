#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

int BIT[100001] = {0};

int lowbit(int n){
    return n&(-n);
}

void update(int idx, int val){
    while(idx <= 100001){
        BIT[idx] += val;
        idx += lowbit(idx);
    }
}

int getSum(int idx){
    int sum = 0;
    while (idx > 0){
        sum += BIT[idx];
        idx -= lowbit(idx);
    }
    return sum;
}
int binSearch(int key){
    int left = 0, right = 100001;
    int mid;
    while(left <= right){
        mid = left + (right-left)/2;
        int tmp = getSum(mid);
        if(tmp > key)
            right = mid - 1;
        else if(tmp < key)
            left = mid+1;
        else
            right = mid - 1;
    }
    return left;
}

int main(){
    int N, tmp;
    scanf("%d", &N);
    stack<int> st;
    char ope[11];
    while(N--){
        scanf("%s", ope);
        if(ope[1] == 'o'){
            if(st.empty()) printf("Invalid\n");
            else{
                tmp = st.top();
                st.pop();
                printf("%d\n", tmp);
                update(tmp, -1);
            }
        }
        else if(ope[1] == 'u'){
            scanf("%d", &tmp);
            st.push(tmp);
            update(tmp, 1);
        }
        else{
            if(st.empty()) printf("Invalid\n");
            else{
                tmp = binSearch((int)(st.size() + 1)/2);
                printf("%d\n", tmp);
            }
        }
    }
    return 0;
}

