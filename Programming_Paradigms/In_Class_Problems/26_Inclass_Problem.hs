combs :: [a] -> [[a]]
combs []    = [[]]
combs (x:xs) = yss ++ map (x:) yss
                where yss = combs xs

interleave :: a -> [a] -> [[a]]
interleave x [] = [[x]]
interleave x (y:ys) = (x:y:ys) : map (y:) (interleave x ys)

perms :: [a] -> [[a]]
perms []    = [[]]
perms (x:xs) = concat (map (interleave x) (perms xs))

choices :: [a] -> [[a]]
choices xs = [p | ys <- combs xs, p <- perms ys]
