/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: n aeroportos que serao atendidos no dia
		 n linhas com:
		  3 chars(codigo IATA) 
		 + m inteiro(numero de minutos necessários para partir de Campinas e voar até o aeroporto de destino)
		 + pida que representa o número de passageiros que devem ser transportados até aquela cidade
		 + pvolta que representa o número de passageiros que devem ser transportados daquela cidade até Campinas

saida: n linhas com:
		cada codigo IATA dos aeroportos na ordem 
	    seguido da aeroave a atende-lo (EMB-195 ou ERJ-145) \n
	   \n
	   total voado por ERJ-145
	   total voado por EMB-195
	   formato ---> printf("ERJ-145 %d minutos\nEMB-195 %d minutos\n", totalMinutosERJ, totalMinutosEMB);

3              IN
CWB 137 46 34
GYN 145 18 28
BSB 109 34 35

CWB EMB-195     OUT
GYN ERJ-145
BSB EMB-195

ERJ-145 290 minutos
EMB-195 492 minutos


OBS.:
ERJ-145 deve ser a aeronave que voa o menor tempo.
EMB-195 com capacidade para 124
EJR-145 com capacidade para 50

O número máximo de aeroportos atendidos em um dia é 10.
A Bird Air não pratica overbooking. O número máximo de bilhetes vendidos para uma rota, em um determinado dia, é 124.
Considere que os vôos sempre partem de Campinas, voam até o seu destino e voltam para Campinas, 
	e que uma cidade é atendida por apenas um vôo a cada dia.
Considere que o tempo para voar da cidade A até a cidade B é igual ao tempo de voar de B até A.
Não é necessário considerar o tempo que a aeronave fica em solo.
O único critério de desempate que você deve considerar está descrito na seção Tarefa.
Os testes garantem que não há mais do que uma resposta possível para uma mesma entrada.
Você deve implementar as funções cujos cabeçalhos estão descritos no arquivo lab11.h.
Após imprimir o resultado você deve inserir uma quebra de linha \n.
*/
#include <stdio.h>
#define MAX 10 /*Define o número máximo de cidades atendidas em um dia*/

/* Avalia Combinação                                                                                                    *
 * Objetivo:    Dada uma combinação atual, e a melhor combinação que já havia encontrado, determina se a                *
                nova combinação é melhor do que a melhor combinação que já havia encontrado.                            *
                Se sim, atualiza a melhor combinação, e o tempo atual das aeronaves.                                    *
 * Saída:       void                                                                                                    *
 * Parâmetros:                                                                                                          *
 *      - int *combinacao: apontador para o vetor que armazena a nova combinação que será avaliada                      *
 *      - int *melhorCombinacao: apontador para o vetor que armazena a melhor combinação que já foi avaliada            *
 *      - int *tempoVoo: apontador para o vetor que armazena os tempos de voos para cada destino                        *
 *      - int *paxIda: apontador para o vetor que armazena o número de passageiros que vão a todos os destinos          *
 *      - int *paxVolta: apontador para o vetor que armazena o número de passageiros que voltam de todos os destinos    *
 *      - int *tempoA: apontador para um inteiro que armazena o tempo percorrido pela aeronave A na melhor combinação   *
 *      - int *tempoB: apontador para um inteiro que armazena o tempo percorrido pela aeronave B na melhor combinação   *
 *      - int n: número de cidades atendidas naquele dia                                                                *
 */
void avaliaCombinacao(int *combinacao, int *melhorCombinacao, int *tempoVoo, int *paxIda, int *paxVolta, int *tempoA, int *tempoB, int n){

	int i, naoPossivel = 0, diferencaNew[11], diferencaMelhor[11];
	int dif = 0, difMelhor = 0;

	/*printf("\n n = %d   combinacao: ", n);
	for(i = 0; i < n; i++){
		printf("%d ", combinacao[i] );
	}
	printf("\nmelhorCombinacao: ");
	for(i = 0; i < n; i++){
		printf("%d ", melhorCombinacao[i] );
	}
	*/

	for(i = 0; i < n; i++){

		if((paxIda[i] > 50 || paxVolta[i] > 50) && combinacao[i] == 1){
			naoPossivel = 1;
			i = 100;
		}

		if (combinacao[i] == 0){ /* SE FOR 0 (A)--> POSITIVO   SE 1 (B)---> NEGATIVO  PRA TIRAR DIFERENÇA*/
			diferencaNew[i] = tempoVoo[i];
		}
		else {
			diferencaNew[i] = (-1)*tempoVoo[i];
		}
	}

	if(naoPossivel == 0){ /* SE A COMBINAÇÃO É POSSIVEL CONSIDERANDO OS N PASSAGEIROS*/

		for(i = 0; i < n; i++){

			if (melhorCombinacao[i] == 0){
				diferencaMelhor[i] = tempoVoo[i];
			}
			else {
				diferencaMelhor[i] = (-1)*tempoVoo[i];
			}
		}
		/*printf("diferencaMelhor: ");
		for(i = 0; i < n; i++){
				printf("%d ", diferencaMelhor[i] );
			}
		*/

		for(i = 0; i < n; i++){
			dif += diferencaNew[i];
			difMelhor += diferencaMelhor[i];

		}
		if (dif < 0){
			dif *= (-1);
		}
		if (difMelhor < 0){
			difMelhor*= (-1);
		}

		if (dif < difMelhor){ /*SE ENTRAR NO IF, NOVO melhorCombinacao FOI ENCONTRADO */
			*tempoA = 0;
			*tempoB = 0;
			for(i = 0; i < n; i++){

				if(combinacao[i] == 0){
					*tempoA += tempoVoo[i];
				}
				else{
					*tempoB += tempoVoo[i];
				}

				melhorCombinacao[i] = combinacao[i];
			}
			/*printf("tempo a: %d e b: %d\n", *tempoA, *tempoB);
			printf("dif: %d difmelhor: %d \n", dif, difMelhor);

			printf("\n---NOVA melhorCombinacao: ");
			for(i = 0; i < n; i++){
				printf("%d ", melhorCombinacao[i] );
			}
			*/
		}
	}
}


/* Próxima Combinação                                                                                                           *
 * Objetivo:    Determina qual a próxima combinação a ser avaliada                                                              *
 * Saída:       Um inteiro que indica que já foram percorridas todas as combinações possíveis, ou não                           *
 * Parâmetros:                                                                                                                  *
 *      - int *combinacao: apontador para o vetor que armazena a combinação que está sendo avaliada, e que deve ser atualizado  *
 *      - int n: número de cidades atendidas naquele dia                                                                        *
 */
int proxCombinacao(int *combinacao, int n){  /*tira a proxima combinação*/
	
	int end = 0, soma = 0, i;
	
	for(i = 0; i < n; i++){

		soma += combinacao[i];
	}

	if (soma != n){

		for(i = 0; i < n; i++){ /*POR SOMA BINARIA*/

			if (combinacao[i] == 0){
				combinacao[i] = 1;
				i = 100;
			}

			else {
				combinacao[i] = 0;
			}
		}
	}
	else {
		end = 1;
	}
	/*printf("end e soma: %d %d\n", soma, end );*/
	return end;
}

int main (){/*-------------------------------------------------------------------------------------------------------------------*/

	int n, aux = 0, i, j = 0, tempoVoo[MAX], paxIda[MAX], paxVolta[MAX];
	int combinacao[MAX], melhorCombinacao[MAX], tempoA, tempoB = 0; /* A = EMB   B = ERJ */ 
	char IATAs[35];

	scanf("%d", &n);

	for(i = 0; i < n; i++){/*COMO UM REGISTRO: guarda todas informações de cada n */

			scanf(" %c%c%c", &IATAs[j], &IATAs[j + 1], &IATAs[j + 2]);
			j+=3;
			scanf("%d %d %d", &tempoVoo[i], &paxIda[i], &paxVolta[i]);
			/*printf("tempoVoo [i]: %d\n",tempoVoo[i] );*/
	}

	for(i = 0; i < n; i++){ /* IDA E VOLTA*/
		tempoVoo[i] *= 2;
		/*printf("tempoVoo [i]: %d\n",tempoVoo[i] );*/
	}	

	/*INICIALIZANDO OS TEMPOS DAS AERONAVES: INICIALMENTE EMB VAI TER TODOS OS VOOS E ERJ NENHUM */
	for(i = 0; i < n; i++){
		tempoA += tempoVoo[i]; /* INICIALMENTE, NA PRIMEIRA COMB, A TEM TODOS VOOS (0,0,0,0,0,0,0,0)*/
		/*printf("tempoA: %d \n", tempoA);*/
	}
	for(i = 0; i < n; i++){
		combinacao[i] = 0;
	}
	for(i = 0; i < n; i++){
		melhorCombinacao[i] = combinacao[i]; /* PRIMEIRA COMB É A INICIALMENTE A MELHOR*/
	}

	while (proxCombinacao(&combinacao[0], n) == 0){

		avaliaCombinacao(&combinacao[0], &melhorCombinacao[0], &tempoVoo[0], &paxIda[0], &paxVolta[0], &tempoA, &tempoB, n);

		/*printf("\nFORA DA F melhorCombinacao: ");
			for(i = 0; i < n; i++){
				printf("%d ", melhorCombinacao[i] );
			}
		*/
	}
	if (tempoB > tempoA){
		aux = tempoA;
		tempoA = tempoB;
		tempoB = aux;

		for (i = 0; i < n; i++){
			if( melhorCombinacao[i] == 0){
				melhorCombinacao[i] = 1;
			}
			else{
				melhorCombinacao[i] = 0;
			}

		}
	}

	

	j = 0;
	 /* ENVOLVE: IATAs, melhorCombinacao, tempoA e tempoB */
	for (i = 0; i < n; i++){

		printf("%c%c%c ", IATAs[j], IATAs[j+1], IATAs[j+2]);
		j+=3;

		if (melhorCombinacao[i] == 0){
			printf("EMB-195\n");
		}
		if (melhorCombinacao[i] == 1){
			printf("ERJ-145\n");
		}
	}
	printf("\n");
	printf("ERJ-145 %d minutos\nEMB-195 %d minutos\n", tempoB, tempoA);

return 0;
}


/*  ??  //  ||  \\
\n

gcc lab11.c -o lab11 -Wall -Werror -ansi -pedantic    */