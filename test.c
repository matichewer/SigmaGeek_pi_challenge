#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main() {
    int c = 0;
    FILE *fp;
    fp = fopen("one_millon.txt", "r");
    int palindrome_prime = 0; //0 is false
    int num = 0;
    int cant_digitos = 9;

    while(c != EOF && cant_digitos>0){
        c = fgetc(fp);
        cant_digitos = cant_digitos - 1;
        num = concatenate(num,c-'0'); // el c-'0' esta puesto para que lea correctamente los numeros
    }
    //printf("El primer numero de 9 digitos es: %i \n", num);
    if(initial_check(num)){
    	//palindrome_prime = checkNumber(num);
    	if(checkNumber(num))
        printf("----------El numero %i es palindromo y primo---------\n",num);
    }
       	// AHORA EN CADA ITERACION HAY QUE IR AGREGANDO UN DIGITO A LA VARIABLE num
    // Y ADEMAS QUITARLE EL PRIMER DIGITO
    while(c != EOF){
        c = fgetc(fp);
	if((48<=c) && (c<=57)){
            num = remove_first_digit(num);
	    int cant_dig = hasNineDigits(num);
	    //printf("la cant de dig es: %d \n",cant_dig);
	    while(hasNineDigits(num)<8){
		//printf("Entre\n");
	    	num = concatenate(num, c-'0');
		c = fgetc(fp);
	    }
		
       	    num = concatenate(num,c-'0');
	}
	printf("Siguiente numero a analizar: %i\n",num);
	if(initial_check(num)){
	    //palindrome_prime = checkNumber(num);
	    if(checkNumber(num))
	    	printf("----------El numero %i es palindromo y primo----------\n",num);
    	}
    }    


    fclose(fp);

}
