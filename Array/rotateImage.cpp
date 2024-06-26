#include <bits/stdc++.h>
using namespace std;

// rotate the image by 90 degree
void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void rotate(vector<vector<int>> &matrix)
{

    transpose(matrix);
    // reverse the elements row-wise
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{

    return 0;
}