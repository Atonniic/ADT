#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char         data;
    struct node *next; 
} node_t;


node_t *push(node_t *s, char value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = value;
    node -> next = NULL;

    node -> next = s;
    s = node;
    return s;  
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

char top(node_t *s) {
    if(s == NULL) {
      return '0';
    } 
    return s -> data;
}

int main(void) {
    node_t *s = NULL;
    int n, i;
    
    scanf("%d", &n);
    char symbols;
    for (i=0; i<n; i++) {
        scanf(" %c", &symbols);
        if      (symbols == '(' || symbols == '[' || symbols == '{') {
            s = push(s, symbols);
        }
        else if (symbols == ')' || symbols == ']' || symbols == '}') {
            if      (symbols == ')' && top(s) == '(') {
                s = pop(s);
            }
            else if (symbols == ']' && top(s) == '[') {
                s = pop(s);
            }
            else if (symbols == '}' && top(s) == '{') {
                s = pop(s);
            }
            else {
                s = push(s, symbols);
            }
        }
    }
    if (s == NULL) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}