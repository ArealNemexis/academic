graph = {
    'A':['B', 'C','D'],
    'B':['A','D','E'],
    'C':['A','D'],
    'D':['A','B','C'],
    'E':['B','D']
}

queue = []
visited = []
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


bfs(visited, graph, 'A')
print()