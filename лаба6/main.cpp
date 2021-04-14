#include <iostream>
#include <utility>
#include <algorithm>
#include<fstream>
#include<stdio.h>
#include "main.h"
using namespace std;
    void Tree:: add_node(int number)
    {
        _add_node(number,root);
    }
    void Tree:: preorder_print()
    {
        _preorder_print(root);
    }
    void Tree:: order_print()
    {
        _order_print(root);
    }
    int Tree:: Size()
    {
        return size;
    }
    bool Tree:: empty()
    {
        if(size==0){
            return true;
        }
        return false;
    }
    void Tree:: clear()
    {
        _clear(root);
        root=nullptr;
    }

Tree::Tree()
{
    root=nullptr;
    size=0;
}
Tree::~Tree()
{
    _clear(root);
    root=nullptr;
}
void Tree::_clear(Node* leaf)
{
    if(leaf!=nullptr){
        _clear(leaf->left);
        _clear(leaf->right);
        delete leaf;
    }
}
Node* Tree::_add_node(int number,Node *leaf)
{
   if(leaf==nullptr){
        leaf=new Node (number,0,0);
        if(root==nullptr)root=leaf;
        size++;
    }
    if(leaf->data>number){
        leaf->left=_add_node(number,leaf->left);
    }
    if(leaf->data<number){
        leaf->right=_add_node(number,leaf->right);
    }
    return leaf;
}
void Tree::_preorder_print(Node *leaf)
{
    if(leaf!=nullptr){
        _preorder_print(leaf->left);
        cout<<leaf->data;
        _preorder_print(leaf->right);
    }
}
void Tree::_order_print(Node *leaf)
{
    if(leaf!=nullptr){
        _order_print(leaf->right);
        cout<<leaf->data;
        _order_print(leaf->left);
    }
}
Node::Node(int  data,Node *left,Node *right)
    {
        this->data=data;
        this->left=left;
        this->right=right;
        prev=nullptr;
        next=nullptr;
    }
int main(int argc, const char * argv[]) {
    int m;
    cin>>m;
    Tree **a=new Tree*[m];
    for(int i=0;i<m;i++){
        a[i]=new Tree[m];
    }
    int **count=new int*[m];
    for(int i=0;i<m;i++){
        count[i]=new int[m];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            count[i][j]=0;
        }
    }
    FILE *fp;
    if ((fp = fopen("file4.txt", "r")) == NULL){
        cout<<"mistake";
    }
    char ch;
    while(!feof(fp)){
         ch=fgetc(fp);
        if(ch == '\n'){
           break;
        }
        int position1=rand()%m;
       int  position2=rand()%m;
        int n=ch-'0';
        a[position1][position2].add_node(n);
        count[position1][position2]+=n;
    }
   fclose(fp);
   int max=count[0][0];
   int imax=0;
   int jmax=0;
   for(int i=0;i<m;i++){
       for(int j=0;j<m;j++){
           if(max<count[i][j]){
               max=count[i][j];
               imax=i;
               jmax=j;
           }
       }
   }
    a[imax][jmax].preorder_print();
        cout<<endl;
    a[imax][jmax].order_print();
    return 0;
}
 


