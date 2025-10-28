#include <stdio.h>
#include <string.h>

// Estrutura de uma carta
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    struct Carta carta1, carta2;
    int opcao;

    // Cadastro das cartas (pode ser fixo neste nível)
    strcpy(carta1.nome, "Brasil");
    carta1.populacao = 214000000;
    carta1.area = 8515767.0;
    carta1.pib = 2.32; // em trilhões
    carta1.pontosTuristicos = 15;
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    strcpy(carta2.nome, "Argentina");
    carta2.populacao = 45380000;
    carta2.area = 2780400.0;
    carta2.pib = 0.64; // em trilhões
    carta2.pontosTuristicos = 10;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    // Exibe o menu de atributos
    printf("=== SUPER TRUNFO - COMPARADOR DE CARTAS ===\n");
    printf("Cartas disponíveis:\n");
    printf("1. %s\n", carta1.nome);
    printf("2. %s\n\n", carta2.nome);
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite o número da opção desejada: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");

    // Estrutura switch para seleção do atributo
    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.nome);
            else if (carta1.populacao < carta2.populacao)
                printf("Resultado: %s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área (km²)\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: %s venceu!\n", carta1.nome);
            else if (carta1.area < carta2.area)
                printf("Resultado: %s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB (trilhões de dólares)\n");
            printf("%s: %.2f\n", carta1.nome, carta1.pib);
            printf("%s: %.2f\n", carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.nome);
            else if (carta1.pib < carta2.pib)
                printf("Resultado: %s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta1.nome);
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade demográfica
            printf("Atributo: Densidade Demográfica (habitantes/km²)\n");
            printf("%s: %.2f\n", carta1.nome, carta1.densidadeDemografica);
            printf("%s: %.2f\n", carta2.nome, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                printf("Resultado: %s venceu (menor densidade)!\n", carta1.nome);
            else if (carta1.densidadeDemografica > carta2.densidadeDemografica)
                printf("Resultado: %s venceu (menor densidade)!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
    }

    return 0;
}
