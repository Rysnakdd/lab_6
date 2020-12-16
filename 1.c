#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int revers (int num, int arg, int div);
int initArg (int num);

int main (void){
    int num, arg, div, opp;
    printf ("Введіть число: ");
    while (scanf ("%d", &num) != false){
        while (num / 10 == 0){
            printf ("Введіть число більше 10: ");
            if (scanf ("%d", &num) != true){
                printf ("Помилка\n!");
                exit (1);
            }
        }
        arg = initArg (num);
        div = arg;
        opp = revers(num, arg, div);
        printf ("Число = %d\n", opp);
        printf ("Введіть число: ");
    }  
    return 0;
}

int initArg (int num){
    int arg;
    int i;
    for (arg = 10, i = 1; (num % arg) / i != 0; arg *= 10, i *= 10)
        ;
    return arg / 10;
}

int revers (int num, int arg, int div){
    int result;
    int d = div / 10;
    if (d != 0)
         result = (num % div) / d;
    else return 0;   
    div = d;
    result = result * arg / (div * 10) + revers (num, arg, div);   
    return result;
}
