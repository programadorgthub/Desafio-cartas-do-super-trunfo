#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} carta;

// Função para exibir informações da carta
void exibirCarta(carta c) {
    printf("Cidade: %s (%s)\n", c.nome_cidade, c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n\n", c.pontosTuristicos);
}

int main() {
    srand(time(NULL)); // Semente para números aleatórios

    // Definição das cartas (baralho)
    carta baralho[] = {
        {"São Paulo", "SP001", "São Paulo", 12300000, 1521.11, 2300000000000.0, 200},
        {"Rio de Janeiro", "RJ001", "Rio de Janeiro", 6700000, 1200.27, 410000000000.0, 150},
        {"Belo Horizonte", "MG001", "Belo Horizonte", 2520000, 331.40, 160000000000.0, 90},
        {"Salvador", "BA001", "Salvador", 2900000, 693.83, 120000000000.0, 120},
        {"Curitiba", "PR001", "Curitiba", 1950000, 435.04, 100000000000.0, 85}
    };

    int total_cartas = sizeof(baralho) / sizeof(baralho[0]);

    // Sorteia cartas para o jogador e para o computador
    int indice_jogador = rand() % total_cartas;
    int indice_computador = rand() % total_cartas;
    
    carta jogador = baralho[indice_jogador];
    carta computador = baralho[indice_computador];

    // Exibe a carta do jogador
    printf("Sua carta:\n");
    exibirCarta(jogador);

    // Jogador escolhe o atributo para comparar
    int opcao;
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - PIB\n");
    printf("3 - Pontos Turísticos\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Define valores com base na escolha do jogador
    float valor_jogador, valor_computador;
    char atributo[30];

    switch (opcao) {
        case 1:
            valor_jogador = jogador.populacao;
            valor_computador = computador.populacao;
            sprintf(atributo, "População");
            break;
        case 2:
            valor_jogador = jogador.pib;
            valor_computador = computador.pib;
            sprintf(atributo, "PIB");
            break;
        case 3:
            valor_jogador = jogador.pontosTuristicos;
            valor_computador = computador.pontosTuristicos;
            sprintf(atributo, "Pontos Turísticos");
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Exibe a carta do computador
    printf("\nCarta do Computador:\n");
    exibirCarta(computador);

    // Compara os valores e determina o vencedor
    printf("Comparação pelo atributo: %s\n", atributo);
    printf("Sua carta: %.2f\n", valor_jogador);
    printf("Carta do Computador: %.2f\n", valor_computador);

    if (valor_jogador > valor_computador) {
        printf("Parabéns! Você venceu!\n");
    } else if (valor_computador > valor_jogador) {
        printf("O Computador venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}

    