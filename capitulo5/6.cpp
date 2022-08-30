#include <iostream>

using std::cout;
using std::cin;

double c_to_f(double c)
{
    double f = (c * 9/5) + 32;
    return f;
}

double f_to_c(double f)
{
    double c = (f-32.0) * 5/9;
    return c;
}

int main()
{
    int op;
    cout<<"1. Celsius to Farenheit\n2. Farenheit to Celsius\n";
    cin>>op;
    if(op == 1)
    {
        double c;
        cin>>c;
        cout<<c<<" is "<<c_to_f(c)<<" degrees Farenheit\n";
    }

    if(op == 2)
    {
        double f;
        cin>>f;
        cout<<f<<" is "<<f_to_c(f)<<" degrees Celsius\n";
    }
}