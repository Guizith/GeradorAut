#include <stdio.h>
#include <stdlib.h>


 //Este codigo automato foi gerado pelo programa main.c

 //Guilherme Henrique Moreira  22117039-2

 //Compiladores Projeto1  Prof: Pier

void e0();
void e1();
void e2();
void rejeita();
void aceita(); 

char stc[200]; 
int p=0; 

int main(){ 
 
	printf("digite a sentenca: "); 
	scanf("%s",stc);
	e0(); 
	return(0); 
}

void e0(){ 
	if(stc[p]=='a'){ 
		p++;
		e1();
	} 
 
	else{
		rejeita();
	}

}

void e1(){ 
	if(stc[p]=='b'){ 
		p++;
		e0();
	} 
 
	else if(stc[p]=='c'){ 
		p++;
		e2();
	} 
 
	else if(stc[p]==0){
		aceita();
	}
	else{
		rejeita();
 	}

}

void e2(){ 
	if(stc[p]==0){
		aceita();
	}
	else{
		rejeita();
 	}

}

void rejeita(){
	printf("rejeita");
	exit(0);

} 
 
void aceita(){
	printf("aceita");
	exit(0);
} 
 
