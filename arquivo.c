#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int valor;
	struct no *prox;
}No;

void inserir_no_inicio(No **lista, int num){
	No *novo = malloc(sizeof(No));
	
	novo->valor = num;
	novo->prox = *lista;
	*lista = novo;
}

void inserir_no_fim(No **lista, int num){
	No *aux, *novo = malloc(sizeof(No));
	
	novo->valor = num;
	novo->prox = NULL;
	
	if(lista == NULL){
		*lista = novo;
	}
	else{
		aux = *lista;
		while(aux->prox){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void inserir_no_meio(No **lista, int num, int ref){
	No *aux, *novo = malloc(sizeof(No));
	
	novo->valor = num;
	
	if(lista == NULL){
		novo->prox = NULL;
		*lista = novo;
	}
	else{
		aux = *lista;
		while(aux->valor != ref && aux->prox){
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void imprimir(No *no){
	printf("\n\tLista: ");
	while(no){
		printf("%d ", no->valor);
		no = no->prox;
	}
	printf("\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, valor, anterior;
	No *lista = NULL;
	
	do{
		printf("\n\t0 - sair\n\t1 - inserir no in�cio\n\t2 - inserir no final\n\t3 - inserir no meio\n\t4 - imprimir\n");
		scanf("%d", &opcao);
		
		switch(opcao){
		case 1:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_inicio(&lista, valor);
			break;
		case 2:
			printf("Digite um valor: ");
			scanf("%d", &valor);
			inserir_no_fim(&lista, valor);
			break;
		case 3:
			printf("Digite um valor e o valor de refer�ncia: ");
			scanf("%d %d", &valor, &anterior);
			inserir_no_meio(&lista, valor, anterior);
			break;
		case 4:
			imprimir(lista);
			break;
		default:
			if(opcao != 0){
				printf("Op��o inv�lida!\n");
			}
		}	
	}while(opcao != 0);
	
	printf("FIM");
	
	return 0;
}