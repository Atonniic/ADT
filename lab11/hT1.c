#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item{
    char *text;
    struct item *next;
} item_t;

typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
} hash_t;

hash_t* init_hashtable(int m, int hash_key){
    hash_t *hash = (hash_t*)malloc(sizeof(hash_t));
    int i;

    hash -> table = (item_t**)malloc(sizeof(item_t*)*m);
    hash -> size = m;
    hash -> hash_key = hash_key;
    for (i=0; i<m; i++) {
        hash -> table[i] = NULL;
    }
    return hash;
}

unsigned int hash_function(char *text, int n, int hash_key) {
    if (n == 0) {
        return text[0];
    }
    return hash_key*hash_function(text, n-1, hash_key) + text[n];
}

int hashh(char *text, int m, int hash_key) {
    return hash_function(text, strlen(text)-1, hash_key)%m;
}

void insert(hash_t *hash, char *text) {
    int index = hashh(text, hash -> size, hash -> hash_key);
    item_t *new_item = (item_t*)malloc(sizeof(item_t));

    new_item -> text = (char*)malloc(sizeof(char)*TEXTSIZE);
    strcpy(new_item -> text, text);
    new_item -> next = hash -> table[index];
    hash -> table[index] = new_item;
}

int search(hash_t *hash, char *text) {
    int index = hashh(text, hash -> size, hash -> hash_key);
    item_t *temp = hash->table[index];

    while (temp!=NULL) {
        if (strcmp(temp->text, text)==0) {
            return index;
        }
        temp = temp -> next;
    }
    return -1;
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char) * TEXTSIZE);

    for(i=0; i<n; i++) {
        scanf("%d %s", &command, text);
        switch(command) {
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n",search(hashtable, text));
                break;
        }
    }
    return 0;
}