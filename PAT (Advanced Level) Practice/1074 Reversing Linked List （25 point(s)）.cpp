#include <cstdio>

struct Node{
    int data;
    int next;
}List[100005];

int main(){
    // freopen("data.in", "r", stdin);
    int head, N, K, tmp;
    scanf("%d %d %d", &head, &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d", &tmp);
        scanf("%d %d", &List[tmp].data, &List[tmp].next);
    }

    N = 0;
    for(tmp = head; tmp != -1; N++, tmp = List[tmp].next);
    
    int cnt = N / K;
    int pre, cur, next, tmprear;
    next = head;
    int rear = 100004;
    List[rear].next = head;
    while(cnt--){
        pre = -1;
        for(int i = 0; i < K; ++i){
            if(!i)
                tmprear = next;
            cur = next;
            next = List[next].next;
            List[cur].next = pre;
            pre = cur;
            if(i == K-1){
                List[rear].next = cur;
                rear = tmprear;
            }
        }
    }

    List[rear].next = next;
    for(head = List[100004].next; List[head].next != -1; head = List[head].next)
        printf("%05d %d %05d\n", head, List[head].data, List[head].next);
    printf("%05d %d -1", head, List[head].data);
    return 0;
}