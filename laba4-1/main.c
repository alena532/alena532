#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define LONG_STR 80
#define MAX_WORD 40
char** writeWord(char **word,int countWords,char *str)
{
    int i;
    int indxWord=0,indxLetter=-1;
    for( i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            word[indxWord][++indxLetter]=str[i];
        }else{
            ++indxWord;
            indxLetter=-1;
        }
    }
    return word;


}
void showWords(char **word,int countWords)
{
    int i,j;
    for(i=0;i<countWords;i++){
        char min=word[i][0];
        for( j=1;word[i][j]!='\0';j++){
            if(word[i][j]<=min){
                break;
            }else{
                min=word[i][j];
            }
            if(word[i][j+1]=='\0'){
                int m;
                for(m=0;word[i][m]!='\0';m++){
                    printf("%c",word[i][m]);
                }
                printf(" ");
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int i,j;
    printf("If you want finish program press z\n");
    while(1){
        char str[LONG_STR];
        gets(str);
        if(str[0]!='z'){
            str[LONG_STR-1]='\0';
            int countWords=1;
            for( i=0;i<LONG_STR;i++){
                if(str[i]==' ')
                countWords++;
            }
            char **word=(char **)malloc(countWords*sizeof(char*));;
            for(i=0;i<countWords;i++){
                word[i]=(char *)malloc(MAX_WORD*sizeof(char));
            }
            writeWord(word,countWords,str);
            showWords(word,countWords);
            printf("\n");
            for( i=0;i<countWords;i++){
                free(word[i]);
            }
        }
        else{
            exit(0);
        }
    }
    return 0;
}
