#include "main.h"
#include <assert.h>
#include <stdio.h>

void test(){
    myNumber a = Create("5897565");
    myNumber b = Create("5897");
    assert(Equal(&a,&b)==1);
    myNumber c = Create("5897565");
    myNumber d = Create("5897989889");
    assert(Equal(&a,&b)==-1);
}
#undef main
int main(){
    test();
    return 0;
}
