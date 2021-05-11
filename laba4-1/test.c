#include "main.h"
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>
#define MAX_WORD 40

void test(){
    char *str = "asd abc";
    int countWords=2;
    char** temp=(char**)malloc(MAX_WORD*sizeof(char*));
    for(int i=0;i<countWords;i++){
        temp[i]=(char*)malloc(MAX_WORD*sizeof(char));
    }
    temp[0] = "asd";
    temp[1] = "abc";
    char* word[countWords];
    for(int i=0;i<countWords;i++){
        word[i]=(char*)malloc(MAX_WORD*sizeof(char));
    }
    writeWord(word,countWords,str);
    for(int i = 0; i <countWords + 3; i++){
        printf("%s %s\n", word[i], temp[i]);
    }

    
}
#undef main
int main(){

    test();
    return 0;
}