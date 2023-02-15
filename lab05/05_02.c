#include <stdio.h>
#include <string.h>

char x[20000], y[20000];
int res[20000];

int main() {
    int len_a, len_b, i, j, k, X=0;

    scanf(" %s",x);
    scanf(" %s",y);
    len_a = strlen(x);
    len_b = strlen(y);
    for (i=len_a-1, j=len_b-1, k=0; i>=0 && j>=0; i--, j--, k++) {
        res[k] = (x[i] - '0') + (y[j] - '0') + X;
        X = res[k] / 10;
        res[k] %= 10;
    }
    if (i > 0) {
        for (; i>=0; i--, k++) {
            res[k] = (x[i] - '0') + X;
            X = res[k] / 10;
            res[k] %= 10;
        }
    }
    else if (j >0) {
        for (; j>=0; j--, k++) {
            res[k] = (y[j] - '0') + X;
            X = res[k] / 10;
            res[k] %= 10;
        }
    }
    res[k] = X; 
    k++;
    for(; k>=0 && res[k]==0; k--);
    for(; k>=0; k--) {
        printf("%d", res[k]);
    }
    return 0;
}