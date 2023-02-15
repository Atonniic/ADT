#include <stdio.h>
#include <string.h>

int main() {
    char text[100001], word[30001][51];
    int i=0;

    scanf("%[^\n]s", &text);
    char * token = strtok(text, " ");
    while (token != NULL) {
        strcpy(word[i++], token);
        token = strtok(NULL, " ");
    }
    while (i--) {
        printf("%s ",word[i]);
    }
    return 0;
}