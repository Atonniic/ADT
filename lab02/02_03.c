#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, x=0, y=0;
    float res;
    scanf("%d", &n);
    char order[n];
    scanf("%s", &order);
    for (i=0; i<n; i++) {
        if (order[i] == 'L') {
            j -= 1;
        }
        else if (order[i] == 'R') {
            j += 1;
        }
        else {
            if (j<0) {
                while (j<0) {
                    j += 4;
                }
            }
            if (j%4 == 0) {
                x += 1;
            }
            else if (j%4 == 1) {
                y -= 1;
            }
            else if (j%4 == 2) {
                x -= 1;
            }
            else {
                y += 1;
            }
        }
    }
    res = sqrt(pow(x, 2)+pow(y, 2));
    printf("%.4f", res);
}