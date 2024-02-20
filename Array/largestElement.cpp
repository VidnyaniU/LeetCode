// find the largest element in the array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2, 8, 5, 3, 2, 1, 9};
    int largest = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout << "Largest element : " <<largest;

    return 0;
}