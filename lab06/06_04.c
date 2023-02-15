#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float        data;
    struct node *next; 
} node_t;

node_t *push(node_t **s, float value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = value;
    node -> next = NULL;

    node -> next = *s;
    *s = node;  
}

node_t *pop(node_t *s) {
    if (s == NULL) {
        return s;
    }
    else {
        node_t *tmp = s;
        s = s -> next;
        free(tmp);
    }
    return s;
}

float top(node_t *s) {
    if(s == NULL) {
      return 0;
    } 
    return s -> data;
}

int main(void) {
    node_t *s = NULL;
    int n, i;
    float a, b;
    char v;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &v);
        if (v == '+' ) {
            b = top(s);
            s = pop(s);
            a = top(s);
            s = pop(s);
            push(&s, a+b);
        }
        else if (v == '-') {
            b = top(s);
            s = pop(s);
            a = top(s);
            s = pop(s);
            push(&s, a-b);
        }
        else if (v == '*') {
            b = top(s);
            s = pop(s);
            a = top(s);
            s = pop(s);
            push(&s, a*b);
        }
        else if (v == '/') {
            b = top(s);
            s = pop(s);
            a = top(s);
            s = pop(s);
            push(&s, a/b);
        }
        else {
            push(&s, v-'0');
        }
    }
    printf("%.2f\n", top(s));
}