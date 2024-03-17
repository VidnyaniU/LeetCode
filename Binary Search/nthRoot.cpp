#include <bits/stdc++.h>
using namespace std;
// find the  nth root of a number else return -1

// to find nth power of i
long long utilityF(int i, int n)
{
    long long ans = 1;
    long long base = i;


    while (n>0)
    {
        if (n%2)
        {
            /* code */
        }
        
    }
    

}
long long nthRootBrute(int n, long long  number)
{
    for (int i = 1; i <= number; i++)
    {
        if (utilityF(i, n) == number)
        {
            return i;
        }
        else if (utilityF(i, n) > number)
        {
            break;
        }
    }

    return -1;
}
int main()
{

    return 0;
}