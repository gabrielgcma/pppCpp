#include <iostream>
#include "std_lib_facilities.h"

void firstN (vector<int> nums, int n)
{
    if(n > nums.size()) error("Number of integers passed is out of range!");
    
    int sum = 0;
    for(int i=0; i<n; ++i)
    {
        sum += nums[i];
    }

    cout << "The sum of the first "<< n <<" elements is: " << sum << "\n";
}

int main()
{
    cout << "Enter the number of values you want to sum:\n";
    int n;
    cin >> n;
    
    cout << "Enter some integers (enter '|' to stop):\n";
    vector<int> nums;
    int num;
    while(cin >> num)
    {   
        nums.push_back(num);
    }

    try
    {
        firstN(nums, n);
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    
}