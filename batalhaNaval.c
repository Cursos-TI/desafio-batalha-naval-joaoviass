#include <stdio.h>
#define TAM 10

// Função para inicializar e imprimir o tabuleiro
void iniciartab(int tabuleiro[TAM][TAM]) {
    // Imprime os caracteres do alfabeto acima das colunas
    printf("    "); // Espaço para alinhar com os números da linha
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf("%c ", c);
    }
    printf("\n");

    // Inicializa o tabuleiro com zeros
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona um navio (número 3) de 3 espaços fixos
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Imprime o tabuleiro
    for (int i = 0; i < TAM; i++) {
        printf("%2d: ", i + 1); // Número da linha com alinhamento (começando de 1)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM]; // Declara o tabuleiro
    iniciartab(tabuleiro);   // Chama a função para inicializar e imprimir o tabuleiro

    return 0;
}

