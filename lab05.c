/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: n, tamanho do labirinto
		 x, numero de efeitos
		 {A, E, F, M, S} + posição do efeito  (no caso de S: + a posição que o portal leva)
		 s, numero de vezes que T e M se movem
		 s numeros, pra T 
		 s numeros, pra M

saida: printf "Fugio" ou "Morreu" + coordenada de morte
 ex:
6    n=6

2     x=2

M 2    martelo em coordenada 2

S 4 1     passagem de coord 4 pra coord 2

3          T e M tem 3 sprints

2 -1 1       

-1 -1 1

Fugiu

*/

#include <stdio.h>

int main (){
	int i,e, n, posiEfeito[99], x, destino[99], s, T, vetSdeT[99], PosiAnterior, M, vetSdeM[99], PosiAnteriorMino, morte = 0, martelo = 0;
	char efeito[99];


	scanf ( "%d", &n );
	T = n-1;
	M = 1;

	scanf( "%d", &x );

	for ( i = 0; i < x; i++){
		scanf ( " %c %d", &efeito[i], &posiEfeito[i] ); /*até 99 efeitos, guardados em cada i: 0 1 2 ...99*/

		if (efeito[i] == 'S'){
			scanf( "%d" , &destino[i] ); /*coord do destino do portal fica guardada na posição i do labirinto, sendo a posição que T vai*/
		}
	}
	i = 0;

	scanf ( "%d", &s); /* diz o numero de sprints*/

	for (i = 0; i < s; ++i) /*pega todos os S do Teseu e guarda cada um em seu indice do vet (0, 1, 2...max 99)*/
	{
		scanf( "%d", &vetSdeT[i] );
	}
	i = 0;

	for (i = 0; i < s; ++i) /*mesmo para os S do Minotauro */
	{
		scanf( "%d", &vetSdeM[i] );
	}
	i = 0;

	/*agora tenho:
	 posição de T = n-1
	 posição de M = 1
	 posições e Letras guaradadas em N e efeitos 
	 s numero de rodadas com numero de passos de T e M

	 agora faço s comparações. aplicando os efeitos(IFS), e checando toda vez se T morre (PASSA POR OU ACABA NA MESMA CASA QUE M)*/

	for (i = 0; i < s; ++i){
		PosiAnterior = T;
		T -= vetSdeT[i];

		if (T > n){
			T = n;    /*LIMITE DO LABIRINTO*/
		}
		if (T < 1){
			T = 1;


		if (morte == 0){

			if ((PosiAnterior > M && T < M) || (PosiAnterior < M && T > M)){
				morte = M;
			} 
			
		    if (morte == 0){

		    	/* ''Todo efeito deve necessariamente ser computado no final do sprint do Teseu, a menos que ele já esteja morto.
		    	Não há encadeamento de efeitos'' */

		    	for (e = 0; e < x; ++e){

		    		int desencadeou = 0;
					if (T == posiEfeito[e] && morte == 0 && desencadeou == 0){ /*	checa todas as posi com efeitos, se alguma for igual a T, procura qual efeito */


						if (efeito[e] == 'A'){
							vetSdeT[i+1] = 0;
							efeito[e] = 'X'; /* EFEITO SÓ VALIDO UMA VEZ POR POSIÇÃO*/
							desencadeou = 1;
						}

						if (efeito[e] == 'E'){
							if (M == T){
								morte = M;
							}
							T = PosiAnterior;
							desencadeou = 1;
						}

						if (efeito[e] == 'F'){
							if (vetSdeT[i+1] > 2){
								vetSdeT[i+1] = 2;
							}
							if (vetSdeT[i+1] < (-2)){
								vetSdeT[i+1] = -2;
							}

							if (vetSdeT[i+2] > 2){
								vetSdeT[i+2] = 2;
							}
							if (vetSdeT[i+2] < (-2)){
								vetSdeT[i+2] = -2;
							}
							efeito[e] = 'X';
							desencadeou = 1;
						}

						if (efeito[e] == 'M'){
							if (T == M){
								morte = M;
							}
							martelo = 1;
							desencadeou = 1;   
						}

						if (efeito[e] == 'S'){
							if (M == T){
								morte = M;
							}
							T = destino[e];
							desencadeou = 1;
						}

			    	} 
			    	
				}
				
				if ( T == M ){
					morte = M;
				}

				PosiAnteriorMino = M;
				M -= vetSdeM[i];
				if (M > n){
					M = n;
				}
				if (M < 1){
					M = 1;
				}
				if ((PosiAnteriorMino > T && M < T) || (PosiAnteriorMino < T && M > T) || M == T){
					morte = T;
				} 
			}

		}
	
	}

	if (morte == 0 || martelo == 1){
		printf("Fugiu\n");
	}
		
	
	else  printf( "Morreu\n%d\n", morte);

/*TESTE---   printf(" %d %c\n", posiEfeito[0],efeito[0] );*/
return 0;
}

/*  gcc lab05.c -o lab05 -Wall -Werror -ansi -pedantic    */