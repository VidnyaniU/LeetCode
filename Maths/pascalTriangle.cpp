#include <bits/stdc++.h>
using namespace std;
// n = num of rows
void printPascal(int n)
{
    for (int row = 1; row < n; row++)
    {
        int ans = 1;
        cout << ans << " ";
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            cout << ans << " ";
        }
        cout << endl;
    }
}
int main()
{
    printPascal(5);
    return 0;
}