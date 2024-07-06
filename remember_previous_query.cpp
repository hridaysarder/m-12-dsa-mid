#include <bits/stdc++.h>
using namespace std;

void print_linked_list(list<int> &myList)
{
    cout << "L -> ";
    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "R -> ";
    for (auto it = myList.end(); it != myList.begin();)
    {
        it--;
        cout << *it << " ";
    }
    cout << endl;
}
void previous_query(list<int> &myList, int x, int v)
{
    if (x == 0)
    {
        myList.push_front(v);
    }
    else if (x == 1)
    {
        myList.push_back(v);
    }
    else if (x == 2)
    {
        if (v >= 0 && v < myList.size())
        {
            auto it = myList.begin();
            for (int i = 0; i < v; i++)
            {
                it++;
            }
            myList.erase(it);
        }
    }
}

int main()
{
    int q;
    cin >> q;
    list<int> myList;
    while (q--)
    {
        int x, v;
        cin >> x >> v;
        previous_query(myList, x, v);
        print_linked_list(myList);
    }
    return 0;
}
