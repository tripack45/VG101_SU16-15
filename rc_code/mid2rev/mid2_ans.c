//
// Created by patri on 2016/7/7.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CHARACTER_CNT 5
#define WEAPON_CNT 5
#define LOCATOION_CNT 5

typedef struct{
    int character;
    int location;
    int weapon;
}Guess;

int countEqual(Guess *guess1, Guess *guess2);
void getUserGuess(Guess* guess);
void randomGuess(Guess* guess);

int main() {
    char* suspects[] = {
            "Butcher",
            "Hairdresser",
            "Salesman",
            "Banker",
            "Student"
    };

    char* location[] = {
            "Lounge",
            "Lobby",
            "Reception",
            "Restuaant",
            "Coffee shop"
    };

    char* weapons[] = {
            "Hammer",
            "Fork",
            "Knife",
            "Poison",
            "Candlestick"
    };

    Guess answer = {0, 0, 0};
    Guess* userGuess[11];
    randomGuess(&answer);
    int turn = 1;
    while (turn <= 10) {
        userGuess[turn] = malloc(sizeof(Guess));
        printf("Round %d\n", turn);

        printf("List of suspects:");
        for (int i = 0; i < CHARACTER_CNT; ++i) {
            printf("%d. %s ", i + 1, suspects[i]);
        }
        printf("\n");

        printf("List of locations:");
        for (int i = 0; i < LOCATOION_CNT; ++i) {
            printf("%d. %s ", i + 1, location[i]);
        }
        printf("\n");

        printf("List of Weapons:");
        for (int i = 0; i < WEAPON_CNT; ++i) {
            printf("%d. %s ", i + 1, weapons[i]);
        }
        printf("\n");

        printf("\n");

        getUserGuess(userGuess[turn]);
        int ret = countEqual(userGuess[turn], &answer);
        printf("You made %d correct guesses\n", ret);
        printf("You suspected the %s to have killed Janis in the %s using a %s\n",
               suspects[userGuess[turn]->character],
               location[userGuess[turn]->location],
               weapons[userGuess[turn]->weapon]);
        if (ret == 3) break;
        printf("\n");
        turn ++;
    }

    if (turn <= 10) { // Winned
        printf("Congratulations, you solved the case using the following sequence\n");
    } else {// Lost
        printf("Game over, you failed to solve the case using the following sequence\n");
    }

    for (int i = 1; i <= turn && i < 11; ++i) {
        printf("%d. You suspected the %s to have killed Janis in the %s using a %s\n",
               i,
               suspects[userGuess[i]->character],
               location[userGuess[i]->location],
               weapons[userGuess[i]->weapon]);
    }
    puts("");
    printf("Conclusion: the %s has killed Janis in the %s using a %s.",
           suspects[answer.character],
            location[answer.location],
            weapons[answer.weapon]
    );

    for (int j = 1; j < turn ; ++j) {
        free(userGuess[j]);
    }

}

void randomGuess(Guess* guess) {
    srand(time(NULL));
    guess->character = rand() % CHARACTER_CNT;
    guess->weapon = rand() % WEAPON_CNT;
    guess->location = rand() % LOCATOION_CNT;
}

int countEqual(Guess *guess1, Guess *guess2) {
    int ret = 0;
    if (guess1->location == guess2->location) ret ++;
    if (guess1->character == guess2->character) ret ++;
    if (guess1->weapon == guess2->weapon) ret++;
    return ret;
}

void getUserGuess(Guess* guess) {
    printf("Please select a suspect, a location, and a weapon: ");
    scanf("%d %d %d",
          &(guess->character),
          &(guess->location),
          &(guess->weapon));
    guess->character--;
    guess->location--;
    guess->weapon--;
    printf("\n");
}