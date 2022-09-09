#include "std_lib_facilities.h"

int main()
{
    string n;
    cout << "Type a numer:\n";
    cin >> n;
    
    int thousands = 0, hundreds = 0, tens = 0, ones = 0;

    for (int i=0; i<n.size(); i++)
    {
        if (n.size() == 4)
        {
            switch (i)
            {
                case 0:
                    thousands += n[i] - '0';
                    break;

                case 1:
                    hundreds += n[i] - '0';
                    break;

                case 2:
                    tens += n[i] - '0';
                    break;

                case 3:
                    ones += n[i] - '0';    
                    break;
            }   
        }

        if (n.size() == 3)
        {
            switch(i)
            {
                case 0:
                    hundreds += n[i] - '0';
                    break;

                case 1:
                    tens += n[i] - '0';
                    break;
                
                case 2:
                    ones += n[i] - '0';
                    break;
            }
        }

        if (n.size() == 2)
        {
            switch(i)
            {
                case 0: 
                    tens += n[i] - '0';
                    break;

                case 1:
                    ones += n[i] - '0';
                    break;
            }
        }

        if (n.size() == 1)
            ones += n[i];
    }

    switch(n.size())
    {
        case 1:
            cout << n << " is " << ones << " ones\n";
            break;

        case 2:
            cout << n << " is " << tens << " tens and " << ones << " ones\n";
            break;
        
        case 3:
            cout << n << " is " << hundreds << " hundreds and " << tens << " tens and " << ones << " ones\n";
            break;

        case 4:
            cout << n << " is " << thousands << " thousands and " << hundreds << " hundreds and " << tens
                 << " tens and " << ones << " ones\n";  
            break;
    }
}