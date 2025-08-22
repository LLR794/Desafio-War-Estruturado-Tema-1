#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missao.h"

extern const char *CORES_JOGADORES[]; // Acessa a variável global de territorio.c

// Inicializa o vetor de jogadores
Jogador* inicializar_jogadores(int num_jogadores) {
    Jogador *jogadores = (Jogador*) malloc(num_jogadores * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocacao de memoria para jogadores.\n");
        exit(1);
    }

    for (int i = 0; i < num_jogadores; i++) {
        strcpy(jogadores[i].cor, CORES_JOGADORES[i]);
        jogadores[i].missao_secreta = NULL; // Importante inicializar com NULL
    }
    return jogadores;
}

// Aloca e atribui missões aleatórias aos jogadores
void atribuir_missoes(Jogador *jogadores, int num_jogadores) {
    for (int i = 0; i < num_jogadores; i++) {
        // Alocação dinâmica para a missão
        jogadores[i].missao_secreta = (Missao*) malloc(sizeof(Missao));
        if (jogadores[i].missao_secreta == NULL) {
            printf("Erro de alocacao de memoria para missao.\n");
            exit(1);
        }

        // Lógica simples de atribuição de missão
        if (i % 2 == 0) {
            jogadores[i].missao_secreta->tipo = CONQUISTAR_TOTALMENTE;
            strcpy(jogadores[i].missao_secreta->alvo, ""); // Sem alvo específico
            sprintf(jogadores[i].missao_secreta->descricao, "Conquistar todos os 10 territorios.");
        } else {
            jogadores[i].missao_secreta->tipo = DESTRUIR_JOGADOR;
            // Destruir o próximo jogador na lista (de forma circular)
            strcpy(jogadores[i].missao_secreta->alvo, jogadores[(i + 1) % num_jogadores].cor);
            sprintf(jogadores[i].missao_secreta->descricao, "Destruir todas as tropas do jogador %s.", jogadores[i].missao_secreta->alvo);
        }
         printf("Jogador %s recebeu a missao: %s\n", jogadores[i].cor, jogadores[i].missao_secreta->descricao);
    }
    printf("\n");
}

// Verifica se a condição de vitória de um jogador foi atingida
int verificar_vitoria(Jogador *jogador_atual, Territorio *mapa, int num_territorios, Jogador *jogadores, int num_jogadores) {
    Missao *missao = jogador_atual->missao_secreta;
    int territorios_do_jogador = 0;
    int tropas_do_alvo = 0;
    int territorios_do_alvo = 0;


    switch (missao->tipo) {
        case CONQUISTAR_TOTALMENTE:
            for (int i = 0; i < num_territorios; i++) {
                if (strcmp(mapa[i].cor_proprietario, jogador_atual->cor) == 0) {
                    territorios_do_jogador++;
                }
            }
            return territorios_do_jogador == num_territorios;

        case DESTRUIR_JOGADOR:
             for (int i = 0; i < num_territorios; i++) {
                if (strcmp(mapa[i].cor_proprietario, missao->alvo) == 0) {
                    territorios_do_alvo++;
                }
            }
            return territorios_do_alvo == 0;

        default:
            return 0;
    }
}

// Libera a memória alocada para as missões e para os jogadores
void liberar_memoria_jogadores(Jogador *jogadores, int num_jogadores) {
    for (int i = 0; i < num_jogadores; i++) {
        if (jogadores[i].missao_secreta != NULL) {
            free(jogadores[i].missao_secreta); // Libera cada missão
        }
    }
    free(jogadores); // Libera o vetor de jogadores
    printf("\nMemoria dos jogadores e missoes liberada com sucesso.\n");
}
