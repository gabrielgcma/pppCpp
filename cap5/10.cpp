#include <iostream>
#include <cmath>
#include "std_lib_facilities.h"

void firstN (vector<double> nums, int n)
{
    if(n > nums.size()) error("Out of range!");
    
    double sum = 0;
    for(int i=0; i<n; ++i)
    {
        sum += nums[i];
    }

    cout << "The sum of the first "<< n <<" elements is: " << sum << "\n";
}

void firstNdiffs (vector<double> nums, int n)
{
    if(n > nums.size()) error("Out of range!");

    vector<double> diffs;
    for(int i=0; i<n; ++i)
    {
        double diff;
        diff = abs(nums[i]-nums[i+1]);
        diffs.push_back(diff);
    }
    
    cout << "The diference between the first " << n << " values are:\n";
    for(double diff : diffs)
    {
        cout << diff << ' ';
    }
}

int main()
{
    cout << "Enter the number of values you want to sum:\n";
    int n;
    cin >> n;
    
    cout << "Enter some doubles (enter '|' to stop):\n";
    vector<double> doubles;
    double d;
    while(cin >> d)
    {   
        doubles.push_back(d);
    }

    try
    {
        firstN(doubles, n);
        firstNdiffs(doubles, n);
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}