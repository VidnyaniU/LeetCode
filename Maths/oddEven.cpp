#include <bits/stdc++.h>
using namespace std;
// find if the number is odd or even without using conditional statement

int main()
{
    vector<string> arr = {"Even", "Odd"};
    int num = 9;
    cout << arr[num % 2] << endl;
    return 0;
}