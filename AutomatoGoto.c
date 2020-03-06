#include <stdio.h>
#include <stdlib.h>


 //Este codigo automato foi gerado pelo programa main.c

 //Guilherme Henrique Moreira  22117039-2

 //Compiladores Projeto1  Prof: Pier

int main(){ 
 
	char stc[200]; 
	int p=0; 
	printf("digite a sentenca: "); 
	scanf("%s",stc);
	goto E0; 

	E0:

	if(stc[p]=='a'){ 
		p++;
		goto E1;
	} 
 
	else{
		goto REJEITA;
	}

	E1:

	if(stc[p]=='b'){ 
		p++;
		goto E0;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]==0){
		goto ACEITA;
	}
	else{
		goto REJEITA;
 	}

	E2:

	if(stc[p]==0){
		goto ACEITA;
	}
	else{
		goto REJEITA;
 	}

	REJEITA:
	printf("rejeita"); 
	exit(0);
 
 	ACEITA:
	printf("aceita"); 
	exit(0);
 
 } 