# 04-03 Data Structures Notes



**Connected Components of undirected graphs G = (V,E)**

&#x09;-vertex (v) is reachable if there is a path from (u) to (v)

&#x09;-connected component of (G) is a subset of its vertex set V where they are reachable

&#x09;- Graph is connect if there is one connected component

&#x09;	\*Basically everything is connected in  a mesh\*



&#x09;**Finding Connected Components**

&#x09;	*Method 1: Disjoint set method*

&#x09;		*-Make\_Set(x)*

&#x09;		*-Union(x,y)*

&#x09;		*-Find\_Set(x,y)*

&#x09;	Makes a new set for each vertex with Make\_Set(x). Each edge connecting two vertices u and v are merged if they

&#x09;	don't belong to the same set. Repeat.



&#x09;	*Method 2: Graph Search Algorithms (BFS, DFS)*

&#x09;		-Start from some vertex, then discovers all vertices reachable from s, these form

&#x09;		a connected component of G

&#x09;		-For other unexplored vertices, pick another vertex s' and discover another connected component 

&#x09;		-Repeat



&#x09;



**Free tree Properties**

&#x09;-Undirected, conneted, and acyclic

&#x09;-forest = collection of free trees

&#x09;

&#x09;-any two vertices connected by a unique simple path

&#x09;-if any new edge is added, the resulting tree will contain a cycle





**Spanning tree**

&#x09;**-**connected, undirected graph tree that contains all vertices in V and a subset of edges A in E

&#x09;\*Like in linear algebra\*  A spans E



**Minimum Spanning Tree**

&#x09;**-**weighted graph; connected, undirected graph G = (V,E) with weight function w(u,v) that specifies cost of each edge (u,v) ∈ E



&#x09;applied in efficient network design



**Finding MST**

&#x09;safe edge

&#x09;	-Cut: partition of graph G = (V,E) vertex set V into two disjoint subsets S and V-S

&#x09;	-Cross: an edge (u,v) who's endpoint belongs to S and the other V-S

&#x09;	-Respect: opposite of a cross; edges does not cross cuts



&#x09;	an edge is considered safe if:

&#x09;		-there exists a cut that respects A

&#x09;		-(u,v) corsses the cut (S, V-S) and its weight is the minimum among all edges crossing the cut



&#x09;*Generic Method: starts with empty tree and grows MST by adding one "safe edge" at a time*



