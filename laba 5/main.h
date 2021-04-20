typedef struct{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;
typedef struct{
    Node* head;
    Node* tail;
    int size;
}myNumber;
void Add(myNumber *number,int str);
myNumber Create(char* str);
int Equal(myNumber *number1,myNumber *number2);
int BigNumber(myNumber *number1);
void LongDivShort(myNumber *number,int x);
void Show(myNumber *number);