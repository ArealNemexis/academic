import os, sys

def check_limit(var_name, var_value, min_value, max_value):
    if not min_value <= var_value <= max_value:
        print(f"o valor de {var_name} deve estar entre {min_value} e {max_value}")
        exit(2)

N = int(input())
lista = list(map(int, input().split()))

if len(lista) != N:
    print(f"A quantidade de numeros no vetor deve ser {N}")
    exit(2)

for numero in lista:
    check_limit('numero', numero, 2, 22500)

try:
    input()
    exit(2)
except EOFError:
    exit(0)
