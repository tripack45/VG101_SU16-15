//
// Created by patri on 2016/6/18.
//

#ifndef CTEMPLATE_ASSIGNMENT_H
#define CTEMPLATE_ASSIGNMENT_H

int getExerciseNumber(int argc, char* argv[]);
/* This function gets the exercise number to run from
 * 1. programe argument (for graders)
 * 2. student input prompt (for students)
 * To input the number from argument, call "outputFile.exe -exN"
 * for exercise N. Assume 0 < N < 10
 * To input it from prompt, enter an integer between 1 to 9
 * Wrong input will be prompt for re-input.
 *
 * Written by VG101_SU16TA/patrick
 */

extern void ex1();
extern void ex2();
extern void ex3();
extern void ex4();

#endif //CTEMPLATE_ASSIGNMENT_H
