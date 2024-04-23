#ifndef SYNT_ANALYZER_H
#define SYNT_ANALYZER_H

#include <string>
#include <stack>

struct state
{
	int q;
	int S;
};

int synt_analyzer(std::string str);
int toktonum(char token);

#endif