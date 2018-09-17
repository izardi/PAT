#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node{
    char name[9];
    int age, worth;
    bool operator < (const struct Node& b){
        if(worth != b.worth)
            return worth > b.worth;
        else if( age != b.age)
            return age < b.age;
        else
            return strcmp(name, b.name) < 0;
    }
};

int main(){
    int i, j, N, K;
    scanf("%d %d", &N, &K);
    struct Node array[100001];
    for(i = 0; i < N; i++)
        scanf("%s %d %d", array[i].name, &array[i].age, &array[i].worth);
    sort(array, array+N);

    bool flag;
    int M, Amin, Amax;
    for(i = 1; i <= K; i++){
        printf("Case #%d:\n", i);
        flag = true;
        scanf("%d %d %d", &M, &Amin, &Amax);
        int count = 0;
        for( j = 0; j < N && count < M; j++){
            if(array[j].age >= Amin && array[j].age <= Amax){
                flag = false;
                count++;
                printf("%s %d %d\n", array[j].name, array[j].age, array[j].worth);
            }
        }
        if(flag)
            printf("None\n");
    }
    return 0;
}
