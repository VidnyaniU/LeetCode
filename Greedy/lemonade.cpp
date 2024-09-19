#include <bits/stdc++.h>
using namespace std;

/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.*/
bool lemonadeChange(vector<int> &bills)
{

    int five = 0;
    int ten = 0;

    for (int i = 0; i < bills.size(); i++)
    {

        if (bills[i] == 5)
        {

            five++;
        }

        else if (bills[i] == 10)
        {

            if (five)
            {

                five--;
                ten++;
            }

            else
                return false;
        }

        else
        {
            if (five && ten)
            {
                five--;
                ten--;
            }

            else if (five >= 3)
            {

                five -= 3;
            }

            else
                return false;
        }
    }
    return true;
}
int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << lemonadeChange(bills) << endl;
    return 0;
}