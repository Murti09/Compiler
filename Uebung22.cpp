#include <stdio.h>
#include <iostream>
#include <string>

// S: ABbC
// A: bbD
// D: A | B
// B: aE
// E: cC | epsilon
// C: F
// F: cF | epsilon

char token;
char current;
void S();
void A();
void B();
void C();
void D();
void E();
void F();

char scanner()
{
    current = getchar();
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
    if (token == 'b')
    {
        printf("Regel S->ABbC angewandt\n");
        A();
        B();
        check('b');
        C();
    }
    else
        printf("Syntaxfehler: b erwartet\n");
}

void A()
{
    if (token == 'b')
    {
        printf("Regel A->bbD angewandt\n");
        check('b');
        check('b');
        D();
    }
    else
    {
        printf("Syntaxfehler in A: b erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void B()
{
    if (token == 'a')
    {
        printf("Regel B->aE angewandt\n");
        check('a');
        E();
    }
    else
    {
        printf("Syntaxfehler in B: a erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void C()
{
    printf("Regel C->F angewandt\n");
    F();
}

void D()
{
    if (token == 'b')
    {
        printf("Regel D->A angewandt\n");
        A();
    }
    else if (token == 'a')
    {
        printf("Regel D->B angewandt\n");
        B();
    }
    else
    {
        printf("Syntaxfehler in D: b oder a erwartet\n");
        while (token != '\n')
            token = scanner();
    }
}

void E()
{
    if (token == 'c')
    {
        printf("Regel E->cC angewandt\n");
        check('c');
        C();
    }
    else
    {
        printf("Regel E->epsilon angewandt\n");
        // epsilon Produktion, nichts zu tun
    }
}

void F()
{
    if (token == 'c')
    {
        printf("Regel F->cF angewandt\n");
        check('c');
        F();
    }
    else
    {
        printf("Regel F->epsilon angewandt\n");
        // epsilon Produktion, nichts zu tun
    }
}

int main()
{
    while (!feof(stdin))
    {
        parser();
    }
}