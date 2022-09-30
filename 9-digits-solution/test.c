#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main() {
    int c = 0;
    FILE *fp;
    fp = fopen("one_million.txt", "r");
    int num = 0;
    int cant_digitos = 9;
    unsigned int iteration_number = 0;

    while(c != EOF && cant_digitos>0){
        c = fgetc(fp);
        cant_digitos = cant_digitos - 1;
        num = concatenate(num, c-'0'); // el c-'0' esta puesto para que lea correctamente los numeros
        iteration_number = iteration_number + 1;
    }
    //printf("El primer numero de 9 digitos es: %i \n", num);
    if(initial_check(num)){
        if(check_number(num))
            printf("---------- The number %i is palindrome and prime ---------\n", num);
    }
    while(c != EOF){
        c = fgetc(fp);
        if((48<=c) && (c<=57)){
            num = remove_first_digit(num);
            while(amount_of_digits(num) < 8){
                num = concatenate(num, c-'0');
                c = fgetc(fp);
                iteration_number = iteration_number + 1;
                if(iteration_number%100000 == 0 && c!=EOF)
                    printf("analyzing iteration number: %i\n", iteration_number);
            }          
            num = concatenate(num,c-'0');
            iteration_number = iteration_number + 1;
        }
        
        if(iteration_number%100000 == 0 && c!=EOF){
            printf("Analyzing iteration number: %i\n", iteration_number);
        }
        
        //printf("Siguiente numero a analizar: %i\n",num);
        if(initial_check(num)){
            if(check_number(num)){
                printf("\n---------- The number %i is palindrome and prime ---------\n", num);
                printf("-------------- Was found in iteration number %i -------------\n\n", iteration_number);
                //break;
            }
        }
    }

    fclose(fp);

}
