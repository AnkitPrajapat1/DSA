#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtHead(int data, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // create new node
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(int data, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // create new node
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

Node *getTail(Node *&head)
{
    Node *tail = NULL;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return tail = temp;
}

void insertAtPosition(int data, Node *&head, Node *&tail, int position)
{
    // if(position<=1) insertAtHead(data,head,tail);
    // if(position>=getLength(head)+1) insertAtTail(data,head,tail);
    // Node *temp=head;
    // Node *prev=NULL;
    // Node *curr=head;
    // Node *newNode=new Node(data);
    // while(position!=1){
    //     prev=curr;
    //     curr=curr->next;
    //     position--;
    // }
    // prev->next=newNode;
    // newNode->next=curr;

    // using only previous pointer
    if (position <= 1)
        insertAtHead(data, head, tail);
    if (position >= getLength(head) + 1)
        insertAtTail(data, head, tail);
    Node *temp = head;
    Node *prev = head;
    Node *newNode = new Node(data);
    while (position > 2)
    {
        prev = prev->next;
        position--;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}
int main()
{

    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail=findTail(head);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(10, head, tail);
    insertAtTail(20, head, tail);
    insertAtTail(30, head, tail);
    insertAtTail(40, head, tail);
    insertAtTail(50, head, tail);
    insertAtHead(5, head, tail);
    insertAtPosition(1000, head, tail, 4);

    print(head);

    return 0;
}