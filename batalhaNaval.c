#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    int linha_horizontal = 2;
    int coluna_horizontal = 3;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Valida se os navios estão dentro dos limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    if (linha_vertical + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: o navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 3 ||
            tabuleiro[linha_vertical + i][coluna_vertical] == 3) {
            printf("Erro: sobreposição de navios detectada.\n");
            return 1;
        }
    }

    // Posiciona os navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3; // Horizontal
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;     // Vertical
    }

    // Cabeçalho com letras A-J
    printf("    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Linha divisória
    printf("   +");
    for (int i = 0; i < TAMANHO; i++) {
        printf("--");
    }
    printf("\n");

    // Tabuleiro com numeração de linhas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d |", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
