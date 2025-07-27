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

void reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

Node *reverseUsingRecursion(Node *prev, Node *curr)
{

    if (curr == NULL)
    {
        return prev;
    }
    Node *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    return reverseUsingRecursion(prev, curr);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(10, head, tail);
    insertAtTail(20, head, tail);
    insertAtTail(30, head, tail);
    insertAtTail(40, head, tail);
    insertAtTail(50, head, tail);

    // print(head);
    // reverse(head);
    // cout<<endl;
    // print(head);

    // reverse using recurrsion
    Node *prev = NULL;
    Node *curr = head;
    print(head);
    cout << endl;
    print(reverseUsingRecursion(prev, curr));
    return 0;
}