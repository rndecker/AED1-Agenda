#include <stdio.h>
#include <stdlib.h>



#define TAMVAR 12
#define TAMNOME 50
#define TAMEND 60
#define TAMTEL 11

#define CONTATO 121

/* 0 - 12 duas variaveis int (QTD dada pelo usuario, contador)
   9 - 59 primeiro nome inserido
   60 - 120 endereco
   121 - 132 telefone
*/

//0-4 contador de contatos
//8-12 variavel de loops
//12-16 inteiro usado para a escolha no menu
void* alocar(void *pBuffer);
void inclui(void *pBuffer);
void apaga(void *pBuffer);
void busca(void *pBuffer);
void lista(void *pBuffer);

int main(){

	void *pBuffer = NULL;
	int *op;

	//pBuffer = malloc(TAMVAR + sizeof(void*)*3);
	pBuffer = alocar(pBuffer);
    op = (int*)pBuffer+8;
   // printf("%d\n", *((int*)pBuffer));
	while(*op != 5){
		printf("1-Inserir\n2-Buscar\n3-Apagar\n4-Listar\n5-Sair\nEscolha: ");
		
		scanf("%d", op);
		__fpurge(stdin);

	
		switch(*op){
			case 1:
	            inclui(pBuffer);
			break;
			case 2:
	            busca(pBuffer);
			break;
			case 3:
	            apaga(pBuffer);
			break;
			case 4:
				lista(pBuffer);
			break;
			case 5:
				exit(1);
			break;
		}
	}

	return 0;
	free(pBuffer);
}

void inclui(void *pBuffer){

	pBuffer = alocar(pBuffer);    
	
	printf("\nNome: ");
	fgets(pBuffer+TAMVAR+*((int*)pBuffer)*CONTATO, TAMNOME, stdin);
	
	printf("\nEndereco: ");
	fgets(pBuffer+TAMVAR+TAMNOME+*((int*)pBuffer)*CONTATO, TAMEND, stdin);
	
	printf("\nTelefone: ");
	fgets(pBuffer+TAMVAR+TAMNOME+TAMEND+*((int*)pBuffer)*CONTATO, TAMTEL, stdin);
}

void* alocar(void *pBuffer){
    int *qtd;
    //qtd = pBuffer;
	if(pBuffer==NULL){
		pBuffer = malloc(TAMVAR + CONTATO + sizeof(void*)*3);
		qtd = pBuffer;
		*qtd = 1; //contador de  registros
	}
	else{
		*qtd++;	// incrementa contador de registros
		pBuffer = realloc(pBuffer, *qtd*CONTATO+TAMVAR);
		
	}

    return pBuffer;

}



void apaga(void *pBuffer){
	if(pBuffer == NULL)
		printf("\nAgenda vazia\n");
	else
		printf("\nok\n");
}

void busca(void *pBuffer){
	if(pBuffer == NULL)
		printf("\nAgenda vazia\n");
}

void lista(void *pBuffer){
	if(pBuffer == NULL)
		printf("\nAgenda vazia\n");
}
