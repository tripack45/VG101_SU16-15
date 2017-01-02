#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHARACTER_CNT 5
#define WEAPON_CNT 5
#define LOCATOION_CNT 5

typedef struct {
    int suspect;
    int location;
    int weapon;
}Guess;

void getRandomGuess(Guess* guess);
void getUserGuess(Guess* guess);
int compareGuess(Guess* guess1, Guess* guess2);

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

    Guess answer;
    getRandomGuess(&answer);

    Guess* userGuess[10] = {NULL};

    int round = 0;
    int isWin = 0;

    while (round < 10) {

        printf("Round %d\n", round + 1);

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

        userGuess[round] = malloc(sizeof(Guess));
        if (userGuess + round == NULL) {
            return -1;
        }
        getUserGuess(userGuess[round]);
        int t = compareGuess(userGuess[round], &answer);
        printf("You made %d correct guesses\n", t);
        printf("You suspected the %s to have killed Janis in the %s using a %s\n",
               suspects[userGuess[round]->suspect],
               location[userGuess[round]->location],
               weapons[userGuess[round]->weapon]);

        if (t == 3) {isWin = 1; round ++; break; };

        round++;
    }

    if (isWin) {
        printf("Congratulations, you solved the case using the following sequence\n");
    } else {
        printf("Game over, you failed to solve the case using the following sequence\n");
    }

    for (int j = 0; j < round; ++j) {
        printf("%d. You suspected the %s to have killed Janis in the %s using a %s\n",
               j,
               suspects[userGuess[j]->suspect],
               location[userGuess[j]->location],
               weapons[userGuess[j]->weapon]);

    }

    printf("Conclusion: the %s has killed Janis in the %s using a %s.",
           suspects[answer.suspect],
           location[answer.location],
           weapons[answer.weapon]
    );

    for (int i = 0; i < round; ++i) {
        free(userGuess + i);
    }
}

void getRandomGuess(Guess *guess) {
    srand(time(NULL));
    guess->suspect = rand() % CHARACTER_CNT;
    guess->weapon = rand() % WEAPON_CNT;
    guess->location = rand() % LOCATOION_CNT;
    return;
}

void getUserGuess(Guess *guess) {
    printf("Please select a suspect, a location, and a weapon: ");
    scanf("%d %d %d",
          &(guess->suspect),
          &(guess->location),
          &(guess->weapon));
    guess->suspect--;
    guess->location--;
    guess->weapon--;
    printf("\n");
}

int compareGuess(Guess *guess1, Guess *guess2) {
    int cnt = 0;
    if (guess1->suspect == guess2->suspect) cnt++;
    if (guess1->location == guess2->location) cnt++;
    if (guess1->weapon == guess2->weapon) cnt++;
    return cnt;
}
