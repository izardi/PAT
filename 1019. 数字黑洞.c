#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define bit 4
#define Kaprekar 6174
int strTonum(const char *array){
    int num = 0;
    for(int i=0; i<bit; i++)
        num = num*10+(array[i]-'0');
    return num;
}
void numToStr(int num, char *array){
    for(int i=bit-1;i >=0; i--){
        array[i] = (num %10) + '0';
        num = num/10;
    }
}
char* strMaxSort(char *array){
    for(int i=0; i< bit-1; i++){
        for(int j=i+1; j<bit; j++){
            if(array[j] > array[i]){
                char tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    return array;
}
char* strMinSort(char* array){
    for(int i=0; i< bit-1; i++){
        for(int j=i+1; j<bit; j++){
            if(array[j] < array[i]){
                char tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
    return array;
}
bool isSame(const char* array){
    if(array[0] == array[1] && array[2] == array[3] && array[1] == array[2]) {
        return 1;
    }
    return 0;
}
int main(){
    char *array = (char*)malloc(bit*sizeof(char));
    int i=0;
    char c;
    scanf("%c", &c);
    while(c !='\n'){
        array[i++] = c;
        scanf("%c", &c);
    }
    while(i != bit){
        array[i++] = '0';
    }
    int max, min, result=0;
    if(isSame(array)) {
        printf("%d - %d = 0000", strTonum(array), strTonum(array));
    }
    else{
        while(result != Kaprekar){
            max = (strTonum(strMaxSort(array)));
            min = (strTonum(strMinSort(array)));
            result = max - min;
            printf("%04d - %04d = %04d\n",max,min,result);
            numToStr(result,array);
        }
    }
    return 0;
}
