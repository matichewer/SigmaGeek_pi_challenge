import requests

print('pi = 3.41592653...')
print('position 0 = 3')
print('position 1 = 1')
print('position 2 = 4')
print('...\n')

print('Remember: the number of digits generated is always a multiple of 1000.\n')
starting_position = int(input('Enter starting position: '))
ending_position = int(input('Enter ending position:   '))
file_path = input("Enter the file path where pi will be generated (for example: mi_pi.txt): ")

url1 = 'https://api.pi.delivery/v1/pi?start='
url2 = '&numberOfDigits=1000'

def add_digits_of_pi_from_num(num):
    url_from_n = url1 + str(num) + url2
    response = requests.get(url_from_n)
    if response.status_code == 200:
        data = response.json()
        pi = data['content']
        file = open(file_path, 'a')
        file.write(pi)
        file.close()
    return response.status_code

response = 200
while starting_position<ending_position and response==200:
    response = add_digits_of_pi_from_num(starting_position)
    starting_position = starting_position + 1000

print("\nFile ",file_path, " generated")
print("Code response: ", response)
print("Position: ", starting_position)
