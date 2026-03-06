#Author: Davina Love
#03-03-2026
#Binary Search Tree

#Create node, starts out not pointing to anything
class BSTNode:
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None
        self.p = None


class BST:

#Init root of tree with node x
    def __init__(self, x):
        self.root = x

#Takes a node and a key as input
#If the x.key is less than k, then search left side of  tree
#Else, search the right side of tree

    def tree_search(self,x, k):
        if x is None or k is x.key:
            return x
        if k < x.key:
            return self.tree_search(x.left, k)
        else:
            return self.tree_search(x.right, k)
    
    def tree_insert(self, z):
        x = self.root           #Node being compared with z
        y = None                #y will be the parent of z

        while x is not None:    #Go down until a leaf is reached
            y = x

            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.p = y                 #found location, insert z with parent y

        if y is None:
            self.root = z       #If tree is empty, make new node the root
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z
       

#Continue walk until reach the root of the tree
    def inorder_tree_walk(self,x):
        if x is None:
            return
        self.inorder_tree_walk(x.left)
        print(f"{x.key}", end=" ")
        self.inorder_tree_walk(x.right)

#Find node with smallest key value        
    def tree_min(self,x):
        while x.left is not None:
            x = x.left
        return x

#Find node with largest key value
    def tree_max(self,x):
        while x.right is not None:
            x = x.right
        return x
       
#Find next node in inorder tree walk
    def tree_successor(self,x):
#If right subtree is not empty, then return smallest node in right subtree
        if x.right is not None:
            return self.tree_min(x.right)
        else:
#If right subtree is empty, then return lowest ancestor of x whose left
#child is also an ancestor of x
            y = x.p
            while y is not None and x is y.right:
                x = y
                y = y.p
            return y
       
            
    def tree_predecessor(self, x):
#If left subtree is not empty, then return largest node in left subtree
        if x.left is not None:
            return self.tree_max(x.left)
        else:
#If left subtree is empty, then return lowest ancestor of x whose right
#child is an ancestor of x
            y = x.p
            while y is not None and x is y.left:
                x = y
                y = y.p
            return y


#Test Cases
#Case 1

root_1  = BSTNode(15)

tree_1 = BST(root_1)

keys_1 = [6, 18, 3, 7, 17, 20, 2, 4, 13, 9]
for k in keys_1:
    tree_1.tree_insert(BSTNode(k))

print("Tree 1 Test Cases: \n")
print("Inorder Tree Walk\n")
tree_1.inorder_tree_walk(tree_1.root)
print("\n")

minimum_1 = tree_1.tree_min(tree_1.root)
maximum_1 = tree_1.tree_max(tree_1.root)

print(f"Min: {minimum_1.key}")
print(f"Max: {maximum_1.key}")

successor_1 = tree_1.tree_successor(tree_1.tree_search(tree_1.root,13))
print(f"Successor of 13: {successor_1.key}\n")

#Case 2

root_2 = BSTNode(37)

tree_2  = BST(root_2)

keys_2 = [24, 51, 7, 32, 41, 85, 2, 40, 120]

for j in keys_2:
    tree_2.tree_insert(BSTNode(j))

print("Tree 2 Test Cases: \n")
print("Inorder Tree Walk\n")
tree_2.inorder_tree_walk(tree_2.root)
print("\n")

minimum_2 = tree_2.tree_min(tree_2.root)
maximum_2 = tree_2.tree_max(tree_2.root)
print(f"Min: {minimum_2.key}")
print(f"Max: {maximum_2.key}")

predecessor_2 = tree_2.tree_predecessor(tree_2.tree_search(tree_2.root,40))
print(f"Predecessor of 40: {predecessor_2.key}")





