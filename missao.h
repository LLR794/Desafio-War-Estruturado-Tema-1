#ifndef MISSAO_H
#define MISSAO_H

#include "territorio.h"

// Enum para os tipos de missão
typedef enum {
    CONQUISTAR_TOTALMENTE,
    DESTRUIR_JOGADOR
} TipoMissao;


// Estrutura da Missão (usará alocação dinâmica)
typedef struct {
    char descricao[150];
    TipoMissao tipo;
    char alvo[20]; // Pode ser uma cor de jogador a ser destruído
} Missao;

// Estrutura para o Jogador
typedef struct {
    char cor[20];
    Missao *missao_secreta; // Ponteiro para a missão alocada dinamicamente
} Jogador;

// Protótipos
Jogador* inicializar_jogadores(int num_jogadores);
void atribuir_missoes(Jogador *jogadores, int num_jogadores);
int verificar_vitoria(Jogador *jogador_atual, Territorio *mapa, int num_territorios, Jogador *jogadores, int num_jogadores);
void liberar_memoria_jogadores(Jogador *jogadores, int num_jogadores);


#endif // MISSAO_H
