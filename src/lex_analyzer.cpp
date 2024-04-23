#include "lex_analyzer.h"

int lex_analyzer(std::string *str)
{
	size_t cur_ind{};
	size_t spc_ind{};
	std::array<std::string, 5> Terminals = {"if", "then", "else", ":=", ";"};
	while ((spc_ind = (str->find(" ", cur_ind))) != std::string::npos)
	{
		std::string tempstr;
		tempstr.append(str->substr(cur_ind, spc_ind - cur_ind));
		str->replace(cur_ind, spc_ind - cur_ind + 1, termtotok(tempstr));
		if (termtotok(tempstr) == "E")
			return -1;
		cur_ind++;
	}
	return 0;
}

void addSpaces(std::string *str)
{
	size_t index{};
	while (((index = str->find(":=", index)) != std::string::npos) && (str->find(":=", index) != 0))
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

	if ((str->substr(str->length() - 2, 1) != " ") && (str->substr(str->length() - 1, 1) == ";"))
		str->insert(str->length() - 1, " ");
	if (str->substr(str->length() - 1, 1) != " ")
		str->append(" ");
}

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

int Identifier(std::string str)
{
	int id_states[2][3] = {{1, -1, -1},
						   {1, 1, -1}};
	int id_q = 0;
	int ind_str = 0;
	while (id_q != -1 && ind_str != str.length())
	{
		id_q = id_states[id_q][chtostid(str[ind_str])];
		ind_str++;
	}
	if (id_q == -1)
		return 1;
	return 0;
}

int chtostid(char ch)
{
	if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
		return 0;
	if (ch >= 48 && ch <= 57)
		return 1;
	return 2;
}

int Integer(std::string str)
{
	int int_states[2][3] = {{1, 1, -1},
							{-1, 1, -1}};
	int int_q = 0;
	int ind_str = 0;
	while (int_q != -1 && ind_str != str.length())
	{
		int_q = int_states[int_q][chtostint(str[ind_str])];
		ind_str++;
	}
	if (int_q == -1)
		return 1;
	return 0;
}

int chtostint(char ch)
{
	if ((ch == 43) || (ch == 45))
		return 0;
	if (ch >= 48 && ch <= 57)
		return 1;
	return 2;
}