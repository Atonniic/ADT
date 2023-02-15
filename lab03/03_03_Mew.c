#include <stdio.h>
#include <string.h>

int main() {
    char text[100001], word[30001][51], tmp[51];
    int i, cou=0;
    
    scanf("%[^\n]s", &text);
    printf("%s\n", word[0]);
    sscanf(text, "%s", tmp);
    strcpy(word[cou++], tmp);
    
    for (i=0; i<strlen(text); i++) {
        if (text[i] == ' ') {
            sscanf(text+i, "%s", tmp);
            strcpy(word[cou++], tmp);
        }
    }
    for(i=cou-1;i>=0;i--){
        printf("%s ", word[i]);
    }
    return 0;
}
