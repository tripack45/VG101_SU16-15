#include "assignment.h"

int main(int argc, char* argv[]) {
    int ex = getExerciseNumber(argc, argv);
    switch (ex){
        case 1 :
            ex1();
            return 0;
        case 2:
            ex2();
            return 0;
        case 3:
            ex3();
            return 0;
        case 4:
            ex4();
            return 0;
        default:
            printf("\n The exercise does not exist!\n");
            printf("You specified exercise: %d", ex);
            return 0;
    }
}

int getExerciseNumber(int argc, char* argv[]){
    if(argc <= 0 || argc > 2) {
        printf("Illegal Usage");
        exit(-2);
    }
    if (argc == 2) {
        // Grader provided argument
        char *str = argv[1];
        int crit = 1;
        crit = crit && (str[0] == '-');
        crit = crit && (str[1] == 'e');
        crit = crit && (str[2] == 'x');
        if (crit)
            if ( str[3] > '0' && str[3] <= '9')
                return (str[3] - '0');
        printf("Illegal argument");
        exit(-3);
    }
    if (argc == 1){
        // Student running without argument
        int exerciseNum = 0;
        for(;;) {
            printf("Please input your exercise number: ");
            scanf("%d", &exerciseNum);
            fflush(stdin);
            if(exerciseNum > 0 && exerciseNum < 10)
                return exerciseNum;
            printf("Illegal input, try again");
        }
    }
}

