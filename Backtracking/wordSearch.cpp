// Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are
// horizontally or vertically neighboring. The same letter cell may not be used more than once.
#include <iostream>
#include <vector>

using namespace std;
class WordSearch
{
public:
    bool help(vector<vector<char>> &board, string word, int i, int j, int n, int m, int k)
    {
        if (k >= word.size())
            return true;
        if (i < 0 || i > n || j < 0 || j >= m || board[i][j] == '.' || word[k] != board[i][j]) // check in vertical horizontal direction , check if we already tracked that word and word at kth index is not what we want
            return false;
        if (word.size() == 1 && word[k] == board[i][j])
            return true;
        board[i][j] = '.';
        bool temp = false;
        int x[4] = {0, 0, -1, 1}; // x and y coordinates
        int y[4] = {-1, 1, 0, 0};

        for (int index = 0; index < 4; index++)
        {
            temp = temp || help(board, word, i + x[index], j + y[index], n, m, k + 1);
        }
        board[i][j] = word[k]; // backtrack
        return temp;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        if (word.size() == 0)
            return false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (word[0] == board[i][j])
                {
                    if (help(board, word, i, j, m, n, 0))
                        return true;
                }
            }
        }
        return false;
    }
};