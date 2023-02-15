#include <stdio.h>
#include <math.h>

int main() {
    double a, b, A, B, n, i, x, y1=0, y2=0, res=0, sum=0, pi=3.14159265358979323846;
    scanf("%lf %lf %lf %lf %lf", &a, &b, &A, &B, &n);
    x = (b-a)/n;
    for (i=0; i<n; i++) {
        res = (x*(A*sin((pi*(a+(i*x)))/B)+A*sin(pi*((a+(i+1*x))))/2));
        sum += res;
    }
    printf("%.5lf", sum);
    return 0;
}