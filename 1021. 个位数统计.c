#include <stdio.h>
int main() {
    char i;
    int array[10];
    for(int i=0; i< 10; i++){
        array[i] = 0;
    }

    while(scanf("%c", &i) != EOF){
        array[i-'0']++;
    }
    for(int i=0; i< 10; i++){
        if(array[i] != 0){
            printf("%d:%d\n",i,array[i]);
        }
    }
    return 0;
}
