#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


 //Este codigo automato foi gerado pelo programa main.c

 //Guilherme Henrique Moreira  22117039-2

 //Compiladores Projeto1  Prof: Pier

void e0();
void e1();
void e2();
void e3();
void e4();
void rejeita();
void aceita(); 

char stc[200]; 
int p=0; 

int main(){ 
 
	printf("digite a sentenca: "); 
	gets(stc);
	e1(); 
	return(0); 
}

void e0(){ 
	if(stc[p]=='d'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='a') { 
		rejeita();
	} 
 
	else if(stc[p]=='b') { 
		rejeita();
	} 
 
	else if(stc[p]=='c') { 
		rejeita();
	} 
 
} 
 
void e1(){ 
	if(stc[p]=='a'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e0();
	} 
 
	else if(stc[p]=='b') { 
		rejeita();
	} 
 
	else if(stc[p]=='d') { 
		rejeita();
	} 
 
} 
 
void e2(){ 
	if(stc[p]=='a'){ 
		p++;
		e4();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='c') { 
		rejeita();
	} 
 
	else if(stc[p]=='d') { 
		rejeita();
	} 
 
} 
 
void e3(){ 
	if(stc[p]=='d'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='a') { 
		rejeita();
	} 
 
	else if(stc[p]=='b') { 
		rejeita();
	} 
 
	else if(stc[p]=='c') { 
		rejeita();
	} 
 
	else
		aceita();

} 
 
void e4(){ 
	if(stc[p]=='a'){ 
		p++;
		e4();
	} 
 
	else if(stc[p]=='b') { 
		rejeita();
	} 
 
	else if(stc[p]=='c') { 
		rejeita();
	} 
 
	else if(stc[p]=='d') { 
		rejeita();
	} 
 
	else
		aceita();

} 
 
void rejeita(){
	printf("rejeita");
	getch();
	exit(0);

} 
 
void aceita(){
	printf("aceita");
	getch();
	exit(0);
} 
 
