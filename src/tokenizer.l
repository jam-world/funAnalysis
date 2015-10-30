%{
#include "funAnalysis.tab.h"
extern "C"
{
  int yylex(void);
}
%}



%%

string {return STRING;}
int {return INT;}
[A-Za-z]+[0-9]* {yylval.s = strdup(yytext); return IDENT;}
"(" |
")" |
"," |
";" {return yytext[0];}
"\n"
.

%%
