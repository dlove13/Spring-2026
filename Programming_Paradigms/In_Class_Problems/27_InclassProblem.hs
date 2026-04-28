import System.IO

putStr' :: String  -> IO ()
putStr' xs = sequence_ [putChar x | x <- xs]

getCh :: IO Char
getCh = do
        hSetEcho stdin False
        x <- getChar
        hSetEcho stdin True
        return x

sgetLine :: IO String
sgetLine = do 
        x <- getCh
        if x == '\n' then
                do putChar x
                   return []
        else
                do putChar '*'
                   xs <- sgetLine
                   return (x:xs)

getPassword :: IO ()
getPassword =  do
        putStr' "Enter a password: "
        xs <- sgetLine
        putStr' (show (length xs))
        putStr' ("\n") 
