#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int         data;
    struct node *next; 
} node_t;  

typedef node_t queue_t;

queue_t *enqueue(queue_t *q, int v) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node -> data = v;
    node -> next = NULL;
    
    if (q == NULL) {
        q = node;
    }
    else {
        node_t *tmp = q;
        while (tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = node;
    }
    return q;
}

queue_t *dequeue(queue_t *q) {
    if (q == NULL) {
        printf("Queue is empty.\n");
        return q;
    }
    else {
        node_t *tmp = q;
        q = q -> next;
        printf("%d\n", tmp -> data);
        free(tmp);
        
    }
    return q;
}

void show(queue_t *q) {
    int v;
    if (q == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        int v;
        node_t *tmp = q;
        v = tmp -> data;
        while (tmp != NULL) {
            v = tmp -> data;
            printf("%d ", v);
            tmp = tmp -> next;
        }
        printf("\n");
    }
}

void empty(queue_t *q) {
    if (q == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue is not empty.\n");
    }
}

void size(queue_t *q) {
    int c = 0;
    while (q != NULL) {
        c++;
        q = q -> next;
    }
    printf("%d\n", c);
}

int main(void) {
    queue_t *q = NULL;
    int     n, i , command, v;

    scanf("%d" , &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1 :
                scanf("%d", &v);
                q = enqueue(q, v);
                break;
            case 2 :
                q = dequeue(q);
                break;
            case 3 :
                show(q);
                break;
            case 4 :
                empty(q);
                break;
            case 5 :
                size(q);
                break;
        }
    }
    return 0;
}