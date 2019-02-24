//
//	EE 4374 Assignment # 2 Command Executer
//	Author: Michael Contreras
//

#include <unistd.h>
#include <stdlib.h>

int execBackground(char **args)
{
    int i;
    // check for the ampersand at the end of the set of tokens
    i = 0;
    while(args[i] != 0)
    {
         i++;
    }                       // traverse to the end of the tokens
    if(args[i-1][0] == '&') // check the last token
    {
        free(args[i-1]);
        args[i-1] = NULL;  // remove the ampersand
        return 1;
    }
    else
    {
        return 0;
    }
}

int executeCmd(char **args)
{
  char ** input = args;
  if(execBackground(input) == 1)
    {
      execvp(input[0],input);
    }
  else return 1;
}
