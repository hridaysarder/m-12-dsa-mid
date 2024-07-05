#include <bits/stdc++.h>
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
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void palindrome(Node *head, Node *tail)
{
    bool isPalindrome = true;
    while (head != tail && head->prev != tail)
    {
        if (head->val != tail->val)
        {
            isPalindrome = false;
            break;
        }
        head = head->next;
        tail = tail->prev;
    }
    if (isPalindrome == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head, tail, val);
    }
    palindrome(head, tail);
    return 0;
}