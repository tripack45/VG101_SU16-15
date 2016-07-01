# A not so short (But interesting) passage on pointers
Dear all:

I'm receiving got questions on pointers lately.

To understand pointers, eventually you will have to understand the "memory", where the program store all its data (both "data" data and "instruction" data).

I'd like to help you understand this using the following story, a story adapted from one that helped myself understand pointers (years ago). We now assume you understand the pointer's syntax. (How to define pointers, how to assign values to them, how to take the address of a variable, etc.). Draw pictures to help you understand!

Suppose you are in front of a bunch of deposit boxes. Let's say JI deposit service.

## Part A:
JI mail service has 100 boxes, numbered from 1 to 100. You have a homework to deposit. You just want one of them, you don't care which one.
How to do that? Easy, you go and printed out a paper, write `homework` on to it, then stick it to a random box. Lets say you stick that name plate to box number `50`.

Then you opened it, found someone else's homework. You are an honest student, so you thought: since the box is unnamed, so whatever in it must be useless. Thus your throw it away. Then you immediately put your home work into it, let's say it's a peice of paper with number `14` on it. 

## Part B:
One day, a very good friend of you wants your help on his homework. You don't have time to teach him, so you make a photo copy of the homework. 

"Thank you"

Your friend take your copy and walked away. You have no idea what he did to that photo copy of your homework.

Your friend only needs half your homework, he thinks the entire homework takes too much space, so throw away some pages, then put the rest in his own box `hcHW`.

##Part C:

You always put your homework in the box. One day, you find yourself mistaken the due day. You have to come to your instructor's office, and told the instructor:

" I left my work in the deposit box in JI building, what should I do?"

Then the professor said:

" Oh, these things happen very often, I'm prepared", he continued.

" I have a deposit box, I call it `hwptr`, which box is your homework in."

" `50` ", you replied.
    
The instructor wrote `50` down, then put this piece of paper into the `hwptr` box.
    
Next day, the instructor opens his `hwptr` box, found a peice of paper with number `50` on it, then follows it to the number `50` box, then graded your homework.

## Explanations

Now imagine the deposit box are your computer memory, each box represents one byte of the memory. The serial number 50 represents it's address. Every byte of the memory has an address, just like any box has a serial number.

In part A, you are running some code like:

```c
char homework; homework = 14;
```

The first statement finds a "random" memory regeion, 1 byte large (1 box large), then "name" it with `homework`, a name that is only meaningful to you, the programmer. As you see, it's toatally possible that someone has used memory regeion before, and left some data in it. This is the exactly why "unintialized" variable contains "random value". In part A of the story, you immediately initialize your memory regeion.

* Extra Notes:
 * Note this story is a good example. Since an unintialized memory could contain other program's used information. These information are most likely nonsense to your program, but sometimes they can contain valuable information (In the story, perhaps your student's homework!). For example, a login program could store a user's password in the memory. When it exited, some malicious program could run, setup so many unintialized variables to search for the regeion that the login program used to store the password. This is an real-life cyber-attack example. That's why security related program always wipe its memory (set them to zero after using them).

In part B, you are running code like:

```c
void yourFriendTakeAway(char hw) {
   hcHW = hw / 2;
}

yourFriendTakeAway(homework);
```

What happened (conceptually) in memory, is that `homework` is first copied, then send to your friend (the function). This step happens when you calls the function (before the content of the function begins executing). The function get a copy of original value, then do whatever with it. Since its a copy, it won't affect the original. 

Things changes in the third the situation, now your teacher has to grade your homework, so he must operates on the original copy, let's first see the code.

```c
void yourInstructorGrade(char* hwptr) {
    *hwptr = GRADED_HOMEWORK;
}

yourInstructorGrade(&homework);
```

Note that now pointers come into play. 

* A pointer, or is essentially an address (serial number of a box).

* A pointer variable, is a variable (a box, which itself has an serial number), whose value (the content in the box) is an address (a serial number of another box). 

* A `&homework` takes the address of `homework`. i.e. the "value" of `&homework` is the address of `homework` (serial number of a box), essentially a number (`50` in our story). This value has a pointer datatype (to signify it's not a random number, but an address). 

* `*hwptr` follows the `hwptr` to a specific location in memory. We assume `hwptr` is a pointer. i.e. the value of `hwptr` is an address (`hwptr` contains a serial number for a box in our story). Then `*hwptr` follows that address (technical term is "dereference") to a specific location in the memory. In our story, it refers to the box with serial number stored in `hwptr`. 

Understand these 4 sentences before we go on. 

Now imagine the instructor as a function that grades the homework (which is not true in real life!). The function takes an argument, that is an pointer (the instructor asks for your box serial number). In calling `yourInstructorGrade(&var)`, You make a copy of the address (the serial number), pass the copied address to the function argument `hwptr` (put the copies in the instructor's box). Note variable `hwptr` is a pointer variable (since it stores a address, just like the instructor's box stores the serial number of your box). 

Then your work is done. The function dereferences `hwptr` using `*hwptr` (the instructor follows the serial number in his box), then find your variable (your box). Change whatever is inside it. As you have seen, since calling functions always makes a copy of the passed value, thus in C passing the pointer (address) is the only way allowing a function to change what's not belonged to it (just like the instruction grades your homework, a work that belongs to you.)

Part D: Arrays

Array are stored continuously in memory. Meaning, suppose you open an array of `char varArray[10];`. It will be just like say occupying box 11 to 20 in our story. You take down the address of the first box, i.e. 11, store it in `varArray`. Now `varArray` stores 11, an address, so it is essentially a pointer. The fact that the name of an array is actually an pointer seems strange. But think about it, when you access `varArray[2]`, for example, you can regard it as "Get me the content of a box, whose serial number 2 boxes larger then `varArray`". Meaning,  `varArray[2]` is essentially `*(varArray + 2)`. Thus it's now possible to use the address of the first element, to represent the entire array, since any elements are just "an element whose address is some number larger then the `varArray`". It's the same reasoning that passing an array as an argument to a function is effectively the same as pass an pointer. It's also the reason why `fun(char array[10]);` makes no sense, since a pointer is a just a pointer, the number 10 will not get passed to the function.

But, think about it, suppose you have an array of size 10. What happens when you access `varArray[10]`? Well, following our story, you own box from 11 to 20, now varArray stores 11, so `varArray[10]` accesses the box with serial number `11 + 10 = 21`, which is not your box. It might be unused. It could possibly contain important data. Unfortunately, the C compiler will not stop you from doing this, there will be no warning, so you **COULD** successfully change the content of `varArray[10]`. It such way important data might get lost. 

This is the reason why you should pass the size of the array to a function. Since passing a array to a function is essentially passing a pointer, so the function have no idea how many bytes after where the pointer points are part of the valid array. Chances are you write on some memory that you shouldn't. If that memory is too important, so it is protected by the operating system (Windows, Linux, MacOS...), then the CPU refuses to continue executing your code (because it is doing damage!). This is sometimes "Segment Fault".

## Part E: Strings in C:

Strings in C are essentially arrays. Meaning, characters in a string are stored one by one continuously in memory. So it is sufficient to represent the entire string using its array name (essentially a pointer). That's why strings have type `char*`, essentially pointer to chars, also the reason why you don't need `&` for strings when using `printf()`. However, there is something does not add up. If strings are array, then why library functions that operates on string does not require the user to pass the size? How does library functions (such as `strcmp()` ) prevent problem mentioned in part D? Well, this leads to one very important feature of a C string: it always ends with `'\0'`, or number `0`. This is how library function determines the end of a string. For example, `printf("%s", s)`, prints every byte as a character, starting with s, until it meets a `'\0'`. 

What will happen if you forgot `'\0'`? Well, printf will keep printing, until 1) it meets `'\0'` accidentally 2) stopped by OS (your program crashes). For the first case, sensitive information might get exposed accidentally (password for example). A very famous joke around programmers who program in Visual Studio is, when you try to print a not properly ended string, you will get see `烫烫烫烫`. It's because VS initializes unused memory by some special value, which in the end becomes the Chinese characters.

## Part F: More pointers

If you are dealing with things like pointers to pointers, try to draw a graph and use our story as an inspiration. Always remember that a pointer is essentially an address. And a pointer variable is just a regular variable, whose value is simply an address. The type of a pointer is just the type of value that address contains.