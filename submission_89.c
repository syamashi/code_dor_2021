#include <stdio.h>
 
int main(void)
{
  char a;
  char b;
  char c;
 
  scanf("%c%c%c", &a, &b, &c);
 
  if (a == b && b == c) {
    printf("Won\n");
  }
  else {
    printf("Lost\n");
  }
}
