#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10


typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX];
int totalItens = 0;

void limparEnter(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

void mostrarMenu() {
    printf("\n");
    printf(" = = = = SISTEMA DE MOCHILA = = = =\n");

    printf("1 - Inserir item\n");
    printf("2 - Remover item\n");
    printf("3 - Listar mochila\n");
    printf("4 - Buscar item\n");
    printf("5 - Ordenar mochila \n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

void inserirItem() {
    if (totalItens >= MAX) {
        printf("=== Mochila cheia! ===\n");

        return;
    }
    printf("\nNome do item: ");
    fgets(mochila[totalItens].nome, 30, stdin);
    limparEnter(mochila[totalItens].nome);

    printf("Tipo do item: ");
    fgets(mochila[totalItens].tipo, 20, stdin);
    limparEnter(mochila[totalItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);
    getchar();

    totalItens++;
    printf(" === Item inserido com sucesso! ===\n");

}

void listarItens() {
    if (totalItens == 0) {
        printf("==== MOCHILA VAZIA ====\n");
        return;
    }

    printf("\n");

    printf("│ ID  -  Nome                         Tipo               Quant.   \n");
    for (int i = 0; i < totalItens; i++) {
        printf("│ %-2d │ %-28s │ %-18s │ %-8d │\n",
               i + 1,
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
    printf("Total de itens: %d\n", totalItens);
}

int buscarSequencial(char nome[], int *comparacoes) {
    *comparacoes = 0;

    for (int i = 0; i < totalItens; i++) {
        (*comparacoes)++;

        if (strcmp(mochila[i].nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

void removerItem() {
    char nome[30];
    int comparacoes;

    printf("\nDigite o nome do item a remover: ");
    fgets(nome, 30, stdin);
    limparEnter(nome);

    int pos = buscarSequencial(nome, &comparacoes);

    if (pos == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    for (int i = pos; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("=== Item removido com sucesso! ====\n");

}

void exibirBuscaSequencial() {
    char nome[30];
    int comparacoes;

    printf("\nDigite o nome do item: ");
    fgets(nome, 30, stdin);
    limparEnter(nome);

    int pos = buscarSequencial(nome, &comparacoes);

    if (pos == -1) {
        printf(" === Item não encontrado!  ===\n");
    } else {
        printf(" = = = ITEM ENCONTRADO = = =\n");;
        printf("Nome: %-30s\n", mochila[pos].nome);
        printf("Tipo: %-30s\n", mochila[pos].tipo);
        printf("Quantidade: %-24d\n", mochila[pos].quantidade);
    }

    printf("Comparações realizadas: %d\n", comparacoes);
}

void ordenarMochila() {
    Item temp;

    for (int i = 0; i < totalItens - 1; i++) {
        for (int j = 0; j < totalItens - i - 1; j++) {
            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\n==== Mochila ordenada por nome! ====\n");

}

int main() {
    int opcao;

    do {
        mostrarMenu();

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                exibirBuscaSequencial();
                break;

            case 5:
                ordenarMochila();
                break;


            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
