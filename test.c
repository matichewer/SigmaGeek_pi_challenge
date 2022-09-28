#include <stdio.h>

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

int main() {
    int c = 0;
    FILE *fp;
    fp = fopen("numeros.txt", "r");

    int num = 0;
    int cant_digitos = 9;

    while(c != EOF) {
        c = fgetc(fp);
        if((48 <= c) && (c <= 57)){
            //c = c - '0';
            printf("%d\n", c - '0');
            if(cant_digitos>0){
                cant_digitos = cant_digitos - 1;
                num = concatenate(num,c - '0');
            } else {
                printf("%d\n",num);
                num = 0;
                cant_digitos = 9;
            }
        }
    }

    fclose(fp);

}
