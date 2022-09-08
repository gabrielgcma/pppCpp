#include <iostream>
#include "std_lib_facilities.h"

class Name_value
{
public:
    string name;
    int score;
};

int main()
{   
    vector<Name_value> people;

    cout << "Enter name and score. Terminate input typing 'NoName'\n";
    while(true)
    {
        Name_value person;
        cin >> person.name >> person.score;
        bool existent = false;

        if (people.size() != 0 || people.size() != 1)
        {
            for(Name_value i : people)
            {
                if (i.name == person.name)
                    error("Same person entered twice.");
            }
        }
    
        if (person.name == "NoName") 
            break;
        else 
            people.push_back(person);
    }

    cout << "Entered:\n";
    for(Name_value person : people)
        cout << person.name << ' ' << person.score << '\n';
}