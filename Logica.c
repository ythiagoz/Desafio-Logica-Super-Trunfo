#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a estrutura para uma carta do jogo
typedef struct {
    char cidade[50];
    char pais[50];
    int populacao;
    float area_km2;
    float idh;
    int altitude_m;
} Carta;

// Protótipos das funções
void exibirMenuPrincipal();
void cadastrarCartas(Carta baralho[], int *numCartas);
void exibirTodasAsCartas(const Carta baralho[], int numCartas);
void compararCartas(const Carta baralho[], int numCartas);
const char* getNomeAtributo(int indice);
float getValorAtributo(Carta carta, int indice);
void limparBufferEntrada();

int main() {
    Carta baralho[10]; // Suporta até 10 cartas
    int numCartas = 0;
    int opcao;

    // Preenche o baralho com algumas cartas de exemplo
    cadastrarCartas(baralho, &numCartas);

    // Loop principal do menu dinâmico
    do {
        exibirMenuPrincipal();
        printf("Escolha uma opcao: ");
        
        // Validação da entrada do usuário
        while (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite um numero: ");
            limparBufferEntrada();
        }
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                exibirTodasAsCartas(baralho, numCartas);
                break;
            case 2:
                if (numCartas < 2) {
                    printf("\nE necessario ter pelo menos 2 cartas cadastradas para comparar.\n");
                } else {
                    compararCartas(baralho, numCartas);
                }
                break;
            case 3:
                printf("\nSaindo do jogo. Ate a proxima!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
        printf("\nPressione Enter para continuar...");
        getchar();
        // system("clear || cls"); // Descomente para limpar a tela (pode não funcionar em todos os ambientes)

    } while (opcao != 3);

    return 0;
}

/**
 * @brief Exibe o menu principal do jogo.
 */
void exibirMenuPrincipal() {
    printf("\n=====================================\n");
    printf("  SUPER TRUNFO - PAISES (NIVEL MESTRE)\n");
    printf("=====================================\n");
    printf("1. Visualizar todas as cartas\n");
    printf("2. Iniciar uma comparacao\n");
    printf("3. Sair do Jogo\n");
    printf("-------------------------------------\n");
}

/**
 * @brief Preenche o baralho com dados de exemplo.
 * @param baralho O array de cartas a ser preenchido.
 * @param numCartas Ponteiro para o número total de cartas.
 */
void cadastrarCartas(Carta baralho[], int *numCartas) {
    strcpy(baralho[0].cidade, "Sao Paulo");
    strcpy(baralho[0].pais, "Brasil");
    baralho[0].populacao = 12300000;
    baralho[0].area_km2 = 1521.0f;
    baralho[0].idh = 0.805f;
    baralho[0].altitude_m = 760;

    strcpy(baralho[1].cidade, "Toquio");
    strcpy(baralho[1].pais, "Japao");
    baralho[1].populacao = 13900000;
    baralho[1].area_km2 = 2194.0f;
    baralho[1].idh = 0.915f;
    baralho[1].altitude_m = 40;

    strcpy(baralho[2].cidade, "Cidade do Mexico");
    strcpy(baralho[2].pais, "Mexico");
    baralho[2].populacao = 9200000;
    baralho[2].area_km2 = 1485.0f;
    baralho[2].idh = 0.779f;
    baralho[2].altitude_m = 2240;

    strcpy(baralho[3].cidade, "Nova Iorque");
    strcpy(baralho[3].pais, "EUA");
    baralho[3].populacao = 8400000;
    baralho[3].area_km2 = 783.8f;
    baralho[3].idh = 0.920f;
    baralho[3].altitude_m = 10;

    strcpy(baralho[4].cidade, "Londres");
    strcpy(baralho[4].pais, "Reino Unido");
    baralho[4].populacao = 9000000;
    baralho[4].area_km2 = 1572.0f;
    baralho[4].idh = 0.929f;
    baralho[4].altitude_m = 11;

    strcpy(baralho[5].cidade, "Cairo");
    strcpy(baralho[5].pais, "Egito");
    baralho[5].populacao = 9500000;
    baralho[5].area_km2 = 3085.0f;
    baralho[5].idh = 0.707f;
    baralho[5].altitude_m = 23;

    strcpy(baralho[6].cidade, "Sydney");
    strcpy(baralho[6].pais, "Australia");
    baralho[6].populacao = 5300000;
    baralho[6].area_km2 = 12368.0f;
    baralho[6].idh = 0.944f;
    baralho[6].altitude_m = 3;

    *numCartas = 7; // Atualiza o número total de cartas
}

/**
 * @brief Exibe todas as cartas disponíveis no baralho.
 * @param baralho O array de cartas.
 * @param numCartas O número de cartas no baralho.
 */
void exibirTodasAsCartas(const Carta baralho[], int numCartas) {
    printf("\n--- CARTAS DISPONIVEIS ---\n");
    for (int i = 0; i < numCartas; i++) {
        printf("\n[%d] %s, %s\n", i + 1, baralho[i].cidade, baralho[i].pais);
        printf("    Populacao: %d\n", baralho[i].populacao);
        printf("    Area (km2): %.2f\n", baralho[i].area_km2);
        printf("    IDH: %.3f\n", baralho[i].idh);
        printf("    Altitude (m): %d\n", baralho[i].altitude_m);
    }
}

/**
 * @brief Lida com a lógica de comparação de duas cartas com base em dois atributos.
 * @param baralho O array de cartas.
 * @param numCartas O número de cartas no baralho.
 */
void compararCartas(const Carta baralho[], int numCartas) {
    int id_carta1, id_carta2, atr1, atr2;

    // Escolha da primeira carta
    printf("\nEscolha a primeira carta para a batalha (1 a %d): ", numCartas);
    while (scanf("%d", &id_carta1) != 1 || id_carta1 < 1 || id_carta1 > numCartas) {
        printf("Escolha invalida. Digite um numero entre 1 e %d: ", numCartas);
        limparBufferEntrada();
    }
    id_carta1--; // Ajusta para o índice do array (0 a N-1)

    // Escolha da segunda carta
    printf("Escolha a segunda carta para a batalha (1 a %d): ", numCartas);
    while (scanf("%d", &id_carta2) != 1 || id_carta2 < 1 || id_carta2 > numCartas || id_carta2 == id_carta1 + 1) {
        if (id_carta2 == id_carta1 + 1) {
            printf("Voce nao pode escolher a mesma carta. Tente novamente: ");
        } else {
            printf("Escolha invalida. Digite um numero entre 1 e %d: ", numCartas);
        }
        limparBufferEntrada();
    }
    id_carta2--; // Ajusta para o índice do array

    // Escolha dos atributos
    printf("\n--- Escolha os atributos para comparar ---\n");
    printf("1. Populacao\n2. Area\n3. IDH\n4. Altitude\n");
    
    printf("\nEscolha o PRIMEIRO atributo (1-4): ");
    while (scanf("%d", &atr1) != 1 || atr1 < 1 || atr1 > 4) {
        printf("Escolha invalida. Digite um numero entre 1 e 4: ");
        limparBufferEntrada();
    }

    printf("Escolha o SEGUNDO atributo (1-4, diferente do primeiro): ");
    while (scanf("%d", &atr2) != 1 || atr2 < 1 || atr2 > 4 || atr2 == atr1) {
        if (atr2 == atr1) {
            printf("Voce deve escolher um atributo diferente do primeiro. Tente novamente: ");
        } else {
            printf("Escolha invalida. Digite um numero entre 1 e 4: ");
        }
        limparBufferEntrada();
    }
    
    Carta carta1 = baralho[id_carta1];
    Carta carta2 = baralho[id_carta2];
    
    // Pega os valores dos atributos
    float val1_atr1 = getValorAtributo(carta1, atr1);
    float val2_atr1 = getValorAtributo(carta2, atr1);
    float val1_atr2 = getValorAtributo(carta1, atr2);
    float val2_atr2 = getValorAtributo(carta2, atr2);

    int pontos_carta1 = 0;
    int pontos_carta2 = 0;

    printf("\n---------- BATALHA ----------\n");
    printf("Cartas: %s vs %s\n", carta1.cidade, carta2.cidade);
    
    // Comparação do primeiro atributo usando operador ternário
    printf("\n1. Atributo: %s\n", getNomeAtributo(atr1));
    printf("   %s: %.2f\n", carta1.cidade, val1_atr1);
    printf("   %s: %.2f\n", carta2.cidade, val2_atr1);
    
    (val1_atr1 > val2_atr1) ? pontos_carta1++ : (val2_atr1 > val1_atr1) ? pontos_carta2++ : 0;
    printf("   Vencedor do atributo: %s\n", (val1_atr1 > val2_atr1) ? carta1.cidade : (val2_atr1 > val1_atr1) ? carta2.cidade : "Empate");

    // Comparação do segundo atributo usando operador ternário
    printf("\n2. Atributo: %s\n", getNomeAtributo(atr2));
    printf("   %s: %.2f\n", carta1.cidade, val1_atr2);
    printf("   %s: %.2f\n", carta2.cidade, val2_atr2);

    (val1_atr2 > val2_atr2) ? pontos_carta1++ : (val2_atr2 > val1_atr2) ? pontos_carta2++ : 0;
    printf("   Vencedor do atributo: %s\n", (val1_atr2 > val2_atr2) ? carta1.cidade : (val2_atr2 > val1_atr2) ? carta2.cidade : "Empate");
    
    // Lógica de decisão aninhada/encadeada para o resultado final
    printf("\n----------- PLACAR -----------\n");
    printf("Pontos %s: %d\n", carta1.cidade, pontos_carta1);
    printf("Pontos %s: %d\n", carta2.cidade, pontos_carta2);
    printf("------------------------------\n");
    
    if (pontos_carta1 > pontos_carta2) {
        printf("VENCEDOR FINAL: %s!\n", carta1.cidade);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("VENCEDOR FINAL: %s!\n", carta2.cidade);
    } else {
        printf("RESULTADO FINAL: EMPATE!\n");
    }
}


/**
 * @brief Retorna o nome de um atributo com base em seu índice.
 * @param indice O índice numérico do atributo.
 * @return const char* O nome do atributo.
 */
const char* getNomeAtributo(int indice) {
    switch(indice) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "IDH";
        case 4: return "Altitude";
        default: return "Desconhecido";
    }
}

/**
 * @brief Retorna o valor de um atributo específico de uma carta.
 * @param carta A carta da qual se quer o valor.
 * @param indice O índice numérico do atributo.
 * @return float O valor do atributo.
 */
float getValorAtributo(Carta carta, int indice) {
    switch(indice) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area_km2;
        case 3: return carta.idh;
        case 4: return (float)carta.altitude_m;
        default: return 0.0f;
    }
}

/**
 * @brief Limpa o buffer de entrada do teclado para evitar loops infinitos com scanf.
 */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
