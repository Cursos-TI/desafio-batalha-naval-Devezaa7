#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Exibe o tabuleiro com os valores correspondentes
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Inicializa o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona alguns navios (3) no tabuleiro
    tabuleiro[2][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[1][8] = 3;
    tabuleiro[8][1] = 3;
}

// Gera matriz de habilidade: Cone apontado para baixo
void gerarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Gera matriz de habilidade: Cruz
void gerarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Gera matriz de habilidade: Octaedro (losango)
void gerarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica a habilidade ao tabuleiro, centrando no ponto de origem
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tabuleiro = origem_linha - TAM_HABILIDADE / 2 + i;
            int coluna_tabuleiro = origem_coluna - TAM_HABILIDADE / 2 + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tabuleiro >= 0 && linha_tabuleiro < TAM_TABULEIRO &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 0) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5; // Marca área da habilidade
                }
            }
        }
    }
}

// Exibe matriz da habilidade para debug
void exibirHabilidade(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("\nHabilidade: %s\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);

    // Habilidade 1: Cone
    gerarCone(habilidade);
    exibirHabilidade(habilidade, "Cone");
    aplicarHabilidade(tabuleiro, habilidade, 3, 3);  // Ponto de origem (3,3)
    exibirTabuleiro(tabuleiro);

    // Habilidade 2: Cruz
    gerarCruz(habilidade);
    exibirHabilidade(habilidade, "Cruz");
    aplicarHabilidade(tabuleiro, habilidade, 6, 6);  // Ponto de origem (6,6)
    exibirTabuleiro(tabuleiro);

    // Habilidade 3: Octaedro
    gerarOctaedro(habilidade);
    exibirHabilidade(habilidade, "Octaedro");
    aplicarHabilidade(tabuleiro, habilidade, 1, 8);  // Ponto de origem (1,8)
    exibirTabuleiro(tabuleiro);

    return 0;
}
