#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAR 4 //quantidade de inteiros salvos no inicio do código
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
void atualiza();
void SelectSort();


void *pBuffer;
int *qtd, *i, *j, *min;

int main(){

	pBuffer = NULL;
	int *op;			//op e j usam a mesma posicao no buffer para operacoes diferentes
	pBuffer = alocar();
	do {
		atualiza();
		op = pBuffer+8;

		printf("1-Inserir\n2-Buscar\n3-Apagar\n4-Listar\n5-Sair\n6-Sort\nEscolha: ");

		scanf(" %d", op);
		setbuf(stdin, NULL); //limpar o buffer de entrada do teclado
			
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
			case 6:
				SelectSort();
			break;
		}
	}while(*op!=5);


	free(pBuffer);
	return 0;
}


void *alocar(){

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
	atualiza();

	return pBuffer;
}


void inclui(){
	struct Pessoa *pessoa;
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
	struct Pessoa *pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));

	if((*i) >= 0){
		for(*j = *i; *j < *qtd; (*j)++){
			strcpy((pessoa+(*j))->nome, ((pessoa+((*j)+1))->nome));
			strcpy((pessoa+(*j))->telefone, ((pessoa+((*j)+1))->telefone));
		}
		pBuffer = realloc(pBuffer, sizeof(struct Pessoa)*(*qtd)+VAR*sizeof(int));		
		atualiza();
		(*qtd)--;
	}
	*j=0; //como *j aponta para o mesmo lugar que *op, essa posição recebe zero para não sair do programa quando voltar para o while
}


void busca(){

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

	qtd = pBuffer;

	pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));

	i = pBuffer+4;
	*i = 0;
	while(*i < *qtd){
		printf("%s", (pessoa+(*i))->nome);
		printf("%s", (pessoa+(*i))->telefone);
       (*i)++;
      
	}

}

void atualiza(){
	qtd = pBuffer;
	i = pBuffer+4 ;
	j = pBuffer+8;
	min = pBuffer+12;
}

void SelectSort(){
	struct Pessoa *pessoa;
	pessoa = pBuffer+(VAR*sizeof(int))+(sizeof(struct Pessoa));
	struct Pessoa *aux;
	aux = pBuffer+(VAR*sizeof(int));

	for(*i = 0; *i < (*qtd)-1; (*i)++){
		*min = *i;
		for(*j = (*i)+1; *j< *qtd; (*j)++){
			if(strcmp(((pessoa+(*min))->nome), (pessoa+(*j))->nome) > 0){
				*min = *j;
			}
		}
		if(*min != *i){
			strcpy(aux->nome, (pessoa+(*min))->nome);
			strcpy(aux->telefone, (pessoa+(*min))->telefone);
			strcpy((pessoa+(*min))->nome, (pessoa+(*i))->nome);
			strcpy((pessoa+(*min))->telefone, (pessoa+(*i))->telefone);
			strcpy((pessoa+(*i))->nome, aux->nome);
			strcpy((pessoa+(*i))->telefone, aux->telefone);
		}
	}
	printf("\nOrdenado por Selection Sort\n\n");
	*j = 0; //evitar erros com switch

}