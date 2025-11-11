#include <stdio.h>

// S: ABC
// A: aB|b
// B: bb|C
// C: c

char token;
void S();
void A();
void B();
void C();

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
    if (token == 'a' || token == 'b' || token == 'c')
    {
        A();
        B();
        C();
    }
    else
        printf("Syntaxfehler: a, b oder c erwartet\n");
}

void A()
{
    if (token == 'a')
    {
        printf("Regel A->aB angewandt\n");
        check('a');
        B();
    }
    else if (token == 'b')
    {
        printf("Regel A->b angewandt\n");
        check('b');
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
        printf("Regel B->bb angewandt\n");
        check('b');
        check('b');
    }
    else if (token == 'c')
    {
        printf("Regel B->C angewandt\n");
        C();
    }
    else
    {
        printf("Syntaxfehler in B: b oder c erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void C()
{
    if (token == 'c')
    {
        printf("Regel C->c angewandt\n");
        check('c');
    }
    else
    {
        printf("Syntaxfehler in C: c erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

int main()
{
    while (!feof(stdin))
        parser();
}