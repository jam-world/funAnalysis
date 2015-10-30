%{
#include <iostream>
#include "fun.hpp"
#include "funTab.hpp"

funTab *current;
fun* currentFun;


// define some extern functions to make grammer.y suitable for cpp
void yyerror(const char *s)
{
	fprintf(stderr, "error: %s\n", s);
}

int counter = 0;

extern "C"
{
        int yyparse(void);
        int yylex(void);  
        int yywrap()
        {
                return 1;
        }

}

using namespace std;
 
%}

%union{
  char* s;
 }

%token <s> IDENT
%token INT
%token STRING


%type <s> T


%%

S:
D
| S D

D:
T IDENT '(' L ')' ';'
   {
     currentFun->setReturnType($1);
     if (current->isFunExist($2)) {
       if (!current->getFun($2)->isFunSame(currentFun))
         cout << "declaration error for function: " << $2 << endl;
     } else {
       current->addFun($2,currentFun);
     }
     currentFun = new fun();
   }
| T IDENT '(' ')' ';'
   {
     currentFun->setReturnType($1);
     if (current->isFunExist($2)) {
       if (!current->getFun($2)->isFunSame(currentFun))
         cout << "declaration error for function: " << $2 << endl;
     } else {
       current->addFun($2,currentFun);
     }
     currentFun = new fun();
   }

L:
P
| L ',' P

P:
T IDENT {currentFun->addVar($2,$1);}

T:
INT {$$="int";}
| STRING {$$="string";}

%%

int main(int argc, char** argv) {
  current = new funTab();
  currentFun = new fun();
  yyparse();
  current->print();
  return 0;
}

void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}


