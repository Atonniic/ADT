#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node_t;

node_t* append(node_t *Node){
    int value;

    node_t *startNode = (node_t *)malloc(sizeof (node_t));
    node_t *node = (node_t *)malloc(sizeof (node_t));
    startNode = Node;
    scanf("%d", &value);
    node -> data = value;
    node -> next = NULL;
    if (Node == NULL) {
        Node = node;
        return Node;
    }
    while (Node -> next != NULL) {
        Node = Node -> next;
    }
    Node -> next = node;
    return startNode;
}

void get(node_t *Node){
    int pos, count=0;
    scanf("%d", &pos);
    while (count++ != pos) {
        Node = Node -> next;
    }
    printf("%d\n", Node -> data);
}

void show(node_t *Node) {
    while (Node != NULL) {
        printf("%d ", Node -> data);
        Node = Node -> next;
    }
    printf("\n");
}

node_t* reverse(node_t *Node) {
    node_t *nextNode1 = (node_t *)malloc(sizeof (node_t));
    node_t *nextNode2 = (node_t *)malloc(sizeof (node_t));
    node_t *startNode = (node_t *)malloc(sizeof (node_t));
    startNode = Node;
    nextNode1 = Node -> next;
    if (nextNode1 == NULL) {
        return Node;
    }
    nextNode2 = nextNode1 -> next;
    if (nextNode2 == NULL) {
        nextNode1 -> next = Node;
        Node -> next = NULL;
        return nextNode1;
    }
    while (nextNode2 != NULL) {
        nextNode1 -> next = Node;
        Node = nextNode1;
        nextNode1 = nextNode2;
        nextNode2 = nextNode2 -> next;
    }
    nextNode1 -> next = Node;
    startNode -> next = NULL;
    return nextNode1;
}

node_t* cut(node_t *Node) {
    int st, en, count=0;
    node_t *startNode;
    scanf("%d %d", &st, &en);
    while (count <= en) {
        if (count == st) {
            startNode = Node;
        }
        if (count == en) {
            Node -> next = NULL;
            return startNode;
        }
        Node = Node -> next;
        count++;
    }
}

int main(void){
    node_t *startNode;
    int n,i;
    char command;
    
    startNode = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf(" %c",&command);
        switch(command){
            case 'A' : 
                startNode = append(startNode);   
                break;
            case 'G' : 
                get(startNode);                  
                break;
            case 'S' : 
                show(startNode);                 
                break;
            case 'R' : 
                startNode = reverse(startNode);  
                break;
            case 'C' : 
                startNode = cut(startNode);      
                break;
            default  :                                  
                break;
        }
    }
    return 0;
}