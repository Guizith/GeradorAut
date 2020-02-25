#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


 //Este codigo automato foi gerado pelo programa main.c

 //Guilherme Henrique Moreira  22117039-2

 //Compiladores Projeto1  Prof: Pier

int main(){ 
 
	char stc[200]; 
	int p=0; 
	printf("digite a sentenca: "); 
	gets(stc);
	goto E0; 

	E0:

	if(stc[p]==0){
		goto REJEITA; 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		goto E4;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E1;
	} 
 
	E1:

	if(stc[p]==0){
		goto REJEITA; 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		goto E4;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E1;
	} 
 
	E2:

	if(stc[p]=='a'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E2;
	} 
 
	else
		goto ACEITA;
 
	E3:

	if(stc[p]==0){
		goto REJEITA; 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		goto E4;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E2;
	} 
 
	E4:

	if(stc[p]==0){
		goto REJEITA; 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		goto E5;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E1;
	} 
 
	E5:

	if(stc[p]==0){
		goto REJEITA; 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E1;
	} 
 
	REJEITA:
	printf("rejeita"); 
	exit(0);
 
 	ACEITA:
	printf("aceita"); 
	exit(0);
 
 } 