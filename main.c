#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 130
int main(int argc, const char * argv[]) {
    int i;
    char buffer[N];
    int amount=0;
    FILE *fp,*file;
    fp = fopen("ex42b.txt", "r");
    file=fopen("file.txt", "w");
    if (!fp) exit(1);
    if (!file) exit(1);
    while (fgets(buffer, N, fp) )
    {
        amount++;
        int number=amount;
        while(number!=0){
            char temp= buffer[strlen(buffer)-2];
            for(i=strlen(buffer)-2;i>0;i--){
                buffer[i]=buffer[i-1];
            }
            buffer[0]=temp;
            number--;
        }
        fputs(buffer, file);
    }
    fclose(fp);
    fclose(file);
    return 0;
}

