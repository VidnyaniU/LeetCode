#include <bits/stdc++.h>
using namespace std;
int numWaterBottles(int numBottles, int numExchange)
{
    if (numBottles < numExchange)
        return numBottles;
    int sum = numBottles;
    cout << "Sum :: " << sum << endl;

    int newBottles = (numBottles) / numExchange;
    cout << "newBottles :: " << newBottles << endl;

    int remaining = numBottles % numExchange;
    cout << "remaining :: " << remaining << endl;

    while (newBottles > 0)
    {
        // if(bottlesAfterExchange<numExchange)return sum+1;
        sum += newBottles;
        cout << "Sum :: " << sum << endl;
        
        remaining =( newBottles+remaining) % numExchange;
        cout << "remaining :: " << remaining << endl;

        newBottles = round((newBottles + remaining) / numExchange);
        cout << "newBottles :: " << newBottles << endl;

    }
    return sum;
}

int main()
{
    int numBottles = 19;
    int numExchange = 4;
    numWaterBottles(numBottles, numExchange);
    // cout << endl
    //  << "Maximum number of water bottles :: " << numWaterBottles(numBottles, numExchange) << endl;
    return 0;
}