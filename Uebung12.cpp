#include <stdio.h>
#include <iostream>
#include <string>

// S: A
// A: 1B|1|0
// B: 0B|0|1B|1

// S: 1A|1|0
// A: 0A|0|1A|1

char token;
char current;
std::string text;
void S();
void A();
void B();


int binToDez(std::string t)
{
    int dezimal = 0;
    for (char c : t)
    {
        if (c == '1')
        {
            dezimal = dezimal * 2 + 1;
        }
        else if (c == '0')
        {
            dezimal = dezimal * 2 + 0;
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
    if (token == '1' || token == '0')
    {
        A();
    }
    else
        printf("Syntaxfehler: 1 oder 0 erwartet\n");
}

void A()
{
    if (token == '0')
    {
        printf("Regel A->0 angewandt\n");
        check('0');
        std::cout << "Binaer: " << text << "Dezimal: "<< binToDez(text) << std::endl;
    }
    else if (token == '1')
    {
        check('1');

        if (current == '\n')
        {
            printf("Regel A->1 angewandt!\n");
            std::cout << "Binaer: " << text << "Dezimal: "<< binToDez(text) << std::endl;
        }
        else
        {
            printf("Regel A->1B angewandt\n");
            B();
        }
    }
    else
    {
        printf("Syntaxfehler in A: '0' oder '1' erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void B()
{
    if (token == '0')
    {
        check('0');

        if (current == '\n')
        {
            printf("Regel B->0 angewandt!\n");
            std::cout << "Binaer: " << text << "Dezimal: "<< binToDez(text) << std::endl;
        }
        else
        {
            printf("Regel B->0B angewandt\n");
            B();
        }
    }
    else if (token == '1')
    {
        check('1');

        if (current == '\n')
        {
            printf("Regel B->1 angewandt!\n");
            std::cout << "Binaer: " << text << "Dezimal: "<< binToDez(text) << std::endl;
        }
        else
        {
            printf("Regel B->1B angewandt\n");
            B();
        }
    }
    else
    {
        printf("Syntaxfehler in B: 1 oder 0 erwartet\n");
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