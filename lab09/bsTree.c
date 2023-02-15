#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t bst_t;

struct node *New_node(int v) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = v;
    tmp->left = tmp->right = NULL;
    return tmp;
}

bst_t *insert(bst_t *t, int data) {
    if (t == NULL) {
        return New_node(data);
    }
    if (data < t->data) {
        t -> left = insert(t -> left, data);
    }
    else if (data > t->data) {
        t -> right = insert(t -> right, data);
    }
    return t;
}

bst_t *pos_min(bst_t *t) {
    bst_t *pos = t;
    while (pos&&pos->left != NULL) {
        pos = pos->left;
    }
    return pos;
}

bst_t *pos_max(bst_t *t) {
    bst_t *pos = t;
    while (pos&&pos->right != NULL) {
        pos = pos->right;
    }
    return pos;
}

bst_t *delete(bst_t *t, int data) {
    if( t == NULL) {
        return t;
    }
    if (data < t->data) {
        t -> left = delete(t -> left,data);
    }
    else if (data > t->data) {
        t -> right = delete(t -> right,data);
    }
    else {
        if (t->left == NULL) {
            bst_t *tmp = t->right;
            free(t);
            return tmp;
        }
        else if (t->right == NULL) {
            bst_t *tmp = t->left;
            free(t);
            return tmp;
        }
        bst_t *tmp = pos_min(t->right);
        t->data = tmp->data;
        t->right = delete(t->right,tmp->data);
    }
    return t;
}

int find(bst_t *t, int data) {
    if (t == NULL) {
        return 0;
    }
    if (data < t->data) {
        return find(t -> left, data);
    }
    else if (data > t->data) {
        return find(t -> right, data);
    }
    return 1;
}

int find_min(bst_t *t) {
    return pos_min(t) -> data;
}

int find_max(bst_t *t) {
    return pos_max(t) -> data;
}

int main(void) {
    bst_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1 :
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2 :
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3 :
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4 :
                printf("%d\n", find_min(t));
                break;
            case 5 :
                printf("%d\n", find_max(t));
                break;
        }
    }   
    return 0;
}