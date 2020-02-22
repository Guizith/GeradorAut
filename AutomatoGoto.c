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
	goto E1; 

	E0:

	if(stc[p]=='d'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='a') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='b') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='c') { 
		goto REJEITA;
	} 
 
	E1:

	if(stc[p]=='a'){ 
		p++;
		goto E2;
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		goto E0;
	} 
 
	else if(stc[p]=='b') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='d') { 
		goto REJEITA;
	} 
 
	E2:

	if(stc[p]=='a'){ 
		p++;
		goto E4;
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='c') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='d') { 
		goto REJEITA;
	} 
 
	E3:

	if(stc[p]=='d'){ 
		p++;
		goto E3;
	} 
 
	else if(stc[p]=='a') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='b') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='c') { 
		goto REJEITA;
	} 
 
	else
		goto ACEITA;
 
	E4:

	if(stc[p]=='a'){ 
		p++;
		goto E4;
	} 
 
	else if(stc[p]=='b') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='c') { 
		goto REJEITA;
	} 
 
	else if(stc[p]=='d') { 
		goto REJEITA;
	} 
 
	else
		goto ACEITA;
 
	REJEITA:
	printf("rejeita"); 
	exit(0);
 
 	ACEITA:
	printf("aceita"); 
	exit(0);
 
 } 