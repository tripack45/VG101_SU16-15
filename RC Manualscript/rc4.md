# C/C++ Environment Setup Guide

## Background knowledge

Skip the part if you are not interested. 
But these knowledge are essential if you want to understand what you are doing.

C/C++ are compiled languages. Meaning, the general way of writing and executing a C program, is

1. Write a C program in a text file (or a collection of files), call this file a "source" file.
2. Use a special program (namely "the C compiler") to translate the into a binary file, this step is "compile".
3. Run this binary file to see results.

You are expected to know these three steps. 

So basically, to set up the C environment is to the following 2 things:

1. You need a text editor to edit text file. 
2. You need a compiler so when you are editing, use it to compile the file.

So you just pick one editor from a bunch of choices, then install the compiler. Then you are good.

For the first one, in most systems, text editors are already there, such as `Notepad.exe`(记事本) on Windows.
They often provide the basic functionality. So basic that using them to write programs can be unpleasant. So
in many cases, people with use better tools, things like `Sublime text`, `VS Code`, etc.

For the second one, the compiler we use for this course is `gcc`, stands for `GNU C Compiler`. For Windows 
users, we use (one of many) its Windows versions, called `TDM-GCC`.

Above we introduce the traditional "Editor + Compiler" environment.

 Another popular choice is "IDE + Compiler". `IDE` is short for "Integrated Development Environment".
 You can think of is as a super editor, tailored for writing code (and testing, maintaining code...).
 A good IDE provides insight into your code, help the programmer by providing suggestions,
and detects potential mistakes in the code. 

We suggest students start with this choice.

## Installing the compiler:

For students using Windows, you are about to do download and install `TDM-GCC`, a `gcc` portation on Windows.

(Windows) Please do the following: 

* Go to [official website](http://tdm-gcc.tdragon.net/download) and download the 32bit version (the top most one).
* If you can't do that because various reasons, download from [here](http://jcube.sjtu.edu.cn/f/34295/tdm-gcc-5.1.0-3.exe), thanks to SJTU.
* Install, by keep clicking "continue".
* Verify if you installed it correctly, by running `gcc -v` in `cmd`.

If your intallation is successful, the last line of output should be like(minor difference possible):
```
gcc version 5.1.0 <tdm32-1>
```

(Mac OSX) Please contact your TA "Yuni Zhang" for help. 

(Linux) Please contact any one of your TA for help.

## Option 1, Using a text editor:
Text editor are fast, lightweight. However to use them conveniently, you need to do more work.

## Option 2, Using an IDE

Due to various reasons. **Microsoft Visual Studio is strictly PROHIBITED**

**DO NOT USE MS VISUAL STUDIO**

**DO NOT USE MS VISUAL STUDIO**

**DO NOT USE MS VISUAL STUDIO**

IDEs are heavy weight. They are easy to use out-of the box. However the cost is they are much slower.

### Clion

It's my personal favourite. It'a commercial software from a company called JetBrains.
 Students with SJTU email-address can apply for a free liscense easily.

It is arguably the most powerful IDE at this time. Unlike many other IDEs, it actually tries to understand
your code, other then seeing them as texts. 

Here is its [Official Website](https://www.jetbrains.com/clion/). 
After installing the sofware you will need to inform it where your "gcc" is.
You will need to regester for your JetBrains Account also on the official website for the free lisence.

Note that this IDE also works for Linux and Mac.

### Code::Blocks

**Attentiion: The IDE comes with its own gcc. No need to install another one**

It is an open-source, cross-platform IDE. Meaning it works on "Windows, Linux, MacOSX".

It was the choice of this course before this semester. 

It's official download page is [here](http://www.codeblocks.org/downloads/26). 

For windows users remember to download the one `codeblocks-16.01mingw-setup.exe`. 
It comes with its own compiler.


