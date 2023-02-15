#include <stdio.h>

int main() {
    int m ,y ,dm[131] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i, dy=0, dl, j;
    char *nm[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter year: ");
    scanf("%d", &y);
    printf("Enter month: ");
    scanf("%d", &m);
    printf("====================\n");
    printf("%s %d\n", nm[m-1], y);
    if (y%4 == 0 && y%100 != 0) {
        dm[2] = 29;
        for (i=0; i<m; i++) {
            dy += dm[i];
        }
    }
    else if (y%400 == 0) {
        dm[2] = 29;
        for (i=0; i<m; i++) {
            dy += dm[i];
        }
    }
    else {
        for (i=0; i<m; i++) {
            dy += dm[i];
        }
    }
    for (i=1990; i<y; i++) {
        if (i%4 == 0 && i%100 != 0) {
            dy += 366;
        }
        else if (i%400 == 0) {
            dy += 366;
        }
        else {
            dy += 365;
        }
    }
    dl = (dy%7)+1;
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    j = dl;
    for (i=1; i<dl+1; i++) {
        printf(" \t");
    }
    for (i=1; i<dm[m]+1; i++) {
        if (j == 7) {
            printf("\n");
            j = 0;
        }
        printf("%d\t", i);
        j += 1;
    }
    return 0;
}
