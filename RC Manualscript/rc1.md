# Recitation Class 1
 Covering Page 1 to Page 72:
 
 Covering Chap 0: Intro, Chap 1 Arrays, Chap2. Control Flow;
 
 Source file of this file see [github.com: tripack45/VG101_SU16-15](https://github.com/tripack45/VG101_SU16-15/blob/master/RC%20Manualscript/rc1.md)
 
# Section 1: Basic Section (45 mins)

## RC Intro:
   * Intro 2 The recitation class, the two part arrangement.
   
## Homework:
   * What should you hand in, how to hand in
     * See Annoucement.
   * Do Not Copy Principal, honor console violation, judging fo homework.
   * Be careful of special cases
     * Things like dividing by zero, Number of roots of a `ax^2 + bx + c = 0` equation.
     * These things are offened called "Boundary Condition"
     * The Test Engineer Joke
   
## Know the environment:
   * Turn Your Matlab Into English
     * 『首选项』=>『常规』=>『桌面语言』=>『英语』, 重启 Matlab。
   * Know the workspace, the command window, the editor, the menu. (And how to dock them);
   * Know the `PATH` variable.
     * A variable stores places that Matlab searches through to find your scripts and funcitons.
     * Know how to add directory to `PATH` or change it to someplace
   * `.m` files are files that contains Matlab code. 
     * Could be a `script` or a `function`
     * `script` is a collection of code that runs one by one. Think of a scripth as a package of frequently used code.
     * `functions` will be discuss in the future
   * Learn to read error message!
   * Semicolumns are end of an expression(which becomes a statement). One statement per line.
   * Strings ("text") are put in `''`
   * Know the debugging interface
   
## Help from Matlab
   * Documentation center on the top right coner.
   * The `help` Command
   * `Tab` key and auto-completion.
   * Learn to read error message!
   * `clear` to clear workspace, elimate possible interference from existing variables.
   * `clc` to clear command windows. 

## Building blocks: Array and Matricies:
   * Arrays(Matrix) is huge table of numbers. i.e. numbers arranged in the form of rows and columns.
   * (Almost) every thing in Matlab is an array (matrix). 
     * Terms `Array` and `Matrix` usually means the same, given the dimension is less or equal then 2.
     * Array: "数组，阵列". Matrix: "矩阵"
     * A single number, or in other words, a scalar, is an 1 by 1 array.
   * A one dimensional array is often called a "Vector", depending on if it is a row or a column, we call it "row vector" or "column vector".
   * `[]` operator "glues" arrays together. 
     * `[A, B]` or `[A B]` glues `B` to the left of `A` (Horizontally).
     * `[A; B]` glues `B` under `A` (Vertically).
     * Possible to use this on more then 1 matrix.
   * Use `a:b:c` expression to genrate a row of numbers, starting from `a` to `c`, one every `b` numbers:
     * No need to write `[a:b:c]`
     * `1 : 2: 10` becomes `[1 3 5 7 9]`
     * `5 :-1: 2` becomes `[5,4,3,2,1]`
   * Use `linespace(start,end,n)` to generate `n` evenly distributed numbers on the interval `[start,end]`
   * Use `zero(row,column)` or `ones(row,column)` to gnerate arrays of zeros(ones) of size "row by column"
   * Use `magic(n)` to generator n by n "random" matrix.
   * Matrix Operators:
     * Plus(`+`), Minus(`-`), Matrix Multiplication(`*`), Matrix Division(`/`), Transpose(`'`)
     * Element by element multiplication (`.*`) and division(`./`) and power (`.^`)
     * No "Element by element transpose"
     * For scalars(Numbers, 1 by 1 matrix), (`*`) and (`.*`) are essentailly the same. Also true for (`./`) and (`/`)
   * `numel(n)` counts the number of elements
   * Pay attention to the behavior of `sum(),mean(), ...` functions
   
## Accessing Elements of a matrix:
   * 3 Ways of doing so: 
    * By linear indexing. Counting from the first column then second....
    * By specifying the subscript `A(row,column)` access the element on `row` row and `column` column. Notice the order of row and solumn.
    * By logical masks. Talks about in future.
   * `:` symbol means "all possible values"
   * `end` symbol means last possible values
    * It is possible to append to a one dimensional array `B` by doing `B(end+1) = 1;`
   * Possible to access multiple elements by specifying the argument as an array
    * If `A=magic(5)`, **be careful with the difference of `A([1,3,4])` and `A([1;3;4])`
    * `A(:)` will always return a column vector with all the elements of `A` inside it. Good for `sum()`
   
## Boolean logic and relational operators
   * These things all returns(calculate out as) `true` or `false`.
   * Know the meaning of logical "AND" "OR" "NOT" and their symbols.
   * Know the symbol for "larger, equals, not equals ...."

## Conditional Statements (If):
```matlab
    % Code                    % English
    if expression1            % If the "expression1" is true (evaluates to be true)
        statement1            %    Please run "statments1".
    elseif expression2        % If the firsty condition is not satified, but "expression2" statisfies
        statement2            %    Plase run "statement2".
    ....                      ....
    elseif expression3        % If none of the conditions above are satisfied, but "expression3" statisfies
        statement3            %    Please run "statements3".
    ....                      ....
    else                      % If none of above satisfies, 
        statements            %    Run "Statments"
    end
```
    
   * the "elseif"s and "else" appears only when needed. i.e. They are optional
   * Be familiar with the grammar! 
   * Read (And write!) your code as if you are writing English!
  
       >   Any fool can write code that a computer can understand. Good programmers write code that humans can understand.        ~Martin Fowler 

   * Pay attention to the indentation.
   * Rhy Wiskey
    
## Conditional Statements (Switch):
```matlab
    % Code                    %English
    switch variable           % Please check "variable" against the "value1" to "valuen"
        case value1
            statements1
        case value2           % If any of them satisfies,
            statements2            % Run the accordingly statements
        ...
        case valueN
            statementsN
        otherwise             % If none of them satisfies,
            statements             % Run "Statements"
    end
```
    
   * The "otherweise" part is optional.
   * Notice that the "value"s can be strings, things like `'abc'`
       * Normally if you are to compare 2 string you have to call `strcmp(str1,str2)`
       * Doing something like `str1 == str2` will result in an error.
       * `switch` statement automatically compares strings without you calling `strcmp()`
        
## Loops (`for` loop and `while` loop):
```matlab
   % Code                                % English
   for i = start : increment : end       % Let i increase(decrease) from "start" to "end', change "increment" every time
        statemnts                        % Do something
   end
   
   while expression                      % While expression is satisfied
        statements                       %     Keep doing statements.
   end
``` 
   
   * For loops mostly used when you know how many times to loop over
   * Be careful with infinite loops when using while loops. (A never ending loop).

## Vectorizing Loop.
   * Implicit loops that utilizes Matlab language features.
        * You have met them, elementwise "Add, Minus ...".
   * Really fast! Properly use them will be awared with extra credits.
   * Abusing them will make your code unable to read.


# Further Topics (45 mins)
## Coding Styles:
   Guidelines to follow if you want clean code, not mandatory!!
   * Constants:
        * No magic numbers, always factor out constants
        * Name them properly.
   * Nameing:
        * Use  `smallCaseCamel` method on variables and functions.
        * Use meaningful English! Avoid unsual acrynom.
        * e.g. `numberOfStudents = 10;`, `getPresentFrom(myClassmate)`
   * Indentation:
        * Use "smart indent" in matlab.
   * Spacing: 
        * Space between operators. (Such as `+,-,=,==,>=`);
        * Space after a comma. (`ones(1, 2, 4);`)
        * No space after brackets.
        * No space after unary operators. (operator applies only to one variable)
   * Sample code:
```matlab
   if isReachedBottom(author) || isCameUp(author)
        ocean = ~whiskey;
        disp('I am not a duck'); % I SHALL NOT BE A duck
   else
        if hasLuck(author) || hasCards(author)
            ocean = wiskey;
            disp('Now I am a duck');
        end
   end
   for whiskey = firstWhiskey : lastWhiskey
        authorCry(whiskey);
   end
   while isAlive(author)
        authorGet(whiskey);
   end
```
        
## Know your instructor's Environment:
   * A black box, called "Command Line"
   * A `linux` environment
        * Linus travolds. 


## Pitfalls regarding logical expressions:
   * `true` is intepreted as number "1" in calculation. 
       * `false` as zero
 ```matlab
         a = true; 
         b = true;
         disp(a+b); % displays 2
 ```
   * Any number **other then zero** will be regarded by matlab as `true`
```matlab
         a = 1;
         b = -2;
         if a
            disp('1 means true'); % 1 means true;
         end
         if b
            disp(`-2 means true'); % -2 also means true;
         end
```
   
## More about loops:
   * Rewriting for loops with while loops.
   * What exactly is happening inside a `for` loop?
        * will the two code behave the same?
```matlab
           % ===============
           for i = 1 : 5
              disp(i);
           end
           % ===============
           vector = 1 : 5;
           for i = vector
              disp(i);
           end
 ```
  * For loops can always be rewritten by while loops, while keep them?
 
## How many ways of summing all elements in an matrix:
   * Basic style:
        * For loop on row and columns
   * Improved style:
        * While loop using linear indexing
   * Advanced style:
        * Make use of `sum()`
   * Best practive:
        * `sum(A(:))`
        * Good, because it works regrardless of dimension.
        * Good, uses vectorized loop.
        * Good, no room for mistakes.
        * Bad, will never work without Matlab. Impossible to translate into another language.
   * Take away: Fast/Efficient code usually means make best use of language features.
        
            
## Basic debugging
    * Use of debugging tools
