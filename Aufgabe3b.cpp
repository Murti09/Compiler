#include <iostream>

// Die Sprache der ganzen Dezimalzahlen (Integer) mit Vorzeichen und ohne führende 0

int main()
{
    char c;
    c = getchar();

    if (c == '+' || c == '-')
        c = getchar();
    else
    {
        std::cout << "Akzeptiert nicht" << std::endl;
        return 1;
    }

    if(c=='0')
        {
            std::cout << "Akzeptiert nicht" << std::endl;
            return 1;
        }

    if (c >= '1' && c <= '9')
    {
        c = getchar();

        while (c >= '1' && c <= '9')
            c = getchar();

        if ((c < '0' || c > '9') && c != '\n')
        {
            std::cout << "Akzeptiert nicht" << std::endl;
            return 1;
        }

        std::cout << "Akzeptiert" << std::endl;
        return 0;
    }

    std::cout << "Akzeptiert nicht" << std::endl;
    return 1;
}