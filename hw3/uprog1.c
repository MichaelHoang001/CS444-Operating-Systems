#include "tunistd.h"
#include "tty_public.h"

int main1(void);

#define MILLION 1000000
#define DELAY (400 * MILLION)

int main1()
{
  int i;

  write(TTY1,"aaaaaaaaaa",10);
  write(TTY1, "zzz", 3);
  for (i=0;i<DELAY;i++)	/* enough time to drain output q */
    ;
  write(TTY1,"AAAAAAAAAA",10);	/* see it start output again */
  return 2;
}
