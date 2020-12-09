# Implementation and Application of Stack
----------------------------------------
### Language : C++   
### Every input/ouput uses standard I/O   
   
### Problem 1   
Implementation of stack using doubly linked list. The stack processes following commands
   
* PUSH   
add an element to stack   
* POP   
remove an element from stack   
* SIZE   
return the number of elements in the stack   
* EMPTY   
return true if the stack is empty   
* TOP   
return the element on the top of the stack   
* QUIT   
close the program   
   
**EXAMPLE**   
Input   
<pre>
PUSH five   
PUSH three   
POP   
PUSH seven   
POP   
TOP   
POP   
POP   
EMPTY   
PUSH nine   
PUSH seven   
SIZE   
PUSH three   
PUSH five   
POP   
EMPTY   
SIZE   
QUIT   
</pre>      
   
Output   
<pre>
five   
ERROR   
TRUE   
2   
FALSE   
3   
</pre>

### Problem 2
Problem 2 and 3 are sub-problems about how computer processes mathemetical formula.
In Problem 2, the program aims to convert the mathematical formula from infix notation(ex.__(3+5)*(4+2)__) to postfix notation(ex.__3 5 + 4 2 + *__), utilizing the stack in the Problem 1.
      
**Conditions**   
Operators : __+,-,*,/,(,)__   
Operands : __4byte integers__   
   
**Example**   
Input   
The number of formulas(1<=N<=1000) to convert comes in the first line.   
From the second line to (N+1)th line, N formulas in infix notation come in.   
Each operators and operands are seperated by blanks " ".   
   
<pre>   
2   
( 3 + 5 ) * ( 4 + 2 )   
1 + 2   
</pre>   
   
Output   
<pre>
3 5 + 4 2 + *   
1 2 +   
</pre>
   
## Problem 3   
In Problem 3, the program calculates the result of formulas. It gets formulas in postfix notation and print out the results. 
      
**Example**   
Input   
<pre>
2   
3 5 + 4 2 + *   
1 2 +   
</pre>
   
Output   
<pre>
48   
3   
</pre>
 
