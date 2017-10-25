#include <stdio.h>
#define CLK_TCK 100
int main(){
    int c1, c2;
    double c3;
    int h, m, s;
    scanf("%d %d", &c1, &c2);
    c3 = (double)(c2 - c1)/CLK_TCK;
    h = (int)c3 /3600;
    c3 =  c3 - h*3600;
    m = (int)c3 / 60;
    c3 = c3 - m*60;
    s = (int)c3;
    c3 *=10;
    if((int)c3%10 >=5){
        s+=1;
    }
    if(s==60){
        m += 1;
        s = 0;
        if(m == 60){
            h += 1;
            m = 0;
        }
    }
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
