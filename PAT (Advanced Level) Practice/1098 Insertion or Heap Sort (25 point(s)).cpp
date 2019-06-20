#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    freopen("data.in", "r", stdin);
    int N, fir[105], sec[105];
    scanf("%d", &N);
    int i, j;
    for(i = 0; i < N; ++i)
    	scanf("%d", &fir[i]);
    for(i = 0; i < N; ++i)
    	scanf("%d", &sec[i]);
    for(i = 0; i < N - 1 && sec[i] <= sec[i+1]; ++i);
    for(j = 0; j < N && fir[j] == sec[j]; ++j);
    if(j == N){
    	printf("Insertion Sort\n");
    	sort(fir, fir+i+2);
    }else{
    	printf("Heap Sort\n");
    	int k = N-1;
    	while(true){
    		int flag = 0;
    		for(i = 0; i < N; ++i)
    			if(fir[i] != sec[i])
    				break;
    		
    	}
    }
}