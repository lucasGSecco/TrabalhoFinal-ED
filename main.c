#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs básicas
typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct fardo {
    char cultivar[20];
    char tipoDeFeno;
    int diametro;
} Fardo;

typedef struct producao {
    int codigo;
    Data dataProducao;
    Fardo tipoDeFardo;
    int qtDeFardos;
    int tempoEmMin;
    struct producao *prox;
} Producao;

Producao *inicio = NULL;

void incluirProducao() {
    Producao *nova = (Producao *) malloc(sizeof(Producao));
    if (nova == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    printf("Código da produção: ");
    scanf("%d", &nova->codigo);

    printf("Data (dd mm aaaa): ");
    scanf("%d %d %d", &nova->dataProducao.dia, &nova->dataProducao.mes, &nova->dataProducao.ano);

    printf("Cultivar: ");
    scanf(" %[^\n]", nova->tipoDeFardo.cultivar);

    printf("Tipo de feno (char): ");
    scanf(" %c", &nova->tipoDeFardo.tipoDeFeno);

    printf("Diâmetro: ");
    scanf("%d", &nova->tipoDeFardo.diametro);

    printf("Quantidade de fardos: ");
    scanf("%d", &nova->qtDeFardos);

    printf("Tempo em minutos: ");
    scanf("%d", &nova->tempoEmMin);

    nova->prox = inicio;
    inicio = nova;

    printf("Produção incluída com sucesso!\n");
}

void consultarProducao() {
    int codigo;
    printf("Digite o código da produção para consultar: ");
    scanf("%d", &codigo);

    Producao *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("\n--- Detalhes da Produção ---\n");
            printf("Código: %d\n", atual->codigo);
            printf("Data: %02d/%02d/%04d\n", atual->dataProducao.dia, atual->dataProducao.mes, atual->dataProducao.ano);
            printf("Cultivar: %s\n", atual->tipoDeFardo.cultivar);
            printf("Tipo de feno: %c\n", atual->tipoDeFardo.tipoDeFeno);
            printf("Diâmetro: %d\n", atual->tipoDeFardo.diametro);
            printf("Quantidade de fardos: %d\n", atual->qtDeFardos);
            printf("Tempo: %d minutos\n", atual->tempoEmMin);
            return;
        }
        atual = atual->prox;
    }

    printf("Produção com código %d não encontrada.\n", codigo);
}

void alterarProducao() {
    int codigo;
    printf("Digite o código da produção para alterar: ");
    scanf("%d", &codigo);

    Producao *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("Nova quantidade de fardos: ");
            scanf("%d", &atual->qtDeFardos);

            printf("Novo tempo (em minutos): ");
            scanf("%d", &atual->tempoEmMin);

            printf("Alteração realizada com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Produção com código %d não encontrada.\n", codigo);
}

void excluirProducao() {
    int codigo;
    printf("Digite o código da produção para excluir: ");
    scanf("%d", &codigo);

    Producao *atual = inicio;
    Producao *anterior = NULL;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            if (anterior == NULL) {
                inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Produção excluída com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Produção com código %d não encontrada.\n", codigo);
}

void listarProducoes() {
    if (inicio == NULL) {
        printf("Nenhuma produção cadastrada.\n");
        return;
    }

    printf("\n--- Lista de Produções ---\n");
    Producao *atual = inicio;
    while (atual != NULL) {
        printf("Código: %d | Data: %02d/%02d/%04d | Cultivar: %s | Fenos: %d\n",
            atual->codigo,
            atual->dataProducao.dia,
            atual->dataProducao.mes,
            atual->dataProducao.ano,
            atual->tipoDeFardo.cultivar,
            atual->qtDeFardos);
        atual = atual->prox;
    }
}

void liberarLista() {
    Producao *atual = inicio;
    while (atual != NULL) {
        Producao *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    int opcao;

    do {
        printf("\n========== MENU DE PRODUÇÃO ==========\n");
        printf("1. Incluir Produção\n");
        printf("2. Consultar\n");
        printf("3. Alterar\n");
        printf("4. Excluir\n");
        printf("5. Listar todos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProducao();
                break;
            case 2:
                consultarProducao();
                break;
            case 3:
                alterarProducao();
                break;
            case 4:
                excluirProducao();
                break;
            case 5:
                listarProducoes();
                break;
            case 6:
                liberarLista();
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}
