#include <cstdio>
#include <cmath>

int main(int argc, char *argv[])
{
    freopen("in", "r", stdin);
    double r1, p1, r2, p2;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    double A = r1*r2*cos(p1)*cos(p2) - r1*r2*sin(p1)*sin(p2);
    double B = r1*r2*cos(p1)*sin(p2) + r1*r2*sin(p1)*cos(p2);
    if(A + 0.005 >= 0 && A < 0)
        printf("0.00");
    else printf("%.2lf", A);
    if(B >= 0 ) printf("+");
    if(B + 0.005 >= 0 && B <0)
        printf("+0.00i");
    else printf("%.2lfi", B);
    return 0;
}
