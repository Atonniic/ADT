#include <stdio.h>

int main(){
    int m, p, n, i, j, cou, x1=0, x2=0;
    char text[100000], key[100000], idx[100000];

    scanf("%d %d %d", &m, &p, &n);
    scanf("%s", text);
    scanf("%s", key);
    for (i=0; i<=m-p; i++) {
        cou = 0;
        for (j=0; j<p; j++) {
            if (text[i+j] != key[j]) {
                cou +=1;
            }
            if (cou > n) {
                break;
            }
        }
        if (cou > n) {
            continue;
        }
        idx[x1++] = i;
        i += p - 1;
    }
    for (i=0; i<m; i++) {
        if (i == idx[x2]) {
            x2 += 1;
            printf("[");
            for (j=0; j<p; j++) {
                if (text[i+j] == key[j]) {
                    printf("%c",text[i+j]);
                }
                else {
                    printf("?");
                }
            }
            printf("]");
            i += p - 1;
        }
        else {
            printf("%c",text[i]);
        }
    }
    return 0;
}