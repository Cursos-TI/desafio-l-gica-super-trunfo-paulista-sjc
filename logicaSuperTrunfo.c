#include <stdio.h>

int main() {
    
    // ----------------------------------------------
    // Declaração das variáveis - Carta 1
    // ----------------------------------------------
    
    char estado1[3];               // Ex: "SP"
    char codigo1[4];               // Ex: "A01"
    char nomeCidade1[50];          // Nome da cidade
    int populacao1;                // População
    float area1;                   // Área em km²
    float pib1;                    // PIB em bilhões
    int pontosTuristicos1;         // Número de pontos turísticos
    float densidade1;              // Densidade populacional
    float pibPerCapita1;           // PIB per capita

    // ----------------------------------------------
    // Declaração das variáveis - Carta 2
    // ----------------------------------------------
    
    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;

    // ----------------------------------------------
    // Cadastro da primeira carta
    // ----------------------------------------------
   
    printf("Cadastro da primeira carta:\n");
    printf("Digite o estado (ex: SP): ");
    scanf("%s", estado1);
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1); // Lê com espaços
    printf("Digite a populacao: ");
    scanf("%d", &populacao1);
    printf("Digite a area (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da primeira carta
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // ----------------------------------------------
    // Cadastro da segunda carta
    // ----------------------------------------------
   
    printf("\nCadastro da segunda carta:\n");
    printf("Digite o estado (ex: RJ): ");
    scanf("%s", estado2);
    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a populacao: ");
    scanf("%d", &populacao2);
    printf("Digite a area (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da segunda carta
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // ----------------------------------------------
    // Comparação de um único atributo
    // (Neste exemplo, vamos comparar a POPULAÇÃO)
    // ----------------------------------------------
   
    printf("\n===== COMPARAÇÃO DE CARTAS =====\n");
    printf("Atributo: Populacao\n\n");

    printf("Carta 1 - %s (%s): %d habitantes\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n\n", nomeCidade2, estado2, populacao2);

    // Estrutura de decisão IF / ELSE
   
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } 
    else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } 
    else {
        printf("Resultado: Empate! Ambas as cidades têm a mesma população.\n");
    }

    // ----------------------------------------------
    // Exibição adicional (dados calculados)
    // ----------------------------------------------
   
    printf("\n===== DADOS CALCULADOS =====\n");
    printf("Carta 1 - %s:\n", nomeCidade1);
    printf(" - Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf(" - PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2 - %s:\n", nomeCidade2);
    printf(" - Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf(" - PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}
