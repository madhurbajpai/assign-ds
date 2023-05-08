/*
Name: Madhur Bajpai
Reg. No.: 2022ca047
Date: 7-2-23
Objective: To convert and infix operation to a postfix operation
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 1000

//stack and top variable
char stack[MAX];
int top = -1;

//to push a character to stack
void push(char c)
{
	stack[++top] = c;
}

//popping from top of stack
char pop()
{
	if (top == -1)
		return -1;
	else
		return stack[top--];
}

//defines priority of the character
int priority(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

//infix to postfix conversion function
void infixToPostfix(char infix[], char postfix[])
{

	int i, j = 0;
	char c;
	
	//parsing the infix expression and changing it to postfix expression
	for (i = 0; i < strlen(infix); i++)
	{
		//checking the character
		c = infix[i];
		if (isalnum(c))
			postfix[j++] = c;
		//checking for brackets and pushing and popping using the bracket encountered
		else if (c == '(')
			push(c);
		else if (c == ')')
		{
			while (stack[top] != '(')
				postfix[j++] = pop();
			pop();
		}
		//in case of the operator priority the push pop changes
		else
		{
			//pushing to postfix expression from stack
			while (priority(stack[top]) >= priority(c))
				postfix[j++] = pop();
			//pushing element c
			push(c);
		}
	}
	//emptying the stack
	while (top != -1)
		postfix[j++] = pop();
	postfix[j] = '\0';
}


//driver function
int main()
{
	char infix[MAX], postfix[MAX];
	printf("Enter the Infix Expression: ");
	scanf("%s", infix);
	infixToPostfix(infix, postfix);
	printf("Postfix Expression: %s\n", postfix);
	return 0;
}

