// An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits
#include <bits/stdc++.h>
using namespace std;
// brute
bool isArmstrongBrute(int x)
{
    vector<int> num;
    int temp = x;
    while (temp > 0)
    {
        num.push_back(temp % 10);
        temp = temp / 10;
    }
    int power = num.size();
    int y = 0;
    for (auto it : num)
    {
        y += pow(it, power);
    }
    return (x == y);
}

bool isArmstrong(int x)
{
    int power = to_string(x).length();
    int num = x;
    int sum = 0;
    while (num > 0)
    {
        sum += pow(num % 10, power);
        num = num / 10;
    }
    return (x == sum);
}
int main()
{
    int x = 153;
    cout << isArmstrong(x) << endl;

    return 0;
}