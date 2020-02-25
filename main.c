#include <stdio.h>
#include <stdlib.h>

/*	Programa gerador de programas automatos finitos deterministicos (AFD).

	Feito por: Guilherme Henrique Moreira  22117039-2
	Materia: Compiladores CC6252  -Prof= Pier Ricchetti
	Ci�ncia da Comta��o FEI

	*/

int main(int argc, char *argv[]) {
	
	//Variaveis de informa��es do automato
	int i,j;
	int numsimb = 0; 	//Qtd simbolos no alfabeto
	char simb[100];		//Alfabeto
	int est=0;			//Estados
	int estini =0;		//Estado inicial
	int qtdfin=0;		//Qtd estados finais
	int fin[100];		//Estados finais
	int fugo=0;			//decisao para gerar fun��o ou goto
	
	
	//Entrada de quantos e quais simbolos
	printf("\n Quantos Simbolos?:");
	scanf("%d",&numsimb);
	for(i=0;i<numsimb;i++){
		printf("\n Qual o simbolo %d (digite apenas o caracter, NAO aperte ENTER) :",i);
		simb[i]=getche();
	}
	
	//Entrada de estado inicial, estados e estados finais
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
	
	//Entrada da matriz de adjacencia das regras 
	int reg [est][numsimb];
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf("Para o estado e%d , simbolo %c , qual proximo estado? ", i,simb[j]);
				scanf("%d",&reg[i][j]);
		}
	}
	
	//Entrada de decis��o de como construir o automato
	printf("\nComo voce quer que seja feito o codigo do automato: \n");
	printf("Digite 1-Funcao\n");
	printf("Digite 2-Goto\n");
	printf("Digite 3-Goto e Funcao(sera gerado dois arquivos.c)\n");
	scanf("%d",&fugo);
	
	/*
	//print regras
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf(" \n regra do estado %d , simb %c : %d  \n \n",i,simb[j],reg[i][j] );		
		}	
	}
	*/
	/*
	//print estados
	printf("\n estados: %d", est);
	printf("\n estados ini: %d", estini);
	printf("\n estados fin: %d", qtdfin);
		for(i=0;i<qtdfin;i++){
		printf("\n estado final %d :",fin[i]);
	}
	*/
	/*
	//print afabeto
	printf("\nestados %d \n", numsimb);
	for(i=0;i<numsimb;i++){
		printf("\nsimbs:%s", simb);
	}*/
	
//=====================================================>>> Inicio de constru��o do codigo <<< ===============================================================================
	if(fugo ==2){
		FILE *sc=fopen("AutomatoGoto.c", "w");
		fflush(sc);
		
		//inicializa�o code goto
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
		
		//constru��o do automato goto
		for(i=0;i<est;i++){
			fprintf(sc,"	");
			fprintf(sc,"E%d:\n\n",i);
			
			int final=0;
			int nescr =0;
			int jfp=0;		//variavel importante! caso seja estado final o primeiro if n�o sera de rejei��o caso a senten�a acabe
							//logo, esta variavel � um flag para que o for que escreve else if saber que o primeiro caso ja foi feito
			
			//For para verificar se o estado atual � final!!!
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){		
					nescr++;
				}
			}
			
			//Caso nao seja estado final, fazer p==0 -> rejeita
			if(nescr == 0){
				fprintf(sc,"	");
				fprintf(sc,"if(stc[p]==0){\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"goto REJEITA; \n");
				fprintf(sc,"	");
				fprintf(sc,"}\n \n");
			}
			//Caso seja estado final fazer o primeiro if, e definir variavel jfp=1
			else if(nescr==1){
				for(j=0;j<numsimb;j++){
					if(reg[i][j]!=(-1)){
						jfp=1;
						fprintf(sc,"	");
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
				
			}
	
			//For para fazer else if apos o primeiro if
			for(j=0;j<numsimb;j++){	
				if(reg[i][j]!=(-1) && jfp==0){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
				//Caso o primeiro if ja tenho sido feito(jpf) escrever apenas os proximos 
				else if(reg[i][j]!=(-1) && jfp==1){
					jfp=0;
				}
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
			if(nescr==1){
				fprintf(sc,"	");
				fprintf(sc,"else\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"goto ACEITA;\n \n");
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
		if(fclose(sc)==0){
			printf("[ I ]	Arquivo 'AutomatoGoto.c' Gerado!	[ I ]\n");
		}else{
			printf("[ I ]	Erro!! Arquivo nao foi finalizado corretamente	[ I ]\n");
		}
		
	}
	else if(fugo==1){
		FILE *sc=fopen("AutomatoFunc.c", "w");
		fflush(sc);

		//inicializa�o code funcao
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		
		//for declara��o func�oes estados
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d();\n",i);
		}
		
		//declara��o aceita rejeita, char stc, int p
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
		
		//Constru��o do automato funcao
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d(){ \n",i);	
			
			int final=0;
			int nescr =0;
			int jfp=0;		//variavel importante! caso seja estado final o primeiro if n�o sera de rejei��o caso a senten�a acabe
							//logo, esta variavel � um flag para que o for que escreve else if saber que o primeiro caso ja foi feito
							
			//For para verificar se o estado atual � final!!!
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){		
					nescr++;
				}
			}
			
			//Caso nao seja estado final, fazer p==0 -> rejeita
			if(nescr == 0){
				fprintf(sc,"	");
				fprintf(sc,"if(stc[p]==0){\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"rejeita(); \n");
				fprintf(sc,"	");
				fprintf(sc,"}\n \n");
			}
			//Caso seja estado final fazer o primeiro if, e definir variavel jfp=1
			else if(nescr==1){
				for(j=0;j<numsimb;j++){
					if(reg[i][j]!=(-1)){
						jfp=1;
						fprintf(sc,"	");
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
				
			}
			
			
			
			//For para fazer else if apos o primeiro if
			for(j=0;j<numsimb;j++){	
				if(reg[i][j]!=(-1) && jfp ==0){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
				//Caso o primeiro if ja tenho sido feito(jpf) escrever apenas os proximos 
				else if(reg[i][j]!=(-1) && jfp ==1){
					jfp=0;
				}
			}
			
			//For para fazer else de rejei��o apos o primeiro if
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
			
			//For para fazer aceita(); caso seja estado final
			if(nescr==1){
				fprintf(sc,"	");
				fprintf(sc,"else\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"aceita();\n\n");
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
		if(fclose(sc)==0){
			printf("[ I ]	Arquivo 'AutomatoFunc.c' Gerado!	[ I ]\n");
		}else{
			printf("[ I ]	Erro!! Arquivo nao foi finalizado corretamente	[ I ]\n");
		}
		
	}
	else if(fugo==3){
		
//------------------------------------------------------->>> AUTOMATO GOTO <<<-----------------------------------------------------------------------
		FILE *sc=fopen("AutomatoGoto.c", "w");
		fflush(sc);
		
		//inicializa�o code goto
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
		
		//constru��o do automato goto
		for(i=0;i<est;i++){
			fprintf(sc,"	");
			fprintf(sc,"E%d:\n\n",i);
			
			int final=0;
			int nescr =0;
			int jfp=0;		//variavel importante! caso seja estado final o primeiro if n�o sera de rejei��o caso a senten�a acabe
							//logo, esta variavel � um flag para que o for que escreve else if saber que o primeiro caso ja foi feito
			
			//For para verificar se o estado atual � final!!!
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){		
					nescr++;
				}
			}
			
			//Caso nao seja estado final, fazer p==0 -> rejeita
			if(nescr == 0){
				fprintf(sc,"	");
				fprintf(sc,"if(stc[p]==0){\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"goto REJEITA; \n");
				fprintf(sc,"	");
				fprintf(sc,"}\n \n");
			}
			//Caso seja estado final fazer o primeiro if, e definir variavel jfp=1
			else if(nescr==1){
				for(j=0;j<numsimb;j++){
					if(reg[i][j]!=(-1)){
						jfp=1;
						fprintf(sc,"	");
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
				
			}
	
			//For para fazer else if apos o primeiro if
			for(j=0;j<numsimb;j++){	
				if(reg[i][j]!=(-1) && jfp==0){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"goto E%d;\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
				//Caso o primeiro if ja tenho sido feito(jpf) escrever apenas os proximos 
				else if(reg[i][j]!=(-1) && jfp==1){
					jfp=0;
				}
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
			if(nescr==1){
				fprintf(sc,"	");
				fprintf(sc,"else\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"goto ACEITA;\n \n");
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
		if(fclose(sc)==0){
			printf("[ I ]	Arquivo 'AutomatoGoto.c' Gerado!	[ I ]\n");
		}else{
			printf("[ I ]	Erro!! Arquivo nao foi finalizado corretamente	[ I ]\n");
		}
		
//------------------------------------------------------->>> AUTOMATO FUN��O <<<-----------------------------------------------------------------------
	
		sc=fopen("AutomatoFunc.c", "w");
		fflush(sc);

		//inicializa�o code funcao
		//fprintf(sc,"	");
		fprintf(sc,"#include <stdio.h>\n");
		fprintf(sc,"#include <stdlib.h>\n");
		fprintf(sc,"#include <conio.h>\n\n");
		fprintf(sc,"\n //Este codigo automato foi gerado pelo programa main.c\n");
		fprintf(sc,"\n //Guilherme Henrique Moreira  22117039-2\n");
		fprintf(sc,"\n //Compiladores Projeto1  Prof: Pier\n\n");
		
		//for declara��o func�oes estados
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d();\n",i);
		}
		
		//declara��o aceita rejeita, char stc, int p
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
		
		//Constru��o do automato funcao
		for(i=0;i<est;i++){
			fprintf(sc,"void e%d(){ \n",i);	
			
			int final=0;
			int nescr =0;
			int jfp=0;		//variavel importante! caso seja estado final o primeiro if n�o sera de rejei��o caso a senten�a acabe
							//logo, esta variavel � um flag para que o for que escreve else if saber que o primeiro caso ja foi feito
							
			//For para verificar se o estado atual � final!!!
			for(final=0;final<qtdfin;final++){	
				if(i==fin[final]){		
					nescr++;
				}
			}
			
			//Caso nao seja estado final, fazer p==0 -> rejeita
			if(nescr == 0){
				fprintf(sc,"	");
				fprintf(sc,"if(stc[p]==0){\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"rejeita(); \n");
				fprintf(sc,"	");
				fprintf(sc,"}\n \n");
			}
			//Caso seja estado final fazer o primeiro if, e definir variavel jfp=1
			else if(nescr==1){
				for(j=0;j<numsimb;j++){
					if(reg[i][j]!=(-1)){
						jfp=1;
						fprintf(sc,"	");
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
				
			}
			
			
			
			//For para fazer else if apos o primeiro if
			for(j=0;j<numsimb;j++){	
				if(reg[i][j]!=(-1) && jfp ==0){
					fprintf(sc,"	");
					fprintf(sc,"else if(stc[p]=='%c'){ \n",simb[j]);
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"p++;\n");
					fprintf(sc,"	");
					fprintf(sc,"	");
					fprintf(sc,"e%d();\n",reg[i][j]);
					fprintf(sc,"	");
					fprintf(sc,"} \n \n");
				}
				//Caso o primeiro if ja tenho sido feito(jpf) escrever apenas os proximos 
				else if(reg[i][j]!=(-1) && jfp ==1){
					jfp=0;
				}
			}
			
			//For para fazer else de rejei��o apos o primeiro if
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
			
			//For para fazer aceita(); caso seja estado final
			if(nescr==1){
				fprintf(sc,"	");
				fprintf(sc,"else\n");
				fprintf(sc,"	");
				fprintf(sc,"	");
				fprintf(sc,"aceita();\n\n");
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
		if(fclose(sc)==0){
			printf("[ I ]	Arquivo 'AutomatoFunc.c' Gerado!	[ I ]\n");
		}else{
			printf("[ I ]	Erro!! Arquivo nao foi finalizado corretamente	[ I ]\n");
		}
		
	}
	
	return 0;
}
