/**
 * Problema A - Maratona de 2011
 * Título: Ácido Ribonucleico Alienígena
 * Categoria: Pilha, Strings
 * Solução em C
 * Problema 1242 do URI
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *str;
    int len;
} stack;

void init(stack *pilha)
{
    pilha->str = (char *) malloc(301 * sizeof(char));
    pilha->len = 0;
}

void clear(stack *pilha)
{
    pilha->str[0] = '\0';
    pilha->len = 0;
}

int empty(stack *pilha)
{
    return (pilha->len == 0);
}

void pop(stack *pilha)
{
    if (!empty(pilha))
    {
        pilha->len--;
        pilha->str[pilha->len] = '\0';
    }
}

void push(stack *pilha, char c)
{
    pilha->str[pilha->len] = c;
    pilha->len++;
    pilha->str[pilha->len] = '\0';
}

char top(stack *pilha)
{
    return (pilha->str[pilha->len -1]);
}

int solve(stack *pilha, char* str, int str_len)
{
    int i;
    for(i = 0; i < str_len; i++)
    {
        if  (!empty(pilha) && ((str[i] == 'B' && top(pilha) == 'S') ||
                              ( str[i] == 'S' && top(pilha) == 'B')))
        {
            pop(pilha);
        }
        else if (!empty(pilha) && ((str[i] == 'C' && top(pilha) == 'F') ||
                                  ( str[i] == 'F' && top(pilha) == 'C')))
        {
            pop(pilha);
        }
        else
        {
            push(pilha, str[i]);
        }
    }

    return pilha->len;
}

int main()
{
    int ans, len;
    char *str = (char *) malloc(301 * sizeof(char));
    stack *pilha = (stack *) malloc(sizeof(stack));

    init(pilha);

    while(scanf("%s", str) != EOF)
    {
        len = strlen(str);
        ans = (len - solve(pilha, str, len))/2;
        printf("%d\n", ans);
        clear(pilha);
    }

    return 0;
}
