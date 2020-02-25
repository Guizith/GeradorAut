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
void e5();
void rejeita();
void aceita(); 

char stc[200]; 
int p=0; 

int main(){ 
 
	printf("digite a sentenca: "); 
	gets(stc);
	e0(); 
	return(0); 
}

void e0(){ 
	if(stc[p]==0){
		rejeita(); 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		e4();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e1();
	} 
 
} 
 
void e1(){ 
	if(stc[p]==0){
		rejeita(); 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		e4();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e1();
	} 
 
} 
 
void e2(){ 
	if(stc[p]=='a'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e2();
	} 
 
	else
		aceita();

} 
 
void e3(){ 
	if(stc[p]==0){
		rejeita(); 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		e4();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e2();
	} 
 
} 
 
void e4(){ 
	if(stc[p]==0){
		rejeita(); 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		e5();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e1();
	} 
 
} 
 
void e5(){ 
	if(stc[p]==0){
		rejeita(); 
	}
 
	else if(stc[p]=='a'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]=='b'){ 
		p++;
		e3();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e1();
	} 
 
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
 
