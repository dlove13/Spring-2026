data Tree a = Leaf a | Node (Tree a) (Tree a)

--1
--Returns the number of leaves in a tree
leaves :: Tree a -> Int
leaves (Leaf a) = 1
leaves (Node l r) = leaves l + leaves r

--2
--Checks if a tree is balanced
balanced :: Tree a -> Bool
balanced (Leaf a) = True
balanced (Node l r) = abs (leaves l - leaves r) <= 1 && balanced l && balanced r

--Find difference in leaves in left and right subtree
--Recursively checks if the tree is balanced within its own subtree
--
 
