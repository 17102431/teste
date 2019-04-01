#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c{
	char nome[20];
}contato;

typedef struct d{
	int contadorNomes;
	int tamanhoBuffer;
	char testeNome[20];
	int i;
}controle;

void *buffer;
contato *pcontato;
controle *pcontrole;

int main(){
	buffer = malloc(sizeof(controle));
	if (buffer == NULL){
		exit(1);
	}

	pcontrole = buffer;
	pcontrole->contadorNomes = 0;
	pcontrole->tamanhoBuffer = 0;
	
	while(1){
	 	printf("Entre um nome:  ");
	 	fgets(pcontrole->testeNome,20, stdin);
		if (pcontrole->testeNome[0] == '\n'){
			break;
		}

		(pcontrole->contadorNomes)++;
		pcontrole->tamanhoBuffer = sizeof(controle) + (pcontrole->contadorNomes)*sizeof(contato);

		buffer = realloc(buffer, pcontrole->tamanhoBuffer);
		pcontrole = buffer;
		pcontato = buffer + pcontrole->tamanhoBuffer - sizeof(contato);

		for (pcontrole->i = 0; pcontrole->testeNome[pcontrole->i] != '\n' && pcontrole->testeNome[pcontrole->i] != '\0'; (pcontrole->i)++){
			pcontato->nome[pcontrole->i] = pcontrole->testeNome[pcontrole->i];
		}
	}

	if (pcontrole->contadorNomes != 0) {
		contato *contatoAtual;
		contatoAtual = buffer + sizeof(controle);
		while(pcontrole->contadorNomes > 0){
			printf("%s\n", contatoAtual->nome);
			contatoAtual ++;
			pcontrole->contadorNomes--;
		}
			
	}
}
