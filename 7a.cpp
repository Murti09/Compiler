#include <iostream>
using namespace std;

//a*(a|b)
int main()
{
    int zustand = 0;

    int c;

    while ((c = getchar()) != EOF)
    {
        switch (zustand)
        {
        case 0: // A
            if (c == 'a')
            {
                zustand = 1;
            }
            else if (c == 'b')
            {
                zustand = 2;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand A)" << endl;
                return 1;
            }
            break;
        case 1: // Endzustand B
            if (c == 'a')
            {
                zustand = 1;
            }
            else if (c == 'b')
            {
                zustand = 2;
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
        case 2: // Endzustand C
            if (c == '\n')
            {
                cout << "Akzeptiert (Zustand C)" << endl;
                return 0;
            }
            else
            {
                cout << "Akzeptiert nicht (Zustand C)" << endl;
                return 1;
            }
        default:
            break;
        }
    }
}