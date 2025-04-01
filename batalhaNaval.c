#include <stdio.h>
#define TAM 10
#define HSIZE 5

// Função para inicializar o tabuleiro
void iniciartab(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona dois navios horizontalmente ou verticalmente
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    // Posiciona dois navios na diagonal
    tabuleiro[6][2] = 3;
    tabuleiro[7][3] = 3;
    tabuleiro[8][4] = 3;

    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;
    tabuleiro[3][6] = 3;
}

// Aplica uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HSIZE][HSIZE], int origemX, int origemY) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            int x = origemX + i - HSIZE / 2;
            int y = origemY + j - HSIZE / 2;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM && habilidade[i][j] == 1) {
                if (tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Cria matriz de habilidade em forma de cone
void criarCone(int habilidade[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            habilidade[i][j] = (j >= HSIZE / 2 - i && j <= HSIZE / 2 + i) ? 1 : 0;
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criarCruz(int habilidade[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            habilidade[i][j] = (i == HSIZE / 2 || j == HSIZE / 2) ? 1 : 0;
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int habilidade[HSIZE][HSIZE]) {
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            habilidade[i][j] = (abs(i - HSIZE / 2) + abs(j - HSIZE / 2) <= HSIZE / 2) ? 1 : 0;
        }
    }
}

// Imprime o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    ");
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf("%c ", c);
    }
    printf("\n");
    
    for (int i = 0; i < TAM; i++) {
        printf("%2d: ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[HSIZE][HSIZE], cruz[HSIZE][HSIZE], octaedro[HSIZE][HSIZE];
    
    iniciartab(tabuleiro);
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    aplicarHabilidade(tabuleiro, cone, 6, 3);
    aplicarHabilidade(tabuleiro, cruz, 4, 6);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);
    
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}
