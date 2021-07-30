#include <unistd.h>


int main()
{
  
  execlp("cal", "12", "2020", NULL);
  
  return 0;
}
