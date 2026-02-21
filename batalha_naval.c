#include <stdio.h>

int main() {

    // ==========================================
    // 1️⃣ DECLARAÇÃO DO TABULEIRO 10x10
    // ==========================================
    // A matriz representa o mar.
    // 0 = água
    // 3 = parte do navio

    int tabuleiro[10][10];

    // ==========================================
    // 2️⃣ INICIALIZAR TABULEIRO COM 0 (ÁGUA)
    // ==========================================
    // Usamos dois loops aninhados:
    // Um percorre as linhas
    // Outro percorre as colunas

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // ==========================================
    // 3️⃣ CRIAÇÃO DOS NAVIOS (TAMANHO FIXO = 3)
    // ==========================================

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // ==========================================
    // 4️⃣ DEFININDO COORDENADAS INICIAIS
    // ==========================================
    // Navio Horizontal começa na linha 2, coluna 4
    // Navio Vertical começa na linha 5, coluna 1

    int linhaH = 2;
    int colunaH = 4;

    int linhaV = 5;
    int colunaV = 1;

    // ==========================================
    // 5️⃣ VALIDAÇÃO SIMPLES (LIMITES DO TABULEIRO)
    // ==========================================
    // Verificamos se o navio cabe dentro da matriz

    if (colunaH + 3 <= 10) {  // Horizontal ocupa colunas
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa o limite!\n");
    }

    if (linhaV + 3 <= 10) {   // Vertical ocupa linhas
        for (int i = 0; i < 3; i++) {

            // Verificação simples de sobreposição
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            } else {
                printf("Erro: Sobreposicao detectada no navio vertical!\n");
            }
        }
    } else {
        printf("Erro: Navio vertical ultrapassa o limite!\n");
    }

    // ==========================================
    // 6️⃣ EXIBINDO O TABULEIRO
    // ==========================================
    // Vamos imprimir linha por linha

    printf("\n===== TABULEIRO =====\n\n");

    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n"); // quebra de linha ao final de cada linha
    }

    return 0;
}