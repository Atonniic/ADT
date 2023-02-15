#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
tydef struct node{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t avl_t;
#endif

avl_t* New_node(int data) {
    avl_t* tmp = (avl_t*)malloc(sizeof(avl_t));
    tmp -> data   = data;
    tmp -> left   = NULL;
    tmp -> right  = NULL;
    tmp -> height = 1;  
    return tmp;
}

int height(avl_t *t) {
    if (t == NULL)
        return 0;
    return t -> height;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

avl_t *rotate_L(avl_t*t) {
    avl_t *TR = t -> right;
    avl_t *TR_L = TR -> left;

    TR -> left = t;
    t -> right = TR_L;
    t -> height = max(height(t -> left), height(t -> right))+1;
    TR -> height = max(height(TR -> left), height(TR -> right))+1;
    return TR;
}

avl_t *rotate_R(avl_t*t) {
    avl_t *TL = t -> left;
    avl_t *TL_R = TL -> right;

    TL -> right = t;
    t -> left = TL_R;
    t -> height = max(height(t -> left), height(t -> right))+1;
    TL -> height = max(height(TL -> left), height(TL -> right))+1;
    return TL;
}

int get_balance(avl_t *t) {
    if (t == NULL)
        return 0;
    return height(t -> left)-height(t -> right);
}

avl_t *insert(avl_t* t, int data) {
    if (t == NULL) {
        return New_node(data);
    }
    if (data < t->data) {
        t -> left  = insert(t -> left, data);
    }
    else if (data > t->data) {
        t -> right = insert(t -> right, data);
    }
    t -> height = 1 + max(height(t -> left), height(t -> right));
 
    int balance = get_balance(t);
    if (balance > 1 && data < t->left->data) {
        return rotate_R(t);
    }
    if (balance < -1 && data > t->right->data) {
        return rotate_L(t);
    }
    if (balance > 1 && data > t->left->data) {
        t -> left =  rotate_L(t -> left);
        return rotate_R(t);
    }
    if (balance < -1 && data < t->right->data) {
        t -> right = rotate_R(t -> right);
        return rotate_L(t);
    }
    return t;
}

avl_t *pos_min(avl_t *t) {
    avl_t *pos = t;
    while(pos&&pos->left != NULL)
        pos = pos->left;
    return pos;
}

avl_t* delete(avl_t* t, int data) {
    int balance = get_balance(t);

    if (t == NULL) {
        return t;
    }
    if ( data < t->data ) {
        t -> left = delete(t -> left, data);
    }
    else if( data > t->data ) {
        t -> right = delete(t -> right, data);
    }
    else {
        if((t -> left == NULL) || (t -> right == NULL)) {
            avl_t *tmp = t -> left ? t -> left : t -> right;
            if (tmp == NULL) {
                tmp = t;
                t = NULL;
            }
            else {
             *t = *tmp; 
            }
            free(tmp);
        }
        else {
            avl_t *tmp = pos_min(t -> right);
            t -> data = tmp -> data;
            t -> right = delete(t -> right, tmp -> data);
        }
    }
    if (t == NULL) {
      return t;
    }
    t -> height = 1 + max(height(t -> left), height(t -> right));
    
    if (balance > 1 && get_balance(t -> left) >= 0) {
        return rotate_R(t);
    }
    if (balance > 1 && get_balance(t -> left) < 0) {
        t -> left =  rotate_L(t -> left);
        return rotate_R(t);
    }
    if (balance < -1 && get_balance(t -> right) <= 0) {
        return rotate_L(t); 
    }
    if (balance < -1 && get_balance(t -> right) > 0) {
        t -> right = rotate_R(t -> right);
        return rotate_L(t);
    }
    return t;
}
int main(void){
    avl_t *t = NULL;
    int n, i;
    int command , data;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete(t, data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}