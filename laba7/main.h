#include<fstream>
struct Node
{
    Node*previous;
    Node*next;
    char flightNumber[15];
    char planeType[15];
    char country[15];
    char interCountry[50];
    char time[15];
    int seats[20];
    char days[50];
    
    Node(Node *previous,Node*next){
        this->previous=previous;
        this->next=next;
    }
};
class List
{
public:
    Node *head;
    Node *tail;
    int size;
public:
    List();
    void Delete_list(FILE *file2);
    void Show();
    void Push_back(FILE *file);
    int Size();
    bool Empty();
    ~List();
};