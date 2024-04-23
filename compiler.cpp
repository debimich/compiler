#include <iostream>
#include <stack>
#include <string>

struct state
{
	int q;
	int S;
};

int transform(char token);
int addSpaces(std::string *str);

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
	std::stack<int> stack;
	std::string str;
	std::cout << "Input string:" << std::endl;
	std::getline(std::cin, str);
	while (str != "end")
	{
		addSpaces(&str);
		int qpre = 0;
		int q = 0;
		int ind = 0;
		while (q != -1 && q != 15)
		{
			qpre = q;
			q = states[q][transform(str[ind])].q;
			if (q == 2)
				stack.push(states[qpre][transform(str[ind])].S);
			else if (q == -2)
			{
				q = stack.top();
				stack.pop();
			}
			else
				ind++;
		}
		if (q == 15 && ind == str.length())
			std::cout << "Correct" << std::endl;
		else
			std::cout << "Failed" << std::endl;
		std::cout << "Input string:" << std::endl;
		std::cin >> str;
	}
	return 0;
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

int addSpaces(std::string *str)
{
	size_t index{};
	while ((index = str->find(":=", index)) != std::string::npos)
	{
		std::cout << index << std::endl;
		if (str->substr(index - 1, 1) != " ")
		{
			str->insert(index, " ");
			index++;
		}
		if (str->substr(index + 2, 1) != " ")
		{
			str->insert(index + 2, " ");
			index++;
		}
		index += 2;
	}
	return 0;
}