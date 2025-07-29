#include <iostream>
#include <vector>
#include <unordered_map>
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

bool detectCycleUsingMap(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, int> um;
    while (temp != NULL)
    {
        if (temp == 0)
        {
            um[temp] = 1;
        }
        else
            return true;
    }
    return false;
}

bool detectCycleUsingSlowFast(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
            return true;
    }
    return false;
}

Node *getStartingPointOfCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    Node *pos = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            pos = slow;
            return pos;
        }
    }
    return pos;
}
void removeCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    Node *pos = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
            
        }
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
    insertAtTail(60, head, tail);

    // print(head);
    // reverse(head);
    // cout<<endl;
    // print(head);

    // reverse using recurrsion
    Node *prev = NULL;
    Node *curr = head;
    Node *loop = tail;
    loop->next = head->next->next;

    // cout << detectCycleUsingMap(head);
    // cout << detectCycleUsingSlowFast(head);
    Node *pos = getStartingPointOfCycle(head);
    cout << "data of first node of cycle: " << pos->data;
    removeCycle(head);
    print(head);
    cout << endl;
    return 0;
}