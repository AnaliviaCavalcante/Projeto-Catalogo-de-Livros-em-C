#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Arquivo: Catalogo Biblioteca.c
 * Autores:
 *  Alexsandro Gonçalves.
 *  Amanda Cavalcante.
 *  Ana Livia Cavalcante.
 *  Emanuele Maldonato.
 * Data: 20/06/2025
 * Descrição: Programa para gerenciamento de um catálogo de livros, com funcionalidades para inserir, buscar, atualizar, remover e listar livros.
 *            Os dados são salvos em um arquivo CSV chamado "catalogo.csv".
 */

#define MAX_BOOKS 100       // Número máximo de livros no catálogo
#define MAX_STRING 100      // Tamanho máximo para strings (ISBN, título, autor, editora)
#define FILE_NAME "catalogo.csv"  // Nome do arquivo CSV para armazenamento dos dados

// Estrutura que representa um livro no catálogo
typedef struct {
    char isbn[MAX_STRING];
    char titulo[MAX_STRING];
    char autor[MAX_STRING];
    char editora[MAX_STRING];
    int ano;
    int exemplares;            
} Livro;

// Array global para armazenar o catálogo de livros
Livro catalogo[MAX_BOOKS];
// Contador global para o número total de livros no catálogo
int totalLivros = 0;

/*
 * Salva o catálogo de livros no arquivo CSV.
 * Abre o arquivo em modo escrita e grava cada livro como uma linha no formato: isbn,titulo,autor,editora,ano,exemplares
 */
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

/*
 * Carrega o catálogo de livros a partir do arquivo CSV.
 * Lê cada linha do arquivo e armazena os dados na estrutura Livro, incrementando totalLivros.
 */
void carregarCatalogo() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

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

/*
 * Insere um novo livro no catálogo.
 * Solicita os dados do livro (ISBN, título, autor, editora, ano, exemplares) e salva no arquivo.
 * @return: void (incrementa totalLivros e salva o catálogo se bem-sucedido)
 */
void inserirLivro() {
    if (totalLivros >= MAX_BOOKS) {
        printf("Catalogo cheio!\n");
        return;
    }
    printf("ISBN do livro: "); scanf("%s", catalogo[totalLivros].isbn);
    printf("Titulo: "); scanf(" %[^\n]", catalogo[totalLivros].titulo);
    printf("Autor: "); scanf(" %[^\n]", catalogo[totalLivros].autor);
    printf("Editora: "); scanf(" %[^\n]", catalogo[totalLivros].editora);
    printf("Ano de lancamento: "); scanf("%d", &catalogo[totalLivros].ano);
    printf("Exemplares disponiveis: "); scanf("%d", &catalogo[totalLivros].exemplares);
    totalLivros++;
    salvarCatalogo();
}

/*
 * Lista todos os livros do catálogo.
 * Exibe as informações de cada livro (ISBN, título, autor, editora, ano, exemplares).
 */
void listarLivros() {
    for (int i = 0; i < totalLivros; i++) {
        printf("ISBN do livro: %s\n"
               "Nome do livro: %s\n"
               "Autor: %s\n"
               "Editora: %s\n"
               "Ano lancamento: %d\n"
               "Exemplares disponiveis: %d\n\n",
               catalogo[i].isbn, catalogo[i].titulo,
               catalogo[i].autor, catalogo[i].editora, catalogo[i].ano, catalogo[i].exemplares);
    }
}

/*
 * Busca um livro no catálogo por ISBN ou título.
 * Exibe as informações do livro encontrado ou uma mensagem de erro se não encontrado.
 */
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

/*
 * Atualiza as informações de um livro no catálogo com base no ISBN.
 * Solicita novos dados para o livro e salva o catálogo atualizado.
 */
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

/*
 * Remove um livro do catálogo com base no ISBN.
 * Reorganiza o array de livros e salva o catálogo atualizado.
 */
void removerLivro() {
    char isbn[MAX_STRING];
    printf("Digite o ISBN do livro a remover: "); scanf("%s", isbn);
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].isbn, isbn) == 0) {
            // Desloca os livros subsequentes para preencher o espaço
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

/*
 * Função principal do programa.
 * Carrega o catálogo inicial e exibe um menu interativo para gerenciar livros.
 * @return: 0 ao finalizar o programa
 */
int main() {
    carregarCatalogo();

    int opcao;
    do {
        printf("**********MENU**********\n");
        printf("1. Inserir Livro\n2. Buscar Livro\n3. Atualizar Livro\n4. Remover Livro\n5. Listar Livros\n**********@@@@**********\nEscolha: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: inserirLivro(); break;
            case 2: buscarLivro(); break;
            case 3: atualizarLivro(); break;
            case 4: removerLivro(); break;
            case 5: listarLivros(); break;
            default: printf("Opcao invalida!\n"); break;
        }
    } while (opcao != 0);
    salvarCatalogo();
    return 0;
}