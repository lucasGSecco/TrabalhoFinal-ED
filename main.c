#include <stdio.h>

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
} Producao;

void incluirProducao() {
    printf("Função para incluir produção.\n");
}

void consultarProducao() {
    printf("Função para consultar uma produção.\n");
}

void alterarProducao() {
    printf("Função para alterar uma produção.\n");
}

void excluirProducao() {
    printf("Função para excluir uma produção.\n");
}

void listarProducoes() {
    printf("Função para listar todas as produções.\n");
}

int main() {
    int opcao;

    Producao *listaProducao; 

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
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    } while (opcao != 6);

    return 0;
}