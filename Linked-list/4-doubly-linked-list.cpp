#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        if (position <= 1)
        {
            insertAtHead(head, tail, data);
        }
        else if (position >= getLength(head) + 1)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            Node *newNode = new Node(data);
            Node *currNode = head;
            while (position != 1)
            {
                position--;
                currNode = currNode->next;
            }
            newNode->next = currNode;
            newNode->prev = currNode->prev;
            currNode->prev->next = newNode;
            currNode->prev = newNode;
        }
    }
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "can't delete LL is empty" << endl;
    }
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if (position == getLength(head))
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {

        Node *currNode = head;
        Node *prevNode = NULL;
        while (position != 1)
        {
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node *nextNode = currNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;

        // Node *currNode = head;

        // while (position != 1)
        // {
        //     position--;
        //     currNode = currNode->next;
        // }
        // currNode->prev->next=currNode->next;
        // currNode->next->prev=currNode->prev;
        // currNode->next=NULL;
        // currNode->prev=NULL;
        // delete currNode;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    // insertAtPosition(head, tail, 500, 4);
    print(head);
    cout << endl;
    deleteAtPosition(head, tail, 4);
    print(head);

    return 0;
}