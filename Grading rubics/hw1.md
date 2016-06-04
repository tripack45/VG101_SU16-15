# Grading rubic for VG101-SU16 HW1

* Contains A Total of 40 points. 5 Exercises, Ex1 4 points, Others 9 points each.
* Deduction will be adjusted based on how you write your README!
* Unable to clearly state what kind of input your program require or what your program is outputing
  * -1 to -2 points based on severeness.
* If the code fails to be executed, deduct 75% percent of the points. 
  * This includes: 1) Any type of Run-time error. 2) No proper output of any form.
    * Adjusted according to readme
* The following deduction will be capped at -4 points
  * Each missing readme: -1 point
  * Wrong file format of the readme: -1 point
* Answer files not correctly organized: -1 point

* Explorative or innovative solution. 1 Extracredit
  * Includes correct use of vector in Ex4.
* Completely follows a clean and consistent coding style, 1 Extracredit.

## Ex1.
* Unable to describe "README". Deduction based on specific case
* Use source without proper citation: -1 points.

## Ex2.
* Following capped at -7 points:
  * Fail to calculate correct remainning meters (WA): -4 points.
  * Fail to calculate correct remainning meters when no meters remainning(WA): -4 points  
* Fail to correctly return integer value of laps: -4 points.

## Ex3.
* Following capped at -5 points:
  * Fail to correctly describe the method or the algorithm: -3 points each
  * Use online source only, without the students' own writing: -5 points
    * The Problem stated "explain the method and wirte an algorithm". It is clear that the students are required to do the writing.
  * Use online source and failed to cite the source properly: -1 points

* Fails to correctly calculate the circumference of the Earth. -2 points
* Fails to correctly calculate the radius of the Earth. -2 points

## Ex4.
* Fail to implement required conversion: -3 points each.
* Fail to return correct value: Each converstion -3 points each.
* Fail to indicate what unit is the display result. -1 points.
* Misunderstand the problem, use the previous conversion result as the input for the next result: -4 points.

## Ex5.
For each question: 
* Failed to write the code in single line.
  * Major violation : -3 points e.g. use of `for`/`while` loops. 
  * Minor violation : -2 points e.g. Q1 `number = primes(100000); numel(number);`    
* Failed to return the correct answer. -3 points.
    * Adjust according to readme
* For each question, deduction capped at -4 poinst.
* Generate random integers, not real numbers in Q2 : -2 points.
* Wrongly typed the number in Q1 : -1 points.
* No deduction for people who write: 
```
(rand * 9 + 1) * (rand * 9 + 1) * (rand * 9 + 1) * (rand * 9 + 1) * (rand * 9 + 1)
```
  I strongly against doing that, since it's not elegant. Besides, what if the instruct requires you 
to generate 32767 numbers? However, they are not wrong, since the problem does not requyire a specific implementation.

  I would like to say a few words on behalf of the people who do that. 
  
  Suppose you are asked to solve a problem, say print 1 to 10.
  
  You may write: 
```matlab
for i = 1 : 10
    fprintf('%d ', i);
end
```
  But one could totally argue `disp('1 2 3 4 5 6 7 8 9 10');` is better. It's faster, and more direct.
  The thing is, sometimes a general solution can be difficult, in some cases impossible. Taking advantage of 
  the nature of the problem(in our case only 5 random numbers are required) might become essential. Sometimes you will have to balance between being general
  and elegent, against being easy but dirty. 