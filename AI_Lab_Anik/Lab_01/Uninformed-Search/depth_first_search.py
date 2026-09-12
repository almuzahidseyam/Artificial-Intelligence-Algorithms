# Using a Python dictionary to act as an adjacency list
graph = {
  'A' : ['B','C'],
  'B' : ['D', 'E'],
    'C': [],

    'D' : ['F'],
  'E' : ['H','G'],

  'G' : [],
  'H' : [],
  'F' : []

}
x = 0

visited = set() # Set to keep track of visited nodes of graph.

def dfs(visited, graph, node):  #function for dfs
    if node not in visited:
        print (node)
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour)
        global x
        x = x + 1
# Driver Code
print("Following is the Depth-First Search")
dfs(visited, graph, 'A')
print ("Complexity",x)