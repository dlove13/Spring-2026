#Author: Davina Love
#03-03-2026
#Binary Search Tree

#Create node, starts out not pointing to anything
class BSTNode:
    #Init root of tree
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None

    def __init__(self):

    def tree_insert(self,n):
        if self is None:
               return self.n
        if self.n === self.key
            return self.key
        if self.key < n
            self.right = insert(self.right, n)
        else:
            self.left = insert(self.left, n)

        return self.key

    def inorder_tree_walk(n):
        if not self:
            return
        self.inorder_tree_walk(self.left)
        return self.key
        self.inorder_tree_walk(self.right)
            
    def tree_min():
        if self is None:
            return None
        
        while self.left is not None:
            self = self.left
        return self

    def tree_max():
        if self is None:
            return None

        while self.right is not None:
            self = self.right
        return self
#TODO
    def tree_successor(n):
        if self.key is None:
            return None

        if self.key == n and self.right is not None:
            return 
            
#TODO
    def tree_predecessor(n):


#Test Cases
#Case 1
BST = BSTNode()

BST.tree_insert(15)
BST.tree_insert(6)
BST.tree_insert(18)
BST.tree_insert(3)
BST.tree_insert(7)
BST.tree_insert(17)
BST.tree_insert(20)
BST.tree_insert(2)
BST.tree_insert(4)
BST.tree_insert(13)
BST.tree_insert(9)

print(f"{BST.inorder_tree_walk()}")
print(f"{BST.tree_min()}")
print(f"{BST.tree_max()}")
print(f"{BST.tree_successor(13)}")

#Case 2
BST2 = BSTNode()

BST2.tree_insert(37)
BST2.tree_insert(24)
BST2.tree_insert(51)
BST2.tree_insert(7)
BST2.tree_insert(32)
BST2.tree_insert(41)
BST2.tree_insert(85)
BST2.tree_insert(2)
BST2.tree_insert(40)
BST2.tree_insert(120)

print(f"{BST2.inorder_tree_walk()}")
print(f"{BST2.tree_min()}")
print(f"{BST2.tree_max()}")
print(f"{BST2.tree_successor(40)}")







