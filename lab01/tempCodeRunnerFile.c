#include <stdio.h>
int main() {
    unsigned t ,d ,hr ,min;
    scanf("%u" ,&t);
    d = t/86400;
    hr = (t%86400)/3600;
    min = ((t%86400)%3600)/60;
    t = (((t%86400)%3600)%60);
    printf("%d %d %d %d" ,d ,hr ,min ,t);
    return 0;
}