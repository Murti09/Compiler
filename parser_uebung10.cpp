#include <stdio.h>

// S: AB
// A: aaA|B
// B: b

char token;
void S();
void A();
void B();

char scanner()
{
    return getchar();
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
    if (token == 'a' || token == 'b')
    {
        A();
        B();
    }
    else
        printf("Syntaxfehler: a oder b erwartet\n");
}

void A()
{
    if (token == 'a')
    {
        printf("Regel A->aaA angewandt\n");
        check('a');
        check('a');
        A();
    }
    else if (token == 'b')
    {
        printf("Regel A->B angewandt\n");
        B();
    }
    else
    {
        printf("Syntaxfehler in A: 'a' oder 'b' erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void B()
{
    if (token == 'b')
    {
        printf("Regel B->b angewandt\n");
        check('b');
    }
    else
    {
        printf("Syntaxfehler in B: 'b' erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

int main()
{
    while (!feof(stdin))
        parser();
}