#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    char sexo;
    int idade;
    float peso, altura;
    printf("Digite a sua idade, peso, altura e o seu sexo(m, M, F ou f): ");
    scanf("%d%f%f %c", &idade, &peso, &altura, &sexo); //Aqui entre as variáveis %f e %c, deve-se dar o espaço para não dar o erro
    printf("Sua idade é: %d\nSeu peso é: %.1f\nSua altura é: %.2f\nSeu sexo é: %c\n", idade, peso, altura, sexo);
    return 0;
}
