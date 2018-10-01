//agenda com struct 


#include <stdio.h>
#include <stdlib.h>

#define VAR 13
//0-4 contador de contatos
//8-12 variavel de loops
//12-16 inteiro usado para a escolha no menu

struct Pessoa{
	char nome[20];
	int telefone;
};


struct Pessoa *pessoa;

void* alocar(void *pBuffer);
void inclui(void *pBuffer);
void apaga(void *pBuffer);
void busca(void *pBuffer);
void lista(void *pBuffer);



int main(){
	printf("%d\n", sizeof(struct Pessoa));
	void *pBuffer = NULL;
	int *op;
	pBuffer = alocar(pBuffer);

	op = (int*)pBuffer+8;
	while(*op!=5){
		printf("1-Inserir\n2-Buscar\n3-Apagar\n4-Listar\n5-Sair\nEscolha: ");
		
		scanf("%d", op);
		__fpurge(stdin);
		switch(*op){
			case 1:
				inclui(pBuffer);
			break;
			case 2:
				apaga(pBuffer);
			break;
			case 3:
				busca(pBuffer);
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
}


void *alocar(void *pBuffer){
    int *qtd;
    void *aux;
	if(pBuffer == NULL){
		pBuffer = (struct Pessoa*)malloc(sizeof(struct Pessoa*)+3*sizeof(int));
		qtd = (int*)pBuffer;
        *qtd = 1;
	}
	else{
	    int *qtd;
        qtd = (int*)pBuffer;
        *qtd++;
		aux = (struct Pessoa*)realloc(pBuffer, sizeof(struct Pessoa*)*(*qtd)+3*sizeof(int));
		if(aux != NULL){
            pBuffer = aux;
		}
	}

    return pBuffer;
}/*
void *alocar(void *pBuffer){
	int *qtd;
	
	if(pBuffer == NULL){
		pBuffer = (struct Pessoa*)malloc(sizeof(struct Pessoa*)+VAR);
		qtd = (int*)pBuffer;
		*qtd = 0;
		qtd++;

	}
	else{
		*qtd++;
		pBuffer = (struct Pessoa*)realloc(pBuffer, sizeof(struct Pessoa*)*(*qtd));
	}

	return pBuffer;
}
*/
void inclui(void *pBuffer){
	char *c;
	int *i;
	pBuffer = alocar(pBuffer);
	i = (int*)pBuffer+4;
	*i = 0;
	c = (char*)pBuffer+13;
	printf("Nome: ");
	scanf("%c", c);
	while(c != "\n"){
		*(((char*)pBuffer)+pessoa->nome[*i]) = *c;
		//fgets(((char*)pBuffer+pessoa->nome[*i])+sizeof(struct Pessoa), 20, stdin);
		i++;
		scanf("%c", c);
	}


}

void apaga(void *pBuffer){
	printf("ok");

}
void busca(void *pBuffer){
	printf("ok");
}

void lista(void *pBuffer){
	printf("ok");
}