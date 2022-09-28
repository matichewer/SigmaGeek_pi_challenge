#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <math.h>

int get_pi(){
    CURL *curl = curl_easy_init();
	if (!curl) {
		fprintf(stderr, "init failed\n");
		return EXIT_FAILURE;
	}

	// set link get request
	curl_easy_setopt(curl, CURLOPT_URL, "https://api.pi.delivery/v1/pi?start=1&numberOfDigits=1000");

	// execute request
	CURLcode result = curl_easy_perform(curl); // this line print the result

	if (result != CURLE_OK) {
		fprintf(stderr, "download problem: %s\n", curl_easy_strerror(result));
	}

	curl_easy_cleanup(curl);
	return EXIT_SUCCESS;
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
    if (flag == 1) {
        printf("%d is a prime number\n", num);
    }
    else {
        printf("%d is not a prime number\n", num);
    }
 
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
    
    if (num == reverse)
        printf("%d is palindrome\n", num);
    else
        printf("%d is not palindrome\n", num);

    return num == reverse;
}


int main(){
    int num = 318272813;
    if( is_palindrome(num) && is_prime(num) ){
        printf("El numero %i es palindromo y primo.\n", num);
    }

    get_pi();
}
