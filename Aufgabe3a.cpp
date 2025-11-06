#include <iostream>

// L(1*0*0)

int main()
{
    char c;
    c = getchar();

    while (c == '1')
        c = getchar();

    if (c == '0')
    {
        while (c == '0')
            c = getchar();

        if (c != '0' && c != '\n')
        {
            std::cout << "Akzeptiert nicht" << std::endl;
            return 1;
        }

        std::cout << "Akzeptiert" << std::endl;
    }
    else
        std::cout << "Akzeptiert nicht" << std::endl;
}