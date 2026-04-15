#Implement MST with Kruskal and Prim's Algorithms
#Copy of code from Lab 7 Disjoint Set
import function import cmp_to_key

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

def MST_Kruskal(G, e):
    e = sorted(e, key = cmp_to_key(comparator))

    dsu = Make_Set(G)
    cost = 0
    count = 0
    for x, y, w in e:
        if dsu.Find_Set(
