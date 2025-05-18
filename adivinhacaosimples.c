#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\n--------------------------------------------------\n");
    printf("\n Bem vindo ao nosso jogo de adivinhação simples.\n");
    printf("\n--------------------------------------------------\n");
    
    int number = 13;
    int chute;
    int tentativas = 3;
    
    for(int i=1; i<=tentativas; i++){
        printf("Tentativa %d de %d\n", i, tentativas);
        printf("\nDigite um número entre 1 à 20: ");
        scanf("%d", &chute);
        
        if(chute == number){
            printf("\nParabéns, você acertou!\n\n");
            break;
        }
        else{
            if(chute>number){
                printf("\nSeu chute foi maior que o número secreto. Tente novamente.\n\n");
            }
            if(chute<number){
                printf("\nSeu chute foi menor que o número secreto. Tente novamente. \n\n");
            }
            }
    }
    printf("Fim de jogo!\n\n");
    return 0;
}
