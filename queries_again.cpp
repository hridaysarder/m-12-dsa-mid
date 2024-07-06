#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_index(Node *&head, Node *&tail, int index, int val)
{
    Node *newNode = new Node(val);

    if (index < 0)
    {
        cout << "Invalid" << endl;
        delete newNode;
        return;
    }

    if (index == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }

    Node *temp = head;
    int cnt = 0;

    while (temp != NULL && cnt < index - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL && index > 0)
    {
        cout << "Invalid" << endl;
        delete newNode;
        return;
    }

    if (temp == NULL)
    {
        cout << "Invalid" << endl;
        delete newNode;
        return;
    }

    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
    else
    {
        newNode->next = temp->next;
        newNode->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void print_linked_list(Node *head, Node *tail)
{
    if (head == NULL)
    {
        cout << "L -> " << endl;
        cout << "R -> " << endl;
        return;
    }

    cout << "L -> ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "R -> ";
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;
        insert_at_index(head, tail, x, v);
        print_linked_list(head, tail);
    }

    return 0;
}
