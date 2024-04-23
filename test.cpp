#include <iostream>
#include <string.h>

int strtoken(char *str, const char *sep, char *token);

int main()
{
	char string[100];
	std::cout << "Input string:" << std::endl;
	std::cin >> string;
	int temp;
	do
	{
		char token[100] = "";
		temp = strtoken(string, " ", token);
		puts(token);
	} while (temp != 0);
	return 0;
}

int strtoken(char *str, const char *sep, char *token)
{
	char *temp = strstr(str, sep);
	int i = 0;
	while (str + i != temp && i != strlen(str))
		i++;
	if (i == strlen(str))
		return 0;
	else
	{
		strncpy(token, str, i);
		str = str + i;
		return 1;
	}
}