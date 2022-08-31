#include <iostream>
#include "std_lib_facilities.h"

using namespace std;

int main()
{
    // bull = right number in the right position
    // cow = right number in the wrong position

    vector<int> v(4);
    vector<int> guess(4);

    int seed, cows = 0, bulls = 0;

    while(true) 
    {
        system("clear");
        cout << "Try to guess the correct sequence of numbers!\n";
        cout << "Enter a seed number:\n";
        cin >> seed;

        seed_randint(seed);

        for(int i=0; i<4; ++i)
        {
            v[i] = randint(10);
        }

        while(true)
        {
            cout << "Type your guess:\n";

            if(bulls == 4)
            {
                cout << bulls << " bulls and " << cows << " cows\n";
                bulls = 0; cows = 0;
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
                    break;
                }
            }

            cout << bulls << " bulls and " << cows << " cows\n";

            if(bulls == 4) 
            {
                bulls = 0;
                cows = 0;
                break;
            }

            bulls = 0;
            cows = 0;
        }

        cout << "Well done! Press ENTER to continue\n";
        setbuf(stdin, NULL);
        getchar();
    }
}