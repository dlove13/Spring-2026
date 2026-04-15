--1

sumdown :: Int -> Int
sumdown 0 = 0
sumdown n = n + sumdown(n-1)

--2
newMap :: (a -> b) -> [a] -> [b]
newMap f = foldr (\x xs -> f x : xs ) []

--Base case (foldr f): []
--Recursive Case (foldr ⊕): lambda function \
--  that takes two arguments x and list of xs
--  and applied function f to each variable x and appends
--  result of f x to new list of xs


