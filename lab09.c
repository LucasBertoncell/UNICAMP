/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: passagens de tempo e unidade da passagem---> 10 s 50 m 6 S 90 M
S	Graus	Movimento, em graus, do ponteiro de segundos.
M	Graus	Movimento, em graus, do ponteiro de minutos.
s	Segundos (tempo)	Número de movimentos do ponteiro de segundos.
m	Minutos (tempo)	Número de movimentos do ponteiro de minutos.


saida: Se Al não morre:
		SAIU
		HH:MM:SS

	   Se AL morre:
	   	MORREU
	   	HH:MM:SS
	  SE Al ENCONTRAR lagarta--->printf( lista de quem Al econtrou )

obs: 
Um mesmo personagens pode ser encontrado diversas vezes durante a jornada de Alice.
 Entretanto, para que haja dois encontros consecutivos com o mesmo personagem,
  o segundo encontro deve ocorrer pelo menos 60 segundos depois do primeiro.
Ao encontrar com uma lagarta, Alice nunca precisa listar mais do que 50 personagens.
Quando for necessário listar os personagens já encontrados, 
 seu programa deverá imprimir um espaço após cada caractere e uma quebra de linha no final da lista.
Um personagem ignorado não deve ser listado na lista de encontros.
Os momentos em graus são sempre múltiplos de 6.
No final da jornada de Alice, seu programa deve parar de processar a entrada.
Alice necessariamente sai ou morre exatamente uma vez em todos os testes.

O seu programa deve conter, no mínimo, sete funções além da main(). Os cabeçalhos dessas funções estão descritas no arquivo lab09.h.

Você pode implementar outras funções que desejar, além das que estão declaradas no arquivo lab09.h.
Exemplos

*/


#include <stdio.h>

unsigned int converter_graus(unsigned int entrada){

	/* VAI DAR SEGUNDOS OU MINUTOS */

	return entrada/6;
}


char qual_personagem(unsigned int min){
	char personagem = 'X';

	if (min == 7 || min == 30){

		personagem = 'R';

		}
	if (min == 23 || min == 25){

		personagem = 'V';

		}
	if (min == 9 || min == 48){

		personagem = 'L';

		}
	if (min == 34 || min == 55){

		personagem = 'M';

		}
	if (min == 15 || min == 50){

		personagem = 'D';

		}
	if (min == 42){

		personagem = 'C';

		}

	return personagem;
}

int rainha(unsigned int tempo){
	unsigned int win = 0;

	if(tempo/60 <= 42){

		win = 1;

	}
	return win;
}

int valete(unsigned int jogou_criquete, unsigned int ganhou_criquete){

	unsigned int morte = 0;

	if (jogou_criquete == 1 && ganhou_criquete == 0){
		morte = 1;
	}

	return morte;
}

int coelho(unsigned int jogou_criquete){

	unsigned int saiu = 0;

	if (jogou_criquete == 1){
		saiu = 1;
	}

	return saiu;
}

int imprimir_personagens(char personagens[], int numero){

	int i;

	for (i = 1; i <= numero; i++){

		printf("%c ", personagens[i] );
	}


	printf("\n");


return 1;

}



void imprimir_horario(unsigned int segundos){

	int minutos = 0, horas = 0;
		if (segundos >= 60){
			minutos += segundos/60;
			segundos %= segundos/60;
		}
		if (minutos >= 60){
			horas += minutos/60;
			minutos %= minutos/60;
		}


		if (horas < 10){
			printf("0%d", horas );
		}
		else {printf("%d", horas );}

		if (minutos < 10){
			printf(":0%d", minutos );
		}
		else {printf(":%d", minutos );}

		if (segundos < 10){
			printf(":0%d\n", segundos );
		}
		else {printf(":%d\n", segundos );}

		/*printf("%d:%d:%d\n", );*/
}

/*----------------------------------------------------------------------------------------------------------------------*/


int main (){

	unsigned int i,j, entrada, tempo = 0, jogou_criquete = 0, ganhou_criquete = 0;
	unsigned int segundos = 0, min = 0, cooldown = 0, ignorado = 0;
	int MORREU = 0, SAIU = 0, numero = 1;

	char tipo, personagens[60], personagemANT = '\0';
	/*
	 tempo marca o total da jornada
	 segundos e minutos podem ser resetados pelo M, marcam o relogio para sabermos qual_persoagem encontramos
	*/

	for (i = 0; i <= 100; i++){
		personagens[i] = '\0';
	}

	for (j = 0; j == 0;){
		scanf("%u %c", &entrada, &tipo);

		if(tipo == 's'){
			segundos += entrada;
			cooldown += entrada;

			tempo += entrada;
		}
		if(tipo == 'm'){
			segundos += 60*entrada;
			cooldown += 60*entrada;

			tempo += 60*entrada;
		}
		if(tipo == 'S'){
			segundos += converter_graus(entrada);
			cooldown += converter_graus(entrada);

			tempo += converter_graus(entrada);
		}
		if(tipo == 'M'){
			segundos += 60*converter_graus(entrada);
			cooldown += 60*converter_graus(entrada);

			tempo += 60*converter_graus(entrada);
		}
		/*
		MIN EM FUNÇAO DE SEC, PRA ANALISAR QUAL PERSONAGEM
		obs--min e sec são o relogio, servem pra ver onde estamos
     	tempo mede o tempo total a ser imprimido
		*/
		min = segundos/60;

		if (min >= 60){
			min %= 60;
		}


		/*printf("entradas: %u %c -- tempo: %u --- cooldown: %u\n",entrada,tipo, tempo, cooldown );
		printf("\nmin: %u\n", min );*/


		if(qual_personagem(min) != 'X'){

			personagens[numero] = qual_personagem(min);

			if (personagens[numero] == personagemANT && cooldown < 60){

				personagens[numero] = '\0';
				numero -=1;

			}
		personagemANT = personagens[numero];

		numero += 1;
		}

		/*printf("\nnumero =  %d   personagens[numero] = %c    personagens[]:%s\n",numero,personagens[numero],personagens );

-----------------------PERSONAGEMS EFECT -----------------------------------------------*/	

		if (qual_personagem(min) != 'X' && ignorado == 0){

			if (qual_personagem(min) == 'R'){
				jogou_criquete = 1;

				if (rainha(tempo) == 1){
				ganhou_criquete = 1;

				}				
			}

			if (qual_personagem(min) == 'V'){
				if (valete(jogou_criquete, ganhou_criquete) == 1){
					MORREU = 1;
				}

			}

			if (qual_personagem(min) == 'L'){

				numero = imprimir_personagens(personagens, numero);		

			}

			if (qual_personagem(min) == 'M'){

				segundos = 0;
				min = 0;

			}

			if (qual_personagem(min) == 'D'){

				ignorado = 1;

			}

			if (qual_personagem(min) == 'C'){

				SAIU = coelho(jogou_criquete);

				ignorado = 0;
		
			}

		else if (qual_personagem(min) != 'X'){

			ignorado = 0;
		}


		}


		if (cooldown >= 60){
			cooldown = 0;
		}


		if (MORREU != 0){

			printf("MORREU\n");
			j = 1;
			imprimir_horario(segundos);
		}
		if (SAIU != 0){

			j = 1;
			printf("SAIU\n");
			imprimir_horario(segundos);
		}

		
		
	}

return 0;
}


/*   gcc lab09.c -o lab09 -Wall -Werror -ansi -pedantic    */