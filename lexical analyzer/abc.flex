%{
#include<stdio.h>
int cnt=0, lcnt=0;
%}

%%
[a-zA-Z]*\<[a-zA-Z|\.]*\>  { printf("\nHeaderfile : %s",yytext+7); }
"int"|"void"|"main"|"do"|"if"|"for" { printf("\nKeyword : %s",yytext); }
[a-zA-Z]*\( { printf("\nFunction %s",strcat(yytext,")")); }
"="|"+"|"-"|"++"|"--"|"*"|"<="|">=" { printf("\nOPerator %s",yytext); }
-?[0-9]* { printf("\n Number %s",yytext); }
" " { cnt++; }
"\n" { lcnt++; }
. { printf(" "); }
%%


main(int argc, char **argv)
{
FILE *fp ; 
fp= fopen(argv[1],"r");
yyin=fp;
yylex();
printf("\n NO of white spaces %d",cnt);
printf("\n NO of lines %d",lcnt);

}

int yywrap()
{
return 1 ; 
}
