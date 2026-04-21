--Part I
--Replicate: produces a list of identical elements a an int  number of times
replicate' :: Int -> a -> [a]
replicate' n x = [x | _ <- [1..n]]
--Perfects: integer is perfect if it equals the sum of all its factors, excluding the number itself
--Returns list of all perfect numbers up to given limit
--x: generates numbers 1 to limit, m: generates factors of x from 1 to limit-1, then checks if the sum of those
--factors are === to limit
perfects :: Int -> [Int]
perfects n = [x | x <- [1..n], sum [m | m <- [1..x-1], x `mod` m  == 0] == x]

--Find: Returns list of all values associated with a given key in a table
--Input: a key and a table
--Find value y from a tuple (x,y) from a table t where key == x
find :: Eq a => a -> [(a,b)] -> [b]
find k t = [y | (x,y) <- t, k == x]

--Positions: redefine from list comprehensions lecture using find.
--zip: adds a key to the list, so that it will act like a tuple
positions :: Eq a => a -> [a] -> [Int]
positions x xs = find x (zip xs [0..])

--Scalar Product: define function using list comprehension and zip function that returns the scalar product of two lists
--Create tuple (n,m) with zip, then multiply n * m, then sum 
scalarproduct :: [Int] -> [Int] -> Int
scalarproduct ns ms = sum [n * m | (n,m) <- zip ns ms ]

--Part II
--Used Gemini to implement 'choose' and look up discrete formulas
factorial ::  Int -> Int
factorial x = product [1..x]

choose :: Int -> Int -> Int
choose n k = factorial n `div` (factorial k * factorial (n - k))
--Count number of ways to distribute (n) distiguishable objects into (k) distiguishable boxes with (m) objects per box
dodb :: Int -> Int -> Int ->  Int
dodb n k m
        | n /= k * m = 0
        | otherwise = factorial n `div` (factorial m ^ k)
         
--Number of ways to distribute (n) indistiguishable objects into distinguishable boxes (k)
iodb :: Int -> Int -> Int
iodb n k = choose (n + k - 1) (k - 1)

--Number of ways to distribute (n) distinguishable objects into (k) indistinguishable boxes
doib :: Int -> Int -> Int
doib n k = choose n k 

--Number of ways to distribute (n) indistinguishable objects into (k) indistinguishable boxes
--n < k: less objects than boxes
--k == 1: one box
--n == k: equal number of objects and boxes
ioib :: Int -> Int -> Int
ioib n k
 | n < k    = 0
 | k == 1   = 1
 | n == k   = 1
 | otherwise = ioib (n - 1) (k - 1) + ioib (n - k) k
