#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "territorio.h"
#include "batalha.h"
#include "missao.h"

#define NUM_TERRITORIOS 10
#define NUM_JOGADORES 3

int main() {
    // Semente para geração de números aleatórios
    srand(time(NULL));

    // --- FASE 1: Cadastro e Estrutura de Dados ---
    Territorio mapa[NUM_TERRITORIOS];
    inicializar_mapa(mapa, NUM_TERRITORIOS);

    // --- FASE 3: Sistema de Missões (inicialização) ---
    Jogador *jogadores = inicializar_jogadores(NUM_JOGADORES);
    atribuir_missoes(jogadores, NUM_JOGADORES);

    int jogador_atual_idx = 0;
    int jogo_ativo = 1;
    int rodada = 1;

    // Loop principal do jogo
    while (jogo_ativo) {
        printf("\n<<<<<<<<<<<<<<<<<<<< RODADA %d - VEZ DO JOGADOR %s >>>>>>>>>>>>>>>>>>>>\n", rodada, jogadores[jogador_atual_idx].cor);
        exibir_mapa(mapa, NUM_TERRITORIOS);

        Jogador *jogador_da_vez = &jogadores[jogador_atual_idx];
        printf("Sua missao: %s\n", jogador_da_vez->missao_secreta->descricao);


        // --- FASE 2: Funcionalidade de Ataque ---
        int id_atacante, id_defensor;
        printf("Digite o ID do territorio de ataque (-1 para passar a vez): ");
        scanf("%d", &id_atacante);

        if (id_atacante == -1) {
            printf("Jogador %s passou a vez.\n", jogador_da_vez->cor);
        } else {
            printf("Digite o ID do territorio de defesa: ");
            scanf("%d", &id_defensor);

            // Validações básicas
            if (id_atacante < 0 || id_atacante >= NUM_TERRITORIOS ||
                id_defensor < 0 || id_defensor >= NUM_TERRITORIOS) {
                printf("IDs invalidos!\n");
            } else if (strcmp(mapa[id_atacante].cor_proprietario, jogador_da_vez->cor) != 0) {
                printf("Ataque invalido! Voce nao e o proprietario do territorio de ataque.\n");
            } else if (strcmp(mapa[id_defensor].cor_proprietario, jogador_da_vez->cor) == 0) {
                printf("Ataque invalido! Voce nao pode atacar seu proprio territorio.\n");
            } else {
                // Ponteiros para os territórios são passados para a função
                simular_ataque(&mapa[id_atacante], &mapa[id_defensor]);
            }
        }

        // --- FASE 3: Verificação de Vitória ---
        if (verificar_vitoria(jogador_da_vez, mapa, NUM_TERRITORIOS, jogadores, NUM_JOGADORES)) {
            printf("\n\n############################################################\n");
            printf("VITORIA!!! O JOGADOR %s COMPLETOU SUA MISSAO!\n", jogador_da_vez->cor);
            printf("############################################################\n");
            jogo_ativo = 0; // Termina o jogo
        }

        // Passa para o próximo jogador
        jogador_atual_idx = (jogador_atual_idx + 1) % NUM_JOGADORES;
        if (jogador_atual_idx == 0) {
            rodada++; // Incrementa a rodada quando voltar ao primeiro jogador
        }
    }

    // --- Limpeza da Memória ---
    liberar_memoria_jogadores(jogadores, NUM_JOGADORES);

    return 0;
}
