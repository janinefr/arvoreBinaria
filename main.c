#include <stdio.h>
#include <stdlib.h>

// Implemente a Árvore Binária de Busca

// definição

typedef struct No {
  int valor;
  struct No *direita;
  struct No *esquerda;
} tArvoreBinaria;

// typedef tNo *ArvoreBinaria;

tArvoreBinaria *cria_arvore();
tArvoreBinaria *inserir_arvore(tArvoreBinaria *raiz, int num);

// criacao da arvore
tArvoreBinaria *cria_arvore() {
  tArvoreBinaria *raiz = (tArvoreBinaria *)malloc(sizeof(tArvoreBinaria));
  if (raiz != NULL) {
    raiz = NULL;
  }
  return raiz;
}

// insercao na arvore
tArvoreBinaria* inserir_arvore(tArvoreBinaria *raiz, int num) {
  if (raiz == NULL) {
    tArvoreBinaria *novo = (tArvoreBinaria *)malloc(sizeof(tArvoreBinaria));
    novo->valor = num;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
  //inserindo de forma recursiva
  } else {
    if (num < raiz->valor) {
      raiz->esquerda = inserir_arvore(raiz->esquerda, num);
    } else {
      raiz->direita = inserir_arvore(raiz->direita, num);
    }
    return raiz;
  }
}

//BUSCA ELEMENTO
tArvoreBinaria* busca_elemento(tArvoreBinaria *raiz, int chave){
  if (raiz){
     if (chave == raiz->valor){
        return raiz;
      }
    else if(chave < raiz->valor){
        return busca_elemento(raiz->esquerda, chave);
      }
      else{
        return busca_elemento(raiz->direita, chave);
    
      }
    }
  return NULL;
    }
  

//IMPRIME ARVORE EM ORDEM CRESCENTE
/*
    Imprime os valores da árvore em ordem crescente
*/
void imprimir_arvore(tArvoreBinaria *raiz){
    if(raiz){
        imprimir_arvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_arvore(raiz->direita);
    }
}

int main(void) {

    tArvoreBinaria *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            raiz = inserir_arvore(raiz, valor);
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_arvore(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = busca_elemento(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
