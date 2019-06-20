#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    string id;
    int A, B;
} Stu[1006];
int main(){
    // freopen("d.in", "r", stdin);
    int N;
    scanf("%d", &N);
    int ht[1005] = {0};
    for(int i = 1; i <= N; ++i){
        cin >> Stu[i].id >> Stu[i].A >> Stu[i].B;
        ht[Stu[i].A] = i;
    }
    scanf("%d", &N);
    int tmp;
    while(N--){
        scanf("%d", &tmp);
        cout << Stu[ht[tmp]].id << " " << Stu[ht[tmp]].B << endl;
    }
    return 0;
}