#include <cstdio>

struct Node{
    int data, next;
} arr[100005];

int main(){
    int N, first, K, tmp;
    scanf("%d %d %d", &first, &N, &K);

    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        scanf("%d %d", &arr[tmp].data, &arr[tmp].next);
    }

    int FH = -1, SH = -1, TH = -1;
    int tmp_FH = -1, tmp_SH = -1, tmp_TH = -1;

    tmp = first;
    while(tmp != -1){
        first = arr[tmp].next;
        if(arr[tmp].data < 0){
            if(FH == -1) FH = tmp;
            else arr[tmp_FH].next = tmp;
            tmp_FH = tmp;
            arr[tmp_FH].next = -1;
        }
        else if(arr[tmp].data <= K){
            if(SH == -1) SH = tmp;
            else arr[tmp_SH].next = tmp;
            tmp_SH = tmp;
            arr[tmp_SH].next = -1;
        }
        else{
            if(TH == -1) TH = tmp;
            else arr[tmp_TH].next = tmp;
            tmp_TH = tmp;
            arr[tmp_TH].next = -1;
        }
        tmp = first;
    }

    if(TH != -1) tmp = TH;
    if(tmp_SH != -1){ arr[tmp_SH].next = tmp; tmp = SH;}
    if(tmp_FH != -1){ arr[tmp_FH].next = tmp; tmp = FH;}

    while(arr[tmp].next != -1){
        printf("%05d %d %05d\n", tmp, arr[tmp].data, arr[tmp].next);
        tmp = arr[tmp].next;
    }
    printf("%05d %d -1\n", tmp, arr[tmp].data);
    return 0;
}