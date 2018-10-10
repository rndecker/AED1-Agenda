//agenda com struct


#include <stdio.h>
#include <stdlib.h>

//#define VAR 12
//0-4 contador de contatos
//8-12 variavel de loops
//12-16 inteiro usado para a escolha no menu

struct Pessoa{
	char nome[20];
	char telefone[12];
};


//struct Pessoa *pessoa;

void* alocar();
void inclui();
void apaga();
void busca();
void lista();

void *pBuffer;

int main(){
	printf("%d\n", sizeof(struct Pessoa)); //confere o tamanho de Pessoa
	pBuffer = NULL;
	int *op;
	pBuffer = alocar();

	op = (int*)pBuffer+8;
	while(*op!=5){
		printf("1-Inserir\n2-Buscar\n3-Apagar\n4-Listar\n5-Sair\nEscolha: ");

		scanf("%d", op);
		__fpurge(stdin);
		switch(*op){
			case 1:
				inclui();
			break;
			case 2:
				apaga();
			break;
			case 3:
				busca();
			break;
			case 4:
				lista();
			break;
			case 5:
				exit(1);
			break;
		}
	}


	free(pBuffer);
	return 0;
}


void *alocar(){
    int *qtd;
    void *aux;
	if(pBuffer == NULL){
		pBuffer = (struct Pessoa*)malloc(sizeof(struct Pessoa)+3*sizeof(int));
		qtd = (int*)pBuffer;
        *qtd = 0;
	}
	else{
        qtd = (int*)pBuffer;
        (*qtd)++;
		aux = (struct Pessoa*)realloc(pBuffer, sizeof(struct Pessoa)*(*qtd)+3*sizeof(int));
		qtd = (int*)aux;
		if(aux != NULL){
            pBuffer = aux;
		}
	}
	return pBuffer;
}

void inclui(){
	struct Pessoa *pessoa;
	printf("%d\n", sizeof(pessoa));
	int *qtd;
	qtd = (int*)pBuffer;
	pBuffer = alocar();

	pessoa = (struct Pessoa*)pBuffer+(3*sizeof(int))+(*qtd)*(sizeof(struct Pessoa));

	printf("Nome: ");
	fgets(pessoa->nome, 20*sizeof(char), stdin);

	printf("Telefone: ");
    fgets(pessoa->telefone,11*sizeof(char), stdin);

    __fpurge(stdin);

}

void apaga(){
	printf("ok");

}
void busca(){
	printf("ok");
}

void lista(){
	struct Pessoa *pessoa;
	
	int *qtd;
	int *i;
	qtd = (int*)pBuffer;

	pessoa = (struct Pessoa*)pBuffer+(3*sizeof(int))+(sizeof(struct Pessoa));

	printf("qtd %d\n", *qtd);
	i = (int*)pBuffer+4;
	*i = 0;
	while(*i < *qtd){
		fputs(pessoa->nome, stdout);
        fputs(pessoa->telefone, stdout);
       // pessoa++;
		(*i)++;
	}
}