#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next_sibling;
    struct node *first_child;
    struct node *prev;
 } node_t;
typedef node_t tree_t;
typedef struct qq{
    tree_t *data;
    struct qq *next;
} q_t;
typedef q_t queue_t;
queue_t * enqueue(queue_t *q,tree_t * t)
{
    q_t *newnode = (q_t *)malloc(sizeof(q_t));
    q_t *lastnode = q;
    newnode ->data = t;
    newnode ->next = NULL;
    if (q == NULL)
        return newnode;
    else{
        while(lastnode ->next != NULL)
        {
            lastnode = lastnode->next;
        }
        lastnode->next = newnode;
    }
    return q;
}
queue_t * dequeue(queue_t *q)
{
    if (q==NULL){
        printf("Queue is empty.\n");
        return NULL;}
    queue_t *tmp = q;
    q = q->next;
    free(tmp);

    return q;
}
int is_root(tree_t *t,int v)
{
    return t->data==v;
}
tree_t *search_pos(node_t*t,int v)
{
    tree_t *pos;
    if  (t == NULL|| t->data == v)
        return t;  
    pos = search_pos(t->first_child,v);
    if (pos != NULL)
        return pos;
    else
        return search_pos(t->next_sibling,v);
}
tree_t *attach(node_t *t,int p,int v)
{
    tree_t *node = (tree_t*)malloc(sizeof(tree_t));
    node->data = v;
    tree_t *pos = search_pos(t,p);
    if (pos == NULL)
      {
        return node;
      }
    if (pos->first_child == NULL)
      {
        pos->first_child = node;
        node->prev = pos;
      }
    else
        {
        pos = pos->first_child;
        while (pos ->next_sibling!= NULL)
            pos = pos->next_sibling;
        node->prev = pos;
        pos->next_sibling = node;
        }
    return t;
}
/*void delt(tree_t *root)
{
    if(root == NULL)
         return ;
    
    //delt(root->first_child);
    //delt(root->next_sibling);
    //free(root);
    return;
}*/

tree_t *detach(tree_t *t,int v)
{
    tree_t *pos = search_pos(t,v);
    if (pos != t)
    { 
        tree_t *before=pos->prev ;
        if(pos == before->first_child)
        {
          before->first_child = pos->next_sibling;
          pos->first_child->prev = before;
          //delt(pos);
          return t;
        }
        else if (pos ==before->next_sibling)
        {
          before->next_sibling = pos->next_sibling;
          pos->next_sibling->prev = before;
          //delt(pos);
          return t;
        }
    }
    return NULL;
}
int serach(tree_t *t,int v)
{
    if(search_pos(t,v) == NULL )
        return 0;
    else
        return 1;
}
int degree(tree_t *t,int v)
{
  int num_child = 0;
  tree_t *pos = search_pos(t,v);
  if (pos->first_child != NULL)
  {
    num_child++;
    pos = pos->first_child;
    while(pos->next_sibling != NULL)
    {
      pos = pos->next_sibling;
      num_child++;
    }
  }
  return num_child;
}

int is_leaf(tree_t *t,int v)
{
  tree_t *pos = t;
  if(pos->first_child ==NULL)
    return 1;
  else
    return 0;
}
tree_t * search_parent(node_t*t,int v,tree_t *parent)
{
    tree_t *pos;
    if  (t == NULL)
        return t;
    if (t->data==v)
        return parent;
    pos = search_parent(t->first_child,v,t);
    if (pos != NULL)
        return pos;
    else
        return search_parent(t->next_sibling,v,t);
}
void siblings(tree_t *t,int v)
{
    tree_t *parent = search_parent(t,v,NULL);
    tree_t *first;
    if (is_root(t,v))
      printf("\n");
    else
      {
       first = parent->first_child;
       while(first->next_sibling != NULL)
       {
        printf("%d ",first->data);
        first = first->next_sibling;
       }
       printf("%d ",first->data);
      }
}
int depth(tree_t*t,int v)
{
  if (t==NULL)
    return -1;
  int disk =-1;
  if(t->data == v||(disk = depth(t->first_child,v))>=0||(disk = depth(t->next_sibling,v))>=0)
   return disk+1;
  return disk;
}
int lengthpath(tree_t *t,int v,int length)
{
    if  (t == NULL|| t->data == v)
        return length;
    int a =lengthpath(t->first_child,v,length++);
    int b =lengthpath(t->next_sibling,v,length);
    return length;
}
int path_length(tree_t *t, int start, int end)
{
  tree_t *str = search_pos(t,start);
  return lengthpath(str,end,1);
}
void ancestor(tree_t *t,int v)
{
    if (t ==NULL||t->data==v)
      return;
    printf("%d ", t->data);
    ancestor(t->first_child,v);
    ancestor(t->next_sibling,v);
}
void path(tree_t *t,int end)
{
    if  (t == NULL|| t->data == end)
        return;
    printf("%d ", t->data);
    path(t->first_child,end);
    path(t->next_sibling,end);
}
void print_path(tree_t *t, int start, int end)
{
     tree_t *str = search_pos(t,start);
     path(str,end);
}
void bfs(tree_t *t)
{
  q_t *q= NULL;
  q = enqueue(q,t);
  while(q != NULL)
  {
    q_t *tmp = q;
    q = dequeue(q);
    printf("%d ",tmp->data->data);
    tree_t *pos=q->data ;
    if (pos->first_child != NULL)
    {
      pos = pos->first_child;
      while(pos->next_sibling != NULL)
      {
        enqueue(q,pos);
        pos = pos->next_sibling;
      }
    }
  }
}
void descendant(tree_t *t,int v)
{
    tree_t *start = search_pos(t,v);
    bfs(start);
}
void dfs(tree_t *t)
{
  if(t == NULL)
    return;
  printf("%d ",t->data);
  dfs(t->first_child);
  dfs(t->next_sibling);
}
void print_tree(tree_t*t)
{
  if(t == NULL)
    return;
  for(int i=0;i<depth(t,t->data);i++)
    printf(" ");
  printf("%d/n",t->data);
  dfs(t->first_child);
  dfs(t->next_sibling);
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
        printf("%d\n", serach(t, node));
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
/*
20
1 -1 1
1 1 2 
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
3 1*/
/*24
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
3 1
1
3 2
1
3 8
1
3 11
1
3 13
1
2 12
2 2*/
/*23
1 -1 1
1 1 2
1 1 3
1 2 4 
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
12 1*/



/*
24
1 -1 1
1 1 2
1 1 3
1 2 4
1 2 5
1 3 6
1 3 7
1 4 8
1 5 9
1 5 10
1 6 11
1 6 12
1 6 13
1 13 14
3 1
1
3 2
1
3 8
1
3 11
1
3 13
1
2 12
*/