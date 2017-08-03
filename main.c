#include<stdio.h>
#include"html_basic.h"
#include"skel.h"

FILE *source, *des;

int main(int argc, char *argv[])

{
    
   // FILE *source,  *des;  /***file pointers*****/

    /*********error mechanism*******/
    if (argc < 2)
    {
	printf("ERROR GIVE TWO COMMAND LINE ARGUMENTS\n");
    }

    source = fopen(argv[1], "r");

    /*********error check************/

    if (source == NULL)
    {
	printf("ERROR");
    }
    /**********************/

    des = fopen(argv[2], "w");

    /************error check**********/

    if (des == NULL)
    {
	printf("write error\n");
    }
    /**********************************/
  

    
    
     if(strcmp(argv[3] ,"-n") == 0) 
    {
       printf("line no added\n");
       
      
    }
    
   
    
   html_start(des);
   if (src_to_html(source, des) == SUCCESS)
   {
       printf("file created\n");
   }
   else
   {
       printf("file not created\n");
   }

   html_stop(des);
   fclose(source);
   fclose(des);

}


    
