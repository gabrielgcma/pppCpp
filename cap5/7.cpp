#include <iostream>
#include <cmath>
#include "std_lib_facilities.h"

using namespace std;

void roots(double a, double b, double c)
{
    double delta = b*b - 4*a*c;
    if(delta < 0) error("\nThere are no roots to the equation!\n");
    double r1 = (-b + sqrt(delta)) / 2*a;
    double r2 = (-b - sqrt(delta)) / 2*a;

    cout<<"The roots are: "<<r1<<" and "<<r2<<"\n";
}

int main()
{
    double a, b, c;
    cout<<"Enter the coefficients of the quadratic formula:\n";
    cin>>a>>b>>c;
    try
    {
        roots(a, b, c);
    }
    catch(exception& e)
    {
        cerr<<e.what()<<'\n';
    }   
}