#include <iostream>

// Die Sprache der ganzen Binärzahlen ohne führende 0

int main()
{
    char c;
    c = getchar();

    if (c != '1')
    {
        std::cout << "Akzeptiert nicht" << std::endl;
        return 1;
    }
    else 
    {
        while(c == '0' || c == '1')
            c = getchar();

        if(c != '0' && c != '1' && c != '\n')
        {
            std::cout << "Akzeptiert nicht" << std::endl;
            return 1;
        }

        std::cout << "Akzeptiert" << std::endl;
    }
    return 0;
}