#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include"main.h"
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
 typedef struct myNumber {
    Node* head;
    Node* tail;
    int size;
};
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
    for(int i=strlen(str)-1;i>=0;i--){
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
    Node *temp=number->tail->prev;
    while(temp){
        printf("%d",temp->data);
        temp=temp->prev;
    }
}
int main(int argc, const char * argv[]) {
    myNumber a = Create("5897");
    LongDivShort(&a, 10);
    myNumber b = Create("12389");
    LongDivShort(&b, 12);
    Show(&b);
    return 0;
}
