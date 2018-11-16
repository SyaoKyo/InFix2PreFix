/****************************
*                          *
*  中缀表达式转前缀表达式  *
*                          *
****************************/
#include <iostream>
#include <cstring>
using namespace std;

int getPriority(char op);
void infix2prefix(char infix[], int length, char s2[], int &top2);
void reverseStack(char s2[], int top2, char s3[], int &top3);

const int maxSize = 1000;

int main()
{
	char infix[maxSize] , s2[maxSize], s3[maxSize];
	int top2 = -1, top3 = -1;
	cin >> infix;
	infix2prefix(infix, strlen(infix), s2, top2);
	reverseStack(s2, top2, s3, top3);
	cout << s3 << endl;
	return 0;
}

int getPriority(char op)
{
	if (op == '+' || op == '-')
		return 0;
	else
		return 1;
}

void infix2prefix(char infix[], int length, char s2[], int &top2)
{
	char s1[maxSize];
	int top = -1, i = length - 1;
	while (i >= 0)
	{
		if (infix[i] >= '0'&&infix[i] <= '9')
			s2[++top2] = infix[i--];
		else if (infix[i] == ')')
		{
			s1[++top] = ')';
			i--;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			if (top == -1 || s1[top] == ')' || getPriority(infix[i]) >= getPriority(s1[top]))
				s1[++top] = infix[i--];
			else
				s2[++top2] = s1[top--];
		}
		else if (infix[i] == '(')
		{
			while (s1[top] != ')')
				s2[++top2] = s1[top--];
			top--;
			i--;
		}
	}
	while (top != -1)
		s2[++top2] = s1[top--];
}
void reverseStack(char s2[], int top2, char s3[], int &top3)
{
	while (top2 != -1)
		s3[++top3] = s2[top2--];
	s3[++top3] = '\0';
}