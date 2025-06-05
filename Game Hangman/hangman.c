#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//I can include a .h file for this
void welcome();
void shot();
int wasguessed(char letter);
void printingman();
int hang();
int win();
void secretword();
//

char sw[20];
char guess2 [26];
int userattempts = 0;

void welcome(){
    printf("\n--------------------------------\n");
    printf("            HANGMAN  \n");
    printf("--------------------------------\n");
}

void secretword(){
    FILE* f;
    f = fopen("secretswords.txt", "r");
    if(f == 0){
        printf("Sorry, the database is unavailable.\n\n");
        exit(1);
    }

    int qsw;
    fscanf(f, "%d", &qsw);
    
    srand(time(0));
    int randomico = rand() % qsw;

    for (int i = 0; i<= randomico; i++){
        fscanf(f, "%s", sw);
    }

    fclose(f);
}

void shot(){
    char guess;
    scanf(" %c", &guess); //Correcting a buffer error here
    guess2 [userattempts] = guess;
    userattempts++;
}

int wasguessed(char letter){
    int found = 0;

    for(int j=0; j<userattempts; j++){
        if(guess2[j] == letter){
            found = 1;
            break;
        }    
    }
    return found;
}

void printingman(){
    for (int i=0; i<strlen(sw); i++){
      
        int found = wasguessed(sw[i]);

        if (found){
            printf("%c ", sw[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

int hang(){
    int incorrect = 0;

    for(int i=0; i<userattempts; i++){
        int okword = 0;

        for(int j=0; j<strlen(sw); j++){
            if (guess2[i] == sw[j]){
                okword = 1;
                break;
            }
        }
        if (!okword) incorrect++;
    }
    return incorrect >=5;
}

int win(){
    for (int i = 0; i<strlen(sw); i++){
        if (!wasguessed(sw[i])){
            return 0;
        }
    }
    return 1;
}

int main(){

    secretword();

    welcome();

    do{
        printingman();
        shot();

    } while(!win() && !hang());

    return 0;
}
