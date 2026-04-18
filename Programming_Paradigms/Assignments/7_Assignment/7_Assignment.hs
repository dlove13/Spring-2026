--Part I
--Replicate: produces a list of identical elements a an [int] number off times
replicate' :: Int -> a -> [a]

--Perfects: integer is perfect if it equals the sum of all its factors, excluding the number itself
--Returns list of all perfect numbers up to givem limit
perfects :: Int -> [Int]

--Find: Returns list of all values associated with a given key in a table
find :: Eq a => a -> [(a,b)] -> [b]

--Positions: redefine from list comprehensions lecture using find.
positions :: [a] -> [a]

--Scalar Product: define function using list comprehension and zip function that returns the scalar product of two lists
scalarproduct :: [Int] -> [Int] -> Int

--Part II
--Count number of ways to distribute (n) distiguishable objects into (k) distiguishable boxes with (m) objects per box
dodb n k m :: Int -> Int -> Int ->  Int

--Number of ways to distribute (n) indistiguishable objects into distinguishable boxes (k)
iodb n k :: Int -> Int -> Int

--Number of ways to distribute (n) distinguishable objects into (k) indistinguishable boxes
doib n k :: Int -> Int -> Int

--Number of ways to distribute (n) indistinguishable objects into (k) indistinguishable boxes
ioib n k :: Int -> Int -> Int
