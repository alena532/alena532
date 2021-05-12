#include "Header.h"
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
void test(){
    FILE *file;
    if ((file= fopen("file.txt","r")) == NULL){
        std::cout<<"Mistake";
        exit(0);
        }
    List a;
    while(!feof(file)){
        a.Push_back(file);
        } 
    assert(a.Size()==3);
    assert(a.Empty()==false);
    
}
#undef main
int main(){
    test();
    return 0;
}
