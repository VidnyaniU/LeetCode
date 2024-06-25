#include <bits/stdc++.h>
using namespace std;
// print 1 to n without loop
void printNums(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    printNums(n - 1);
    cout << n << " ";
}
int main()
{
    printNums(10);
    return 0;
}