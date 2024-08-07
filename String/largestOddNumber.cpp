#include <bits/stdc++.h>
using namespace std;
string largestOddNumber(string num)
{
    string odd = "";
    int n = num.length();
    for (int i = n - 1; i >= 0; --i)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            odd = num.substr(0, i + 1);
            break;
        }
    }

    return odd;
}
int main()
{

    string num = "4532";
    cout << largestOddNumber(num) << endl;
    return 0;
}