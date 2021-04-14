#include "main.h"
#include <assert.h>
#include <stdio.h>
#include <iostream>

void test(){
    Tree a;
    a.add_node(5);
    a.add_node(6);
    a.add_node(7);
    a.add_node(8);
    Tree b;
    b.add_node(5);
    b.add_node(6);
    assert(b.Size()==2);
}
#undef main
int main(){
    test();
    return 0;
}