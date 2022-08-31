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

int main()
{
    int size;
    cout << "Enter how many numbers of the Fibonacci sequence you want to see:\n";
    cin >> size;

    nFib(size);
}