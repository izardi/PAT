#include <cstdio>
struct Node{
    int flag;
    char c;
    int next;
} array[100000];


int main(){
    int st1, st2, N;
    scanf("%d %d %d", &st1, &st2, &N);
    int idx;
    for(int i = 0; i < N; i++){
        scanf("%d ", &idx);
        scanf("%c %d", &array[idx].c, &array[idx].next);
        array[idx].flag = 0;
    }
    for(int i = st1; i != -1; i = array[i].next)
        array[i].flag = 1;
    for(int i = st2; i != -1; i = array[i].next)
        if(array[i].flag == 1){
            printf("%05d", i);
            return 0;
        }
    printf("-1");
    return 0;
}