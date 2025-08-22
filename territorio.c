#include <stdio.h>
#include <string.h>
#include "territorio.h"

// Nomes de territórios para inicialização (exemplo com 10 territórios)
const char *NOMES_TERRITORIOS[] = {
    "Brasil", "Argentina", "Peru", "Venezuela", "Mexico",
    "California", "Texas", "Nova York", "Alasca", "Groenlandia"
};

// Cores dos jogadores
const char *CORES_JOGADORES[] = {"Azul", "Vermelho", "Verde"};
const int NUM_JOGADORES = 3;

// Função para inicializar o mapa do jogo com dados básicos
void inicializar_mapa(Territorio *mapa, int num_territorios) {
    printf("Inicializando o mapa de War...\n");
    for (int i = 0; i < num_territorios; i++) {
        strcpy(mapa[i].nome, NOMES_TERRITORIOS[i % 10]); // Usando módulo para ciclar nomes
        strcpy(mapa[i].cor_proprietario, CORES_JOGADORES[i % NUM_JOGADORES]); // Distribui territórios
        mapa[i].tropas = 5; // Todas as áreas começam com 5 tropas
    }
    printf("Mapa inicializado com sucesso!\n\n");
}

// Função para exibir o estado atual de todos os territórios
void exibir_mapa(const Territorio *mapa, int num_territorios) {
    printf("\n================== ESTADO ATUAL DO MAPA ==================\n");
    for (int i = 0; i < num_territorios; i++) {
        printf("ID: %2d | Territorio: %-12s | Proprietario: %-10s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor_proprietario, mapa[i].tropas);
    }
    printf("==========================================================\n\n");
}
