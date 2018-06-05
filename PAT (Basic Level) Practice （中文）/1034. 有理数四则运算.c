#include <stdio.h>

long gcd(long a, long b){
    return b==0 ? a : gcd(b, a%b);
}

typedef struct rationalNumber_{
    long n,d,s;
}RN;

RN reduct(RN rn){
    if(rn.n< 0){rn.s *=-1; rn.n *=-1;}
    long tmp = gcd(rn.n, rn.d);
    rn.n /= tmp;
    rn.d /= tmp;
    return rn;
}

void printRn(RN rn){
    if(rn.d == 0)
        printf("Inf");
    else{
        long i = rn.n/rn.d;
        rn.n = rn.n%rn.d;
        rn = reduct(rn);
        if(rn.n ==0 && i ==0) printf("0");
        else{
            if(rn.s == -1) printf("(-");
            if(i != 0) printf("%ld",i);
            if(i !=0 && rn.n != 0) printf(" ");
            if(rn.n !=0) printf("%ld/%ld", rn.n, rn.d);
            if(rn.s == -1) printf(")");
        }
    }
}
void printEq(RN a, RN b, char c, RN (*fig)(RN,RN)){
    printRn(a);
    printf(" %c ", c);
    printRn(b);
    printf(" = ");
    printRn(reduct((*fig)(a,b)));
    printf("\n");
}

RN plus(RN a, RN b) {return (RN){a.s*a.n*b.d+b.s*b.n*a.d, a.d*b.d, 1};}
RN sub(RN a, RN b) {return (RN){a.s*a.n*b.d-b.s*b.n*a.d, a.d*b.d, 1};}
RN multi(RN a, RN b) {return (RN){a.n*b.n, a.d*b.d, a.s*b.s};}
RN divis(RN a, RN b) {return (RN){a.n*b.d, a.d*b.n, a.s*b.s};}

int main(){
    RN a = {0,0,1}, b ={0,0,1}, (*fig[])(RN, RN) = {plus, sub, multi, divis};
    char c[5] = "+-*/";
    scanf("%ld/%ld %ld/%ld", &a.n, &a.d, &b.n, &b.d);
    for(int i =0; i <4; i++)
        printEq(reduct(a), reduct(b), c[i], fig[i]);
    return 0;
}