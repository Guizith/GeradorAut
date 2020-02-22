#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j;
	int numsimb = 0;
	char simb[200];
	int est=0;
	int estini =0;
	int qtdfin=0;
	int fin[200];
	
	

	printf("\n Quantos Simbolos?:");
	scanf("%d",&numsimb);
	for(i=0;i<numsimb;i++){
		printf("\n Qual o simbolo %d :",i);
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
		scanf("%d",&fin);
	}
	
	
	int reg [est][numsimb];
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf("Para o estado e%d , simbolo %c , qual proximo estado? ", i,simb[j]);
				scanf("%d",&reg[i][j]);
		}
		
	}
	
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

	FILE *sc=fopen("Automato.c", "w");
		
	fflush(sc);
	//inicializaão cod
	fprintf(sc,"#include <stdio.h>\n");
	fprintf(sc,"#include <stdlib.h\n");
	fprintf(sc,"#include <conio.h>\n\n");
	fprintf(sc,"int main(){ \n \n");
	fprintf(sc,"char stc[200]; \n");
	fprintf(sc,"int p=0; \n");
	fprintf(sc,"printf(\"digite a sentenca: \"); \n");
	fprintf(sc,"gets(stc);\n");
	fprintf(sc,"goto E0; \n\n");
	printf("inici");
	
		/*
	i,j=0;
	
	for(i=0;i<est*numsimb;i++){
		fprintf(sc,"E%d:\n\n",i);
		int ft = 0;
		for(j=0;j<numsimb*est;j++){
			
			if(ft== 0){
					printf("if");
				fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
				fprintf(sc,"p++;\n",simb[j]);
				fprintf(sc,"goto E%d;\n",reg[i][j]);
				fprintf(sc,"} \n \n");
				ft = 1;
			}
			else {
				printf("\n else\n");
				fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
				fprintf(sc,"goto REJEITA();\n");
				
				fprintf(sc,"} \n \n");
			}
		}
	}

	i=0;
	j=0;
	int k =0;
	while(i < est){
		printf("while");
		fprintf(sc,"E%d:\n\n",i);
		for(k=0;k<numsimb;k++){
			printf("\n %d \n", reg[i][j]);	
			if(reg[i][j]!=(-1)){
					printf("if");
				fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
				fprintf(sc,"p++;\n",simb[j]);
				fprintf(sc,"goto E%d;\n",reg[i][j]);
				fprintf(sc,"} \n \n");
			} 
			else if(reg[i][j]==(-1)){
				printf("\n else\n");
				fprintf(sc,"else if(stc[p]=='%c') { \n",simb[k]);
				fprintf(sc,"goto REJEITA();\n");
				
				fprintf(sc,"} \n \n");
			}
		}
		
		j=0;
		i++;
	}
		*/

	for(i=0;i<est;i++){
		fprintf(sc,"E%d:\n\n",i);
		int dc=1;
		for(j=0;j<numsimb;j++){
			printf("\n %d \n", reg[j][i]);
			if(reg[j][i]!=(-1)){
				printf("if");
				fprintf(sc,"if(stc[p]=='%c'){ \n",simb[j]);
				fprintf(sc,"p++;\n");
				fprintf(sc,"goto E%d;\n",reg[j][i]);
				fprintf(sc,"} \n \n");
			} 	
		}
			for(j=0;j<numsimb;j++){
				printf("\n %d \n", reg[j][i]);
				if(reg[i][j]==(-1)){
					printf("\n else\n");
					fprintf(sc,"else if(stc[p]=='%c') { \n",simb[j]);
					fprintf(sc,"goto REJEITA();\n");
					fprintf(sc,"} \n \n");
			}
		} 	
	}

		
		
	
	fprintf(sc,"} ");
	fclose(sc);

	return 0;
}
