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

void addOne(Node *head)
{
    Node *temp = head;
    int carry = 1;
    Node *prev = NULL;
    while (temp != NULL)
    {
        int totalSum = temp->data + carry;
        if (totalSum < 10)
        {
            temp->data = totalSum;
            carry=0;
            break;
        }
        int digit = totalSum % 10;
        carry = totalSum / 10;
        temp->data = digit;
        prev = temp;
        temp = temp->next;
    }

    if (carry != 0)
    {
        Node *newNode = new Node(1);
        prev->next = newNode;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(9, head, tail);
    insertAtTail(1, head, tail);
    insertAtTail(4, head, tail);
    // insertAtTail(9, head, tail);
    // insertAtTail(9, head, tail);

    print(head);

    reverse(head);
    addOne(head);
    reverse(head);

    print(head);

    return 0;
}