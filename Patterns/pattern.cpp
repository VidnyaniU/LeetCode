#include <bits/stdc++.h>
using namespace std;
void pattern5(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void pattern7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void pattern8(int n)
{
    int k = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= k)
                cout << "* ";
            else
                cout << " ";
        }
        k--;
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (j > k)
                cout << " *";
            else
                cout << " ";
        }
        k++;
        cout << endl;
    }
}
void pattern9(int n)
{
    pattern6(n);
    //+pattern7

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // space
        for (int j = 1; j <= (2 * n - 2 * i); j++)
        {
            cout << " ";
        } // numbers

        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }

        cout << endl;
    }
}

void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        // alphabet
        char ch = 'A';
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << ch;

            if (j < i)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        // spaces
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}

void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch;
        }

        cout << endl;
    }
}
int main()
{
    pattern18(5);
    return 0;
}