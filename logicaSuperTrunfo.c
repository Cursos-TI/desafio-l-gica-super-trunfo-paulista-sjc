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

// Função para exibir o menu de atributos
void exibirMenu(int atributoJaEscolhido) {
    printf("\nEscolha o atributo para comparação:\n");
    if (atributoJaEscolhido != 1) printf("1 - População\n");
    if (atributoJaEscolhido != 2) printf("2 - Área\n");
    if (atributoJaEscolhido != 3) printf("3 - PIB\n");
    if (atributoJaEscolhido != 4) printf("4 - Pontos Turísticos\n");
    if (atributoJaEscolhido != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite o número da opção: ");
}

// Função que obtém o valor numérico de um atributo (para facilitar o cálculo)
float obterValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0.0;
    }
}

// Função para exibir o nome do atributo escolhido
const char* nomeDoAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB (trilhões de dólares)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica (hab/km²)";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1, carta2;
    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma_c1, soma_c2;

    // --- Cadastro fixo das cartas (mantido dos desafios anteriores) ---
    strcpy(carta1.nome, "Brasil");
    carta1.populacao = 214000000;
    carta1.area = 8515767.0;
    carta1.pib = 2.32; // trilhões
    carta1.pontosTuristicos = 15;
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    strcpy(carta2.nome, "Argentina");
    carta2.populacao = 45380000;
    carta2.area = 2780400.0;
    carta2.pib = 0.64; // trilhões
    carta2.pontosTuristicos = 10;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    printf("=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
    printf("Comparando: %s x %s\n", carta1.nome, carta2.nome);

    // --- Escolha do primeiro atributo ---
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Validação da primeira escolha
    while (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Escolha um número entre 1 e 5.\n");
        exibirMenu(0);
        scanf("%d", &atributo1);
    }

    // --- Escolha do segundo atributo (menu dinâmico) ---
    exibirMenu(atributo1);
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida! Escolha outro atributo.\n");
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
    }

    // --- Comparação e cálculo da soma ---
    valor1_c1 = obterValor(carta1, atributo1);
    valor1_c2 = obterValor(carta2, atributo1);
    valor2_c1 = obterValor(carta1, atributo2);
    valor2_c2 = obterValor(carta2, atributo2);

    // Regras de vitória (menor densidade vence)
    int vitoria1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    int vitoria2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    // Soma dos atributos (para o resultado final)
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributo 1: %s\n", nomeDoAtributo(atributo1));
    printf("  %s: %.2f | %s: %.2f -> %s venceu\n",
           carta1.nome, valor1_c1, carta2.nome, valor1_c2,
           vitoria1 ? carta1.nome : (valor1_c1 == valor1_c2 ? "Empate" : carta2.nome));

    printf("\nAtributo 2: %s\n", nomeDoAtributo(atributo2));
    printf("  %s: %.2f | %s: %.2f -> %s venceu\n",
           carta1.nome, valor2_c1, carta2.nome, valor2_c2,
           vitoria2 ? carta1.nome : (valor2_c1 == valor2_c2 ? "Empate" : carta2.nome));

    // Exibição da soma total
    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    printf("%s: %.2f\n", carta1.nome, soma_c1);
    printf("%s: %.2f\n", carta2.nome, soma_c2);

    // Resultado final com operador ternário
    printf("\n=== RESULTADO FINAL ===\n");
    (soma_c1 > soma_c2) ? 
        printf("🏆 %s venceu a rodada!\n", carta1.nome) :
        (soma_c1 < soma_c2) ? 
            printf("🏆 %s venceu a rodada!\n", carta2.nome) :
            printf("🤝 Empate!\n");

    return 0;
}
