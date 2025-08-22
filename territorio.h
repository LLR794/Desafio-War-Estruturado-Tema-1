#ifndef TERRITORIO_H
#define TERRITORIO_H

// Estrutura para armazenar os dados de cada território
typedef struct {
    char nome[50];
    char cor_proprietario[20]; // Cor do jogador que domina o território
    int tropas;
} Territorio;

// Protótipo da função para inicializar o mapa do jogo
void inicializar_mapa(Territorio *mapa, int num_territorios);

// Protótipo da função para exibir o estado atual do mapa
void exibir_mapa(const Territorio *mapa, int num_territorios);

#endif // TERRITORIO_H
