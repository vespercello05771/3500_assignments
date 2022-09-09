#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char history[200][200];
  char cmd[200];
  char curr[256];

   int x=0;
   
   while(1)
   {
      getcwd(curr,sizeof(curr));
      
      printf("%s> ",curr);
    
      scanf("%[^\n]%*c",cmd);
      strcpy(history[x],cmd);
     x++;
     if(strcmp(cmd,"pwd")==0) printf("%s\n",curr);
     else if(strcmp(cmd,"clear")==0) system(cmd);
     else if(strcmp(cmd,"mkdir")==0) 
     {
        char str[100];
        scanf("%s",str);
        strcat(history[x-1]," ");
        strcat(history[x-1],str);
        mkdir(str,0777);
     }
     else if(strcmp(cmd,"rmdir")==0)
     {
       char str[100];
        scanf("%s",str);
        strcat(history[x-1]," ");
        strcat(history[x-1],str);
       rmdir(str);  
     }
     else if(strcmp(cmd,"ls")==0) system(cmd);
     else if(strcmp(cmd,"ls -l")==0) system(cmd);
     else if(strcmp(cmd,"history")==0)
     {
       for(int i=0;i<x;i++)
       {
         printf("%s\n",history[i]);
       }
     }

     else if(strcmp(cmd,"exit")==0)
     {
        printf("EOB\n");
        break;
     }
     else printf("command not found in the database\n");
     
    }
}