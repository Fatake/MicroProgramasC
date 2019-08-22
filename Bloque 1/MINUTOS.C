#include <stdio.h>
int main()
{
 int x, horas, minutos;
  printf("cuantos minutos desea comvertir?");
  scanf("%d",&x);
   horas = x / 60;
   minutos = x % 60;
  printf("%d minutos es igual a %d hora(s) y %d minutos",x,horas,minutos);
return 0;
}
