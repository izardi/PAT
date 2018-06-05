#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int array[100001] = {0};
    int max_n;
    int max_id = 0, max_count = 0;
    while(N--){
        int id, score;
        scanf("%d %d", &id, &score);
        array[id] += score;
        if(id > max_id)
            max_id = id;
    }
    for(int i =1; i <= max_id; i++){
        if(array[i]>max_count){
            max_count = array[i];
            max_n = i;
        }
    }
    printf("%d %d", max_n, max_count);
    return 0;
}