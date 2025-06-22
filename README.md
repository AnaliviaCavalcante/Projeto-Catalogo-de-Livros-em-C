##  Catálogo de Livros 

Este é um projeto desenvolvido para a disciplina de **Linguagem de Programação** da **Fatec Arthur de Azevedo - Mogi Mirim**, sob a orientação do **Prof. Me. Marcos Roberto de Moraes**. O objetivo principal é aplicar conceitos de **estruturas de dados**, **manipulação de arquivos** e práticas de **desenvolvimento de software em C**.

O sistema implementa um gerenciamento simples de catálogo de livros, permitindo o controle de informações como ISBN, título, autor, editora, ano de publicação e número de exemplares disponíveis, similar a um catálogo de biblioteca.

##  Funcionalidades

* **Adicionar Livro**: Permite a inserir um novo livro no catálogo, registrando seu ISBN, título, autor, editora, ano de lançamento e o número de exemplares disponíveis no momento. 
* **Listar Livros**: Exibe uma lista completa de todos os livros atualmente registrados no catálogo e todos seus detalhes. 
* **Buscar Livro**: Encontra livros no catálogo pelo ISBN ou título.
* **Atualizar Livro**: Modificar os detalhes de um livro ja registrado, localizando pelo ISBN.
* **Remover Livro**: Excluir um livro do catálogo, identificado pelo seu ISBN.
* **Persistência de Dados**: O catálogo é automaticamente salvo em um arquivo `catalogo.csv` e carregado a partir dele, garantindo que os dados não sejam perdidos entre as execuções do programa.

## Exemplo de Livros no Catálogo

Aqui estão alguns exemplos de como os livros são armazenados e listados no sistema:

| ISBN           | Título   | Autor       | Editora          | Ano  | Exemplares disponíveis|
| :------------- | :------- | :---------- | :--------------- | :--- | :--------- |
| 978-6555791464 | Dracula  | Bram Stoker | Pandorga Editora | 2025 | 7          |

##  Como Compilar e Rodar

Para compilar e executar este programa, você precisará de um compilador C.

1.  **Salve o Código**: Certifique-se de que o código-fonte principal (`catalogo_livros.c`) e este arquivo `README.md` estejam na mesma pasta.

2.  **Compile o Código**: Abra seu terminal (ou prompt de comando), navegue até o diretório do projeto e use o seguinte comando para compilar:

    ```bash
    gcc catalogo_livros.c -o catalogo_livros -Wall
    ```
    *A opção `-Wall` é recomendada para ativar todos os avisos do compilador, auxiliando na identificação de potenciais problemas.*

3.  **Execute o Programa**: Após a compilação bem-sucedida, execute o programa com o comando:

    ```bash
    ./catalogo_livros
    ```

##  Como Usar

Ao iniciar o programa, você será recebido por um menu principal, apresentando as opções:


MENU
 * Inserir Livro
 * Buscar Livro
 * Atualizar Livro
 * Remover Livro
 * Listar Livros
 * @@@@
 * Escolha:
<!-- end list -->

Para interagir com o sistema, siga estes passos simples:

1.  **Escolha uma Opção**: Digite o número correspondente para a função que deseja executar.
2.  **Siga as Instruções**: O programa irá guiá-lo, solicitando as informações necessárias para cada operação (como o ISBN, título, autor, etc.). 
3.  **Repetir ou Encerrar**: Após cada operação, o menu principal será exibido novamente. Você pode continuar usando o sistema escolhendo novas opções. Para **encerrar o programa**, basta digitar qualquer número que não corresponda a uma das opções do menu (1 a 5), por exemplo, `0` , e o programa será finalizado.

##  Estrutura de Arquivos

* `catalogo_livros.c`: O código-fonte principal da aplicação.
* `README.md`: Este arquivo, contendo a descrição do projeto e instruções.
* `catalogo.csv`: Arquivo gerado e utilizado pelo programa para armazenar e carregar os dados do catálogo de livros. Ele será criado automaticamente na primeira execução, se não existir.

## Autores
<div class="contributor">
        <a href="https://github.com/AnaliviaCavalcante" target="_blank">Analívia Cavalcante</a>
    </div>
