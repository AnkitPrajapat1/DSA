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
    ~Node()
    {
        cout << "Destructor called for: " << this->data << endl;
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

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    if(head==tail){
        Node *temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
    }

    int length = getLength(head);
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else if (position == length)
    {
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    print(head);
    deleteNode(head, tail, 4);
    cout << endl;
    print(head);

    return 0;
}