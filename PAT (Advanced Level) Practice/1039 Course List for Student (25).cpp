#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int str_to_num(const char* str){
    return ((str[0]-'A')*26*26 + (str[1]-'A')*26 + (str[2]-'A'))*10 + str[3]-'0';  
}
struct Node* array[200000] = {NULL};

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    char tmp[5];
    struct Node* rear;
    for(int i = 0; i < K; i++){
        int idx, num;
        scanf("%d %d", &idx, &num);
        for(int j = 0; j < num; j++){
        scanf("%s", tmp);
        struct Node* tmpNode = (struct Node*)malloc(sizeof(struct Node));
        tmpNode->data = idx;
        tmpNode->next = NULL;
            if(!array[str_to_num(tmp)]){
            array[str_to_num(tmp)] = tmpNode; 
        }
        else{
            tmpNode->next = array[str_to_num(tmp)];
            array[str_to_num(tmp)] = tmpNode;   
        }      
        }   
    }
    for(int i = 0; i < N; i++){
        scanf("%s", tmp);
        printf("%s", tmp);
        int count = 0;
        rear = array[str_to_num(tmp)];
    int tmparray[2500];
        while(rear){
            tmparray[count++] = rear->data;
            rear = rear->next;      
    }
    printf(" %d", count);
    if(count){
            sort(tmparray, tmparray+count);
            for(int j = 0; j < count; j++)
        printf(" %d", tmparray[j]);     
    }
    if(i != N-1)
        printf("\n");
    }

    for(int i = 0; i < 200000; i++){
    rear = array[i];
    while(rear){
            array[i] = rear->next;
        free(rear); 
        rear = array[i];    
    }
    }
    return 0;
}
