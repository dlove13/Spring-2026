--Author: Davina Love
--Date: 04-27-2026
--Assignment 8
--In Class Slides Haskell Parsing was utilized for this assignment

--note: only works on integers and only outputs integers 

--Parsing
parse :: [Char] -> Int
parse xs = rpn ([], shunt( [], parseNumbers (parseTokens xs)))

--Tokenize
--define operators
data Op = Add | Sub | Mul | Div | Mod | Exp deriving (Eq)
instance Show Op where
        show Add = "+"
        show Sub = "-"
        show Mul = "*"
        show Div = "/"
        show Mod = "%"
        show Exp = "**"

--Define precedence
precedence :: Op -> Int
precedence Exp = 3
precedence Mul = 2
precedence Div = 2
precedence Mod = 2
precedence Add = 1
precedence Sub = 1

--Define parseable tokens
data Token = Num Int | Op Op | LeftParen | RightParen deriving (Eq)
instance Show Token where
        show (Num n)    = show n
        show (Op o)     = show o
        show LeftParen  = "("
        show RightParen = ")"

--Define Parsing Function
parseTokens :: [Char] -> [Token]
parseTokens [] = []
parseTokens ('-' : x : xs) | x >= '0' && x  <= '9' =
        let (digits, rest) = span (\c -> c >= '0' && c <= '9') (x : xs)
            negNum = negate (read digits)
        in Num negNum : parseTokens rest
--define operators
parseTokens ('*' : '*' : xs) = Op Exp : parseTokens xs
parseTokens ('%' : xs) = Op Mod : parseTokens xs
parseTokens ('+' : xs) = Op Add : parseTokens xs
parseTokens ('-' : xs) = Op Sub : parseTokens xs
parseTokens ('/' : xs) = Op Div : parseTokens xs
parseTokens ('*' : xs) = Op Mul : parseTokens xs

parseTokens ('(' : xs) = LeftParen : parseTokens xs
parseTokens (')' : xs) = RightParen : parseTokens xs
--define numbers
parseTokens ('0' : xs) = Num 0 : parseTokens xs
parseTokens ('1' : xs) = Num 1 : parseTokens xs
parseTokens ('2' : xs) = Num 2 : parseTokens xs
parseTokens ('3' : xs) = Num 3 : parseTokens xs
parseTokens ('4' : xs) = Num 4 : parseTokens xs
parseTokens ('5' : xs) = Num 5 : parseTokens xs
parseTokens ('6' : xs) = Num 6 : parseTokens xs
parseTokens ('7' : xs) = Num 7 : parseTokens xs
parseTokens ('8' : xs) = Num 8 : parseTokens xs
parseTokens ('9' : xs) = Num 9 : parseTokens xs
parseTokens (' ' : xs) = parseTokens xs
--error handling
parseTokens xs = error
        ("Invalid Characters: unrecognized token starting with " ++ xs)

--Combine number tokens
--Used Gemini for lambda function and negative number handling
parseNumbers :: [Token] -> [Token]
parseNumbers [] = []
parseNumbers (Num n : xs) | n < 0 = Num n : parseNumbers xs
parseNumbers (Num n : xs) =                                                 --fold integers over to combine into larger integer 
        let (digits, rest) = span isNum (Num n : xs)
            value = foldl (\total (Num d) -> total * 10 + d) 0 digits
        in Num value : parseNumbers rest
   where
        isNum (Num _) = True
        isNum _       = False
parseNumbers (t : xs) = t : parseNumbers xs             --Skip non-integers

--Implement Shunting yard Algorithm 
shunt :: ([Token], [Token]) -> [Token]
shunt ([], []) = [] --Base Case: both stack and token list are empty
shunt (stk, []) --other base case where leftovers will be returned to the output
        | any isLeftParen stk = error "unmatched parentheses"           --unmatched parenthesis error
        | otherwise           = stk
     where
        isLeftParen LeftParen = True
        isLeftParen _         = False

shunt (stk, (Num x : xs)) = Num x : shunt (stk, xs) --Token is a number: add to output
shunt (stk, (LeftParen : xs)) = shunt (LeftParen : stk, xs) --Token is ( 
shunt (LeftParen : stk, RightParen : xs) = shunt (stk, xs)      --match with )
shunt (Op o : stk, RightParen : xs)     = Op o : shunt(stk, RightParen : xs)

--Error case: Unmatched Parenthesis
shunt ([], RightParen : xs) = error "unmatched parenthesis"

shunt (Op top : stk, Op o1 : xs)
        | o1 == Exp && top == Exp = shunt (Op o1 : Op top : stk, xs)  --Right associative 
        | precedence top >= precedence o1 = Op top : shunt (stk, Op o1 : xs)
        | otherwise                       = shunt (Op o1: Op top: stk, xs)

shunt (stk, Op o1 : xs) = shunt (Op o1 : stk, xs)


--Evaluate RPN
apply :: Op -> Int -> Int -> Int
apply Add x y = x + y
apply Sub x y = x - y
apply Mul x y = x * y
apply Div x y = x `div` y
apply Mod x y = x `mod` y
apply Exp x y = x ^ y

rpn :: ([Int], [Token]) -> Int
rpn ([x], []) = x       -- Base Case: token list empty, stack has single int
rpn (stk, (Num n : xs)) = rpn (n : stk, xs)
rpn ((x : y : stk), (Op o : xs)) = rpn ((apply o y x : stk), xs)
--Added for debugging purposes per Gemini
rpn (stk, tokens) = error ("RPN Error - Stack: " ++ show stk ++ " Tokens: " ++ show tokens)

