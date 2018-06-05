#include <stdio.h>
#include <stdlib.h>
typedef struct Node* LNode;
struct Node{
    int Address;
    int Data;
    int NextAddress;
    LNode next;
};
int main(){
    int FirstAddress;
    int N, K;
    LNode Head;
    Head = (LNode)malloc(sizeof(struct Node));
    Head -> next = NULL;
    LNode tmpHeadPtr = Head;
    scanf("%d %d %d", &FirstAddress, &N, &K);
    for(int i=0; i<N; i++){
        LNode tmpNode = (LNode)malloc(sizeof(struct Node));
        scanf("%d %d %d", &tmpNode->Address, &tmpNode->Data, &tmpNode->NextAddress);
        tmpNode->next = NULL;
        tmpHeadPtr->next = tmpNode;
        tmpHeadPtr = tmpNode;
    } //read finished
    //sort
    int count = 0;
    LNode tmpList = (LNode)malloc(sizeof(struct Node));
    tmpList->next=NULL;
    LNode tmpListPtr = tmpList;
    int FindAddress = FirstAddress;
    while(FindAddress != -1){
        tmpHeadPtr = Head;
        while(tmpHeadPtr->next) {
            if (tmpHeadPtr->next->Address == FindAddress) {
                count++;
                tmpListPtr->next = tmpHeadPtr->next;
                tmpListPtr = tmpListPtr->next;
                tmpHeadPtr->next = tmpHeadPtr->next->next;
                FindAddress = tmpListPtr->NextAddress;
            }else{
                tmpHeadPtr = tmpHeadPtr->next;
            }
        }
    }
    tmpListPtr->next = NULL;
    Head = tmpList;
    // srot complated!
    //reverse
    tmpList = (LNode)malloc(sizeof(struct Node));
    tmpList->next = NULL;
    tmpListPtr = tmpList;
    tmpHeadPtr = Head;
    LNode tail,tmpNode;
    while(count >= K){
        count -= K;
        for(int i =0; i<K; i++){
            tmpListPtr->next = tmpHeadPtr->next;
            tmpHeadPtr->next = tmpHeadPtr->next->next;
            if(i==0)
                tail = tmpListPtr->next;
            else
                tmpListPtr->next->next = tmpNode;
            tmpNode = tmpListPtr->next;
        }
        tmpListPtr = tail;
    }
    tmpListPtr->next = Head->next;
    Head = tmpList->next;

    while(Head->next){
        printf("%05d %d %05d\n", Head->Address, Head->Data, Head->next->Address);
        Head = Head->next;
    }
    printf("%05d %d -1", Head->Address,Head->Data);
    return 0;
}
