#include <stdio.h>
int main() {
    int n1 ,n2;
    char op;
    scanf("%d %c %d" ,&n1 ,&op ,&n2);
    if (op == '+'){
    printf("%d" ,n1+n2);
    }
    else if (op == '-'){
    printf("%d" ,n1-n2);
    }
    else if (op == '*'){
    printf("%d" ,n1*n2);
    }
    else if (op == '/'){
    printf("%.2f" ,(n1*1.0/n2));
    }
    else if (op == '%'){
    printf("%d" ,n1%n2);
    }
    else {
    printf("Uk");
    }
    return 0;
}