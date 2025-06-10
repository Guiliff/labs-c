#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//I can include a .h file for this
void welcome();
void shot();
int wasguessed(char letter);
void printingman();
int hang();
int win();
void secretword();
void newword();
int fault();
//

char sw[20];
char guess2 [26];
int userattempts = 0;

void welcome(){
    printf("\n--------------------------------\n");
    printf("            HANGMAN  \n");
    printf("--------------------------------\n");
}

void newword(){
    char yes;

    printf("Would you like to add a new word to the game? (Y/N)?");
    scanf( " %c", &yes);
    if(yes == 'Y'){
        char addword[20];
        printf("What's the new word?");
        scanf("%s", addword);

        FILE* f;
        f = fopen("secretswords.txt", "r+");
        if(f == 0){
        printf("Sorry, the database is unavailable.\n\n");
        exit(1);
    }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);
        fseek(f, 0, SEEK_END);

        fprintf(f, "\n%s", addword);
        fclose(f);
    }
    else{
        printf("\nOk. Thanks for playing. See you next time!\n");
    }
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

    for (int i = 0; i < strlen(sw); i++) {
        sw[i] = tolower(sw[i]);
    }

    fclose(f);
}

void shot(){
    char guess;
    printf("Type a letter: ");
    scanf(" %c", &guess); //Correcting a buffer error here
    guess = tolower(guess);
    
    if (wasguessed(guess)){
        printf("You already tried the letter '%c'. Try another one.\n", guess);
        return;
    }
    if (userattempts < sizeof(guess2)){
        guess2[userattempts] = guess;
        userattempts++;
    }
    else{
        printf("You've exceeded the number of attempts\n");
    }
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

    int incorrect = fault();
    printf("       _______\n");
    printf("      |/      |\n");
    printf("      |      %c%c%c\n", (incorrect>=1 ? '(' : ' '), (incorrect>=1 ? '_' : ' '), (incorrect>=1 ? ')' : ' '));
    printf("      |      %c%c%c\n", (incorrect>=3 ? '\\' : ' '), (incorrect>=2 ? '|' : ' '), (incorrect>=3 ? '/' : ' '));
    printf("      |       %c\n", (incorrect>=2 ? '|' : ' '));
    printf("      |      %c %c\n", (incorrect>=4 ? '/' : ' '), (incorrect>=4 ? '\\' : ' '));
    printf("     _|___\n\n");

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

int fault(){
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
    return incorrect;
}

int hang(){
    return fault() >=5;
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

    if(win()){
        printf("\nCongratulations!! You won!\n\n");
    }
    else{
        printf("\nOh no... You were hanged. The secret word is - %s -\n\n", sw);
    }

    newword();

    return 0;
}
