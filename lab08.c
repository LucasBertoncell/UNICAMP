/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: P3,b = base, h = altura, LIM no numero das componentes da cor (normalmente 255), 
			h LINHAS COM b*3 INTS 

saida: se ler AUG depois  UAG, UGA ou UAA nos mult de 7 --->printf do AUG até o UAG, UGA ou UAA
		se não---->printf ''Nao foi possivel encontrar uma fita de RNA valida.''

G	Par	Par
A	Par	Ímpar
C	Ímpar	Par
U	Ímpar	Ímpar

P3 
5 5 
255 
0   255 0   0   255 0   254 255 0   0   255 0   0   255 0   
0   255 0   255 255 1   255 255 0   255 255 0   1   255 0   
255 255 0   255 254 0   0   0   255 255 255 0   255 255 0   
0   255 0   255 255 0   255 255 0   255 255 0   0   255 0   
0   255 0   0   255 0   255 255 0   0   255 0   0   255 0   

Nao foi possivel encontrar uma fita de RNA valida

*/

#include <stdio.h>

int main (){
	int i, j = 0, k = 0, tres, b, h, lim, vet[270000], inicio=0, final=0, existeInicio=0, existeFinal=0, tamanhoS;
	char P, S[38573];
/* 
Tamanho maximo é 300 ints x 300 ints X 3 (270000 ints)
Outra possibilidade seria:como só leio multiplos de 7 (7, 14, 21 ... ), 90000/7 = 12857,14 = vet de 12858 ints
*/
	scanf(" %c%d", &P, &tres);

	if (P == 'P' && tres == 3){

		scanf("%d%d",&b,&h);
		scanf("%d", &lim);

		for (i = 0; i < 38573; i++){
			S[i] = '\0';
		}



		for (j = 0 ; j < (h*b*3); j++){

			scanf ("%d", &vet[j]);

		}

		for (i = 6; i < (b*h*3); i+=14){    /* a /7 sempre aproxima pro menor*/	

/*
TESTE DE PAR ou IMPAR:
if (num%2 == 0) num-->PAR
''0%2 = 0''
*/
			
			if (vet[i]%2 == 0 && vet[i+7]%2 == 0){

				S[k] = 'G';
				k += 1;

			}
			if (vet[i]%2 == 0 && vet[i+7]%2 != 0){

				S[k] = 'A';
				k += 1;

			}
			if (vet[i]%2 != 0 && vet[i+7]%2 == 0){

				S[k] = 'C';
				k += 1;
				
			}
			if (vet[i]%2 != 0 && vet[i+7]%2 != 0){

				S[k] = 'U';
				k += 1;
				
			}
		}
/*
AGORA TENHO UM S (exemplo:GUACCGGAAUGUGAGU)
DEVO ANALIZAR A STRING PARA ACHAR inicio e final 
AUG --> printar dele até UAG, UGA ou UAA
*/
		for (i = 0; i < 38573; i++){
			if (S[i] == '\0'){
				tamanhoS = i;
				i = 38575;
			}
		}
		
		for(i = 0; i <= tamanhoS; i++){

			if (S[i] == 'A' && S[i+1] == 'U' && S[i+2] == 'G'){
				inicio = i;
				i = 38575;
				existeInicio = 1;
			}
		}

		for(i = (inicio+3); i < tamanhoS - (inicio+3); i+=3){

			if (S[i] == 'U' && S[i+1] == 'A' && S[i+2] == 'G'){
				final = i+2;
				i = 38575;
				existeFinal = 1;
			}
			if (S[i] == 'U' && S[i+1] == 'G' && S[i+2] == 'A'){
				final = i+2;
				i = 38575;
				existeFinal = 1;
			}
			if (S[i] == 'U' && S[i+1] == 'A' && S[i+2] == 'A'){
				final = i+2;
				i = 38575;
				existeFinal = 1;
			}
		}
	
/*
AGORA AVALIO SE DE inicio A final TENHO UM CODON VALIDO
*/
		if (inicio < final && existeInicio == 1 && existeFinal == 1 ){


			for(i = inicio; i < (final - inicio); i+=3){

				printf("%c%c%c ",S[i], S[i+1], S[i+2]);

			}
			printf("\n");
		}

		else 
			printf("Nao foi possivel encontrar uma fita de RNA valida\n");
				
	}

return 0;
}


/*   gcc lab08.c -o lab08 -Wall -Werror -ansi -pedantic    */