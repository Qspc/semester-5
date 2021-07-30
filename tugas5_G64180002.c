#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ding(int sig) { 
  pid_t child = fork();
  if (child == 0) {
    while (1) {
      puts("child");
      sleep(1);
    } 
  } 
  else {
      sleep(2);
      kill(child, SIGTERM); // terminate
    }
}

int main()
{
    pid_t child = fork();
    if (child == 0) {
      while (1) {
        puts("child");
        sleep(1);
      } 
    } 
    else {
      sleep(4);
      kill(child, SIGTERM); // terminate
    }
    
    if (fork() == 0) {
      sleep(3);
      kill(getppid(), SIGALRM);
    } 
    else {
      signal(SIGALRM, ding);
      pause();
    }
  return 0; }
