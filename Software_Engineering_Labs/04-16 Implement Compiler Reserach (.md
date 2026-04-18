04-16 Implement Compiler: Reserach (aka just asking AI what the hell)



\-Implement Recursive Descent (basically the intuition of the Software Architecture doc where every operator has its own function)



\-Creating nodes in a tree, categorize them based on whether they token is an operator, integer, or some other symbol. 



Functions in order of precedence



|**Highest**|parsePrimary()|(), int, var|N/A|
|-|-|-|-|
||parseExponent()|\*\*|Right|
||parseUnary()|-, + (unary)|Right|
||parseTerm()|\*, /|Left|
||parseExpression()|+, -|Left|
|**Lowest**|parseAssignment()|=|Right|







