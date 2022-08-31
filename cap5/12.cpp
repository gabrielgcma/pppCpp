#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
    // bull = right number in the right position
    // cow = right number in the wrong position

    vector<int> v = {2, 4, 6, 9};
    vector<int> guess(4);

    int cows = 0, bulls = 0;
    cout << "Try to guess the correct sequence of numbers:\n";

    while(true)
    {
        if(bulls == 4)
        {
            cout << bulls << " bulls and " << cows << " cows\n";
            break; 
        }

        for(int i=0; i<4; ++i)
        {
            int n; cin >> n;
            guess[i] = n;     
        }

        for(int i=0; i<4; ++i)
        {
            if(guess[i] == v[i]) bulls++;

            for(int j=0; j<4; ++j)
            {
                if((i != j) && (guess[i] == v[j])) cows++;
            }
        }

        cout << bulls << " bulls and " << cows << " cows\n";

        if(bulls == 4) break;

        bulls = 0;
        cows = 0;
    }

    cout << "Well done!\n"; 
}