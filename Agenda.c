#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAR 3 //quantidade de inteiros salvos no inicio do código
//0-3 contador de contatos
//4-7 variavel de loops
//8-11 inteiro usado para a escolha no menu e segunda variável de loops

struct Pessoa{
	char nome[20];
	char telefone[12];
};


void* alocar();
void inclui();
void apaga();
void busca();
void lista();
void atualiza(int **qtd, int **i, int **j);

void *pBuffer;

int main(){

	pBuffer = NULL;
	int *op;
	pBuffer = alocar();
	//op = pBuffer+8;
	do {
		op = pBuffer+8;

		printf("1-Inserir\n2-Buscar\n3-Apagar\n4-Listar\n5-Sair\nEscolha: ");

		scanf(" %d", op);
		setbuf(stdin, NULL);
		switch(*op){
			case 1:
				inclui();
			break;
			case 2:
				busca();
			break;
			case 3:
				apaga();				
			break;
			case 4:
				lista();
			break;
			case 5:
				exit(1);
			break;
		}
	}while(*op!=5);


	free(pBuffer);
	return 0;
}


void *alocar(){
    int *qtd;
    void *aux;
	if(pBuffer == NULL){
		pBuffer = (void*)malloc(sizeof(struct Pessoa)+VAR*sizeof(int));
		qtd = (int*)pBuffer;
        *qtd = 0;
	}
	else{
        qtd = (int*)pBuffer;
        (*qtd)++;
		aux = realloc(pBuffer, sizeof(struct Pessoa)*(*qtd + 1)+VAR*sizeof(int));
		qtd = (int*)aux;
		if(aux != NULL){
            pBuffer = aux;
		}
	}
	return pBuffer;
}

void inclui(){
	struct Pessoa *pessoa;
	int *qtd;
	pBuffer = alocar();
	qtd = (int*)pBuffer;
	pessoa = pBuffer+(VAR*sizeof(int))+(*qtd)*(sizeof(struct Pessoa));
    
	
	printf("Nome: "); 
	fgets(pessoa->nome, 20, stdin); 

	printf("Telefone: ");
    fgets(pessoa->telefone,12, stdin);

    setbuf(stdin, NULL);

}

void apaga(){
	busca();	
	int *qtd = pBuffer;
	int *i = pBuffer+4;
	int *j = pBuffer+8;
	struct Pessoa *pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));

	if((*i)!= 0){
		for(*j = *i; *j < *qtd; *j++){
			strcpy((pessoa+(*j))->nome, ((pessoa+(*j+1))->nome));
			strcpy((pessoa+(*j))->telefone, ((pessoa+(*j+1))->telefone));
		}
		pBuffer = realloc(pBuffer, sizeof(struct Pessoa)*(*qtd)+VAR*sizeof(int));		
		atualiza(&qtd, &i, &j);
		(*qtd)--;
	}
}


void busca(){
	int *i = pBuffer+4;
	int *qtd = pBuffer;
	struct Pessoa *pessoa;
	struct Pessoa *alvo; 
	alvo = pBuffer+(VAR*sizeof(int));
	pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));
	printf("Nome: ");
	fgets(alvo->nome, 20, stdin);
	*i = 0;
	while(*i < *qtd){
		if(strcmp(alvo->nome, (pessoa+(*i))->nome) == 0){
			printf("%s", (pessoa+(*i))->nome);
			printf("%s", (pessoa+(*i))->telefone);			
			return;
		}

		(*i)++;
	}
	*i=0;
}

void lista(){
	struct Pessoa *pessoa;
	int *qtd;
	int *i;
	qtd = (int*)pBuffer;

	pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));

	i = pBuffer+4;
	*i = 0;
	while(*i < *qtd){
		printf("%s", (pessoa+(*i))->nome);
		printf("%s", (pessoa+(*i))->telefone);
       (*i)++;
      
	}
}

void atualiza(int **qtd, int **i, int **j){
	*qtd = pBuffer;
	*i = pBuffer+4 ;
	*j = pBuffer+8;
}