#include <stdio.h>
int main() {
    int d ,m ,y ;
    scanf("%d/%d/%d" ,&d ,&m ,&y);
    printf("hello");
    if (y%4 == 0 && y%100 != 0) {
        printf("366");
    }
    else if (y%400 == 0) {
        printf("366");
    }
    else {
        printf("365");
    }
    return 0;
}