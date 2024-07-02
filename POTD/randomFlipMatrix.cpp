#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row, col;
    int last_row = 0;
    int last_col = 0;
    Solution(int m, int n)
    {
        row = m;
        col = n;
    }

    vector<int> flip()
    {
        int ROW = last_row, COL = last_col;

        if (last_col + 1 < col)
            last_col++;
        else if (last_row + 1 < row)
        {
            last_row++;
            last_col = 0;
        }
        else
            last_row = 0, last_col = 0;
        // cout << "ROW :: " << ROW << "COL :: " << COL << endl;
        return {ROW, COL};
    }

    void reset()
    {
    }
};
int main()
{
    // ["Solution","flip","flip","flip","reset","flip"];

    Solution soln(3, 1);
    soln.flip();
    soln.flip();
    soln.flip();
    soln.reset();
    soln.flip();

    return 0;
}