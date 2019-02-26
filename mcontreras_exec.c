//
//	EE 4374 Assignment # 2 Command Executer
//	Author: Michael Contreras
//

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
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
     /*if(execBackground(input) == 1)
    {
      execvp(input[0],input);
      return 1;
    }
    else return 1;*/
  pid_t firstPid;

  /* fork a child process */
  firstPid = fork();

  if(firstPid < 0)
    {
      /* Negative process id means there was an error */
      fprintf(stderr,"Error forking a process\n");
      return -1;
    }
  else if(firstPid == 0)
    {
      /* this is the first child process, run "ls -l" */
      //execlp("ls","ls","-l", NULL);
      execvp(input[0],input);
    }
  else
    {
      /* this is the parent, wait for the children to exit */
      waitpid(firstPid,NULL,0);/* don't read exit code */
    }

  return 0; /* this will invoke an exit() system call */
}
