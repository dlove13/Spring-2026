
--Conditional Implementation
--safetail :: [a] -> [a]
--safetail xs =  if null xs then [] else tail xs

--Guarded Implementation
--safetail :: [a] -> [a]
--safetail xs 
--        | null xs   = []
--        | otherwise = tail xs
 
--Pattern Matching Implementation
--safetail :: [a] -> [a]
--safetail [] = []
--safetail [_:x] = xs

