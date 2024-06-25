#include <bits/stdc++.h>
using namespace std;
// swap two numbers without third variable
void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int main()
{
    int a = 2, b = 5;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}