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
int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }
};
