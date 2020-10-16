from random import randint, seed
import sys
N = int(sys.argv[1])

seed(N)
print(N)
for i in range(N):
    print(randint(0, N))
