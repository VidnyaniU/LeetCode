#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;
class stackLL
{
  int size = 0;

  void stackPush(int x)
  {
    ListNode *element = new ListNode(x);
    element->next = head; // top
    head = element;
    cout << "Element pushed"
         << "\n";
    size++;
  }
};
