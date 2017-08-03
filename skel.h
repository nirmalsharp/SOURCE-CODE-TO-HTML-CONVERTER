#include <stdio.h>
#define SUCCESS 1
#define FAILURE 0

typedef enum states
{
    s0_idle,
    s1_comment,
    s2_preprocessor,
    s3_headerfile,
    s4_res_keyword_data,
    s5_res_keyword_non_data,
    s6_string,
    s7_numeric_constant,
    s8_ASCII_char
}State_e;

typedef enum Events
{
    PEVENT_NULL,
    PEVENT_SINGLE_LINE_COMMENT,
    PEVENT_MULTI_LINE_COMMENT,
    PEVENT_PREPROCESSOR_DIRECTIVE,
    PEVENT_HEADERFILE,
    PEVENT_RESERVED_KEYWORD,
    PEVENT_STRING,
    PEVENT_NUMERIC_CONSTANT,
    PEVENT_ASCII_CHAR,
    PEVENT_SNULL,
    PEVENT_EOF,
    PEVENT_NON_DATA
}Event_e;

int src_to_html(FILE *source, FILE *des);
int check_keyword(char *word);
void replace_html_symbol (char *dat);
