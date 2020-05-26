#include <stdio.h>
char* intToStr(int i, char b[]);

int main(){
    char numero[7];
    int s = 32;
    printf("Numero: %s\n\n",intToStr(s,numero));
}
char* intToStr(int i, char b[]){
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{
        *--p = "0123456789"[i%10];
        i = i/10;
    }while(i);
    return b;
}