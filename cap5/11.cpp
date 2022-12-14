#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

void nFib (int n)
{
    vector<int> fib(n);
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i<n; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    for(int n : fib)
    {   
        cout << n << ' ';
    }

    cout << '\n';   
}   

void largestFib (int limit)
{
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    int i = 2;
    while(true)
    {
        fib.push_back(fib[i-1] + fib[i-2]);

        if(fib[i] > limit)
        {
            cout << "The largest Fib numer that can fit inside " << limit << " is " << fib[i-1] << '\n';
            break;
        }  

        ++i;
    }
}

int main()
{
    int size;
    cout << "Enter how many numbers of the Fibonacci sequence you want to see:\n";
    cin >> size;

    nFib(size);

    int limit;
    cout << "Enter an integer to see the biggest Fibonacci integer that can fit in this int:\n";
    cin >> limit;

    largestFib(limit);
}