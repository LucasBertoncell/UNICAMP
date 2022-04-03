/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: pedagios A, B, C, D, E, F, G, H, I escritos como: pA pB ... pI

saida: menor custo possivel considerando tais pedagios \n 
	   SIM se a estrategia de 'escolher o proximo pedagio mais barato' levar ao menor custo possivel    ou    NAO se o caminho mais barato for outro

*/

#include <stdio.h>

int main(){
	float A,B,C,D,E,F,G,H,I,   c1, c2, c3, c4, c5, c6, Maria,minCusto;

	scanf("%f%f%f%f%f%f%f%f%f",&A,&B,&C,&D,&E,&F,&G,&H,&I);

	/*CUSTO MIN: soma dos 6 possiveis caminhos e comparação deles */

c1 = A + C + H;
c2 = A + C + G + I;
c3 = A + F + I;
c4 = B + E + H;
c5 = B + E + G + I;
c6 = B + D + I;


/*comparando os caminhos para ACHAR O MINCUSTO*/
if ( c1 <= c2 && c1 <= c3 && c1 <= c4 && c1 <= c5 && c1 <= c6){
	printf("%.2f\n", c1);
	minCusto = c1;}

	else if ( c2 <= c1 && c2 <= c3 && c2 <= c4 && c2 <= c5 && c2 <= c6){
	printf("%.2f\n", c2);
	minCusto = c2;}

		else if ( c3 <= c2 && c3 <= c1 && c3 <= c4 && c3 <= c5 && c3 <= c6){
		printf("%.2f\n", c3);
		minCusto = c3;}

			else if ( c4 <= c2 && c4 <= c3 && c4 <= c1 && c4 <= c5 && c4 <= c6){
			printf("%.2f\n", c4);
			minCusto = c4;}

				else if ( c5 <= c2 && c5 <= c3 && c5 <= c4 && c5 <= c1 && c5 <= c6){
				printf("%.2f\n", c5);
				minCusto = c5;}

					else if ( c6 <= c2 && c6 <= c3 && c6 <= c4 && c6 <= c5 && c6 <= c1){
					printf("%.2f\n", c6);
					minCusto = c6;}

	

/*MARIAS STRATEGY: comandos if para anular os valores maiores, para result = soma dos menores*/
	/*3 CAMINHOS POR A + 3 POR B*/
	if (B > A){ /*segue por A*/

		B = 0;
		E = 0;
		D = 0;

		if (C > F){ /*segue por F*/
			C = 0;
			G = 0;
			/*so pode seguir por I*/
			H = 0;} 
			      /* CAMINHO 1: soma de A F I */

		else { /*segue por C */

			F = 0;

			if (G > H){ /*por H*/

				G = 0;
				I = 0;}
					/*CAMINHO 2: soma de A C H*/
			else { /* segue por G*/

				H = 0;} /* so pode ir por I , CAMINHO 3: soma de A C G I*/

		}

	}

	else { /*segue por B*/

		A = 0;
		C = 0;
		F = 0;

		if (E > D){ /* c3: segue por D logo por I*/
			
			E = 0;
			H = 0;
			G = 0;}/*c4*/

		else { /*segue por E*/ 

			D = 0;

			if (G > H){ /*segue por H*/

				G = 0;
				I = 0;}/*c5*/

			else {

				H = 0;}/*c6*/

			}

	}


	
 Maria = A + B + C + D + E + F + G + H + I;



if ( Maria == minCusto ) 
	printf("SIM\n");
else 
	printf("NAO\n");



return 0;

}