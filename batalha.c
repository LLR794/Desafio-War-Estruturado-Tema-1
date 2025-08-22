#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "batalha.h"

// Função auxiliar para simular o lançamento de um dado
int rolar_dado() {
    return (rand() % 6) + 1;
}

// Função que implementa a lógica de ataque entre dois territórios
void simular_ataque(Territorio *atacante, Territorio *defensor) {
    if (atacante->tropas <= 1) {
        printf("Ataque invalido! O territorio de ataque deve ter mais de 1 tropa.\n");
        return;
    }

    printf("\n--- INICIO DA BATALHA ---\n");
    printf("%s (%d tropas) ataca %s (%d tropas)\n",
           atacante->nome, atacante->tropas, defensor->nome, defensor->tropas);

    // Simulação simples: um dado para cada lado
    int dado_ataque = rolar_dado();
    int dado_defesa = rolar_dado();

    printf("Dado de Ataque: %d\n", dado_ataque);
    printf("Dado de Defesa: %d\n", dado_defesa);

    if (dado_ataque > dado_defesa) {
        printf("VITORIA DO ATACANTE! O defensor perdeu 1 tropa.\n");
        defensor->tropas--;
    } else {
        printf("VITORIA DO DEFENSOR! O atacante perdeu 1 tropa.\n");
        atacante->tropas--;
    }

    // Verifica se o território foi conquistado
    if (defensor->tropas == 0) {
        printf("\nTERRITORIO %s CONQUISTADO POR %s!\n", defensor->nome, atacante->cor_proprietario);
        strcpy(defensor->cor_proprietario, atacante->cor_proprietario);

        // Move uma tropa para o novo território
        defensor->tropas = 1;
        atacante->tropas--;
    }
     printf("--- FIM DA BATALHA ---\n\n");
}
