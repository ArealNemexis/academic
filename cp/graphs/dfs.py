graph = {
    'A':['B', 'C','D'],
    'B':['A','D','E'],
    'C':['A','D'],
    'D':['A','B','C'],
    'E':['B','D']
}

visited = set()

def dfs(visited,graph,node):
    if node not in visited:
        print(node, end=' ')
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

dfs(visited, graph, 'A')
print()