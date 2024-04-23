#include <iostream>
#include <stack>
#include <string>
#include "compiler.h"

int main()
{
	std::string str;
	std::cout << "Input string:" << std::endl;
	std::getline(std::cin, str);
	while (str != "end")
	{
		addSpaces(&str);
		lex_analyzer(&str);
		if (lex_analyzer(&str) == -1)
			std::cout << "Incorrect identifier or number" << std::endl;
		else
		{
			synt_analyzer(str);
			if (synt_analyzer(str) == 0)
				std::cout << "Correct" << std::endl;
			else
				std::cout << "Failed" << std::endl;
			std::cout << "Input string:" << std::endl;
			std::getline(std::cin, str);
		}
	}
	return 0;
}
