#Author Davina Love
#04-02-2026
#Disjoint-Set

#Create a new set where x is the representative
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

#Test Cases
#Create new sets with individual elements
a = Make_Set('a')
b = Make_Set('b')
c = Make_Set('c')
d = Make_Set('d')
e = Make_Set('e')
f = Make_Set('f')
g = Make_Set('g')
h = Make_Set('h')

#Union operations
Union(b,a)
Union(d,c)
Union(f,e)
Union(f,g)
Union(c,b)
Union(g,h)
Union(d,g)

#Find Set Operation
Find_Set(f)

#Print Parent values
print(a.p.value)      #a
print(b.p.value)      #a
print(c.p.value)      #a
print(d.p.value)      #a
print(e.p.value)      #a
print(f.p.value)      #a
print(g.p.value)      #e
print(h.p.value)      #e
print("\n")

#Print Rank Values
print(a.rank)   #2
print(b.rank)   #0
print(c.rank)   #1
print(d.rank)   #0
print(e.rank)   #1
print(f.rank)   #0
print(g.rank)   #0
print(h.rank)   #0



