#include <iostream>
#include <utility>
#include <algorithm>
#include<fstream>
#include<stdio.h>
using namespace std;
struct Node
{
    Node *left;
    Node *right;
    int data;
    int height;
    Node(int  data,Node *left,Node *right)
    {
        this->data=data;
        this->left=left;
        this->right=right;
        this->height=1;
    }
};
class Tree
{
private:
    Node *root;
    int size;
public:
    Tree();
    Tree(Tree &temp);
    ~Tree();
    void add_node(int number)
    {
        _add_node(number,root);
    }
    void preorder_print()
    {
        _preorder_print(root);
    }
    void order_print()
    {
        _order_print(root);
    }
    
    int Size()
    {
        return size;
    }
    bool empty()
    {
        if(size==0){
            return true;
        }
        return false;
    }
    void clear()
    {
        _clear(root);
        root=nullptr;
    }
private:
    Node* _add_node(int  number,Node *leaf);
    void _preorder_print(Node *leaf);
    void _order_print(Node *leaf);
    void _clear(Node* leaf);
    int  height(Node* leaf);
    int bfactor(Node* leaf);
    void fixheight(Node* leaf);
    Node* rotateright(Node* leaf);
    Node* rotateleft(Node* leaf) ;
    Node*   balance(Node* leaf);
};
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
int Tree:: height(Node* leaf)
{
    return leaf?leaf->height:0;
}
int Tree:: bfactor(Node* leaf)
{
    return height(leaf->right)-height(leaf->left);
}
void Tree::_clear(Node* leaf)
{
    if(leaf!=nullptr){
        _clear(leaf->left);
        _clear(leaf->right);
        delete leaf;
    }
}
void Tree:: fixheight(Node* leaf)
{
    unsigned char hl = height(leaf->left);
    unsigned char hr = height(leaf->right);
    leaf->height = (hl>hr?hl:hr)+1;
}
Node* Tree:: rotateright(Node* leaf) // правый поворот вокруг p
{
    Node* q = leaf->left;
    leaf->left = q->right;
    q->right = leaf;
    fixheight(leaf);
    fixheight(leaf);
    return q;
}
Node* Tree:: rotateleft(Node* leaf) // левый поворот вокруг q
{
    Node* p = leaf->right;
    leaf->right = leaf->left;
    p->left = leaf;
    fixheight(leaf);
    fixheight(p);
    return p;
}
Node* Tree::  balance(Node* leaf) // балансировка узла p
{
    fixheight(leaf);
    if( bfactor(leaf)==2 )
    {
        if( bfactor(leaf->right) < 0 )
            leaf->right = rotateright(leaf->right);
        return rotateleft(leaf);
    }
    if( bfactor(leaf)==-2 )
    {
        if( bfactor(leaf->left) > 0  )
            leaf->left = rotateleft(leaf->left);
        return rotateright(leaf);
    }
    return leaf; // балансировка не нужна
}
Node* Tree::_add_node(int number,Node *leaf)
{
    if( !leaf ) return new Node(number,nullptr,NULL);
        if( number<leaf->data )
            leaf->left = _add_node(number,leaf->left);
        else
            leaf->right = _add_node(number,leaf->right );
        return balance(leaf);
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
        exit(0);
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
 



