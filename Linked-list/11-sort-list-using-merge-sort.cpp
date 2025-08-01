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

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

Node *sortList(Node *head)
{
    if (head->next == NULL)
        return head;
    Node *middle = findMiddle(head);
    Node *left = head;
    Node *right = middle->next;
    middle->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeTwoLL(left, right);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(1, head, tail);
    insertAtTail(4, head, tail);
    insertAtTail(2, head, tail);
    insertAtTail(11, head, tail);
    insertAtTail(5, head, tail);
    insertAtTail(7, head, tail);
    insertAtTail(3, head, tail);
    print(head);
    head = sortList(head);
    print(head);
    return 0;
}