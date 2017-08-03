#include<stdio.h>
#include<string.h>
#include"skel.h"
int check_keyword(char *word);

char *reserved_key1[] = {"const", "volatile", "extern", "auto", "register", "static", "signed", "unsigned", "short", "long", "double", "char", "int", "float", "struct", "union", "enum", "void", "typedef", "FILE"};
char *reserved_key2[] = {"goto", "return", "continue", "break", "if", "else", "for", "while", "do", "switch", "case", "default", "sizeof", "EOF", "stderr", "stdout", "stdin"};





int check_keyword(char *buff)
{
    int idx = 0, count = 0;
    while(*reserved_key1[idx])
    {
	if (strcmp(reserved_key1[idx++] , buff) == 0)
	{

	    return 1;

	}

	else

	{
	    count++;
	    if (count == 20)
	    {
		goto loop;
	    }
	}

    }

loop:

    idx = 0;

    while(*reserved_key2[idx])
    {

	if (strcmp(reserved_key2[idx++] , buff) == 0)
	{
    return 5;

	}
	else
	{
	    count++;
	    if (count == 37)

	    {
		return 0;
	    }
	}




    }



}


