// add two numbers without using addition or subtraction function
#include <bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
    for (int i = 1; i <= b; i++)
        a++;

    return a;
}
int main()
{
    cout << add(2, 3) << endl;
    return 0;
}