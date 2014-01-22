#include <stdio.h>

int main()
{
   int nl, c;
   for(nl = 0; (c = getchar()) != EOF; nl++) {
      putchar(c);
      c = getchar();
      if (c == '\n')
         nl++;
   }
   printf("%d\n", nl);
   DL
