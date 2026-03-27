#include <stdio.h>

    int main(){

    float peso;
    float altura;
    float resultado_imc;

    printf("qual e o seu peso?\n");
    scanf("%f", &peso);

    printf("qual e sua altura?\n");
    scanf("%f", &altura);

    resultado_imc = peso / (altura * altura);

    printf("seu imc e: %.2f\n", resultado_imc);

    return 0;
}
