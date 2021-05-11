#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;
 typedef struct {
    Node* head;
    Node* tail;
    int size;
}myNumber;
void Add(myNumber *number,int str)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=str;
    temp->prev=NULL;
    temp->next=NULL;
    if(number->head==NULL){
        number->tail= number-> head=temp;
    }else{
        temp->prev=number->tail;
        number->tail->next=temp;
        number->tail=temp;
    }
    number->size++;
}
 myNumber Create(char* str)
{
    myNumber number={NULL,NULL,0};
    int i=0;
    for(i=strlen(str)-1;i>=0;i--){
        Add(&number,str[i]-'0');
    }
    return number;
}
void LongDivShort(myNumber *number,int x)
{
    Node *temp=number->tail;
    Node *another=number->tail->prev;
    while(temp){
        if(temp!=number->head){
            another->data+=(temp->data%x)*10;
        }
        temp->data/=x;
        if(temp!=number->head){
            another=another->prev;
        }
        temp=temp->prev;
    }
    Node *first=number->tail;
    number->tail=first->prev;
    number->tail->next=NULL;
    free(first);
}
int Equal(myNumber *number1,myNumber *number2)
{
    myNumber *first=number1;
    myNumber *second=number2;
    if(first->size>second->size){
        return 1;
    }else if(first->size<second->size){
        return -1;
    }else{
        Node* temp1=number1->tail;
        Node* temp2=number2->tail;
        while(1){
            if(temp1->data>temp2->data){
                return 1;
            }else if(temp1->data<temp2->data){
                return -1;
            }
            temp1=temp1->prev;
            temp2=temp2->prev;
            if(temp1==NULL && temp2==NULL){
                return 0;
            }
        }
    }
}
void Show(myNumber *number)
{
    Node *temp=number->tail;
    while(temp){
        printf("%d",temp->data);
        temp=temp->prev;
    }
}
int main(int argc, const char * argv[]) {
    myNumber a = Create("5899");
    myNumber b = Create("5899");
    printf("%d",Equal(&a,&b));
    return 0;
}

