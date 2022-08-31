#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

bool valid_weekday(string weekday)
{
    string valid_ones[7] = {"Sunday", 
                            "Monday", 
                            "Tuesday", 
                            "Wednesday", 
                            "Thursday", 
                            "Friday", 
                            "Saturday"};

    string valid_ones_short[7] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

    for (string day : valid_ones)
    {
        if (weekday == day) return true;
    }

    for(string day : valid_ones_short) 
    {
        if (weekday == day) return true;
    }

    return false;
}

int main()
{
    vector<string> weekdays;
    vector<int> weekdays_values;

    string weekday;
    int weekday_value, rejected_vals = 0;

    cout << "Enter entries in the format example 'Thursday 99' and type '| |' and press ENTER to stop:\n";

    while (cin >> weekday >> weekday_value)
    {
        if (valid_weekday(weekday))
        {
            weekdays.push_back(weekday);
            weekdays_values.push_back(weekday_value);
        }
        else
        {
            ++rejected_vals;
        }
    }

    int sum = 0;
    for(int n : weekdays_values)
    {
        sum += n;
    }

    cout << "The sum of the valid weekdays values is: " << sum << '\n';
    cout << "The number of rejected entries is: " << rejected_vals << '\n';
}