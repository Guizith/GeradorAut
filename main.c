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
	
	
	for(i=0;i<est;i++){
		for(j=0;j<numsimb;j++){
				printf("Para o estado e%d , simbolo %c , qual proximo estado? ", i,simb[j]);
				
		}
		
	}
	
	
	
	
	
	
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
/*
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
	
	//logica
	while(i <est){
		fprintf(sc,"E%d:\n\n",i);
		i++;
	}
	
	
	
	
	fprintf(sc,"} ");
	fclose(sc);
	*/
	return 0;
}
