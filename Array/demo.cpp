#include <bits/stdc++.h>
using namespace std;
void sum(int a, int b, int &c)
{
    a = b + c;
    b = a + c;
    c = a + b;
}
int main()
{
    int x = 2, y = 3;
    sum(x, y, y);
    cout << x << " " << y << endl; // pass by reference the value of y changes same while swapping two numbers

    return 0;
}