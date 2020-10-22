
aux = {}
valor = 0
for i in range(1,10):
    aux[(str(i)*1)] = valor + len((str(i)*1))
    valor+= len((str(i)*1))
    
    aux[(str(i)*2)] = valor + len((str(i)*2))
    valor+= len((str(i)*2))
    
    aux[(str(i)*3)] = valor + len((str(i)*3))
    valor+= len((str(i)*3))
    
    aux[(str(i)*4)] = valor + len((str(i)*4))
    valor+= len((str(i)*4))

for _ in range(int(input())):
    print(aux[input()])