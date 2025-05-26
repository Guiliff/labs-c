#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char sw[20];
    sprintf(sw, "HAWKMAN");

    int correct = 0;
    int incorrect = 0;

    char guess2 [26];
    int attempts = 0;

    do{
        for (int i=0; i<strlen(sw); i++){
            
            int found = 0;

            for(int j=0; j<attempts; j++){
                if(guess2[j] == sw[i]){
                    found = 1;
                    break;
                }
            }
            if (found){
                printf("%c ", sw[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");

        char guess;
        scanf(" %c", &guess); //Correcting a buffer error here

        guess2 [attempts] = guess;
        attempts++;

    } while(!correct && !incorrect);
}
