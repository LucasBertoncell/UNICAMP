/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: ordenação de 52 cartas
		 x aposta

saldo inicial -- R$ 100

Naipe	Caracter
Espada (♠)	s
Copas (♥)	h
Paus (♣)	c
Ouros (♦)	d

J, K, Q = 10
A = 11 or 1
2 to 10(named 'D') = 2 to 10




saida:  mao do jogado \n
		mao final do crupie \n
		resultado do jogo
		saldo do jogador apos termino da rodada

(em uma linha)
A d K s J d Q s 4 c 8 d J s 3 c 2 c 4 d 6 s Q h 9 s 2 s 2 h 6 c 8 s A h J c 5 s A c K h 9 c 3 h 7 c Q d 6 h 4 h 
A s 7 d 8 h 9 d 7 h Q c 4 s K c 7 s K d 5 c 9 h 2 d 6 d D d 5 h 3 s D s D h J h 5 d D c 3 d 8 c

50

.--. .--.
|Ad| |Jd|
'--' '--'
.--. .--.
|Ks| |XX|
'--' '--'

 

BLACKJACK

R$ 175.00

-----------------------------------------------------------------------------------------------------------*/

#define TAMANHO_HAND 11
#define TAMANHO_BARALHO 52
#include <stdio.h>

int valor(char mao[]){

	int valor = 0, az = 0, i;

	for(i = 0; i < TAMANHO_HAND*2; i+=2){/*VERIFICO SÓ AS CARTAS, NÃO OS NAIPES*/
		if (mao[i] == '\0' || mao[i] == 'X'){
			i = 100;
		}
		else if (mao[i] == 'K' || mao[i] == 'Q' || mao[i] == 'J' || mao[i] == 'D' ){
				valor += 10;
		}
		else if(mao[i] == 'A'){
				valor+=11;
				az = 1;
		}

		else{ 
			if (mao[i] == '2'){
				valor += 2;
			}
			if (mao[i] == '3'){
				valor += 3;
			}
			if (mao[i] == '4'){
				valor += 4;
			}
			if (mao[i] == '5'){
				valor += 5;
			}
			if (mao[i] == '6'){
				valor += 6;
			}
			if (mao[i] == '7'){
				valor += 7;
			}
			if (mao[i] == '8'){
				valor += 8;
			}
			if (mao[i] == '9'){
				valor += 9;
			}
		}
	}
	if (az == 1 && valor == 11){
		az = 0;
	}

	if (az == 1 && valor > 21){/* HARD HAND*/
		valor -= 10;
		az = 0;
	}

	if (az == 1 && valor < 21){ /*SOFT - HAND*/
		valor *= (-1);
	}
	return valor;
}

int basicStrategy(char maoJogador[], int valorCartaCrupie){

	int J, action = 0; /* VERIFICO SE HOUVE DD OU STAND, else --> HIT */
	J = valor(maoJogador);

	if (J < 0){/*----tem um SOFTHAND (valor é -)*/

		J *= (-1);

		if (valorCartaCrupie == 2 || valorCartaCrupie == 7 || valorCartaCrupie == 8){
			if ( J >= 17 && J <= 20){
				action = 2;
			}	
		}
		else if (valorCartaCrupie == 3){
			if (J == 17 || J == 18){
				action = 1;
			}
			else if (J == 19 || J == 20){
				action = 2;
			}
		}
		else if (valorCartaCrupie == 4 || valorCartaCrupie == 5 || valorCartaCrupie == 6){
			if ( J >= 12 && J <= 18){
				action = 1;
			}
			else if (J == 19 || J == 20){
				action = 2;
			}
		}

		else if (valorCartaCrupie == 9 || valorCartaCrupie == 10 || valorCartaCrupie == 11){
			if ( J == 19 || J == 20){
				action = 2;
			}
		}
	}


	else if (J > 0){/*mao sem AZ*/

		if (valorCartaCrupie >= 2 && valorCartaCrupie <= 6){
			if ( J >= 12 && J <= 20){
				action = 2;
			}
			if (valorCartaCrupie >= 3 && valorCartaCrupie <= 6){
				if ( J >= 9 && J <= 11){
					action = 1;
				}
			}
		}
		if (valorCartaCrupie >= 3 && valorCartaCrupie <= 6){
			if ( J >= 9 && J <= 11){
				action = 1;
			}
		}
		else if (valorCartaCrupie >= 7 && valorCartaCrupie <= 11){
			if ( J >= 17 && J <= 20){
				action = 2;
			}
		}
	}
	if (J == 21){
		action = 2;
	}

	return action;
}

void hit(char baralho[], char mao[]){ /* BARALHO JA FOI PUXADO ATÉ [7]--> baralho[7] == \0---->BARALHO[8] É A PRIMEIRA*/

	int cartaAtual = 0, LocalNaMao = 0, i;
	char carta, naipe;

	for( i = 8; i < 104; i++){ /* ACHO ONDE ESTA A PROXIMA CARTA E ZERO ESTA CARTA DEPOIS*/
		if (baralho[i] != '\0'){
			cartaAtual = i;
			i = 1000;
		}
	}

	carta = baralho[cartaAtual];
	naipe = baralho[cartaAtual + 1];

	baralho[cartaAtual] = '\0';
	baralho[cartaAtual + 1] = '\0';

	for( i = 0; i < 104; i++){ /* ACHO ONDE DEVO COLOCAR A CARTA */
		if (mao[i] == '\0'){
			LocalNaMao = i;
			i = 1000;
		}
	}
	mao[LocalNaMao] = carta;
	mao[LocalNaMao+1] = naipe;
}

int crupie(char baralho[], char mao[]){

	int i;

	for ( i = 0; i < 20; i++){

		if ( valor(mao) < 0 && valor(mao) >= -17){

			hit(baralho, mao);
		}

		if (valor(mao) > 0 && valor(mao) <= 17){

			hit(baralho, mao);

		}

		else {

			i = 30;
		}
	}

	return valor(mao);
}

int blackjack(char mao[]){

	int yes = 0;

	if (mao[0]=='A'){
		if (mao[2] == 'K' || mao[2] == 'Q' || mao[2] == 'J' || mao[2] == 'D'){
			yes = 1;
		}
	}

	if (mao[2]=='A'){
		if (mao[0] == 'K' || mao[0] == 'Q' || mao[0] == 'J' || mao[0] == 'D'){
			yes = 1;
		}
	}

	return yes;

}

void printCards(char mao[]){

	int i;

	for(i = 0; i < TAMANHO_HAND*2; i+=2){ /* PRINTARA ATE 11 VEZES, CHECANDO CADA i(NAIPE OU CARTA)*/
		if (mao[i] == '\0'){
			i = 100;
		}
		else printf(".--. ");
	}
	printf("\n");

	for(i = 0; i < TAMANHO_HAND*2; i+=2){/*PRINTARA ATE 11 VEZES, ..*/

		if (mao[i] == '\0'){
			i = 1000;
		}
		else printf("|%c%c| ", mao[i], mao[i+1]);
	}

	printf("\n");

	for(i = 0; i < TAMANHO_HAND*2; i+=2){

		if (mao[i] == '\0'){
			i = 1000;
		}
		else printf("'--' ");	
	}
	printf("\n");

}


/*------------------------------------------------lab10.h-------------------------------------------------------*/

int main (){
	float saldo = 100, aposta = 0;
	int i, valorCartaCrupie=0, estourou = 0, ValorJ = 0;
	char maoJogador[TAMANHO_HAND*2], maoCrupie[TAMANHO_HAND*2], segundaCardCrupie, segundoNaipeCrupie, baralho[110]; 
	/*TAMANHO_HAND*2 pois devo guardar o naipe tbm*/


	for ( i = 0; i < TAMANHO_HAND*2 ; i++){
		maoJogador[i] = '\0';
	}
	for ( i = 0; i < TAMANHO_HAND*2 ; i++){
		maoCrupie[i] = '\0';
	}
	for ( i = 0; i < 110; i++){
		baralho[i] = '\0';
	}


	for ( i = 0; i < 103; i+=2){

		scanf("\n%c %c ", &baralho[i], &baralho[i+1]);

	}
	/*printf("\nBARALHO: %s \n", baralho);*/

	scanf("%f", &aposta);

	/*printf("\nAPOSTA = %.2f\n", aposta);*/
	/*o baralho[] estará em pares CARTA seguido do seu NAIPE, de 0-->103 (numeros serao salvos como char)*/

	/*ORDEM DE DAR CARTAS:(inicialmente) jogador recebe [0,1,  4,5] 
										 crupie recebe [2,3, 6,7]
	
	PRIMEIRA 4 CARTAS DADAS:
	*/ 
	maoJogador[0] = baralho[0];
	maoJogador[1] = baralho[1];
	maoJogador[2] = baralho[4];
	maoJogador[3] = baralho[5];

	maoCrupie[0] = baralho[2];
	maoCrupie[1] = baralho[3];
	maoCrupie[2] = 'X';
	maoCrupie[3] = 'X';

	baralho[0] = '\0'; /* ESSAS CARTAS FORAM PUXADAS--> ZERO ELAS*/
	baralho[1] = '\0';
	baralho[2] = '\0';
	baralho[3] = '\0';
	baralho[4] = '\0';
	baralho[5] = '\0';
	segundaCardCrupie = baralho[6]; /*SERÁ USADA SE CRUPIE VIRAR SUA CARTA XX*/
	segundoNaipeCrupie = baralho[7];
	baralho[6] = '\0';
	baralho[7] = '\0';

	/*printf("\n blackjack(maojogador) = %d \n", blackjack(maoJogador));
	printf("\n maoCrupie[4] e [3]: %c %c maoCrupie: %s \n", maoCrupie[4], maoCrupie[3], maoCrupie );
	printf("\n maoJogador: %s \n", maoJogador );*/
	/*CASO 1*/
	if (blackjack(maoJogador) == 1){ /*SE DER BLACKJACK DE PRIMEIRA, J TEM 2 CARTAS E O C TEM UMA + XX*/

		printCards(maoJogador);
		printf("\n");
		printCards(maoCrupie);

		saldo += 1.5*aposta;
		printf("\nBLACKJACK\nR$ %.2f\n", saldo);

	}
	/*CASOS SEGUINTES(nao houve blackjack de primeira)*/

	else {
		/*VEZ JOGADOR-------------------------------------------
		*/

		valorCartaCrupie = valor(maoCrupie);/* VAI DE 2 ATE 11*/
		/*printf("\n valorMaoJ : %d basicstrategy: %d\n",valor(maoJogador) , basicStrategy(maoJogador, valorCartaCrupie));
		printf("\n valorCartaCrupie = %d\n", valorCartaCrupie );*/
		while( basicStrategy(maoJogador, valorCartaCrupie) != 2 && estourou == 0){

			if(basicStrategy(maoJogador, valorCartaCrupie) == 0){

					hit(baralho,maoJogador);

			}

			else if(basicStrategy(maoJogador, valorCartaCrupie) == 1){

				if (aposta*2 <= 100){

					aposta = aposta*2;

					hit(baralho,maoJogador);
				}
				else{

					hit(baralho,maoJogador);

				}
			}

			if (valor(maoJogador) > 21){
				estourou = 1;
			}
			
		}
		
		/*printf("\n valorCartaCrupie dps = %d\n", valorCartaCrupie );
		printf("\n basicstrategy = %d\n", basicStrategy(maoJogador, valorCartaCrupie) );*/

		if (estourou == 0){

			/*
			VEZ DO CRUPIE-----------------------------------------

			começa revelando sua carta XX e avaliando seu valor
			DEPOIS FARA HITS ATE valor(maoCrupie) >= 17
			*/
			maoCrupie[2] = segundaCardCrupie;
			maoCrupie[3] = segundoNaipeCrupie;

			/*printf("\nmaocrupie[3] [4]: %c %c os segund: %c %c\n",maoCrupie[3], maoCrupie[4], segundaCardCrupie, segundoNaipeCrupie );
			printf("\n maocupie: %s \n", maoCrupie );*/

			valorCartaCrupie = crupie(baralho, maoCrupie);

		

		}
		/*printf("\nvalorCartaCrupie: %d\n", valorCartaCrupie);
		printf("\n maoCrupie AFTER: %s \n", maoCrupie );*/

		/*	AVALIANDO PONTUAÇÕES--> 
		JOGADOR ESTOUROU
		CRUPIE ESTOUROU
		EMPATE
		JOGADOR VENCEU
		CRUPIE VENCEU
		 + SALDO DO JOGADOR*/
		/*printf("\n ValorJ: %d\n", ValorJ );
		printf("\n valorCartaCrupie: %d  valor(maoCrupie) %d\n", valorCartaCrupie, valor(maoCrupie) );*/
		if (valorCartaCrupie < 0){
			valorCartaCrupie *= (-1);
		}

		if (valor(maoJogador) < 0){
			ValorJ = valor(maoJogador) * (-1);/*ANULANDO O (-) DOS SOFTHAND*/
		}
		else{
			ValorJ = valor(maoJogador);
		}


		if (estourou == 1){
			saldo -= aposta;

			printCards(maoJogador);
			printf("\n");
			printCards(maoCrupie);
			printf("\nJOGADOR ESTOUROU\nR$ %.2f\n", saldo);
		}
		else if (valorCartaCrupie > 21){
			saldo += aposta;

			printCards(maoJogador);
			printf("\n");
			printCards(maoCrupie);
			printf("\nCRUPIE ESTOUROU\nR$ %.2f\n", saldo);
		}
		else if (ValorJ == valorCartaCrupie){
			saldo = 100;

			printCards(maoJogador);
			printf("\n");
			printCards(maoCrupie);
			printf("\nEMPATE\nR$ %.2f\n", saldo);
		}
		else if ((21 -ValorJ) < (21 - valorCartaCrupie)){
			saldo += aposta;

			printCards(maoJogador);
			printf("\n");
			printCards(maoCrupie);
			printf("\nJOGADOR VENCEU\nR$ %.2f\n", saldo);
		}
			else if ((21 -ValorJ) > (21 - valorCartaCrupie)){
			saldo -= aposta;

			printCards(maoJogador);
			printf("\n");
			printCards(maoCrupie);
			printf("\nCRUPIE VENCEU\nR$ %.2f\n", saldo);
		}
	}

return 0;
}
/*   gcc lab10.c -o lab10 -Wall -Werror -ansi -pedantic    */