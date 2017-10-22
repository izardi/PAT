#include <stdio.h>
struct{
    int win;
    int lose;
    int array[3];
}p1,p2;
int Max3(int A, int B, int C ){
    return A > B ? A > C ? A : C : B > C ? B: C;
}
char judge(char tmp1, char tmp2){
    switch(tmp1) {
        case 'J':
            switch(tmp2){
                case 'J': return '0';
                case 'C': return tmp2;
                case 'B': return tmp1;
            }
        case 'C':
            switch(tmp2){
                case 'J': return tmp1;
                case 'C': return '0';
                case 'B': return tmp2;
            }
        case 'B':
            switch(tmp2){
                case 'J': return tmp2;
                case 'C': return tmp1;
                case 'B': return '0';
            }
    }
}
void finger(int array[]){
    int j = array[0],c = array[1], b=array[2];
    int max = Max3(j,c,b);
    if(max == b) printf("B");
    else if(max == c) printf("C");
    else printf("J");
}

int main(){
    int N;
    char tmp1, tmp2;
    scanf("%d", &N);
    for(int i=0; i< N; i++){
        scanf("\n%c %c",&tmp1, &tmp2);
        char result = judge(tmp1,tmp2);
        if(result == tmp1){
            if(result-'J'== 0) p1.array[0]++;
            else if(result-'C' == 0) p1.array[1]++;
            else p1.array[2]++;
            p1.win++;
            p2.lose++;
        }else if(result == tmp2){
            if(result-'J'== 0) p2.array[0]++;
            else if(result-'C' == 0) p2.array[1]++;
            else p2.array[2]++;
            p1.lose++;
            p2.win++;
        }
    }
    printf("%d %d %d\n",p1.win,N-p1.win-p1.lose,p1.lose);
    printf("%d %d %d\n",p2.win,N-p2.win-p2.lose,p2.lose);
    finger(p1.array);
    printf(" ");
    finger(p2.array);
    return 0;
}
