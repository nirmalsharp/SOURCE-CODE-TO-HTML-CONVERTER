#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"skel.h"
#include"html_basic.h"

char temp_buff[1000];

void apply_color (FILE *des, char *string, State_e state)
{
    /* check for < and > symbol, if present replace with &lt; and &gt; resp */

    memset (temp_buff, '\0', sizeof (temp_buff));
    replace_html_symbol (string);

    /* code to apply HTML tags and color scheme on source string */
    switch (state)
    {
	case s0_idle:
	    fprintf (des, "<span class=\"idle\">%s</span>", temp_buff);
	    break;

	case  s1_comment:
	    fprintf (des, "<span class=\"comment\">%s</span>", temp_buff);
	    break;

	case  s2_preprocessor:
	    fprintf (des, "<span class=\"preprocess_dir\">%s</span>", temp_buff);
	    break;

	case  s3_headerfile:
	    fprintf (des, "<span class=\"header_file\">%s</span>", temp_buff);
	    break;

	case  s4_res_keyword_data:
	    fprintf (des, "<span class=\"reserved_key1\">%s</span>", temp_buff);
	    break;

	case  s5_res_keyword_non_data:
	    fprintf (des, "<span class=\"reserved_key2\">%s</span>", temp_buff);
	    break;

	case  s6_string:
	    fprintf (des, "<span class=\"string\">%s</span>", temp_buff);
	    break;

	case  s7_numeric_constant:
	    fprintf (des, "<span class=\"numeric_constant\">%s</span>", temp_buff);
	    break;

	case  s8_ASCII_char:
	    fprintf (des, "<span class=\"char\">%s</span>", temp_buff);
	    break;
    }
}

void replace_html_symbol (char *dat)
{
    int index = 0, jndex = 0;
    while(dat [jndex])
    {
	if (dat [jndex] == '<')
	{
	    temp_buff [index++] = '&'; 
	    temp_buff [index++] = 'l'; 
	    temp_buff [index++] = 't'; 
	    temp_buff [index++] = ';'; 
	}
	else if (dat [jndex] == '>')
	{
	    temp_buff [index++] = '&'; 
	    temp_buff [index++] = 'g'; 
	    temp_buff [index++] = 't'; 
	    temp_buff [index++] = ';'; 
	}
	else
	{
	    temp_buff [index++] = dat [jndex]; 
	}
	jndex++;
    }
    temp_buff [index] = '\0';

}

void apply_color1 (FILE *des, char ch, State_e state)
{
    /* check for < and > symbol, if present replace with &lt; and &gt; resp */

    //memset (temp_buff, '\0', sizeof (temp_buff));
    //replace_html_symbol (string);

    /* code to apply HTML tags and color scheme on source string */
    switch (state)
    {
	case s0_idle:
	    fprintf (des, "<span class=\"idle\">%c</span>", ch);
	    break;

	case  s1_comment:
	    fprintf (des, "<span class=\"comment\">%c</span>", ch);
	    break;

	case  s2_preprocessor:
	    fprintf (des, "<span class=\"preprocess_dir\">%c</span>", ch);
	    break;

	case  s3_headerfile:
	    fprintf (des, "<span class=\"header_file\">%c</span>", ch);
	    break;

	case  s4_res_keyword_data:
	    fprintf (des, "<span class=\"reserved_key1\">%c</span>", ch);
	    break;

	case  s5_res_keyword_non_data:
	    fprintf (des, "<span class=\"reserved_key2\">%c</span>", ch);
	    break;

	case  s6_string:
	    fprintf (des, "<span class=\"string\">%c</span>", ch);
	    break;

	case  s7_numeric_constant:
	    fprintf (des, "<span class=\"numeric_constant\">%c</span>", ch);
	    break;

	case  s8_ASCII_char:
	    fprintf (des, "<span class=\"char\">%c</span>", ch);
	    break;
    }
}
