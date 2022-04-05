/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: 
 r dimensao r x r da matriz
 n numero de buracos
 pares [a][b] n vezes (coord dos buracos)

saida:
 "exibir a matriz resultante da planificação,
 contendo todos os buracos representados por * e as casas vazias com um inteiro
 não negativo i representando o número de buracos nas 8 casas vizinhas."

exemplo:
5 
3 
1 1 
3 2 
5 3 

* 2 1 1 1 
2 2 1 0 1 
1 * 1 0 0 
1 2 2 1 0 
1 2 * 1 1 

*/

#include <stdio.h>

int main (){

	int r, n, l, c, i, a, b, matriz[102][102]; 
	/*
	O LIMITE É 100: EU COLOCO 102 DEVIDO AS LINHAS PARA COMPARAÇÕES DE BORDA
	*/

	scanf("%d", &r);
	if (r < 3){
		r = 3;
	}

	r += 1;
	/*
	MATRIZ R+1 x R+1 PARA COMPARAÇOES DE BORDA (normalmente seria )
	TODO R AGORA É = R+1
	*/


	for (l = 0; l < r; l++){
		for (c = 0; c < r; c++){
			matriz[l][c] = 0;
		}
	}
	l = 0;
	c = 0;

	/*
	tenho agora matriz r x r com entradas 0
	*/	

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf ("%d%d", &a, &b);
		matriz[a][b] = -1000;
	}

	/*
	em cada buraco, tenho na entrada da matriz r x r um numero < 0
	
	comparações 
	para cada entrada Aij verificamos o numero de int < 0 em:
	1 i+1  j
	2 i    j+1
	3 i+1  j+1
	4 i-1  j
	5 i    j-1
	6 i-1  j-1
	7 i-1  j+1
	8 i+1  j-1
	
	+ OS CASOS DE BORDA--->atribuo às entradas extra os valores adequados para comparação 
	*/
/*QUINAS*/
	matriz[0][0] = matriz[r-1][r-1];
	matriz[0][r] = matriz[r-1][1];
	matriz[r][0] = matriz[1][r-1];
	matriz[r][r] = matriz[1][1];

/*4 LADOS DA MATRIZ, TIRANDO AS 4 QUINAS*/
	for (l = 1; l < r; l++){
		matriz[l][0] = matriz[l][r-1]; /*lado esquerdo*/
	}
	l = 0;
	for (l = 1; l < r; l++){
		matriz[l][r] = matriz[l][1]; /* direito*/
	}
	l = 0;


	for (c = 1; c < r; c++){
		matriz[0][c] = matriz[r-1][c];  /*cima*/
	}
	c = 0;
	for (c = 1; c < r; c++){
		matriz[r][c] = matriz[1][c];  /*baixo*/
	}
	c = 0;
	


/*COMPARAÇÕES*/
	for (l = 1; l <= (r-1); l++){
		for (c = 1; c <= (r-1); c++){


			int k = c, j = l; /* PARA NÃO DEIXAR C+1 SER MAIOR QUE C? --> DESNESSESSARIO?*/

			if (matriz[j+1][c] < 0){
				matriz[l][c] +=1;}

			if (matriz[l-1][c] < 0){
				matriz[l][c] +=1;}

			if (matriz[l][k+1] < 0){
				matriz[l][c] +=1;}

			if (matriz[l][c-1] < 0){
				matriz[l][c] +=1;}

			if (matriz[j+1][c-1] < 0){
				matriz[l][c] +=1;}

			if (matriz[l-1][k+1] < 0){
				matriz[l][c] +=1;}

			if (matriz[j+1][k+1] < 0){
				matriz[l][c] +=1;}

			if (matriz[l-1][c-1] < 0){
				matriz[l][c] +=1;}				
		}

	}

	l = 0;
	c = 0;
	

	/*
	printo a matriz com \n entre colunas e \t entre linhas
	*/

	for (l = 1; l <= (r-1); l++){
		if (l != 1) {
			printf("\n");
		}
		for (c = 1; c <= (r-1); c++){
			if (matriz[l][c] < 0)
				printf("* ");
			else printf("%d ",matriz[l][c]);
		}
	}
	l = 0;
	c = 0;

	printf("\n");


return 0;
}


/*   gcc lab06.c -o lab06 -Wall -Werror -ansi -pedantic    */