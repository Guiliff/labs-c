#include <stdio.h>
#include <stdlib.h>

// Este código mostra a diferença de precisão entre o float e double.
// This program demonstrates the difference in precision between float and double

int main(){
    float number1 = 1.102030405060;
    double number2 = 1.102030405060;

    printf("\nFloat = %.10f\n", number1);
    printf("\nDouble = %.10f\n\n", number2);

}
