// implementation of stack using LL
#include "linkedList.hpp"
using namespace std;

class stackLL
{
public:
  ListNode *top;
  int size;
  stackLL()
  {
    top = NULL;
    size = 0;
  }
  void stackPush(int x)
  {
    ListNode *element = new ListNode(x);
    element->next = top;
    top = element;
    cout << "Element pushed"
         << "\n";
    size++;
  }
  int stackPop()
  {
    if (top == NULL)
    {
      return -1;
    }
    int topData = top->data;
    ListNode *temp = top;
    top = top->next;
    delete temp;
    size--;
    return topData;
  }
  int stackSize()
  {
    return size;
  }
  bool stackIsEmpty()
  {
    return top == NULL;
  }
  int stackPeek()
  {
    if (top == NULL)
      return -1;
    return top->data;
  }
  void printStack()
  {
    ListNode *current = top;
    while (current != NULL)
    {
      cout << current->data << " ";
      current = current->next;
    }
  }
};
int main()
{
  stackLL s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}