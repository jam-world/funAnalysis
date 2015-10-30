calculator: funAnalysis.y tokenizer.l *.cpp
	bison -d funAnalysis.y
	flex tokenizer.l
	g++ -o funAnalysis funAnalysis.tab.c lex.yy.c *.cpp -ll -I../include 
