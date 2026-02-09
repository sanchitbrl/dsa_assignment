Data Structure Implemented:

A stack is used to store brackets. It has an array to hold characters and a top variable to track the last element.


Functions Implemented:

init()– Initializes the stack.
isEmpty() – Checks if stack is empty.
push() – Adds a bracket to the stack.
pop() – Removes the top bracket.
isOpening() – Checks for opening brackets.
isClosing() – Checks for closing brackets.
isMatching() – Checks if brackets match.
isBalanced() – Checks if the expression is balanced.


Main Function Organization:
The 'main()' function tests three expressions, calls 'isBalanced()' for each, and prints whether they are balanced or not.


Sample Output:

Testing Expression 1: a + (b - c) * (d)
Result: BALANCED

Testing Expression 2: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Testing Expression 3: a + (b - c)
Result: BALANCED
