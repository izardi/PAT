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
    for(int i=0; i<6; i++){
        LNode tmpNode = (LNode)malloc(sizeof(struct Node));
        scanf("%d %d %d", &tmpNode->Address, &tmpNode->Data, &tmpNode->NextAddress);
        tmpNode->next = NULL;
        tmpHeadPtr->next = tmpNode;
        tmpHeadPtr = tmpHeadPtr->next;
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
    LNode tmpHead = (LNode)malloc(sizeof(struct Node));
    tmpHead->next = NULL;
    tmpHeadPtr = tmpHead;
    LNode tmp = Head;
    LNode tail, tmpOld;
    while(count >=K){
        count -= K;
        for(int i=0; i< K; i++){
            tmpHeadPtr->next = tmp->next;
            tmp->next = tmp->next->next;
            if(i==0)
                tail = tmpHeadPtr->next;
            else
                tmp->next->next = tmpOld;
            tmpOld = tmpHeadPtr->next;
        }
        tmpHeadPtr = tail;
    }
    tmpHeadPtr->next = Head->next;
    tmpHeadPtr = tmpHead->next;

    while(tmpHeadPtr->next){
        printf("%05d %d %05d\n", tmpHeadPtr->Address, tmpHeadPtr->Data, tmpHeadPtr->next->Address);
        tmpHeadPtr = tmpHeadPtr->next;
    }
    printf("%05d %d -1", tmpHeadPtr->Address,tmpHeadPtr->Data);
    return 0;
}
