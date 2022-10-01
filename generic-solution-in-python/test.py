import math
import time

cantidad_de_digitos_a_tomar = 21
ruta_archivo = "one_billion.txt"
corta_al_primer_encontrado = True
cada_cuantas_iteraciones_mostrar = 100000


def is_palindrome(num: int) -> bool:
    isPalindromic = False
    strNumber = str(num)
    reversedStrNumber = strNumber[::-1]
    if strNumber == reversedStrNumber:
        isPalindromic = True
    return isPalindromic

def is_prime(num: int) -> bool:
    isPrime = True
    for i in range(2, int(math.sqrt(num))+1):
        if (num % i) == 0:
            isPrime = False
            break
    return isPrime

def hasNDigits(num, numberOfDigits):
    return len(str(num)) == numberOfDigits

def remove_first_digit(num):
    new_num = str(num)[1:]
    return int(new_num)

def concat(x, y):
    return int(str(x) + str(y))




#print(datetime.datetime.now())

file = open(ruta_archivo, "r")
num = file.read(cantidad_de_digitos_a_tomar)
digito = file.read(1)
iteration_number = 1;


while( digito != ''):
    num = remove_first_digit(num)
    num = concat(num,digito)

    while(digito!='' and not hasNDigits(num,cantidad_de_digitos_a_tomar)):     
        digito = file.read(1)  
        num = concat(num, digito)
        iteration_number = iteration_number + 1;
        if(iteration_number%100000 == 0):
            print("analyzing iteration number: ", iteration_number)

    if(is_palindrome(num)):
        if(is_prime(num)):
            print("\n---------- The number ",num, " is palindrome and prime ---------")
            print("--------------- Was found in iteration number",iteration_number," -------------\n")
            if(corta_al_primer_encontrado):
                break

    if(iteration_number%cada_cuantas_iteraciones_mostrar == 0):
        print("analyzing iteration number: ", iteration_number)
    
    iteration_number = iteration_number + 1;
    digito = file.read(1)


file.close()