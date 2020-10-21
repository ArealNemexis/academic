n,m = map(int,input().split())
matrix = [list(map(int, input().split())) for _ in range(n)]

print(n,m)
for line in matrix:
    print(*line)