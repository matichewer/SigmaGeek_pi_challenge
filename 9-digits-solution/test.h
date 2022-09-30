int amount_of_digits(int num){
    int cont = 0;
    while(num!=0){
        num = num / 10;
        cont++;
    }
    return cont;
}

int get_first_digit(int num){
    while(num>=10)
        num = num / 10;
    return num;
}

int get_last_digit(int num){
    return num % 10;
}

unsigned int remove_first_digit(unsigned int n) {
    if( n < 10 )
        return 0;
    else
        return n%10 + remove_first_digit(n/10) * 10;
}

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

int initial_check(int num){
    int firstDigit = get_first_digit(num);
    int lastDigit = get_last_digit(num);
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
    /*
    if (flag == 1) 
        printf("%d is a prime number\n", num);
    else 
        printf("%d is not a prime number\n", num);
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
	
    /*
    if (num == reverse)
        printf("%d is palindrome\n", num);
    else
        printf("%d is not palindrome\n", num);
    */
    return num == reverse;
}

unsigned check_number(unsigned number){
    return (is_palindrome(number) && is_prime(number));
}
