#include <iostream>
using namespace std;

// 0*1*0
int main()
{
    int zustand = 0;

    int c;

    while ((c = getchar()) != EOF)
    {
        switch (zustand)
        {
        case 0: // A
            if (c == '0')
            {
                zustand = 2;
            }
            else if (c == '1')
            {
                zustand = 1;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand A)" << endl;
                return 1;
            }
            break;
        case 1: // B
            if (c == '1')
            {
                zustand = 1;
            }
            else if (c == '0')
            {
                zustand = 3;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand B)" << endl;
                return 1;
            }
            break;
        case 2: // Endzustand C
            if (c == '0')
            {
                zustand = 2;
            }
            else if (c == '1')
            {
                zustand = 1;
            }
            else if (c == '\n')
            {
                cout << "Akzeptiert (Zustand C)" << endl;
                return 0;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand C)" << endl;
                return 1;
            }
            break;
        case 3: // Endzustand D
            if (c == '\n')
            {
                cout << "Akzeptiert (Zustand D)" << endl;
                return 0;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand D)" << endl;
                return 1;
            }
            break;
        default:
            break;
        }
    }
}