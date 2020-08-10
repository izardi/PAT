#include <cstdio>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    int N;
    scanf("%d", &N);
    char c1, c2;
    int w1[3] = {0}, w2[3] = {0};
    int win1 = 0, win2 = 0;
    for(int i = 0; i < N; ++i){
        scanf("\n%c %c", &c1, &c2);
        if(c1 == 'C'){
            if(c2 == 'J'){ ++win1; ++w1[0];}
            else if(c2 == 'B'){ ++win2; ++w2[2];}
        }
        else if(c1 == 'J'){
            if(c2 == 'B'){ ++win1; ++w1[1];}
            else if(c2 == 'C'){ ++win2; ++w2[0];}
        }
        else {
            if(c2 == 'C'){ ++win1; ++w1[2];}
            else if(c2 == 'J') { ++win2; ++w2[1];}
        }
    }
    printf("%d %d %d\n", win1, N-win1-win2, win2);
    printf("%d %d %d\n", win2, N-win1-win2, win1);
    int m1 = 2;
    if(w1[m1] < w1[0]) m1 = 0;
    if(w1[m1] < w1[1]) m1 = 1;
    int m2 = 2;
    if(w2[m2] < w2[0]) m2 = 0;
    if(w2[m2] < w2[1]) m2 = 1;
    char c[] = "CJB";
    printf("%c %c", c[m1], c[m2]);
    return 0;
}
