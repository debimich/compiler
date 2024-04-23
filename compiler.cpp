#include <iostream>
#include <cstring>

struct state
{
	int q;
	int S;
};

struct stack
{
	int nums[100];
	int top;
};

int scanner(char *res, char *inp);
char terminals(char *term);
void init(stack *stk);
void push(stack *stk, int num);
int pop(stack *stk);
int transform(char token);

int main()
{
	state states[13][7] = {{{2, 1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 0
						   {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {15, -1}},	// 1
						   {{3, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 2
						   {{-1, -1}, {4, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 3
						   {{-1, -1}, {-1, -1}, {5, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 4
						   {{2, 8}, {6, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},		// 5
						   {{-1, -1}, {-1, -1}, {-1, -1}, {7, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 6
						   {{-1, -1}, {8, -1}, {-1, -1}, {-1, -1}, {8, -1}, {-1, -1}, {-1, -1}},	// 7
						   {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {9, -1}, {-2, -2}},	// 8
						   {{2, 12}, {10, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 9
						   {{-1, -1}, {-1, -1}, {-1, -1}, {11, -1}, {-1, -1}, {-1, -1}, {-1, -1}},	// 10
						   {{-1, -1}, {12, -1}, {-1, -1}, {-1, -1}, {12, -1}, {-1, -1}, {-1, -1}},	// 11
						   {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-2, -2}, {-2, -2}}}; // 12
	stack stk;
	init(&stk);
	char string[100];
	std::cout << "Input string:" << std::endl;
	std::cin >> string;
	while (strcmp(string, "end") != 0)
	{
		int qpre = 0;
		int q = 0;
		int ind = 0;
		while (q != -1 && q != 15)
		{
			qpre = q;
			q = states[q][transform(string[ind])].q;
			if (q == 2)
				push(&stk, states[qpre][transform(string[ind])].S);
			else if (q == -2)
				q = pop(&stk);
			else
				ind++;
		}
		if (q == 15 && ind == strlen(string))
			std::cout << "Correct" << std::endl;
		else
			std::cout << "Failed" << std::endl;
		std::cout << "Input string:" << std::endl;
		std::cin >> string;
	}
	return 0;
}

int addSpaces(char *res, char *inp)
{
	
}

int scanner(char *res, char *inp)
{
	char *temp = strtok(inp, " ");
	char *temp2;
	while (temp != NULL)
	{
		if (terminals(temp) != '0')
			snprintf(res, strlen(res), "%s", terminals(temp));
		else
		{
			temp2 = strstr(temp, ":=");
			if (temp2 == NULL)
			{
				// Identifier();
			}
		}
		temp = strtok(NULL, " ");
	}
}

char terminals(char *term)
{
	if (strcmp(term, "if") == 0)
		return 'f';
	if (strcmp(term, "then") == 0)
		return 't';
	if (strcmp(term, "else") == 0)
		return 'e';
	if (strcmp(term, ";") == 0)
		return ';';
	if (strcmp(term, ":=") == 0)
		return 'a';
	return '0';
}

void init(stack *stk)
{
	stk->top = 0;
}

void push(stack *stk, int num)
{
	stk->nums[stk->top] = num;
	stk->top++;
}

int pop(stack *stk)
{
	int num;
	stk->top--;
	num = stk->nums[stk->top];
	return num;
}

int transform(char token)
{
	switch (token)
	{
	case 'f':
		return 0;
		break;
	case 'i':
		return 1;
		break;
	case 't':
		return 2;
		break;
	case 'a':
		return 3;
		break;
	case 'n':
		return 4;
		break;
	case 'e':
		return 5;
		break;
	case ';':
		return 6;
		break;
	default:
		return -1;
		break;
	}
}