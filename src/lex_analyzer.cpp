#include "lex_analyzer.h"

// функция, разбивающая строку на токены
int lex_analyzer(std::string *str)
{
	size_t cur_ind{};																			// номер текущего элемента
	size_t spc_ind{};																			// номер следующего пробела
	std::array<std::string, 5> Terminals = {"if", "then", "else", ":=", ";"};					// массив терминалов
	while (((spc_ind = (str->find(" ", cur_ind))) != std::string::npos) && (str->length() > 1)) // цикл разбивает строку на лексемы по пробелу
	{
		std::string tempstr;											  // текущая лексема
		tempstr.append(str->substr(cur_ind, spc_ind - cur_ind));		  // записываем текущую лексему
		str->replace(cur_ind, spc_ind - cur_ind + 1, termtotok(tempstr)); // заменяем лексему на соответсвующий ей токен
		if (termtotok(tempstr) == "E")									  // если лексеме не соответсвутет никакой токен, то выводим ошибку
			return -1;
		cur_ind++;
	}
	if (spc_ind == 0 || str->length() < 2) // если в строке нет пробелов или длина строки меньше 2
		return -1;
	return 0;
}

// функция, добавляющая пробелы в строку
void addSpaces(std::string *str)
{
	size_t index{};
	while (((index = str->find(":=", index)) != std::string::npos) && (str->find(":=", index) != 0)) // цикл выполняющий добавление пробелов между операндом :=
	{
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
	if (str->length() > 1) // добавляем пробелы в конце и перед ;
	{
		if ((str->substr(str->length() - 2, 1) != " ") && (str->substr(str->length() - 1, 1) == ";"))
			str->insert(str->length() - 1, " ");
		if (str->substr(str->length() - 1, 1) != " ")
			str->append(" ");
	}
}

// функция, преобразующая терминалы в токены
std::string termtotok(std::string str)
{
	if (str == "if")
		return "f";
	if (str == "then")
		return "t";
	if (str == "else")
		return "e";
	if (str == ":=")
		return "a";
	if (str == ";")
		return ";";
	if (Identifier(str) == 0)
		return "i";
	if (Integer(str) == 0)
		return "n";
	return "E";
}

// функция, выполняющая лексический анализ идентификатора
int Identifier(std::string str)
{
	// таблица переходов автомата идентификатора
	int id_states[2][3] = {{1, -1, -1},
						   {1, 1, -1}};
	int id_q = 0;								  // текущее состояние автмоата
	int ind_str = 0;							  // текущий символ
	while (id_q != -1 && ind_str != str.length()) // цикл выполняет перебор строки символов до конца или до первого неверного сивола
	{
		id_q = id_states[id_q][chtostid(str[ind_str])]; // автомат принимает новое значение, в зависимости от текущего символа
		ind_str++;										// берем следующий символ
	}
	if (id_q == -1) // автомат пришел в ошибочное состояние
		return 1;
	return 0;
}

// функция, преобразующая символы в номера столбцов таблицы переходов автомата идентификатора
int chtostid(char ch)
{
	if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
		return 0;
	if (ch >= 48 && ch <= 57)
		return 1;
	return 2;
}

// функция, выполняющая лексический анализ целого числа
int Integer(std::string str)
{
	// таблица переходов автомата целого числа
	int int_states[2][3] = {{1, 1, -1},
							{-1, 1, -1}};
	int int_q = 0;								   // текущее состояние автмоата
	int ind_str = 0;							   // текущий символ
	while (int_q != -1 && ind_str != str.length()) // цикл выполняет перебор строки символов до конца или до первого неверного сивола
	{
		int_q = int_states[int_q][chtostint(str[ind_str])]; // автомат принимает новое значение, в зависимости от текущего символа
		ind_str++;											// берем следующий символ
	}
	if (int_q == -1) // автомат пришел в ошибочное состояние
		return 1;
	return 0;
}

// функция, преобразующая символы в номера столбцов таблицы переходов автомата целого числа
int chtostint(char ch)
{
	if ((ch == 43) || (ch == 45))
		return 0;
	if (ch >= 48 && ch <= 57)
		return 1;
	return 2;
}
