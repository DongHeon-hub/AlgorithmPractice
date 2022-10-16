#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

// lparen, rparen, plus, minus, times, divide, mod, eos
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
char *expr;
char *postfix;
int *stack;
precedence *pre_stack;
int top = 0;
int pre_top = 0;
int Index = 0;
void push(int num);
void pop();
void pre_push(precedence token);
precedence pre_pop();
void printToken(precedence token);
void InfixToPostfix();
int front(); // stack의 top 원소 반환
int eval();
precedence getToken(char *symbol, int *n);
precedence getVal(char *symbol, int *n){
    *symbol = postfix[(*n)++];

    switch (*symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return times;
    case '/':
        return divide;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

char getOperator(precedence token){
    switch(token){
        case plus:
            return '+';
        case minus :
            return '-';
        case times :
            return '*';
        case divide :
            return '/';
        case mod :
            return '%';
    }
}


int main()
{
    int sizeOfexpr;
    scanf("%d", &sizeOfexpr);

    expr = (char *)malloc(sizeof(char) * sizeOfexpr);
    postfix = (char *)malloc(sizeof(char) * sizeOfexpr);
    stack = (int *)malloc(sizeof(int) * sizeOfexpr);
    pre_stack = (precedence *)malloc(sizeof(precedence) * sizeOfexpr);
    while (1)
    {
        Index = 0;
        scanf("%s", expr);
        if (expr[0] == '\n')
            break;
        InfixToPostfix();

        printf("The evalution of %s is %d\n", expr, eval());
    }

    return 0;
}

void push(int num)
{
    stack[top++] = num;
}

void pop()
{
    top--;
}

int front()
{
    return stack[top - 1];
}

// postfix expression 을 evalute 해줌
int eval()
{
    precedence token;
    int n = 0;
    char symbol;

    token = getVal(&symbol, &n);

    while (token != eos)
    {
        if (token == operand)
        {
            push(symbol - '0');
        }

        else
        {
            int op2 = front();
            pop();
            int op1 = front();
            pop();

            switch (token)
            {
            case plus:
                push(op1 + op2);
                break;
            case minus:
                push(op1 - op2);
                break;
            case times:
                push(op1 * op2);
                break;
            case divide:
                push(op1 / op2);
                break;
            case mod:
                push(op1 % op2);
                break;
            }
        }

        token = getVal(&symbol, &n);
    }

    int val = front();
    pop();
    return val;
}

void pre_push(precedence token)
{
    pre_stack[pre_top++] = token;
}

precedence pre_pop()
{
    return pre_stack[--pre_top];
}

void InfixToPostfix()
{
    // expr에 infix notation 저장

    char symbol;
    int n = 0;
    precedence token;

    pre_push(eos);

    for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
    {
        if (token == operand){
            printf("%c", symbol);
            postfix[Index++] = symbol;
        }

        else
        {
            if (token == rparen)
            {
                while (pre_stack[pre_top - 1] != lparen)
                {
                    postfix[Index++] = getOperator(pre_stack[pre_top - 1]);
                    printToken(pre_pop());
                }

                pre_pop();
            }
            else
            {
                while (isp[pre_stack[pre_top - 1]] >= icp[token])
                {
                    postfix[Index++] = getOperator(pre_stack[pre_top - 1]);
                    printToken(pre_pop());
                }
                pre_push(token);
            }
        }
    }

    while (pre_stack[pre_top - 1] != eos)
    {
        postfix[Index++] = getOperator(pre_stack[pre_top - 1]);
        printToken(pre_pop());
    }

    postfix[Index] = '\0';

    printf("\n");
}

void printToken(precedence token)
{
    switch (token)
    {
    case plus:
        printf("+");
        return;
    case minus:
        printf("-");
        return;

    case times:
        printf("*");
        return;

    case divide:
        printf("/");
        return;

    case mod:
        printf("%");
        return;
    }
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];

    switch (*symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return times;
    case '/':
        return divide;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return operand;
    }
}