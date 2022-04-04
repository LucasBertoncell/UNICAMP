#include <stdio.h>
#include <math.h>

int main (){

	int nIncertezas, i;
	float dYdincerteza[20], incerteza[20], soma=0;

	printf( "\n PROPAGAÇÃO DE ERRO -- incertezaY^2 = (dx/dy)^2 . incertezaX + (dz/dy)^2 + ...\nQuantas incertezas envolvidas na propagacao(max de 19):");
	scanf("%d", &nIncertezas);

	for(i = 0; i < nIncertezas; i++ ){

		printf("\nValor de dYdincerteza%d já calculado:", i);
		scanf("%f", &dYdincerteza[i]);

		printf("\nValor da incerteza%d:", i);
		scanf("%f", &incerteza[i]);
	}
	printf("\nDADOS:\n");
	for(i = 0; i < nIncertezas; i++){
		printf("dYdincerteza%d = %f   incerteza%d = %f  \n",i,dYdincerteza[i], i,incerteza[i] );
	}

	for(i = 0; i < nIncertezas; i++){
		soma+= pow(dYdincerteza[i],2)*pow(incerteza[i],2);
	}

	printf("\n\terro propagado de Y = %f\n", sqrtf(soma));


return 0;
}