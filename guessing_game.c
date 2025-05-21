#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("\n----------------------------------\n");
    printf("       Welcome to the game\n");
    printf("----------------------------------\n\n");

    srand(time(NULL));
    int number = rand() % 51; // Generated a random number between 0 and 50
    int guess;
    int won = 0; // Flag to check if the answer was correct
    int attempts;

    int level;
    printf("Select a difficulty\n");
    printf("(1) EASY | (2) MEDIUM | (3) HARD:\n");
    scanf("%d", &level);

    switch(level){
        case 1:
            attempts = 15;
            break;
        case 2:
            attempts = 10;
            break;
        default:
            attempts = 5;
            break;
        
    }

    printf("Let's get started.\n\n");

    for (int i=1; i<=attempts; i++){
        printf("Attempt %d of %d\n", i, attempts);
        printf("Tell me a number from 0 to 50: ");
        scanf("%d", &guess);

        int correct = (guess == number);
        int low = guess < number;
        int high = guess > number;

        if (guess<0){
            printf("You can't guess a negative number. Try again.\n\n");
            i--; 
            //so this doesn't count as an attempt
        }

        else if (correct){
            printf("Congratulations! You win.\n\n");
            won = 1;
            break;
        }
        else if (high){
            printf("Your guess was too high.\n\n");
        }
        else if(low){
            printf("Your guess was too low.\n\n");
        }
    }
    if (!won){
        printf("You've used all your attempts. The number was: %d\n\n", number);
    }
    printf("END GAME\n\n");
    return 0;
}
