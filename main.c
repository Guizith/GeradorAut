#include <stdio.h>
#include <stdlib.h>

/*	Programa gerador de programas automatos finitos deterministicos (AFD).

	Feito por: Guilherme Henrique Moreira  22117039-2
	Materia: Compiladores CC6252  -Prof= Pier Ricchetti
	Ciência da Comtação FEI

	*/

int main(int argc, char *argv[]) {
	
	int i,j;
	int numsimb = 0;
	char simb[100];
	int est=0;
	int estini =0;
	int qtdfin=0;
	int fin[100];
	int fugo=0;
	
	

	printf("\n Quantos Simbolos?:");
	scanf("%d",&numsimb);
	for(i=0;i<numsimb;i++){
		printf("\n Qual o simbolo %d (digite apenas o caracter, NAO aperte ENTER) :",i);
		simb[i]=getche();
	}
	
	
	printf("\n Quantos Estados?:");
	scanf("%d",&est);
	printf("\n Qual o estado inicial?:");
	scanf("%d",&estini);
	printf("\n Quantos estados finais?:");
	scanf("%d",&qtdfin);
	for(i=0;i<qtdfin;i++){
		printf("\n Digite o estado final %d :",i);
		scanf("%d",&fin[i]);
	}
	
	
	int reg [est][numsimb];
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf("Para o estado e%d , simbolo %c , qual proximo estado? ", i,simb[j]);
				scanf("%d",&reg[i][j]);
		}
		
	}
	
	printf("Como voce quer que seja feito o codigo do automato: \n");
	printf("Digite 1-Funcao\n");
	printf("Digite 2-Goto\n");
	printf("Digite 3-Goto e Funcao(sera gerado dois arquivos.c)\n");
	scanf("%d",&fugo);
	
	/*
	print regras
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf(" \n regra do estado %d , simb %c : %d  \n \n",i,simb[j],reg[i][j] );		
		}	
	}
	*/
	/*
	print estados
	printf("\n estados: %d", est);
	printf("\n estados ini: %d", estini);
	printf("\n estados fin: %d", qtdfin);
		for(i=0;i<qtdfin;i++){
		printf("\n estado final %d :",fin[i]);
	}
	*/
	/*
	print afabeto
	printf("\nestados %d \n", numsimb);
	for(i=0;i<numsimb;i++){
		printf("\nsimbs:%s", simb);
	}*/

	if(fugo ==2){
		FILE *sc=fopen("AutomatoGoto.c", "w");
		fflush(sc);
		//inicializaão code goto
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		fprintf(sc,"int main(){ \n \n");
		fprintf(sc,"	");
		fprintf(sc,"char stc[200]; \n");
		fprintf(sc,"	");
		fprintf(sc,"int p=0; \n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"digite a sentenca: \"); \n");
		fprintf(sc,"	");
		fprintf(sc,"gets(stc);\n");
		fprintf(sc,"	");
		fprintf(sc,"goto E%d; \n\n",estini);
		
		//construção do automato goto
		for(i=0;i<est;i++){
			fprintf(sc,"	");
			fprintf(sc,"E%d:\n\n",i);
			
			//for para fazer primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]!=(-1)){
					fprintf(sc,"	");
					printf("\n estado %d",i);
					printf("\nvalor simb if 1  %c",simb[j]);
					fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
					j=200;
				} 	
			}
			
			//For para fazer else if apos o primeiro if
			int ft = 1;
			for(j=0;j<numsimb;j++){
				printf("\n estado %d",i);	
				if(reg[i][j]!=(-1) && ft == 0){
					fprintf(sc,"	");
					printf("\n valor simb if2 %c",simb[j]);
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}else if(reg[i][j]!=(-1))
					ft = 0;
			}
			
			//For para fazer else apos o primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]==(-1)){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto REJEITA;\n");
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
			} 
			//For para fazer goto ACEITA, caso seja estado final
			int final;	
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){
					fprintf(sc,"	");
					fprintf(sc,"else\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto ACEITA;\n \n");
				}
			}
		}
	
	
		//aceita e rejeita
		fprintf(sc,"	");
		fprintf(sc,"REJEITA:\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"rejeita\"); \n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n \n ");
		fprintf(sc,"	");
		fprintf(sc,"ACEITA:\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"aceita\"); \n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n \n ");
			
			
		//fechamento main e fechamento arquivo.c
		fprintf(sc,"} ");
		fclose(sc);
	}
	else if(fugo==1){
		FILE *sc=fopen("AutomatoFunc.c", "w");
		fflush(sc);

		//inicializaão code funcao
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		//for declaração funcçoes estados
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d();\n",i);
		}
		//declaração aceita rejeita, char stc, int p
		fprintf(sc,"void rejeita();\n",i);
		fprintf(sc,"void aceita(); \n\n",i);
		fprintf(sc,"char stc[200]; \n");
		fprintf(sc,"int p=0; \n\n");
		
		//int main e chamada e inicio automato
		fprintf(sc,"int main(){ \n \n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"digite a sentenca: \"); \n");
		fprintf(sc,"	");
		fprintf(sc,"gets(stc);\n");
		fprintf(sc,"	");
		fprintf(sc,"e%d(); \n",estini);
		fprintf(sc,"	");
		fprintf(sc,"return(0); \n");
		fprintf(sc,"}\n\n");
		
		//Construção do automato funcao
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d(){ \n",i);	
			//for para fazer primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]!=(-1)){
					fprintf(sc,"	");
					printf("\n estado %d",i);
					printf("\nvalor simb if 1  %c",simb[j]);
					fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
					j=200;
				} 	
			}
			
			//For para fazer else if apos o primeiro if
			int ft = 1;
			for(j=0;j<numsimb;j++){
				printf("\n estado %d",i);	
				if(reg[i][j]!=(-1) && ft == 0){
					fprintf(sc,"	");
					printf("\n valor simb if2 %c",simb[j]);
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}else if(reg[i][j]!=(-1))
					ft = 0;
			}
			
			//For para fazer else apos o primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]==(-1)){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"rejeita();\n");
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
			} 
			//For para fazer aceita();, caso seja estado final
			int final;	
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){
					fprintf(sc,"	");
					fprintf(sc,"else\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"aceita();\n\n");
				}
			}
			fprintf(sc,"} \n \n");
		}
		
		
		//aceita e rejeita
		fprintf(sc,"void rejeita(){\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"rejeita\");\n");
		fprintf(sc,"	");
		fprintf(sc,"getch();\n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n\n");
		fprintf(sc,"} \n \n");
		fprintf(sc,"void aceita(){\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"aceita\");\n");
		fprintf(sc,"	");
		fprintf(sc,"getch();\n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n");
		fprintf(sc,"} \n \n");
		fclose(sc);
	}
	else if(fugo==3){
		
		//AUTOMATO GOTO--------------------------------------------------------------
		FILE *sc=fopen("AutomatoGoto.c", "w");
		fflush(sc);
		//inicializaão code goto
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		fprintf(sc,"int main(){ \n \n");
		fprintf(sc,"	");
		fprintf(sc,"char stc[200]; \n");
		fprintf(sc,"	");
		fprintf(sc,"int p=0; \n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"digite a sentenca: \"); \n");
		fprintf(sc,"	");
		fprintf(sc,"gets(stc);\n");
		fprintf(sc,"	");
		fprintf(sc,"goto E%d; \n\n",estini);
		
		//construção do automato goto
		for(i=0;i<est;i++){
			fprintf(sc,"	");
			fprintf(sc,"E%d:\n\n",i);
			
			//for para fazer primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]!=(-1)){
					fprintf(sc,"	");
					printf("\n estado %d",i);
					printf("\nvalor simb if 1  %c",simb[j]);
					fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
					j=200;
				} 	
			}
			
			//For para fazer else if apos o primeiro if
			int ft = 1;
			for(j=0;j<numsimb;j++){
				printf("\n estado %d",i);	
				if(reg[i][j]!=(-1) && ft == 0){
					fprintf(sc,"	");
					printf("\n valor simb if2 %c",simb[j]);
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}else if(reg[i][j]!=(-1))
					ft = 0;
			}
			
			//For para fazer else apos o primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]==(-1)){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto REJEITA;\n");
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
			} 
			//For para fazer goto ACEITA, caso seja estado final
			int final;	
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){
					fprintf(sc,"	");
					fprintf(sc,"else\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto ACEITA;\n \n");
				}
			}
		}
	
	
		//aceita e rejeita
		fprintf(sc,"	");
		fprintf(sc,"REJEITA:\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"rejeita\"); \n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n \n ");
		fprintf(sc,"	");
		fprintf(sc,"ACEITA:\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"aceita\"); \n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n \n ");
					
		//fechamento main e fechamento arquivo.c
		fprintf(sc,"} ");
		fclose(sc);
		
		
		//AUTOMATO FUNÇÃO --------------------------------------------------------
		sc=fopen("AutomatoFunc.c", "w");
		fflush(sc);

		//inicializaão code funcao
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		//for declaração funcçoes estados
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d();\n",i);
		}
		//declaração aceita rejeita, char stc, int p
		fprintf(sc,"void rejeita();\n",i);
		fprintf(sc,"void aceita(); \n\n",i);
		fprintf(sc,"char stc[200]; \n");
		fprintf(sc,"int p=0; \n\n");
		
		//int main e chamada e inicio automato
		fprintf(sc,"int main(){ \n \n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"digite a sentenca: \"); \n");
		fprintf(sc,"	");
		fprintf(sc,"gets(stc);\n");
		fprintf(sc,"	");
		fprintf(sc,"e%d(); \n",estini);
		fprintf(sc,"	");
		fprintf(sc,"return(0); \n");
		fprintf(sc,"}\n\n");
		
		//Construção do automato funcao
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d(){ \n",i);	
			//for para fazer primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]!=(-1)){
					fprintf(sc,"	");
					printf("\n estado %d",i);
					printf("\nvalor simb if 1  %c",simb[j]);
					fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
					j=200;
				} 	
			}
			
			//For para fazer else if apos o primeiro if
			int ft = 1;
			for(j=0;j<numsimb;j++){
				printf("\n estado %d",i);	
				if(reg[i][j]!=(-1) && ft == 0){
					fprintf(sc,"	");
					printf("\n valor simb if2 %c",simb[j]);
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}else if(reg[i][j]!=(-1))
					ft = 0;
			}
			
			//For para fazer else apos o primeiro if
			for(j=0;j<numsimb;j++){
				if(reg[i][j]==(-1)){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"rejeita();\n");
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
			} 
			//For para fazer aceita();, caso seja estado final
			int final;	
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){
					fprintf(sc,"	");
					fprintf(sc,"else\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"aceita();\n\n");
				}
			}
			fprintf(sc,"} \n \n");
		}
		
		
		//aceita e rejeita
		fprintf(sc,"void rejeita(){\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"rejeita\");\n");
		fprintf(sc,"	");
		fprintf(sc,"getch();\n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n\n");
		fprintf(sc,"} \n \n");
		fprintf(sc,"void aceita(){\n");
		fprintf(sc,"	");
		fprintf(sc,"printf(\"aceita\");\n");
		fprintf(sc,"	");
		fprintf(sc,"getch();\n");
		fprintf(sc,"	");
		fprintf(sc,"exit(0);\n");
		fprintf(sc,"} \n \n");
		fclose(sc);
		
	}
	
	return 0;
}
