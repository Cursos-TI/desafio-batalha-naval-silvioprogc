#include <stdio.h>

#define TAM 10
#define TAMANHO_NAVIO 3

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Função auxiliar para verificar se pode posicionar o navio
    int podePosicionar(int tab[TAM][TAM], int l, int c, int dir, int diag) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int li = l + (diag ? i : (dir == 1 ? i : 0));
            int co = c + (diag ? i : (dir == 0 ? i : 0));

            if (li >= TAM || co >= TAM || tab[li][co] != 0) return 0;
        }
        return 1;
    }

   void posicionar(int tab[TAM][TAM], int l, int c, int dir, int diag) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int li = l + (diag ? i : (dir == 1 ? i : 0));
            int co = c + (diag ? i : (dir == 0 ? i : 0));
            tab[li][co] = 3;
        }
    }

    // --- Navios ---

    // Navio horizontal
    int lh1 = 2, ch1 = 4;
    if (podePosicionar(tabuleiro, lh1, ch1, 0, 0))
        posicionar(tabuleiro, lh1, ch1, 0, 0);

    // Navio vertical
    int lv1 = 5, cv1 = 2;
    if (podePosicionar(tabuleiro, lv1, cv1, 1, 0))
        posicionar(tabuleiro, lv1, cv1, 1, 0);

    // Navio diagonal principal
    int ld1 = 0, cd1 = 1;
    if (podePosicionar(tabuleiro, ld1, cd1, 0, 1))
        posicionar(tabuleiro, ld1, cd1, 0, 1);

    // Navio diagonal 
    int ld2 = 6, cd2 = 9;
    int pode = 1;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int li = ld2 + i;
        int co = cd2 - i;
        if (li >= TAM || co < 0 || tabuleiro[li][co] != 0) {
            pode = 0;
            break;
        }
    }
    if (pode) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            int li = ld2 + i;
            int co = cd2 - i;
            tabuleiro[li][co] = 3;
        }
    }

    // Exibir o tabuleiro
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c: ", linha[i]);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}