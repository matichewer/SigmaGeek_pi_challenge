int hasNineDigits(int num){
    int toReturn = 0;
    int contador = 0;
    while(num!=0){
	    //printf("numero: %d\n",num);
        num = num / 10;
	    //printf("numero sin ult dig %d\n", num);
        contador++;
    }
    if(contador==21)
        toReturn = 1;
    return contador;
}

int getFirstDigit(int num){
    while(num>=10){
        num = num / 10;
    }
    return num;
}

int getLastDigit(int num){
    return num % 10;
}

int initial_check(int num){
    int flag = 0;
    int firstDigit = getFirstDigit(num);
    int lastDigit = getLastDigit(num);
    return firstDigit == lastDigit;
}

int is_prime(int num){
    int i, flag = 1;

    // Iterate from 2 to sqrt(n)
    for (i = 2; i <= sqrt(num); i++) {
        // If n is divisible by any number between 2 and n/2, it is not prime
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    /**
    if (flag == 1) {
        printf("%d is a prime number\n", num);
    }
    else {
        printf("%d is not a prime number\n", num);
    }
    */
    return flag;
}

int is_palindrome(int num){

    int reverse = 0, rem, temp = num;

    //loop to find reverse number
    while(temp != 0) {
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp /= 10;
    };
	
    /**
    if (num == reverse)
        printf("%d is palindrome\n", num);
    else
        printf("%d is not palindrome\n", num);
    */
    return num == reverse;
}

unsigned checkNumber(unsigned number){
    int toReturn=0;
    if(is_palindrome(number) && is_prime(number))
        toReturn=1;
    return toReturn;
}

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
