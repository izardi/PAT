#include <stdio.h>
int main(){
    int array[10];
    for(int i=0; i< 10; i++)
        scanf("%d", &array[i]);
    int i =1;
    while(array[i++]==0);
    printf("%d",i-1);
    array[i-1] -= 1;
    for(i=0; i<10; i++)
        for(int j=0; j< array[i];j++)
            printf("%d", i);

    return 0;
}
