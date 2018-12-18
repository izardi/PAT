#include <cstdio>
#include <algorithm>
using namespace std;
const int _CAP = 100005;
int main(){
    int i, N, arr[_CAP], brr[_CAP];
    scanf("%d", &N);
    for(i = 0; i < N; ++i){
        scanf("%d", &arr[i]);
		brr[i] = arr[i];
	}
	sort(arr, arr + N);
    int res[_CAP], cnt = 0, max = 0;
	for( i = 0; i < N; ++i){
		if(arr[i] == brr[i] && brr[i] > max)
			res[cnt++] = brr[i];
		if(brr[i] > max)
			max = brr[i];
	}
	//还有一种用空间换时间的算法加入一个数组存放当前i右边最小的数
	//对结果排序即可
	printf("%d\n", cnt);
	for(i = 0; i < cnt; ++i){
		if(i != 0) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n"); //莫名奇妙
    return 0;
}