#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu{
    char id[7];
    char name[9];
    int grade;
} stu[100010];

bool cmp1(Stu &a, Stu &b){ return strcmp(a.id, b.id) < 0;}
bool cmp2(Stu &a, Stu &b){ if(strcmp(a.name, b.name)) return strcmp(a.name, b.name) < 0;
                            else return strcmp(a.id, b.id) < 0;}
bool cmp3(Stu &a, Stu &b){ if(a.grade != b.grade) return a.grade < b.grade;
                            else return strcmp(a.id,b.id) < 0;}
int main(){
    int N, C;
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++)
        scanf("%s %s %d",stu[i].id, stu[i].name, &stu[i].grade);
    switch(C){
        case 1:
            sort(stu, stu+N, cmp1);
            break;
        case 2:
            sort(stu, stu+N,cmp2);
            break;
        case 3:
            sort(stu, stu+N,cmp3);
            break;
    }
    for(int i = 0; i < N; i++)
        printf("%s %s %d\n",stu[i].id, stu[i].name, stu[i].grade);
    return 0;
}