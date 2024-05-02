#ifndef SYNT_ANALYZER_H
#define SYNT_ANALYZER_H

// СИНТАКСИЧЕСКИЙ АНАЛИЗАТОР

#include <string>
#include <stack>

struct state
{
	int q; // состояние, в которое автомат должен перейти
	int S; // состояние, которое должно быть добавлено в стек
};

int synt_analyzer(std::string str);
int toktonum(char token);

#endif
