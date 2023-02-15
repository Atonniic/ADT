#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main() {
    int x, i, j;
    long long f;
    double res1, res2, res3, xr;
    scanf("%d", &x);
    xr = (x*PI)/180;
    for (i=0; i<10; i++) {
        f = 1;
        for (j=1; j<=(2*i)+1; j++) {
            f *= j;
        }
        res1 += (pow(-1, 2+i)*pow(xr, 2*i+1))/f;
    }
    res2 = sqrt(1-pow(res1, 2));
    res3 = res1/res2;
    printf("%.14lf %.14lf %.14lf", res1, res2, res3); 
    return 0;
}