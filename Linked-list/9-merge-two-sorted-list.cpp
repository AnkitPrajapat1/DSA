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

Node *mergeTwoLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    Node *l1 = head1;
    Node *l2 = head2;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        if (l1)
            temp->next = l1;
        else
            temp->next = l2;
    }
    return dummyNode->next;
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
    insertAtTail(8, head2, tail2);
    insertAtTail(10, head2, tail2);

    print(head2);

    print(mergeTwoLL(head1, head2));
    return 0;
}