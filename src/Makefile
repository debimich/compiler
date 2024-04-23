CC = g++
CFLAGS = -c

all:	compiler

compiler:	compiler.o synt_analyzer.o lex_analyzer.o
	$(CC) compiler.o synt_analyzer.o lex_analyzer.o -o compiler

compiler.o:	compiler.cpp compiler.h
	$(CC) $(CFLAGS) compiler.cpp -o compiler.o

synt_analyzer.o:	synt_analyzer.cpp synt_analyzer.h
	$(CC) $(CFLAGS) synt_analyzer.cpp -o synt_analyzer.o

lex_analyzer.o:	lex_analyzer.cpp lex_analyzer.h
	$(CC) $(CFLAGS) lex_analyzer.cpp -o lex_analyzer.o

clean:
	rm -rf *.o compiler