graph = {
    'A':['B', 'C','D'],
    'B':['A','D','E'],
    'C':['A','D'],
    'D':['A','B','C'],
    'E':['B','D']
}
graph_numbers = {
    0:[1,2,3],
    1:[0,3,4],
    2:[0,3],
    3:[0,1,2],
    4:[1,3]
}
visited = set()

def dfs(visited,graph,node):
    if node not in visited:
        print(node, end=' ')
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

dfs(visited, graph_numbers, 0)
print()