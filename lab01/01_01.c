#include <stdio.h>
int main() {
    float l ,w;
    printf("length(m.) : ");
    scanf("%f" ,&l);
    printf("width(m.) : ");
    scanf("%f" ,&w);
    printf("Use %.5f seconds." ,(l*w*3.28084*3.28084)/2);
    return 0;
}