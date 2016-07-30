# Midterm 2 Ex1 rubic
## General Rubic:

* Open an unclosed file: -5pts
* Allocated an unreleased memeory: -5pts
* Illegal language:
  * Illegal call to library function: -2pts
  * Returning address to local array: -3pts
  * Calling string function without checking '\0', -1.5 pts
  * Others based on severity

## Q1 [5], Simple BF Code
Answer:
58+.>41+.#
58+.-17-.#
* ASCII code: 58 41
* `#` is not mandatory

## Q2 [10], Readin Characters
* Function prototype: 2pts
  * 3pts if not using function
* Use of "fscanf()" with EOF: 5pts
* Deduct 4 for using "gets()"
* Correct use of pointer/array: 3pts

## Q3 [5], Filter Characters
* Function prototype: 2pts
 * Includes not using function
* Functionality: 3pts

## Q4 [10], Readme:
* Give correct structure of execution: 8pts
  * Mentioning a loop structure: "one by one", "for" :5
* Provide a solution for requirement (g)(h): 2pts

## Q5 [10]:
* General implementation: 10pts
* Improper implementation for "+/-", "<>": -2pts
* Initializing the setup:
  * Allocate chunk memory (`malloc` or `array`): 1pts
  * Setup data pointr: 1pts
  * Properly choose the datatype: 1pts   
* Check for boundary violation: 1pts

Additive rules:
* Properly initialize array 3pts
* Using a proper loop/array structure 2pts
* Correctly Implement '+ - < >' 3pts
* Correctly Implement '.' 2pts
  
## Q6 [10]:
* Grade with care.
* 2pts for `*p==0`
* Use a `for` loop instead of `while` loop: -1pts

## Q7 Bonus [5]:
Answer: [->+<]#
