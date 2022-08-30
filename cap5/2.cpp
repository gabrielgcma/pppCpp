#include "std_lib_facilities.h"
#include <iostream>

double c_To_K(double c)
{
    if(c < 0) error("Below 0K temperature!");
    int k = c+273.15;
    return k;
}

double k_To_C(double k)
{
    if(k < 0) error("Below 0K temperature!");
    int c = k-273.15;
    return c;
}

int main()
{
    try 
    {
        int op;
        double c = 0, k = 0;
        cout<<"1. C to K\n2. K to C\nWhich operation do you want to perform?\n";
        cin>>op;
        if(op == 1)
        {
            cin>>c;
            double k = c_To_K(c);
            cout<<k<<"\n";
        }else
        {
            cin>>k;
            double c = k_To_C(k);
            cout<<c<<"\n";
        }
    }   
    catch(exception& e)
    {
        cerr<<"error: "<<e.what()<<"\n";
    }
}
