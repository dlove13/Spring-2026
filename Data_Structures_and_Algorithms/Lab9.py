#Implement MST with Kruskal and Prim's Algorithms
#Copy of code from Lab 7 Disjoint Set
from functools import cmp_to_key
import heapq

#Lab7 Code
class Node:
    def __init__(self, x):
        self.value = x
        self.p = self
        self.rank = 0

def Make_Set(x):
    return Node(x)

#Union set x and set y
def Union(x,y):
    Link(Find_Set(x), Find_Set(y))

#Update ranks of elements in the Unioni of sets x and y
def Link(x,y):
    if x.rank > y.rank:
        y.p = x
    else:
        x.p = y
        if x.rank == y.rank:
            y.rank = y.rank + 1

#Find the representative of the set that contains x 
def Find_Set(x):
    if x != x.p:
        x.p = Find_Set(x.p)
    return x.p
#End Lab 7 Code

def comparator(edge1, edge2):
    # Standard comparator for cmp_to_key: return negative if edge1 < edge2
    return edge1[2] - edge2[2] 

def MST_Kruskal(G, e):
    #Sort edges
    e = sorted(e, key = cmp_to_key(comparator))
    
    #go through edges in sorted order
    dsu = {v: Make_Set(v) for v in vertices}
    mst = []
    cost = 0

    for x, y, w in e:
        #check if there is no cycles
        x_node = dsu[x]
        y_node = dsu[y]

        if Find_Set(x_node) != Find_Set(y_node):
            Union(x_node,y_node)
            cost += w
            mst.append((x, y, w))
    return mst, cost


def MST_Prim (G, r):
    #Init keys and parents
    key = {node: float('inf') for node in graph}
    parent = {node: None for node in graph}
    visited = set()
    
    key[r] = 0       #Root key = 0
    pq = [(0, r)]    #Init priority queue
    
    mst = []      #Init MST 

    while pq:           #while the queue is not empty
        #remove vertex with smallest key
        current_key, u = heapq.heappop(pq)
        
        if u in visited:
            continue
            
        visited.add(u)
        
        # Add to MST result (except for the root)
        if parent[u] is not None:
            mst.append((parent[u], u, current_key))

        #for each neighbor v of u
        for weight, v in graph[u]:
            # If v is not in the MST and the edge weight is smaller than current key
            if v not in visited and weight < key[v]:
                parent[v] = u
                key[v] = weight
                heapq.heappush(pq, (key[v], v))
                
    return mst

# List of vertices
vertices = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']

# Edge List for Kruskal: (u, v, weight)
edges = [
    ('a', 'b', 4), ('a', 'h', 8),
    ('b', 'c', 8), ('b', 'h', 11),
    ('c', 'd', 7), ('c', 'f', 4), ('c', 'i', 2),
    ('d', 'e', 9), ('d', 'f', 14),
    ('e', 'f', 10),
    ('f', 'g', 2),
    ('g', 'h', 1), ('g', 'i', 6),
    ('h', 'i', 7)
]

# Adjacency List for Prim: { u: [(weight, v), ...] }
# Note: Prim's requires both directions for an undirected graph
graph = {v: [] for v in vertices}
for u, v, w in edges:
    graph[u].append((w, v))
    graph[v].append((w, u))

mst, cost = MST_Kruskal(vertices, edges)

print("--- Kruskal's MST Result ---")
print(f"Total Cost: {cost}")
print(f"Edges: {mst}")

# Run Prim
p_mst = MST_Prim(graph, 'a')
p_cost = sum(w for u, v, w in p_mst)
print("\n--- Prim's MST Result ---")
print(f"Total Cost: {p_cost}")
print(f"Edges: {p_mst}")
