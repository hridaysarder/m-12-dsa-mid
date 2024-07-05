#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void remove_duplicate(list<int> &mylist)
{
    mylist.sort();
    mylist.unique();
}

void print_linked_list(list<int> &myList)
{
    for (int val : myList)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    list<int> myList;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        myList.push_back(val);
    }
    remove_duplicate(myList);
    print_linked_list(myList);
    return 0;
}