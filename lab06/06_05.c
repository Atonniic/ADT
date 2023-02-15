#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char        data;
    struct node *next; 
} node_t;

typedef node_t stack_t;

void *push(stack_t **s, char value) {
    stack_t *node = (stack_t *)malloc(sizeof(stack_t));
    node -> data = value;
    node -> next = NULL;

    node -> next = *s;
    *s = node;  
}

stack_t *pop(stack_t *s) {
    if (s == NULL) {
        return s;
    }
    else {
        stack_t *tmp = s;
        s = s -> next;
        free(tmp);
    }
    return s;
}

char top(stack_t *s) {
    if(s == NULL) {
      return 0;
    }
    return s -> data;
}

int size(stack_t *s) {
    int c = 0;
    while (s != NULL) {
        c++;
        s = s -> next;
    }
    return c;
}

int main(void) {
    stack_t *s = NULL;
    int final_size, size_x;
    char pass, t;

    scanf(" %c", &pass);
    while (pass != 'x') {
        push(&s, pass);
        scanf(" %c", &pass);
    }

    scanf(" %c", &pass);
    while (pass != 'y') {
        if (pass == 'y'){
            break;
        }
        t = top(s);
        if (pass != t) {
            printf("0");
            return 0;
        }
        else {
            s = pop(s);
        }
        scanf(" %c", &pass);
    }
    final_size = size(s);
    if (final_size == 0) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}
/*
1q2w3e4rxr4e3w2q1y
1q2w3e4rx1q2w3e4ry
1q2w3e4rx1q2w3ey
*/