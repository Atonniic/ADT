#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int     data;
    struct  node *left;
    struct  node *right;
} node_t;

typedef node_t tree_t;
#endif

typedef struct node_q{
    tree_t          *value;
    struct node_q   *next;
} queue_t;

queue_t *enqueue(queue_t *q, tree_t *t)
{
    queue_t *node = (queue_t *)malloc(sizeof(queue_t));
    node -> value = t;
    node -> next = NULL;
     
    if (q == NULL) {
        q = node; 
    }
    else {
        queue_t *tmp = q;
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
        queue_t *tmp = q;
        q = q -> next;
        free(tmp);
    }
    return q;
}


int is_full(tree_t *t) {
    int child = 0, full = 0;

    if (t == NULL) {
        return 1;
    }
    if (t->left != NULL) {
        child++;
    }
    if (t->right != NULL) {
        child++;
    }
    if (child == 1) {
        return 0;
    }
    full = is_full(t->left);
    if (full == 1) {
        full = is_full(t->right);
    }
    return full;
}

int num_node(tree_t *t) {
    if (t == NULL) {
        return 0;
    }
    return num_node(t->left) + num_node(t->right) + 1;
}

int height(tree_t*t){
    int hl,hr;
    if (t==NULL)
        return -1;
    hl = height(t->left);
    hr = height(t->right);
    return (hl>hr) ? hl+1:hr+1;
}

int is_perfect(tree_t *t) {
    int h = height(t), n = num_node(t), res = 2;
    for (int i = 0; i < h; i++) {
        res *= 2;
    }
    //printf("%d %d\n",n,res);
    if (n == res-1)
        return 1;
    return 0;
}

int is_complete(tree_t*t){
    queue_t *q = NULL;
    int k = 0; 

    if (t == NULL) {
        return 1;
    }
    q = enqueue(q,t);
    while (q != NULL) {
        tree_t *node = q->value;
        q = dequeue(q);
        //left
        if (node->left != NULL) {
            if (k == 1) {
                return 0;
            }
            q = enqueue(q, node -> left);
        }
        else {
            k = 1;
        }
        //right
        if(node->right != NULL) {
            if(k == 1) {
                return 0;
            
            }
            q = enqueue(q, node -> right);
        }
        else {
            k = 1;
        }
    }
    return 1;
}

int is_degenerate(tree_t *t) {
    int child = 0, full = 0;

    if (t == NULL) {
        return 1;
    }
    if (t->left != NULL) {
        child++;
    }
    if (t->right != NULL) {
        child++;
    }
    if (child == 2) {
        return 0;
    }
    full = is_degenerate(t->left);
    if (full != 1) {
        return full;
    }
    return is_degenerate(t->right);
}

int is_skewed(tree_t *t) {
    int num = num_node(t);
    
    if (t == NULL) {
        return 1;
    }
    if (is_degenerate(t) == 1) {
        if (t->right == NULL) {
            while (t->left != NULL) {
                t = t->left;
                num--;
            }
        }
        else if (t->left == NULL) {
            while (t->right != NULL) {
                t = t->right;
                num--;
            }
        }
        if (num == 1) {
            return 1;
        }
    }
}

int main(void){
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d %d",&parent,&child,&branch);
        t = attach(t,parent,child,branch);
    }
    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
    return 0;
}