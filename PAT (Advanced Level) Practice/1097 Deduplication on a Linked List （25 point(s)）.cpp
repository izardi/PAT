#include <cstdio>
#include <cmath>

struct A{
    int key;
    int next;
};

void print(A * arr, int curAdd){
    while(curAdd != -1){
        if(arr[curAdd].next !=-1)
            printf("%05d %d %05d\n", curAdd, arr[curAdd].key, arr[curAdd].next);
        else
            printf("%05d %d %d\n", curAdd, arr[curAdd].key, arr[curAdd].next);
        curAdd = arr[curAdd].next;
    }
}

int main()
{
    int FirstAdd, N;
    scanf("%d %d", &FirstAdd, &N);

    int hash[10005] = {0};
    int tmp_add, tmp_key, tmp_next;

    A arr[100005];
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d", &tmp_add, &tmp_key, &tmp_next);
        arr[tmp_add].key = tmp_key;
        arr[tmp_add].next = tmp_next;
    }

    int DuplicateAdd = -1;
    int flag = 1;
    hash[(int)fabs(arr[FirstAdd].key)] = 1;
    int alast = FirstAdd;
    int curAdd = arr[FirstAdd].next;
    arr[FirstAdd].next = -1;
  int dlast = 0;
    while( curAdd != -1){
        if(hash[(int)fabs(arr[curAdd].key)] == 0){
            hash[(int)fabs(arr[curAdd].key)] = 1;
            arr[alast].next = curAdd;
            alast = curAdd;
            curAdd = arr[alast].next;
            arr[alast].next = -1;
        }
        else{
            if(flag){
                DuplicateAdd = curAdd;
                dlast = curAdd;
                curAdd = arr[dlast].next;
                arr[dlast].next = -1;
                flag = 0;
            }
            else{
                arr[dlast].next = curAdd;
                dlast = curAdd;
                curAdd = arr[dlast].next;
                arr[dlast].next = -1;
            }
        }
    }

    print(arr, FirstAdd);
    print(arr, DuplicateAdd);
    return 0;
}