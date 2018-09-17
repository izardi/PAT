#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node{
    int address, data, next;
    bool operator < (struct Node& b){
        return data < b.data;
    }
};

int main(){
    int N, headidx;
    scanf("%d %d", &N, &headidx);
    if(headidx == -1){
        printf("0 -1");
        return 0;
    }

    int i, tmp_address;
    struct Node array[100001];
    struct Node linklist[100001];

    for(i = 0; i < N; i++){
        scanf("%d", &tmp_address);
        scanf("%d %d", &array[tmp_address].data, &array[tmp_address].next);
        array[tmp_address].address = tmp_address;
    }

    i = headidx;
    int count = 0;
    while(i != -1){
        linklist[count++] = array[i];
        i = array[i].next;
    }
    sort(linklist, linklist + count);

    printf("%d %05d\n", count, linklist[0].address);
    for(i = 0; i < count - 1; i++)
        printf("%05d %d %05d\n", linklist[i].address, linklist[i].data, linklist[i+1].address);
    printf("%05d %d -1", linklist[count-1].address, linklist[count-1].data);
    return 0;
}
