#include <stdio.h>

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

unsigned int remove_first_digit(unsigned int n) {
    if( n < 10 )
        return 0;
    else 
        return n%10 + remove_first_digit(n/10) * 10;
}

int main() {
    int c = 0;
    FILE *fp;
    fp = fopen("numeros.txt", "r");

    int num = 0;
    int cant_digitos = 9;

    while(c != EOF && cant_digitos>0){
        c = fgetc(fp);
        cant_digitos = cant_digitos - 1;
        num = concatenate(num,c - '0'); // el c-'0' esta puesto para que lea correctamente los numeros
        
    }
    printf("El primer numero de 9 digitos es: %i \n", num);



    // AHORA EN CADA ITERACION HAY QUE IR AGREGANDO UN DIGITO A LA VARIABLE num
    // Y ADEMAS QUITARLE EL PRIMER DIGITO
    while(c != EOF){
        c = fgetc(fp);
        num = remove_first_digit(num);
        num = concatenate(num,c - '0');
        printf("Siguiente numero a analizar: %i\n", num);
    }    


    fclose(fp);

}
