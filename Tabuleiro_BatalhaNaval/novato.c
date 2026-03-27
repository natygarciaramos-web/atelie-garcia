#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main()
{

    int tabuleiro[TAM][TAM];

    // Inicializa com 0
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // 🔹 Cabeçalho com letras
    printf("\n   ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    // 🔹 Tabuleiro
    for (int i = 0; i < TAM; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < TAM; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}