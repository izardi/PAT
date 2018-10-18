#include <cstdio>
#include <algorithm>
using namespace std;

struct Node{
    char name[11];
    char id[11];
    int grade;
    bool operator < (const struct Node & a){
        return grade > a.grade;
    }
};

int main(){
    int N, i;
    scanf("%d", &N);
    struct Node rec[N];
    int grade1, grade2;
    for(i = 0; i < N; ++i)
        scanf("%s %s %d", rec[i].name, rec[i].id, &rec[i].grade);
    scanf("%d %d", &grade1, &grade2);
    int cnt = 0;
    for(i = 0; i < N; ++i){
        if(rec[i].grade < grade1 || rec[i].grade > grade2)
            rec[i].grade = -1;
        else ++cnt;
    }
    sort(rec, rec + N);
    if(cnt){
        for(i = 0; i < cnt; ++i)
            printf("%s %s\n", rec[i].name, rec[i].id);
    }
    else printf("NONE");
    return 0;
}