/*
Desenvolva um programa para gerenciar um acervo de livros eletrônicos armazenados em
um computador. Cada livro possui título, o ano de publicação, nome do autor, editora,
ISBN e um indicador para o usuário saber se o livro já foi (ou não) lido.
Este aplicativo oferece as opções:
1 – Incluir Livro. (O aplicativo não pode aceitar o cadastro de mais de 1 livro com o mesmo
ISBN.)
2 – Ler Livro. (Deve exibir os dados do livro e marca-lo como lido)
3 – Listar livros lidos. (Após listar todos os livros, exibir a mensagem: “Foram localizados
x livros lidos!”, onde x é a quantidade de livros lidos encontrada)
4 – Listar livros não lidos. (Após listar todos os livros, exibir a mensagem: “Foram
localizados x livros não lidos!”, onde x é a quantidade de livros não lidos encontrada)
5 – Excluir livro (Solicitar ao usuário o ISBN do livro a ser excluído. Deve ser verificado
como liberar área de memória).
0 – Sair
Regras:
1. Lista dinâmica de encadeamento simples
2. Não é permitido o uso de variáveis globais
3. Todos devem conhecer completamente o trabalho.
4. A prova contém questões sobre o trabalho.
5. Em caso de cópias, todos os exemplares receberão nota zero (0).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Livro{
    int isbn;
    char titulo[100];
    int anoPublicacao;
    char nomeAutor[100];
    char editora[100];
    int lido;
    struct Livro *proximo;
}Livro;

Livro * cria_elemento(int isbn, char titulo[100], int anoPublicacao, char nomeAutor[100], char editora[100]){
    Livro *novo;
    novo = (Livro *) malloc(sizeof(Livro));
    novo->isbn = isbn;
    strcpy(novo->titulo, titulo);
    novo->anoPublicacao = anoPublicacao;
    strcpy(novo->nomeAutor, nomeAutor);
    strcpy(novo->editora, editora);
    novo->proximo = NULL;
    return novo;
}

Livro * insere_primeiro(Livro * lista, Livro * novo){
        novo->proximo = lista;
        return novo;
}

Livro * insere_ultimo(Livro * lista, Livro * novo){
        if (lista != NULL) {
           Livro * aux = lista;
                   while (aux->proximo != NULL){
                         aux = aux->proximo;}
                   aux->proximo = novo;
                   return lista;}
        else{
             return novo;}
}

void mostra_livros(Livro * lista){
  Livro * aux = lista;
  printf("<-- LIVROS CADASTRADOS -->\n\n");
    while(aux != NULL){
        printf("ISBN: %d \n", aux->isbn);
        printf("Titulo: %s \n", aux->titulo);
        printf("\n");
        aux = aux->proximo;
    }
}

Livro * remove_elemento(Livro * lista, int posicao){
      Livro * aux = lista;
      Livro * remove = NULL;
      int cont = 1;
      if (lista == NULL){ //se lista está vazia
         return NULL;
      }
      while(aux->proximo != NULL && cont < (posicao-1)){
        aux = aux->proximo;
        cont++;
      }
      // se eh a segunda posicao entao so deve atualizar o cont
      if (posicao == 2){
         cont++;
      }
      // Testa se a remoção é o primeiro da lista.
      // Neste caso, existem duas possibilidades: (a) ter mais de um na lista.
      //                                          (b) ser o unico na lista.
      // Quando for mais de um, atualizar a lista para o novo primeiro.
      if (cont == 1){
           if (aux->proximo != NULL){
              lista = aux->proximo;
            } // atualiza o inicio.
           else{
              lista = NULL;
            }     // caso só exista na lista o proprio a ser removido
           free(aux);
        }
      else {
            remove = aux->proximo;
            aux->proximo = remove->proximo;
            free(remove);
        }
      return lista;
}

Livro * buscar_livros(Livro * lista, int isbn){
    while(lista != NULL){
          if((lista->isbn, isbn) == 0){
            return lista;
          } else{
              lista = lista->proximo;
          }
          }
          return NULL;
}


int main()
{
    Livro * lista = NULL;
    int opcao;
    int isbn;
    char titulo[100];
    int anoPublicacao;
    char nomeAutor[100];
    char editora[100];
    int lido;
    int contador = 0;

    while(opcao != 0)
    {
        system ("CLS");
        printf ("\n\n:::::::::: Biblioteca Windows 3.11 ::::::::::\n");
        printf ("---------------------------------------------\n");
        printf ("1:   Incluir Livro - (%d Livros cadastrados)\n", contador);
        printf ("---------------------------------------------\n");
        printf ("2:   Ler Livro                               \n");
        printf ("---------------------------------------------\n");
        printf ("3:   Listar Livros Lidos                     \n");
        printf ("---------------------------------------------\n");
        printf ("4:   Listar Livros Nao Lidos                 \n");
        printf ("---------------------------------------------\n");
        printf ("5:   Excluir Livro                           \n");
        printf ("---------------------------------------------\n");
        printf ("6:   Lista Todos os Titulos                  \n");
        printf ("---------------------------------------------\n");
        printf ("0:   Sair do Sistema                         \n");
        printf ("---------------------------------------------\n");
        printf ("Digite a opcao desejada: ");
        scanf ("%d",&opcao);

        switch(opcao)
        {
            case 0:
            {
                system("cls");
                printf ("\n\n\n\n\n\n\n\n                        FINALIZANDO O SISTEMA AGUARDE!!!!!\n");
            }
            break;

            case 1:
            {
                printf("Digite o ISBN do Livro: ");
                scanf("%d",&isbn);
                fflush(stdin);
                printf("\nInforme o Titulo do Livro: ");
                gets(titulo);
                fflush(stdin);
                printf("\nInforme o Ano de Publicao do Livro: ");
                scanf("%d",&anoPublicacao);
                fflush(stdin);
                printf("\nInforme o Nome do Autor: ");
                gets(nomeAutor);
                fflush(stdin);
                printf("\nInforme a Editora do Livro: ");
                gets(editora);
                fflush(stdin);

                Livro *n = cria_elemento(isbn, titulo, anoPublicacao, nomeAutor, editora);
                lista = insere_ultimo(lista, n);
                contador++;
                printf ("\n\nLivro cadastrado com Sucesso!!\n\n\n");
                system ("pause");
            }
            break;
    /**
            case 2:
            {    //busca dados do produto pelo código.
                printf ("\nDigite o codigo do produto a ser consultado: ");
                int codigo_busca;
                scanf("%d",&codigo_busca);
                Veiculo * busca_cod = busca_produto_codigo(lista, codigo_busca);
                system ("cls");
                printf ("\n\n          DADOS DO PRODUTO CADASTRADO NO SISTEMA   \n");
                printf("\n Dados do produto de codigo: codigo_busca\n\n");
                printf("Codigo: %d\n", busca_cod->codigo);
                printf("Categoria: %d\n", busca_cod->categoria);
                printf("Descriao: %s\n", busca_cod->descr);
                printf("Preco: R$%10.2f \n\n\n", busca_cod->preco);
                system("pause");
            }
            break;
            case 3:
            {
            //Exclui um veiculo pelo codigo
                show_veiculo2(lista);
                fflush(stdin);
                printf("%d", codigo);
                printf ("\nDigite o codigo do veiculo a ser excluido ou 0 para voltar ao menu: ");
                int codigo;
                scanf("%d",&codigo);
                lista = remove_elemento(lista, codigo);
            }
            break;
            case 4:
            {   //Apresenta a lista completa.           //Cópia descarada dos exercícios.
                printf("\n\n");
                show_veiculo(lista);
                system("pause");
            }
            break;
             **/
         case 5:
            {
                printf ("\nDigite o ISBN do Livro que deve ser excluido ou 0 para voltar ao menu: ");
                scanf("%d",&isbn);
                lista = remove_elemento(lista, isbn);
            }
            break;

            case 6:
            {
                printf("\n\n");
                printf("Existem %d livros cadastrados, são eles:\n", contador);
                mostra_livros(lista);
                system("pause");
            }
            break;
/**
            case 5:
            {   //Apresenta a média de preços dos produtos de uma unica categoria.

            }
            break; **/
            default:
            {   //Caso no menu seja escolhido uma opção inválida.
                printf ("\n OPCAO INVALIDA - ESCOLHA UMA DAS OPCOES DO MENU \n");
                system("pause");
            }
            break;
        }
    }
    int fim;
    while ( fim != 400000000)
    { //Loop usado pela balaca do final.
          fim++;
    }
	return(0);
}
