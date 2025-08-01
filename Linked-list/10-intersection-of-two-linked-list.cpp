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
    cout << endl;
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

Node *intersectionPoint(Node *head1, Node *head2)
{
    Node *t1 = head1;
    Node *t2 = head2;
    while (t1 != t2)
    { // if t1==t2 then they must be NULL or same non null node
        if (t1 == t2)
            return t1;
        if (t1 == NULL)
            t1 = head2; // if t1 become null then point it to the head2
        if (t2 == NULL)
            t2 = head1; // if t2 become null then point it to the head1
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    insertAtTail(1, head1, tail1);
    insertAtTail(3, head1, tail1);
    insertAtTail(5, head1, tail1);
    insertAtTail(6, head1, tail1);
    insertAtTail(9, head1, tail1);

    print(head1);

    Node *head2 = NULL;
    Node *tail2 = NULL;
    insertAtTail(2, head2, tail2);
    insertAtTail(4, head2, tail2);
    insertAtTail(7, head2, tail2);
    tail2->next = head1->next->next;

    print(head2);

    Node *result = intersectionPoint(head1, head2);
    cout << result->data;
    return 0;
}