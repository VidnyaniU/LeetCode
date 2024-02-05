// Given n pairs of parentheses,
// write a function to generate all combinations of well-formed parentheses.
#include <iostream>
#include <vector>
using namespace std;
class GenerateParanthesis
{
public:
    void help(vector<string> &v, int n, int oc, int cc, string s)
    {
        // when oc and cc are balanced and equal to n , return
        if (oc == n && cc == n)
        {
            v.push_back(s);
            return;
        }

        // opening bracket count is always less than n
        if (oc < n) // oc is opening bracket count
        {
            help(v, n, oc + 1, cc, s + "(");
        }

        // closing bracket count cannot be greater than opening bracket count
        if (cc < oc) // cc is closing bracket count
        {
            help(v, n, oc, cc + 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        int oc = 0, cc = 0;
        help(v, n, oc, cc, "");
        return v;
    }
};