#include <stdio.h>
#include "skel.h"
#include <string.h>

int src_to_html(FILE *source, FILE *des)
{
    char ch;
    char buff[100];
    int i = 0;

    while(1)
    {
	ch = fgetc(source);
	memset(buff, 0, sizeof(buff));
	i = 0;
        /**********preprocessor directive**************/
	if (ch == '#')
	{
	    fseek(source, -1L, SEEK_CUR);

	    do
	    {
		ch = fgetc(source);


		buff[i] = ch;	
		i++;

	    }while((ch != '<') && (ch != ' ') && (ch != '\"'));

	    buff[i - 1] = '\0';

	    fseek(source, -1L, SEEK_CUR);
	    apply_color(des, buff, s2_preprocessor);

	    //puts(buff);

	}

        /***************single line comment***********/
	else if (ch == '/') 
	{
	    ch = fgetc(source);
	    if (ch == '/')
	    {

		fseek(source, -2L, SEEK_CUR);

		do
		{
		    ch = fgetc(source);
		    buff[i] = ch;
		    i++;
		}while((ch != '\n'));
		buff[i] = '\0';

		//puts(buff);
		apply_color(des, buff, s1_comment);
	    }

	    else if (ch == '*')
	    {

		fseek(source, -1L, SEEK_CUR);
		buff[i] = '/';
		i++;


		do
		{
		    ch = fgetc(source);
		    buff[i] = ch;
		    i++;
		}while((ch != '/'));
		buff[i] = '\0';

		//puts(buff);
		apply_color(des, buff, s1_comment);
	    }




	}

        /********************header files directive************/
	else if(ch == '\"')
	{
	    fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    i++;
	    do
	    {
		ch = fgetc(source);
		buff[i] = ch;
		i++;
	    }while((ch != '\"'));

	    buff[i] = '\0';
	    


	    //puts(buff);

	    apply_color(des, buff, s3_headerfile);
	}
	/***********header*******************/

	else if(ch == '<')
	{
	    fseek(source, -9L, SEEK_CUR);
	    ch = fgetc(source);
	    fseek(source, 9L, SEEK_CUR);



	    if (ch == '#')
	    {
		fseek(source, -2L, SEEK_CUR);

		do
		{
		    ch = fgetc(source);
		    buff[i] = ch;
		    i++;
		}while((ch != '>'));

		buff[i] = '\0';
		apply_color(des, buff, s3_headerfile);

	    }

	    else 
	    {
		fseek(source, -2L, SEEK_CUR);
		ch = fgetc(source);
		buff[i] = ch;
		apply_color(des, buff, s0_idle);
	    }

         }
/**************************ascii char********************/

	else if(ch == '\'')
	{
	     fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    i++;
	    do
	    {
		ch = fgetc(source);
		buff[i] = ch;
		i++;
	    }while((ch != '\''));

	    buff[i] = '\0';


	    //puts(buff);

	    apply_color(des, buff, s8_ASCII_char);
	}

/******************************************************************/
	else if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
	{
	    int x;
	    
	    fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    fseek(source, 1L, SEEK_CUR);

	    if (ch != '#')
	    {
		fseek(source, -2L, SEEK_CUR);
		ch = fgetc(source);
		buff[i] = ch;
		i++;
		do
		{
		    ch = fgetc(source);
		    buff[i] = ch;
		    i++;
		}while((ch != ' ') && (ch != '(') && (ch != ')') && (ch != '[') && (ch != '\n'));

		buff[i-1] = '\0';
		fseek(source, -1L, SEEK_CUR);


		x = check_keyword(buff);
		//printf("%s - %d\n", buff, x);

		if (x == 1)
		{
		     apply_color(des, buff, s4_res_keyword_data);
		}

		else if (x == 5)
		{
		    apply_color(des, buff, s5_res_keyword_non_data);
		}

		else if (x == 0)
		{
		    apply_color(des, buff, s0_idle);
		}
	    }


	}
	

/*****************************************************/
	else if (ch >= '0' && ch <= '9')
	{

	    fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    i++;
	    do
	    {
		ch = fgetc(source);
		buff[i] = ch;
		i++;
	    }while((ch != ' ') && (ch != ',') && (ch != ';') && (ch != ')') && (ch != '}') && (ch != ']'));

	    buff[i-1] = '\0';
	    fseek(source, -1L, SEEK_CUR);



	    apply_color(des, buff, s7_numeric_constant);
	}


/**********************************************************************/


	else if (ch == '\n' || ch == ' ' || ch == '(' || ch == ')'|| ch == '{'|| ch == '}' || ch == ',' || ch == '[' || ch == ']') 
	{
	    fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    apply_color(des, buff, s0_idle);
	}

/*****************************************************************************/

	else if(ch == ';')
	{ fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    apply_color(des, buff, s0_idle);
	}


	else if (ch =='*'|| ch ==  '-'|| ch == '%'|| ch == '=' || ch == '<'|| ch == '>' || ch == '~'|| ch == '&' || ch == '!' || ch ==  '^' || ch == '|')
	{ fseek(source, -1L, SEEK_CUR);
	    ch = fgetc(source);
	    buff[i] = ch;
	    apply_color(des, buff, s0_idle);



	}

/**************************************************************************/
	if (ch == EOF)
	    break;

    }



}




