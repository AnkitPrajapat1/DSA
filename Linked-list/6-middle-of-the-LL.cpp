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

Node *getMiddle(Node *head)
{
    Node *temp = head;
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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
    insertAtTail(60, head, tail);
    print(head);

    // using two iteration
    //  int n = getLength(head);
    //  int position = n / 2 + 1;
    //  Node *middle = head;
    //  while (position != 1)
    //  {
    //      position--;
    //      middle = middle->next;
    //  }
    //  cout << endl
    //       << "Middle is: " << middle->data;

    // using fast and slow pointer/Tortoise algo

    Node *middle = getMiddle(head);
    cout << endl
         << "Middle is: " << middle->data;
    return 0;
}