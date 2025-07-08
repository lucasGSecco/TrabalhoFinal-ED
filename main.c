#include <stdio.h>

typedef struct data{
   int dia;
   int mes;
   int ano;
} Data;

typedef struct fardo{
   char cultivar[20];
   char tipoDeFeno;
   int diametro;
} Fardo;

typedef struct producao{
   int codigo;
   Data dataProducao;
   Fardo tipoDeFardo;  
   int qtDeFardos;
   int tempoEmMin;
} Producao;

int main(){

    printf("\n========== MENU DE PRODUÇÃO ==========\n");
        printf("1. Incluir Produção\n");
        printf("2. Consultar\n");
        printf("3. Alterar\n");
        printf("4. Excluir\n");
        printf("5. Listar todos\n");
        printf("6. Sair\n");

    return 0;
}