#include <iostream>
using namespace std;

// (01)*1*0
int main()
{
    int zustand = 0;

    int c;

    while ((c = getchar()) != EOF)
    {
        switch (zustand)
        {
        case 0: // A,C
            if (c == '0')
            {
                zustand = 1;
            }
            else if (c == '1')
            {
                zustand = 2;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand A,C)" << endl;
                return 1;
            }
            break;
        case 1: // Endzustand B
            if (c == '1')
            {
                zustand = 0;
            }
            else if (c == '\n')
            {
                cout << "Akzeptiert (Zustand B)" << endl;
                return 0;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand B)" << endl;
                return 1;
            }
            break;
        case 2: // D
            if (c == '0')
            {
                zustand = 3;
            }
            else if (c == '1')
            {
                zustand = 2;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand D)" << endl;
                return 1;
            }
            break;
        case 3: // Endzustand E
            if (c == '\n')
            {
                cout << "Akzeptiert (Zustand E)" << endl;
                return 0;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand E)" << endl;
                return 1;
            }
            break;
        default:
            break;
        }
    }
}