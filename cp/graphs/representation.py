graph_letters = {
    'A':['B', 'C','D'],
    'B':['A','D','E'],
    'C':['A','D'],
    'D':['A','B','C'],
    'E':['B','D']
}

graph_numbers = {
    '0':['1','2','3'],
    '1':['0','3','4'],
    '2':['0','3'],
    '3':['0','1','2'],
    '4':['1','3']
}

for i in graph_numbers.keys():
    print(i, ': ', end='')
    print(*graph_numbers[i], sep=' ')




