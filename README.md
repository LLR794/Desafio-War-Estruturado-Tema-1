# Desafio War Estruturado – Tema 1

## Sobre o Desafio

Este projeto é uma implementação em linguagem C dos mecanismos centrais do jogo de tabuleiro War, desenvolvido como parte de um desafio proposto pela empresa fictícia TechNova. O objetivo é criar uma versão do jogo com uma lógica sólida, escalável e eficiente, focando no controle de recursos computacionais e na aplicação de conceitos fundamentais de estrutura de dados.

O desenvolvimento foi dividido em três fases principais:
1.  **Estruturação de Dados:** Utilização de `structs` para modelar os territórios do jogo, armazenando informações como nome, proprietário (cor) e quantidade de tropas em um vetor.
2.  **Mecânica de Ataque:** Implementação da funcionalidade de batalha entre territórios, fazendo uso de ponteiros para modificar os dados diretamente na memória e simulando o combate com base em rolagens de dados.
3.  **Sistema de Missões e Vitória:** Criação de um sistema de missões estratégicas com alocação dinâmica de memória (`malloc`, `free`) para os objetivos de cada jogador. A verificação das condições de vitória é realizada a cada turno.

## Estrutura do Projeto

O código foi modularizado para garantir organização, manutenibilidade e escalabilidade, simulando um ambiente de desenvolvimento profissional. A estrutura de arquivos é a seguinte:

-   `main.c`: Ponto de entrada do programa. Contém o loop principal do jogo, gerencia as rodadas e a interação com o usuário.
-   `territorio.h` / `.c`: Define a `struct Territorio` e contém as funções para inicializar e exibir o mapa do jogo.
-   `batalha.h` / `.c`: Implementa a lógica de combate entre territórios, incluindo a simulação de dados.
-   `missao.h` / `.c`: Define as `structs` para `Jogador` e `Missao`. Gerencia a alocação dinâmica de missões, a atribuição de objetivos e a verificação das condições de vitória.
-   `README.md`: Este arquivo de documentação.

## Funcionalidades Implementadas

-   **Cadastro de Territórios:** O mapa do jogo é representado por um vetor de `struct Territorio`, contendo dados essenciais para a lógica do jogo.
-   **Mecânica de Batalha:** A função `simular_ataque` recebe ponteiros para os territórios atacante e defensor, permitindo a alteração direta de suas tropas e proprietários conforme o resultado do combate.
-   **Sistema de Missões Dinâmicas:** Cada jogador recebe uma `Missao` alocada dinamicamente no início do jogo. As missões podem ser de conquistar todos os territórios ou de eliminar um jogador específico.
-   **Verificação de Vitória:** Ao final de cada turno, o sistema verifica se o jogador atual cumpriu os requisitos de sua missão secreta.
-   **Gerenciamento de Memória:** O projeto utiliza `malloc` para alocar as missões e `free` para liberar a memória ao final do jogo, evitando vazamentos de memória (memory leaks).

## Como Compilar e Executar

Para compilar o projeto, você precisará de um compilador C, como o GCC. Abra o terminal na pasta raiz do projeto e execute o seguinte comando:

```bash
gcc main.c territorio.c batalha.c missao.c -o war_game
```

Após a compilação, um executável chamado `war_game` (ou `war_game.exe` no Windows) será criado. Para iniciar o jogo, execute-o:

```bash
./war_game
```

Siga as instruções no terminal para jogar, inserindo os IDs dos territórios para atacar ou `-1` para passar a vez.
