#include <stdio.h>
#include "html_basic.h"

void html_start(FILE *des)
{

    /* Add HTML begining tags into destination file */
    fprintf(des, "<!DOCTYPE html>\n");
    fprintf(des, "<html lang=\"en-US\">\n");
    fprintf(des, "<head>\n");
    fprintf(des, "<title>%s</title>\n", "s2h");
    fprintf(des, "<meta charset=\"UTF-8\">\n");
    fprintf(des, "<link rel=\"stylesheet\" href=\"styles.css\">\n");
    fprintf(des, "</head>\n");
    fprintf(des, "<body style=\"background-color:black;\">\n");
    fprintf(des, "<pre>\n");
}

void html_stop(FILE *des)
{
    fprintf(des, "</pre>\n");
    fprintf(des, "</body>\n");
    fprintf(des, "</html>\n");
}
void add_line_no (FILE *des, int line_no)
{
    	/* code to enable line number */
        
    	fprintf (des, "<span style=\"color:crimson\">%3d</span> ", line_no);

}
