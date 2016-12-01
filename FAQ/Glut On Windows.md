# Guide for setting up Glut on Windows
This guide applys only for students working on Windows.
For students using MacOS, please seek help from Yuni.

# Background

`Glut` stands for `Open[GL] [U]tility [T]ools`. It's a library designed to ease programmers work while dealing with OpenGL programmes. `OpenGL` stands for `Open Graphics Library`. As its name suggests, it is a library for drawing figures (and more) on the screen. Applications that use this technology includes, games, design softwares (AutoCAD, etc.), visual designing (Photoshop, Premiere, etc.), phones (Android smartphones), and Matlab!

**From now on read the document carefully, miss Nothing!**

**From now on read the document carefully, miss Nothing!**

**From now on read the document carefully, miss Nothing!**

**From now on read the document carefully, miss Nothing!**

**From now on read the document carefully, miss Nothing!**

# General Procedure

### Acquiring library files:
  * You can download the file from the official website, [here](https://www.opengl.org/resources/libraries/glut/glutdlls37beta.zip)
  * Get them from the announcement, or
  * Get them from the QQ group

### Determining your environment:

If you have followed our C setup guide you should have a 32-bit version of `TDM-GCC` on your computer. It's important to verify your environment:

Run `gcc -v` in command line, check the **last line** in your output, you should see something like:

```
gcc version 5.1.0 <tdm-1>
```

Check the whats inside `<>`, if it's `<tdm-1>`, **not `<tdm64-1>`**, then we are fine, you can safely skip the 64-bit section. If otherwise, read through both section, **Do not do anything for now.**. 

If this command does not work, and you are using `Code::Blocks`. 

## Copying `dll`s into Windows directory
Assume your Windows is installed in `C:\`. 

* Decompress the download the file into arbitrary folder.
* Locate `C:\Windows\`. 
* Find inside the decompressed archive `glut.dll` and `glut32.dll`
* Copy both files into `C:\Windows\`.

This step setup the Windows environment for running `Glut` applications. An `Glut` application will fail to start if this step is not done correctly.

## Copy `.h` and `.lib`s into compiler directory
We now proceed to setup compiling environment for `Glut` programmes. If you followed our previous guide, your compiler should be installed under

```
C:\TDM-GCC\
```

Then copy `glut.h` into 

```
C:\TDM-GCC\include\GL\
```


and copy `glut.lib` and `glut32.lib` into 

```
C:\TDM-GCC\lib\
```

## Compile a sample programme (in command line)
Save the following code into a `gl.cpp` then compile it using
```
g++ -std=c++11 -pedantic -Wall gl.cpp -lglu32 -lglut32 -lopengl32
```

**Note that due to a known bug of g++, the library options must come last.**

i.e. the `-lglu32 -lglut32 -lopengl32` must stay on the tail of the compiling command.

Run it, if you see a black and white teapot, then you have done every thing correctly.

```cpp
/* Tea pot example
 * Got from
 * http://math.hws.edu/bridgeman/courses/324/s06/doc/opengl.html
 *
 * Note "windows.h" is neccessary to for students
 * using windows to compile
 * Keep it there no mater what the ide tells you
 */
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>


void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    /* draw scene */
    glutSolidTeapot(.5);

    /* flush drawing routines to the window */
    glFlush();

}

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    glutCreateWindow("hello, teapot!");
    glutDisplayFunc(display);

    /* tell GLUT to wait for events */
    glutMainLoop();
}
```

## Compiling a sample programme (in Clion)
Create a project with above sample.

In the `CMakeLists` file, apply the following change:

Assume that your project is named `project_opgl`. After the line 

```cmake
add_executable(project_opgl ...)
```

add one more line, so that it become
```cmake
add_executable(project_opgl ...)
target_link_libraries(project_opgl opengl32.lib glut32.lib glu32.lib)
```

For `freeglut` users, you should link these librarys instead,

```cmake
target_link_libraries(project_opgl opengl32 glu32 freeglut)
```

Make sure that the project (target name) of two lines are the same.


## Windows, 64-bit compiler:
Situation got complicated since you chose to ignore our kindly advice when setting up C environment. We now begin to deal with it.

First, a 64-bit compiler keeps 2 version of every library, the 64-bit version and the 32-bit version. When compiling a programme, it decides to use one of the versions based on whether you are compiling 32-bit version and 64-bit version.

We thus now have an unfortunate situation:

* `Glut` library only supports 32-bit version (at least it was such).
* A 64-bit compiler always tries to compile 64-bit programmes (by default).

Thus we need to

* Put the `Glut` library files into the 32-bit library directory, not the 64-bit location.
* Force the 64-bit compiler to compile 32-bit version.

Assume you use the default installation directory. Copy `glut.h` into 

```
C:\TDM-GCC-64\x86_64-w64-mingw32\include\GL
```

Copy `glut.lib` and `glut32.lib` into

```
C:\TDM-GCC-64\x86_64-w64-mingw32\lib32
```

When compiling a programme, add `-m32` flag into compiler to force the compiler generate 32-bit programme. The compiling command for the sample programme will be:

```
g++ -std=c++11 -m32 -pedantic -Wall sample.cpp -lopengl32 -lglut32 -lglu32
```

Also the library directives must come last.

For Clion users, in the `CMakeLists.txt`, change `set(CMAKE_CXX_FLAGS ...)` into

```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -std=c++11")
```

Add 
```cmake
target_link_libraries(PROJECT_NAME opengl32.lib glut32.lib glu32.lib)
```

after the `add_executable()` command. Remember to change the project name.

## Important notes for Windows users:
You will learn the basics from the lecture to see how to write `glut` applications. You will also learn what header file to include. There is one more complication. 

**You need to include `windows.h` before including any OpenGL/Glut headers**

This rule works for most Windows computer (very few might not). Note that including `windows.h` must happen before including anything `OpenGL` related. 

**Order of inclusion matters in this case!**

It's just a real life bad practice. 

Note that the IDE might warn you that the file is unused.
Well, it's required for the linker, not the compiler. Thus no, it's not useless.

