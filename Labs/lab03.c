/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada:numero de "k" passos
		passo 1 (33 S)
		passo 2 (50 O)
		..ate passo k ()
		numero x de estrelas
		coordenadas da estrela 1 ( 50 N 150 L) 
		coordenadas da estrela 2 ( 88 S 10 O)
		... ate estrela x ()

saida:  coordenada final depois de n passos
		Se a coordenada final estiver:  na coordenada de uma estrelha, ou a -10 O da estrela, printf "Mapa Correto"
										se não, printf "Mapa Incorreto"

*/

#include <stdio.h>

int main (){

	int k, contadorK = 0,     x, contadorX = 0,    m = 50, n = 50,      passos, mapacorreto = 0;
	char mDIR = 'N', nDIR = 'O', dirpassos;

scanf("%d", &k);


/* Aplico cada coordenada scaneada(passos e dirpassos) ao mfinal e nfinal (começando no m = 50 e n = 50)
dependendo das direções mDIR e nDIR havera SOMA ou SUBTRAÇÃO
*/
while (k > contadorK){


	scanf("%d %c", &passos , &dirpassos);


	if (dirpassos == 'O' || dirpassos == 'L'){

		if ( dirpassos == nDIR ){
			n += passos;
		}
		else {
			n -= passos;
		}


		if (n == 180){
			nDIR = 'O';
		}

		if (n == 0){
			nDIR = 'L';
		}



		/* situações onde passamos por '180 O' e '0 L', invertendo  O ou L*/
		if (n > 180 ){
			int resto = 0;

			if (nDIR == 'O'){ nDIR = 'L';}
			else { nDIR = 'O';}

			resto = n % 180;
			n = 180;
			n -= resto;     /* n = n - resto*/
		}
		

		if ( dirpassos == 'L' ){


		}

		if (n < 0){
			if (nDIR == 'O'){ nDIR = 'L';}
			else { nDIR = 'O';}

			n *= (-1);  /* n = -n, pra anular o negativo*/
		}

		

	}






	if (dirpassos == 'N' || dirpassos == 'S'){

		int resto2 = 0;

		if ( dirpassos == mDIR ){
			m += passos;
		}
		else {
			m -= passos;
		}

		if (m < 0){
			if (mDIR == 'N'){ mDIR = 'S';}
			else { mDIR = 'N' ;}
			m *= (-1);  /* n = -n, pra anular o negativo*/
		}

		if (m > 90){ /*nesse caso, passa-se por cima de um dos polos (N ou S), trocando lados O e L*/

			resto2 = m % 90;
			m = 90;
			m -= resto2;
			/*como passamos pelo polo, o que era antes ,por exemplo,  'x O' torna-se '|x-180| L' e vice versa'*/
			n -= 180;
			n *= (-1);
			if (nDIR == 'O'){ nDIR = 'L';}
			else { nDIR = 'O';}

		}

		if (m == 0){
			mDIR = 'N';
		}


	}



	contadorK += 1;

}  /* agora tenho minhas coordenadas n e m finais */


scanf ("%d", &x);

while (x > contadorX){
	int mstar = 0, nstar = 0 ;
	char mstarDIR , nstarDIR;

	/*star e stardir são resetados a cada ciclo do while,
	 comparando cada coordenada de estrela dada com as minhas coord finais,

	 sinalizando um 1 se estiverem no mesmo lugar (mstar == m && nstar == n && mstarDIR == mDIR && nstarDIR == nDIR), 
	 ou se (mstar == m && mstarDIR == mDIR      && (nstarDIR ==( 'O' && n == (10 + nstar)  ) || nstarDIR == ( )
	*/
	scanf("%d %c %d %c", &mstar, &mstarDIR, &nstar, &nstarDIR);

	if ( mstar == m && mstarDIR == mDIR) {

		if ( nstarDIR == nDIR && nstar == n){

			mapacorreto = 1;

		}

		if ( nstarDIR == 'O' && nDIR == 'O' && (n + 10) >= nstar && nstar > n){

			mapacorreto = 1;
		}

		if ( n == 0 && nstar <= 10){

			mapacorreto = 1;
		}

		if ( nstarDIR == 'L' && nDIR == 'L' && n > nstar && nstar >= (n - 10)){

			mapacorreto = 1;
		}


		if ( nstarDIR == 'O' && nDIR == 'L' && (n - 10) < 0 ){

			int nstarO;
			nstarO = (10 - n);

			if ( nstarO >= nstar ){

			mapacorreto = 1;}


		}
		/*para cubrir os casos de n - 10 = negativo,ou seja, que n < 10 que os IFs passados nao cobrem
		A ESTRELA ESTA NO OESTE E EU TO NO LESTE*/

		if (nDIR == 'O' && nstarDIR == 'L' && n >= 171 && /* 171 -> 180*/ nstar >= 170 /*de 170 -> 179*/){

		int distanciaAteO, distanciaAteL, distanciaTot;

  		distanciaAteO = 180 - n;
  		distanciaAteL = 179 - nstar;
  		distanciaTot = distanciaAteL + distanciaAteO;
  			if ( distanciaTot <= 10 ){

  				mapacorreto = 1;
  			}
  			
		}
		/*se eu estiver no O e star no L -- de 171 O a 170 L -- */

	}

contadorX++;
}



printf ("%d %c %d %c\n", m, mDIR, n, nDIR); /*MINHAS COORD*/

if (mapacorreto == 1){
	printf ("Mapa Correto\n");

}
else {
	printf("Mapa Incorreto\n");
}


return 0;
}


/*   gcc lab03.c -o lab03 -Wall -Werror -ansi -pedantic    */