#Author: Davina Love
#04-08-2026:


#Implement BFS and DFS with adjacency-list graph representation 
import math
from collections import deque

class Vertex:
    def __init__(self, key):
        self.key = key
        self.adj = []           #list of adjacent vertices
        #Attributes
        self.color = "WHITE"    #WHITE: unvisited GRAY: visiting BLACK: finished
        self.d = math.inf       #Init distance/discovery time to infinity
        self.f = math.inf       
        self.pi = None          #Init predecessor

class Graph:
    def __init__(self):
        self.vertices = {}
        self.time = 0

    def add_edge(self, u, v):
        #if edge UV does not exist, create a new edge and mark v is adjacent to u
        if u not in self.vertices: self.vertices[u] = Vertex(u)
        if v not in self.vertices: self.vertices[v] = Vertex(v)
        self.vertices[u].adj.append(self.vertices[v])

    def bfs(self, s):
        #Init vertices
        s = self.vertices[s]
        s.color = "GRAY"
        s.d = 0
        s.pi = None

        queue = deque([s])
        while queue:                    #While the queue is not empty
            u = queue.popleft()         
            for v in u.adj:             #Search neighbors of u
                if v.color == "WHITE":  #if v hasn't been discovered yet
                    v.color = "GRAY"    #change attribute to discovered
                    v.d = u.d + 1       #set distance
                    v.pi = u            #update predecessor to u
                    queue.append(v)     #v is now on the frontier
            u.color = "BLACK"           #u is now behind frontier
    
    def dfs(self):  
        self.time = 0                    #init time
        for u in self.vertices.values(): #init vertices attributes
            u.color = "WHITE"
            u.pi = None
        for u in self.vertices.values(): #Start search from unexplored vertex
            if u.color == "WHITE":
               self. dfs_visit(u)
    
    def dfs_visit(self, u):
        self.time += 1                  #white vertex u just discovered
        u.d = self.time
        u.color = "GRAY"

        for v in u.adj:                 #explore each edge UV
            if v.color == "WHITE":
                v.pi = u
                self.dfs_visit(v)

        u.color = "BLACK"               #mark vertex as finished
        self.time += 1
        u.f = self.time
#function to print interpretable results, from Google Gemini
# Usage:
# g.bfs('s')
# print_graph_results(g, "BFS")
def print_graph_results(graph, mode="BFS"):
    print(f"\n--- {mode} Results ---")
    print(f"{'Node':<8} {'Dist(d)':<10} {'Finish(f)':<10} {'Parent(pi)':<10}")
    print("-" * 40)
    
    # Sort keys so the output is easy to read
    for key in sorted(graph.vertices.keys()):
        v = graph.vertices[key]
        parent = v.pi.key if v.pi else "None"
        finish = v.f if v.f != math.inf else "N/A"
        
        print(f"{v.key:<8} {v.d:<10} {finish:<10} {parent:<10}")

#Test Case
#Init graphs
g1  = Graph()
edges1 = [
    ('r', 's'), ('r','t'),
    ('s', 'w'), ('s', 'u'),
    ('t','u'),
    ('u', 'y'),
    ('w','x'), ('w', 'v'),
    ('x','y'), ('x','z'),
    ('v','y')
]
for u, v in edges1:
    g1.add_edge(u,v)
    g1.add_edge(v,u)

g2 = Graph()
edges2 = [
    ('u','v'), ('u','x'),
    ('x','v'),
    ('v','y'),
    ('y','x'),
    ('w','y'), ('w','z'),
    ('z','z')
]

for u, v in edges2:
    g2.add_edge(u,v)

#Test results
g1.bfs('s')
print_graph_results(g1, "BFS")

g2.dfs()
print_graph_results(g2, "DFS")



























