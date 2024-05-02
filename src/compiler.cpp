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
		addSpaces(&str);			   // добавляем недостающие пробелы
		int flag = lex_analyzer(&str); // производим лексический анализ, составляем строку токенов
		if (flag == -1)
			std::cout << "Lex_analyze: Failed" << std::endl;
		else
		{
			std::cout << "Lex_analyze: Correct" << std::endl;
			synt_analyzer(str); // производим синтаксический анализ строки токенов
			if (synt_analyzer(str) == 0)
				std::cout << "Synt_analyze: Correct" << std::endl;
			else
				std::cout << "Synt_analyze: Failed" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Input string:" << std::endl;
		std::getline(std::cin, str);
	}
	return 0;
}
