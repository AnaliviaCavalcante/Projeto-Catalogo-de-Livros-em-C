#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_BOOKS 100
#define MAX_STRING 100
#define FILE_NAME "catalogo.csv"


typedef struct {
    char isbn[MAX_STRING];
    char titulo[MAX_STRING];
    char autor[MAX_STRING];
    char editora[MAX_STRING];
    int ano;
    int exemplares;
} Livro;


Livro catalogo[MAX_BOOKS];
int totalLivros = 0;


void salvarCatalogo() {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < totalLivros; i++) {
        fprintf(file, "%s,%s,%s,%s,%d,%d\n", catalogo[i].isbn, catalogo[i].titulo, catalogo[i].autor,
                catalogo[i].editora, catalogo[i].ano, catalogo[i].exemplares);
    }
    fclose(file);
}
      // CARREGAR CATALOGO
void carregarCatalogo() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

     // CARREGA OS LIVROS ANTERIORMENTE A PARTIR DE UM ARQUIVO DE TEXTO
    while (fscanf(file, "%99[^,],%99[^,],%99[^,],%99[^,],%d,%d\n",
                  catalogo[totalLivros].isbn,
                  catalogo[totalLivros].titulo,
                  catalogo[totalLivros].autor,
                  catalogo[totalLivros].editora,
                  &catalogo[totalLivros].ano,
                  &catalogo[totalLivros].exemplares) == 6) {
        totalLivros++;
    }
    fclose(file);
}

    // INSERIR LIVRO
void inserirLivro() {
    if (totalLivros >= MAX_BOOKS) {
        printf("Catalogo cheio!\n");
        return;
    }
    //  ADICIONAR UM NOVO LIVRO AO SISTEMA E SALVAR ESSE NOVO ESTADO
    printf("ISBN do livro:"); scanf("%s", catalogo[totalLivros].isbn);
    printf("Titulo: "); scanf(" %[^\n]", catalogo[totalLivros].titulo);
    printf("Autor: "); scanf(" %[^\n]", catalogo[totalLivros].autor);
    printf("Editora: "); scanf(" %[^\n]", catalogo[totalLivros].editora);
    printf("Ano de lancamento: "); scanf("%d", &catalogo[totalLivros].ano);
    printf("Exemplares disponiveis: "); scanf("%d", &catalogo[totalLivros].exemplares);
    totalLivros++;
    salvarCatalogo();
}

// LISTAR LIVROS
void listarLivros() {
    for (int i = 0; i < totalLivros; i++) {
        printf("ISBN do livro: %s\n "
               "Nome do livro: %s\n "
               "Autor: %s\n "
               "Editora: %s\n "
               "Ano lancamento: %d\n "
               "Exemplares disponiveis: %d\n"
               "\n"
               "", catalogo[i].isbn, catalogo[i].titulo,
               catalogo[i].autor, catalogo[i].editora, catalogo[i].ano, catalogo[i].exemplares);
    }
}

// BUSCAR LIVRO
void buscarLivro() {
    char busca[MAX_STRING];
    printf("Digite o ISBN ou titulo: "); scanf(" %[^\n]", busca);
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].isbn, busca) == 0 || strcmp(catalogo[i].titulo, busca) == 0) {
            printf("Livro encontrado: %s - %s, %s, %s, %d, %d exemplares\n", catalogo[i].isbn, catalogo[i].titulo,
                   catalogo[i].autor, catalogo[i].editora, catalogo[i].ano, catalogo[i].exemplares);
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

// ATUALIZAR LIVRO
void atualizarLivro() {
    char isbn[MAX_STRING];
    printf("Digite o ISBN do livro a atualizar: "); scanf("%s", isbn);
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].isbn, isbn) == 0) {
            printf("Novo titulo: "); scanf(" %[^\n]", catalogo[i].titulo);
            printf("Novo autor: "); scanf(" %[^\n]", catalogo[i].autor);
            printf("Nova editora: "); scanf(" %[^\n]", catalogo[i].editora);
            printf("Novo ano: "); scanf("%d", &catalogo[i].ano);
            printf("Novos exemplares disponiveis: "); scanf("%d", &catalogo[i].exemplares);
            salvarCatalogo();
            printf("Livro atualizado com sucesso!\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

// REMOVER LIVRO
void removerLivro() {
    char isbn[MAX_STRING];
    printf("Digite o ISBN do livro a remover: "); scanf("%s", isbn);
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].isbn, isbn) == 0) {
            for (int j = i; j < totalLivros - 1; j++) {
                catalogo[j] = catalogo[j + 1];
            }
            totalLivros--;
            salvarCatalogo();
            printf("Livro removido com sucesso!\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}


int main() {
    carregarCatalogo();

    int opcao;
    do {
        printf("**********MENU**********");
        printf("\n1. Inserir Livro\n2. Buscar Livro\n3. Atualizar Livro\n4. Remover Livro\n5. Listar Livros\n**********@@@@********** \n Escolha:\n ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: inserirLivro(); break;
            case 2: buscarLivro(); break;
            case 3: atualizarLivro(); break;
            case 4: removerLivro(); break;
            case 5: listarLivros(); break;
            default:printf("opcao invalida!\n"); break;
        }
    } while (opcao != 0);
    salvarCatalogo();
        return 0;
    }
