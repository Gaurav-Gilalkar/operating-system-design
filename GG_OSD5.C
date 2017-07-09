#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 pid_t pid;
 //static char *argv[]={"GG_OSD1","OSD program 1",NULL};
char c1[]="GG_OSD1.exe";
 pid =fork();
 
 if(pid<0)
 {
  fprintf(stderr,"\n Fork Failed");
  exit(-1);
 }

 else if (pid==0)
 {
 //execlp("/bin/GG_OSD4.C",NULL);
  system("./GG_OSD4");
  printf("Child Process pid is %d\n",getpid());
 }
 else
 {
   wait(NULL);
   printf("Parent Process pid is %d\n",getpid());
   exit(0);
 }
 return 0;
}


