#include "std_lib_facilities.h"

int fatorial(int num)
{ 
    if (num == 0 || num == 1) 
        return 1;
    return num * fatorial(num - 1);
}

// permutação de n elementos tomados p a p
int permutation(int n, int p)
{
    return (fatorial(n)) / fatorial(n - p);
}

// combinação de n elementos tomados p a p 
int combination(int n, int p)
{
    return (permutation(n, p)) / fatorial(p);
}

int main()
{
    cout << "--- Permutation and Combination Calculator ---"
         << "\nEnter your input in the form: (P or C) (number of elements) (taken p at a time)"
         << "\nType x x x and Enter to quit\n";

    char op;
    int n, p;
    
    while(true)
    {
        cin >> op >> n >> p;
    
        switch (op)
        {
            case 'p': case 'P':
                cout << "Result: " << permutation(n, p) << '\n';
                break;

            case 'c': case 'C':
                cout << "Result: " << combination(n, p) << '\n';
                break;

            case 'x': case 'X':
                exit(0);

            default:
                error("Bad input"); 
        }   
    }
}