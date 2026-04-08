#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10


// Struct do Item
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Variáveis globais
struct Item mochila[MAX];
int totalItens = 0;

// Função para inserir item
void inserirItem() {
    if (totalItens >= MAX) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nNome: ");
    fgets(mochila[totalItens].nome, 30, stdin);
    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

    printf("Tipo: ");
    fgets(mochila[totalItens].tipo, 20, stdin);
    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);
    getchar();

    totalItens++;

    printf("\nItem cadastrado com sucesso!\n");
}

// Função para listar itens
void listarItens() {
    if (totalItens == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n=== INVENTÁRIO ===\n");
    for (int i = 0; i < totalItens; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// Busca sequencial
int buscarItem(char nome[]) {
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Remover item
void removerItem() {
    char nome[30];

    printf("\nDigite o nome do item a remover: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int pos = buscarItem(nome);

    if (pos == -1) {
        printf("\nItem não encontrado!\n");
        return;
    }

    // desloca os elementos
    for (int i = pos; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;

    printf("\nItem removido com sucesso!\n");
}

// Buscar e mostrar item
void exibirBusca() {
    char nome[30];

    printf("\nDigite o nome do item: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int pos = buscarItem(nome);

    if (pos == -1) {
        printf("\nItem não encontrado!\n");
    } else {
        printf("\n=== ITEM ENCONTRADO ===\n");
        printf("Nome: %s\n", mochila[pos].nome);
        printf("Tipo: %s\n", mochila[pos].tipo);
        printf("Quantidade: %d\n", mochila[pos].quantidade);
    }
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n==== SISTEMA DE INVENTÁRIO ====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                exibirBusca();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
