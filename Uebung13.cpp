#include <stdio.h>
#include <iostream>
#include <string>

// S: A
// A: 1A|1

char token;
char current;
std::string text;
void S();
void A();

int unToDez(std::string t)
{
    int dezimal = 0;
    for (char c : t)
    {
        if (c == '1')
        {
            dezimal++;
        }
    }
    
    return dezimal;
}

char scanner()
{
    current = getchar();
    text.push_back(current);
    return current;
}

void check(char e_token)
{
    if (token == e_token)
        token = scanner();
    else
    {
        printf("Syntaxfehler: %c erwartet\n", e_token);
        while (token != '\n')
            token = scanner(); // Lesen bis Eingabeende
    }
}

void parser()
{
    token = scanner();
    S();
    while (token != '\n')
    {
        printf("Syntaxfehler am Eingabeende\n");
        token = scanner();
    }
}

void S()
{
    if (token == '1')
    {
        A();
    }
    else
        printf("Syntaxfehler: 1 erwartet\n");
}

void A()
{
    if (token == '1')
    {
        check('1');
        if (current == '\n')
        {
            printf("Regel A->1 angewandt!\n");
            std::cout << "Unaer: " << text << "Dezimal: "<< unToDez(text) << std::endl;
        }
        else
        {
            printf("Regel A->1A angewandt\n");
            A();
        }
    }
    else
    {
        printf("Syntaxfehler in A: 1 erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

int main()
{
    while (!feof(stdin))
    {
        parser();
        text.clear();
    }
}