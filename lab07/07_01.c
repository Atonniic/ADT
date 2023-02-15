#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
typedef struct node {
   int value;
   struct node *next_sibling;
   struct node *first_child;
} node_t;

typedef node_t tree_t;

typedef struct node_stack {
    int         data;
    struct node_stack *next; 
} stack_t;

typedef struct node_queue{
    tree_t      *data;
    struct node_queue *next;
} queue_t;

void push(stack_t **s, int v) {
    stack_t *node = (stack_t *)malloc(sizeof(stack_t));
    node -> data = v;
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

void top(stack_t *s) {
    printf("%d ", s -> data);
}

int size_s(stack_t *s) {
    int c = 0;
    while (s != NULL) {
        c++;
        s = s -> next;
    }
    return c;
}

int empty_s(stack_t *s) {
    if (s == NULL) {
        //printf("Stack is empty.\n");
        return 1;
    }
    else {
        //printf("Stack is not empty.\n");
        return 0;
    }
}

queue_t *enqueue(queue_t *q, tree_t *t) {
    queue_t *node = (queue_t *)malloc(sizeof(queue_t));
    node -> data = t;
    node -> next = NULL;
    
    if (q == NULL) {
        return node;
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
        return NULL;
    }
    queue_t *tmp = q;
    q = q -> next;
    free(tmp);
    return q;
}

int empty_q(queue_t *q) {
    if (q == NULL) {
        //printf("Queue is empty.\n");
        return 1;
    }
    else {
        //printf("Queue is not empty.\n");
        return 0;
    }
}

void size_q(queue_t *q) {
    int c = 0;
    while (q != NULL) {
        c++;
        q = q -> next;
    }
    printf("%d\n", c);
}

// Write your code here
// ...

tree_t *search_pos(tree_t *t, int v) {
    tree_t *pos = NULL;
    if (t == NULL) {
        return t;
    }
    if (t->value == v) {
        return t;
    }
    pos = search_pos(t -> first_child, v);
    if (pos != NULL) { 
        return pos;
    }
    else {
        return search_pos(t -> next_sibling, v);
    }
}

tree_t *search_prev(tree_t *t, tree_t *pos) {
    tree_t *pos_prev = NULL;

    if (t == NULL ) {
        return t;
    }
    if (t->first_child == pos) {
        return t;
    }
    if (t->next_sibling == pos) {
        return t;
    }
    
    pos_prev = search_prev(t -> first_child, pos);
    if (pos_prev != NULL) { 
        return pos_prev;
    }
    return search_prev(t -> next_sibling, pos);
}

tree_t *attach(tree_t *t, int o,int n) {
    tree_t *pos = NULL;
    tree_t *node = (tree_t*)malloc(sizeof(tree_t));
    node -> value = n;
    node -> next_sibling = NULL;
    node -> first_child = NULL;

    if (t == NULL) {
        t = node;
        return t;
    }
    pos = search_pos(t,o);
    if (pos->first_child == NULL) {
        pos->first_child = node;
    }
    else {
        pos = pos -> first_child;
        while (pos->next_sibling != NULL) {
            pos = pos -> next_sibling;
        }
        pos -> next_sibling = node;
    }
    return t;
}

int search(tree_t *t, int v) {
    if (search_pos(t, v) == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

void delete(tree_t *t) {
    if (t == NULL) {
        return;
    }
    delete(t -> first_child);
    delete(t -> next_sibling);
    free(t);
}

tree_t *detach(tree_t *t,int v) {
    tree_t *pos = NULL;
    tree_t *prev = NULL;
    pos = search_pos(t, v);

    if (t == pos) {
        t = NULL;
        free(pos);
        return t;
    }
    if (pos == NULL) {
        return t;
    }
    else if (pos != NULL) {
        prev = search_prev(t, pos);
        if (prev->first_child == pos) {
            prev->first_child = pos->next_sibling;
        }
        else if (prev->next_sibling == pos) {
            prev->next_sibling = pos->next_sibling;
        }
        delete(pos->first_child);
        free(pos);
        return t;
    }
}

int degree(tree_t *t, int v) {
    tree_t *pos = NULL;
    int c = 0;

    pos = search_pos(t, v);
    if (pos->first_child == NULL) {
        c = 0;
    }
    else if (pos->first_child != NULL) {
        c = 1;
        pos = pos -> first_child;
        while (pos->next_sibling != NULL) {
            c++;
            pos = pos->next_sibling;
        }
    }
    return c;
}

int is_root(tree_t *t, int v) {
    if (t->value == v) {
      return 1;
    }
    else {
      return 0;
    }
}

int is_leaf(tree_t *t, int v) {
    tree_t *pos = NULL;

    pos = search_pos(t, v);
    if (pos->first_child == NULL) {
      return 1;
    }
    else {
      return 0;
    }
}

void siblings(tree_t *t, int v) {
    tree_t *pos = NULL;
    tree_t *prev = NULL;
    tree_t *prev_plus = NULL;

    pos = search_pos(t, v);
    if(pos == t) {
        printf("\n");
        return;
    }
    if (pos == NULL) {
        return;
    }
    else if (pos != NULL) {
        prev = search_prev(t, pos);
        if (prev->first_child == pos) {
            pos = pos->next_sibling;
            while (pos != NULL) {
                printf("%d ", pos->value);
                pos = pos->next_sibling;
            }
            printf("\n");
        }
        else if (prev->next_sibling == pos) {       
            prev_plus = search_prev(t, prev);
            while (prev_plus->first_child != prev) {
                prev = prev_plus;
                prev_plus = search_prev(t, prev);
            }
            //printf("%d\n", prev_plus->value);
            while (prev->value != v) {
                printf("%d ", prev->value);
                prev = prev->next_sibling;
            }
            pos = pos->next_sibling;
            while (pos != NULL) {
                printf("%d ", pos->value);
                pos = pos->next_sibling;
            }
            printf("\n");
        }
    }
}

int depth(tree_t *t, int v) {
    int d = -1;
    
    if (t == NULL){
        return -1;
    }
    if ((t->value == v) || ((d = depth(t->first_child, v)) >= 0)) {
        return d + 1;
    }
    else {
        d = depth(t->next_sibling, v);
    }
    return d;
}

void print_path(tree_t *t, int start, int end) {
    tree_t *pos_start = NULL;
    tree_t *pos_end = NULL;
    tree_t *prev = NULL;
    tree_t *prev_plus = NULL;
    stack_t *s = NULL;

    pos_start = search_pos(t, start);
    pos_end = search_pos(t, end);
    if (pos_start == NULL || pos_end == NULL) {
        return;
    }
    else if (pos_start != NULL && pos_end != NULL) {
        while (pos_end != pos_start) {
            push(&s, pos_end -> value);
            prev = search_prev(t, pos_end);
            if (prev->first_child == pos_end) {
                pos_end = prev;
            }
            else if (prev->next_sibling == pos_end) {       
                prev_plus = search_prev(t, prev);
                while (prev_plus->first_child != prev) {
                    prev = prev_plus;
                    prev_plus = search_prev(t, prev);
                }
                pos_end = prev_plus;
            }
        }
        push(&s, pos_start -> value);
        while (s != NULL) {
            top(s);
            s = pop(s); 
        }
        printf("\n");
    }
}

int path_length(tree_t *t, int start, int end) {
    tree_t *pos_start = NULL;
    tree_t *pos_end = NULL;
    tree_t *prev = NULL;
    tree_t *prev_plus = NULL;
    stack_t *s = NULL;
    int length = 0;

    pos_start = search_pos(t, start);
    pos_end = search_pos(t, end);
    if (pos_start == NULL || pos_end == NULL) {
        return 0;
    }
    else if (pos_start != NULL && pos_end != NULL) {
        while (pos_end != pos_start) {
            push(&s, pos_end -> value);
            prev = search_prev(t, pos_end);
            if (prev->first_child == pos_end) {
                pos_end = prev;
            }
            else if (prev->next_sibling == pos_end) {       
                prev_plus = search_prev(t, prev);
                while (prev_plus->first_child != prev) {
                    prev = prev_plus;
                    prev_plus = search_prev(t, prev);
                }
                pos_end = prev_plus;
            }
        }
        push(&s, pos_start -> value);
        length = size_s(s);
        return length;
    }
}

void ancestor(tree_t *t, int v) {
    tree_t *pos_end = NULL;
    tree_t *prev = NULL;
    tree_t *prev_plus = NULL;
    stack_t *s = NULL;

    pos_end = search_pos(t, v);
    if (pos_end == NULL) {
        return;
    }
    else if (pos_end != NULL) {
        while (pos_end != t) {
            push(&s, pos_end -> value);
            prev = search_prev(t, pos_end);
            if (prev->first_child == pos_end) {
                pos_end = prev;
            }
            else if (prev->next_sibling == pos_end) {       
                prev_plus = search_prev(t, prev);
                while (prev_plus->first_child != prev) {
                    prev = prev_plus;
                    prev_plus = search_prev(t, prev);
                }
                pos_end = prev_plus;
            }
        }
        push(&s, t -> value);
        while (s != NULL) {
            top(s);
            s = pop(s); 
        }
        printf("\n");
    }
}

void bfs(tree_t *t) { 
    queue_t *q= NULL;
    q = enqueue(q,t);
    while(q != NULL) {
        printf("%d ", q->data->value);
        tree_t *pos = q->data ;
        q = dequeue(q);
        pos = pos->first_child;
        while(pos != NULL)
        {
            q = enqueue(q,pos);
            pos = pos->next_sibling;
        }
    }
    printf("\n");
}

void descendant(tree_t *t, int v) {
    tree_t *start = search_pos(t,v);
    tree_t *tmp = start->next_sibling;
    start -> next_sibling = NULL;
    bfs(start);
    start->next_sibling = tmp;
    return;
}

void dfs(tree_t *t) {
  if(t == NULL)
    return;
  printf("%d ", t -> value);
  dfs(t -> first_child);
  dfs(t -> next_sibling);
}

void space_print(tree_t *t, int space)
{
    int i;

    if (t == NULL)
    {
      return;
    }
    for (i = 0; i<space; i++)
    {
        printf(" ");
    }
    printf("%d\n", t->value);
    space_print(t -> first_child, space + 4);
    space_print(t -> next_sibling, space);
}

void print_tree(tree_t *t)
{
    space_print(t, 0);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}