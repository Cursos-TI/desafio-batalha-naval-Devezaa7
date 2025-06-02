#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NUM_NAVIOS 4

// Direções possíveis dos navios
typedef enum {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL_DESC, // linha++, coluna++ (diagonal descendente)
    DIAGONAL_ASC   // linha++, coluna-- (diagonal ascendente)
} Direcao;

// Estrutura para navio
typedef struct {
    int linha_inicial;
    int coluna_inicial;
    Direcao direcao;
} Navio;

// Função para inicializar tabuleiro com 0 (água)
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// Função que verifica se navio pode ser colocado na posição dada sem sair do tabuleiro e sem sobrepor outros navios
int podePosicionar(int tab[TAM][TAM], Navio navio) {
    int l = navio.linha_inicial;
    int c = navio.coluna_inicial;

    for (int i = 0; i < TAM_NAVIO; i++) {
        // Calcula posição atual do navio
        int linha = l, coluna = c;

        switch (navio.direcao) {
            case HORIZONTAL:
                coluna = c + i;
                break;
            case VERTICAL:
                linha = l + i;
                break;
            case DIAGONAL_DESC:
                linha = l + i;
                coluna = c + i;
                break;
            case DIAGONAL_ASC:
                linha = l + i;
                coluna = c - i;
                break;
        }

        // Verifica limites do tabuleiro
        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            return 0; // Fora do tabuleiro
        }

        // Verifica sobreposição
        if (tab[linha][coluna] == 3) {
            return 0; // Já tem navio aqui
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tab[TAM][TAM], Navio navio) {
    int l = navio.linha_inicial;
    int c = navio.coluna_inicial;

    for (int i = 0; i < TAM_NAVIO; i++) {
        int linha = l, coluna = c;

        switch (navio.direcao) {
            case HORIZONTAL:
                coluna = c + i;
                break;
            case VERTICAL:
                linha = l + i;
                break;
            case DIAGONAL_DESC:
                linha = l + i;
                coluna = c + i;
                break;
            case DIAGONAL_ASC:
                linha = l + i;
                coluna = c - i;
                break;
        }

        tab[linha][coluna] = 3;
    }
}

// Função para imprimir o tabuleiro com letras e números
void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("   A B C D E F G H I J\n"); // Letras das colunas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i); // Número das linhas
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Definindo navios manualmente
    Navio navios[NUM_NAVIOS] = {
        {1, 1, HORIZONTAL},     // Navio horizontal começando na linha 1, coluna 1
        {4, 5, VERTICAL},       // Navio vertical começando na linha 4, coluna 5
        {6, 2, DIAGONAL_DESC},  // Navio diagonal descendente começando na linha 6, coluna 2
        {3, 8, DIAGONAL_ASC}    // Navio diagonal ascendente começando na linha 3, coluna 8
    };

    // Validar e posicionar cada navio
    for (int i = 0; i < NUM_NAVIOS; i++) {
        if (podePosicionar(tabuleiro, navios[i])) {
            posicionarNavio(tabuleiro, navios[i]);
        } else {
            printf("Erro: nao foi possivel posicionar o navio %d na posicao (%d,%d)\n", 
                   i+1, navios[i].linha_inicial, navios[i].coluna_inicial);
            return 1;
        }
    }

    // Exibir o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
