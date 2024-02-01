// Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
using namespace std;

class phoneKeypad
{
private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
    {
        // base case
        if (index >= digits.length())
        {
            cout << output << endl;
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0'; // to get a number
        string value = mapping[number];   // mapping corresponding to that number

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
        {
            return ans;
        }

        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
int main()
{
    phoneKeypad pk;
    string digits = "345";
    pk.letterCombinations(digits);

    return 0;
}
