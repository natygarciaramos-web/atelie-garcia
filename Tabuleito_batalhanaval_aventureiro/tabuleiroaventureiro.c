#include <stdio.h>

#define LINHAS 10   // Número de linhas do tabuleiro
#define COLUNAS 10  // Número de colunas do tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios
#define AGUA 0      // Representa água no tabuleiro
#define NAVIO 3     // Representa navio no tabuleiro

// Função para verificar se a posição está dentro dos limites e livre
int posicao_livre(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna)
{
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS)
    {
        return 0; // Fora dos limites
    }
    return tabuleiro[linha][coluna] == AGUA;
}

// Valida se navio horizontal pode ser colocado
int pode_posicionar_horizontal(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna_inicial)
{
    if (coluna_inicial + TAM_NAVIO - 1 >= COLUNAS)
        return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (!posicao_livre(tabuleiro, linha, coluna_inicial + i))
            return 0;
    }
    return 1;
}

// Valida se navio vertical pode ser colocado
int pode_posicionar_vertical(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna)
{
    if (linha_inicial + TAM_NAVIO - 1 >= LINHAS)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (!posicao_livre(tabuleiro, linha_inicial + i, coluna))
            return 0;
    }
    return 1;
}

// Valida navio diagonal descendente
int pode_posicionar_diagonal_desc(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna_inicial)
{
    if (linha_inicial + TAM_NAVIO - 1 >= LINHAS || coluna_inicial + TAM_NAVIO - 1 >= COLUNAS)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (!posicao_livre(tabuleiro, linha_inicial + i, coluna_inicial + i))
            return 0;
    }
    return 1;
}

// Valida navio diagonal ascendente
int pode_posicionar_diagonal_asc(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna_inicial)
{
    if (linha_inicial - (TAM_NAVIO - 1) < 0 || coluna_inicial + TAM_NAVIO - 1 >= COLUNAS)
        return 0;
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        if (!posicao_livre(tabuleiro, linha_inicial - i, coluna_inicial + i))
            return 0;
    }
    return 1;
}

// Posiciona navio horizontal
void posicionar_horizontal(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna_inicial)
{
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha][coluna_inicial + i] = NAVIO;
    }
}

// Posiciona navio vertical
void posicionar_vertical(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna)
{
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha_inicial + i][coluna] = NAVIO;
    }
}

// Posiciona navio diagonal descendente
void posicionar_diagonal_desc(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna_inicial)
{
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha_inicial + i][coluna_inicial + i] = NAVIO;
    }
}

// Posiciona navio diagonal ascendente
void posicionar_diagonal_asc(int tabuleiro[LINHAS][COLUNAS], int linha_inicial, int coluna_inicial)
{
    for (int i = 0; i < TAM_NAVIO; i++)
    {
        tabuleiro[linha_inicial - i][coluna_inicial + i] = NAVIO;
    }
}

// Exibe o tabuleiro com linhas numeradas e colunas nomeadas
void imprimir_tabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    printf("    ");
    for (int c = 0; c < COLUNAS; c++)
    {
        printf("%c ", 'A' + c);
    }
    printf("\n");
    for (int l = 0; l < LINHAS; l++)
    {
        printf("%2d  ", l);
        for (int c = 0; c < COLUNAS; c++)
        {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
}

int main()
{
    int tabuleiro[LINHAS][COLUNAS] = {AGUA}; // Inicializa com água

    // Coordenadas dos navios
    int linhaH = 1, colunaH = 2;   // horizontal
    int linhaV = 5, colunaV = 0;   // vertical
    int linhaDD = 0, colunaDD = 6; // diagonal descendente
    int linhaDA = 7, colunaDA = 2; // diagonal ascendente

    // Posiciona navios com validação
    if (pode_posicionar_horizontal(tabuleiro, linhaH, colunaH))
    {
        posicionar_horizontal(tabuleiro, linhaH, colunaH);
    }
    if (pode_posicionar_vertical(tabuleiro, linhaV, colunaV))
    {
        posicionar_vertical(tabuleiro, linhaV, colunaV);
    }
    if (pode_posicionar_diagonal_desc(tabuleiro, linhaDD, colunaDD))
    {
        posicionar_diagonal_desc(tabuleiro, linhaDD, colunaDD);
    }
    if (pode_posicionar_diagonal_asc(tabuleiro, linhaDA, colunaDA))
    {
        posicionar_diagonal_asc(tabuleiro, linhaDA, colunaDA);
    }

    // Exibe o tabuleiro final
    imprimir_tabuleiro(tabuleiro);

    printf("\nNavios posicionados com sucesso!\n");

    return 0;
}