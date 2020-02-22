#include <stdio.h>
#include <stdlib.h
#include <conio.h>

int main(){ 
 
char stc[200]; 
int p=0; 
printf("digite a sentenca: "); 
gets(stc);
goto E0; 

E0:

if(stc[p]=='a'){ 
p++;
goto E1;
} 
 
else if(stc[p]=='b') { 
goto REJEITA();
} 
 
else if(stc[p]=='c') { 
goto REJEITA();
} 
 
E1:

if(stc[p]=='b'){ 
p++;
goto E2;
} 
 
else if(stc[p]=='a') { 
goto REJEITA();
} 
 
else if(stc[p]=='c') { 
goto REJEITA();
} 
 
E2:

if(stc[p]=='c'){ 
p++;
goto E2;
} 
 
else if(stc[p]=='a') { 
goto REJEITA();
} 
 
else if(stc[p]=='b') { 
goto REJEITA();
} 
 
} 