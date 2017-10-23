#include <stdio.h>
#include <stdlib.h>
#define bit 4
int strTonum(char *array){
    int num = 0;
    for(int i=0; i<bit; i++)
        num = num*10+array[i];
    return num;
}
char* numTostr(char *array,int num){
    for(int i=0;i)

}
int main(){
    char *array = (char*)malloc(4*sizeof(char));
    for(int i=0; i<bit; i++)
        scanf("%c", array[i]);
}
