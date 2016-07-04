# Grading rubic for VG101-SU16 HW4

* Contains A Total of 40 points. 5 Exercises, 8 + 6 + (2 + 4 + 6) + 8 + 6pts
* The instructor warned you of the consequences of violating the rule of the templates. TAs should refuse to grade your homework if you refuse to cooperate. But we decided to be nicer. We thus make the following deductions: Disobeying one, two, three or more of the rules results in, -5pts, -10pts, -20pts Deduction.
 * Wrong README format or extension.
 * Containing extra non-source files in submission
 * Not correctly using the template. I.e. wrote exercise as an independent program (which contains its own `main()` function);
 * Upload in `.rar`

Special cases:
* Not putting your homework in root directory of the archive: -1 pts. 
 * This is a long existing problem. We require this at the very beginning of the course.
 * Write separate `.c` files for some exist while **NOT providing corresponding compile commands**. -1 pts
   * It's not a problem if you need extra source files for your work. Though we don't recommend this since most of your exercises are tiny. But if you decided to do so, you should give your compiler command. You shouldn't let the grader to guess how to compile your work.

## Ex1.
Test cases:
* `z1 = 1.5 + 2.5i` and `z2 = -4 + -2i`. Add:`-2.5+0.5i`, Mul:`-1 - 13i`
* Not using structure: -4 pts
* Not using functions: -4 pts
* Functions are not designed as specified
 * Deduction based on situation
* Not following specification: -2 pts

## Ex2.
* By definition `gcd(0,10) = gcd(10,0) = 10`. 2pts
 * You can deal with it explicitly by notifying the user
 * But crashing/giving wrong answer is not acceptable
* `gcd(1, 10) = 1` 
* `gcd(30, 24) = 6`
* `gcd(24, 30) = 6`
* Not using a recursive solution: -3pts
* The best way to do this is using Euclidean Algorithm (辗转相除法).
 * Using other methods also allowed.
 * Very few cases deduction due to very bad implementation.

## Ex3.
* Not using functions -4pts
* Correctly let user make choice: 2pts
* For the first part, test cases 1pts each.
 * "U" => vowel, "u" => vowel
 * "Z" => consonant, "z" => consonant
* For the second part,
 * Using `switch`: -2pts, you may miss something!
 * Not Using `sizeof()`: -3pts, the program fails on MAC or Linux
 * Wrong Answer: -3pts
 * Consider size variations : +1pts

## Ex4.
* Test cases (2pt each, caps at 6pts);
 * `(1 2 1) => x = -1` 
 * `(8 -6 1) => x = -0.25, x = -0.5`
 * `(1 0 1) => x = +- i` Warning not giving any root: -0.5
 * return no root on (1 0 1) cost 0.5pts
 * return 2 lines on (1 2 1) cost 1pts
* Not following input specification: -2pts;

## Ex5.
Get the macro right: 3pts
Implement the demo: 3pts