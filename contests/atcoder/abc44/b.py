from string import ascii_lowercase
w = input()

for letter in ascii_lowercase:
    if(w.count(letter)%2==1):
        print('No')
        exit(0)

print('Yes')
