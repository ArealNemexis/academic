graph = {
    'A':['B', 'C','D'],
    'B':['A','D','E'],
    'C':['A','D'],
    'D':['A','B','C'],
    'E':['B','D']
}

# graph = {
#     '0':['1','2','3'],
#     '1':['0','3','4'],
#     '2':['0','3'],
#     '3':['0','1','2'],
#     '4':['1','3']
# }

visited = set()
queue = []
visitedl = []
def bfs(visited, graph, node):
  visited.append(node)
  queue.append(node)

  while queue:
    s = queue.pop(0) 
    print (s, end = " ") 

    for neighbour in graph[s]:
      if neighbour not in visited:
        visited.append(neighbour)
        queue.append(neighbour)

def dfs(visited,graph,node):
    if node not in visited:
        print(node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)

dfs(visited, graph, 'A')


bfs(visitedl, graph, 'A')