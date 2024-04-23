#ifndef LEX_ANALYZER_H
#define LEX_ANALYZER_H

#include <string>
#include <array>

int lex_analyzer(std::string *str);
void addSpaces(std::string *str);
std::string termtotok(std::string str);
int Identifier(std::string str);
int chtostid(char ch);
int Integer(std::string str);
int chtostint(char ch);

#endif