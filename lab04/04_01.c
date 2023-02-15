#include <stdio.h>
#include <math.h>

int main() {
    int n, m, i, k;

    scanf("%d", &n);
    m = sqrt(n);
    if (n == 2) {
        printf("1");
        return 0;
    }
    else if (n == 0 || n == 1 || n%2 == 0) {
        printf("0");
        return 0;
    }
    else {
        for (i=3; i<=m; i+=2) {
            if (n%i == 0) {
                printf("0");
                return 0;
            }
        }
    }
    printf("1");
    return 0;
}
//O(sqrt(n))