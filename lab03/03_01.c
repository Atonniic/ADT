#include <stdio.h>
#include <stdlib.h>

void findStats(int x[], int *n, double *avg, int *maxi, int *mini) {
    int j;
    *maxi = -100;
    *mini = 100;
    *avg = 0;
    for(j=0; j<*n; j++){
        *avg += x[j];
        if (x[j] > *maxi) {
            *maxi = x[j];
        }
        if (x[j] < *mini) {
            *mini = x[j];
        }
    }
    *avg /= *n;
}

int main(void) {
    int n, i, maxi, mini;
    double avg;
    int *nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) * n);
    for (i=0; i<n; i++) 
        scanf("%d", nums+i);
    findStats(nums, &n, &avg, &maxi, &mini);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}