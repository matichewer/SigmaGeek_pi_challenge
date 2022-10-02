import requests

# SET CONFIG
position = 10000999000 # about 10 billion = 10.000.000.000
cant_digitos_a_generar = 10000000 # 10 million = 10.000.000



path_file = 'my_pi_2.txt'
url1 = 'https://api.pi.delivery/v1/pi?start='
url2 = '&numberOfDigits=1000'

def add_digits_of_pi_from_num(num):
    url_from_n = url1 + str(num) + url2
    response = requests.get(url_from_n)
    if response.status_code == 200:
        data = response.json()
        pi = data['content']
        file = open(path_file, 'a')
        file.write(pi)
        file.close()
    return response.status_code

response = 200
stop = position + cant_digitos_a_generar
while position<stop and response==200:
    response = add_digits_of_pi_from_num(position)
    position = position + 1000

print("Code response: ", response)
print("Position: ", position)
