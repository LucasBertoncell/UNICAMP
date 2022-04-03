/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada:
A primeira linha da entrada é um inteiro n, maior que 0 e menor ou igual a 100, que representa o número de membros na
árvore genealógica da monarquia atual, seguido de n linhas contendo as informações de cada um dos membros da família real.

Cada membro é descrito por quatro elementos a, b, c e d, que são, respectivamente, 
o nome do membro,
a sua idade (representada por um inteiro entre 0 e 200),
o nome do seu ascendente e um inteiro 0 se ele estiver vivo ou 1 se ele estiver morto. 
As informações de cada membro são separadas por um ; da seguinte forma: nome; idade; ascendente; vivo_ou_morto. 
O primeiro membro da lista é o monarca atual.


saida:
O seu programa deve imprimir, para cada uma das pessoas que ainda estão vivas,
o número que representa a sua ordem de sucessão, seguido do seu nome e de uma quebra de linha.

11
Henrique, Duque de Gloucester;117;Alexandre Hore-Ruthven;0
Tane Lewis;5;Davina Lewis;0
Ricardo, Duque de Gloucester;73;Henrique, Duque de Gloucester;1
Rufus Gilman;5;Rosa Gilman;0
Xan Windsor;10;Alexandre Windsor;0
Senna Lewis;7;Davina Lewis;1
Alexandre Windsor;40;Ricardo, Duque de Gloucester;1
Cosima Windsor;7;Alexandre Windsor;0
Davina Lewis;41;Ricardo, Duque de Gloucester;1
Rosa Gilman;37;Ricardo, Duque de Gloucester;1
Lyla Gilman;7;Rosa Gilman;0

1) Tane Lewis
2) Xan Windsor
3) Cosima Windsor
4) Lyla Gilman
5) Rufus Gilman

obs: MELHOR PROGRAMA QUE JA FIZ ATE AGORA
*/

#include <stdio.h>
#include <string.h>

typedef struct tagmembro {
    char nome[64]; /*Nome*/
    int idade; /*Idade*/
    char antecessor_nome[64]; /*Nome do antecessor*/
    int vivo_ou_morto; /*Flag que indica se está vivo ou morto*/
    int antecessor_indice; /*Índice do antecessor*/
    int primeiro_filho; /*Índice do primeiro filho*/
    int segundo_filho; /*Índice do segundo filho*/
    int terceiro_filho; /*Índice do terceiro filho*/
} membro;



void Pecorre_Arvore(membro heir[],int indice , int* contador){

	if (heir[indice].vivo_ou_morto != 1 && indice != 0){/* SE ESTIVER VIVO E NÃO FOR O REI ATUAL--->print*/

		printf("%d) %s\n", *contador, heir[indice].nome );

		(*contador)+=1;
	}



	if (heir[indice].primeiro_filho != -1){/*PRIMEIRO PASSO PELO RAMO DO PRIMEIRO FILHO*/

		Pecorre_Arvore( heir, heir[indice].primeiro_filho, contador );


	}
	if (heir[indice].segundo_filho != -1){/*DEPOIS PELO RAMO DO SEGUNDO*/

		Pecorre_Arvore( heir, heir[indice].segundo_filho, contador );


	}
	if (heir[indice].terceiro_filho != -1){/*DEPOIS DO tERCEIRO*/

		Pecorre_Arvore( heir, heir[indice].terceiro_filho, contador );


	}

}



int main (){/*------------------------------------------------------------------------------------------------------------------------------------*/

	membro heir[100];
	int n, i, j, aux, um = 1, *counter = &um ;

	scanf("%d", &n);

	for (i = 0; i < n; i++){

		scanf(" %[^;];%d;%[^;];%d", heir[i].nome, &heir[i].idade, heir[i].antecessor_nome, &heir[i].vivo_ou_morto);

	}

	/*for (i = 0; i < n; i++){

		printf("-----%s, %d, %s, %d\n", heir[i].nome, heir[i].idade, heir[i].antecessor_nome, heir[i].vivo_ou_morto);
	}*/

	/* antecessor_indice*/

	for(i = 0; i<n; i++){

		heir[i].primeiro_filho = -1;
		heir[i].segundo_filho = -1;
		heir[i].terceiro_filho = -1;
	}

	/* ACHANDO OS INDICES

	sim, ficou difcil de entender essa parte, mas com o desenho da arvore de possibilidades feita preferi escrever por esse caminho*/

	for(i = 0; i<n; i++){ /* pego cada heir[i] */

		for(j = 0; j<n; j++){ /* comparo com todos heirs, ou seja, cada heir[j] */

			if(strcmp(heir[i].antecessor_nome, heir[j].nome) == 0){   /*se forem iguais--> heir[i] é filho de heir[j] */

				heir[i].antecessor_indice = j;




				/* INDICES DOS FILHOS*/
				if( heir[j].primeiro_filho == -1 ){/*nao tinha primeiro filho listado*/

					heir[j].primeiro_filho = i;
				}

				else {/* ja tinha primeiro filho listado*/

					if( heir[heir[j].primeiro_filho].idade < heir[i].idade ){/*entro se esse for mais novo que o i*/

						aux = heir[j].primeiro_filho;
						heir[j].primeiro_filho = i;

						if( heir[j].segundo_filho == -1 ){ /*nao tem segundo filho listado*/

							heir[j].segundo_filho = aux;
						}

						else{/* ja tem segundo filho listado --> verifico se heir [aux] é mais velho que heir [segundofilho]*/

							if( heir[aux].idade > heir[heir[j].segundo_filho].idade){

								heir[j].terceiro_filho = heir[j].segundo_filho;
								heir[j].segundo_filho = aux;
							}

							else{
								heir[j].terceiro_filho = aux;
							}
						}		
					}

					else{/*ja tinha primeiro filho --->primeiro filho era mais velho que o i*/

						if( heir[j].segundo_filho == -1 ){

							heir[j].segundo_filho = i; 
						}

						else{/* tem segundo filho listado --> verifico se heir [i] é mais velho que heir [segundofilho]*/

							if( heir[i].idade > heir[heir[j].segundo_filho].idade){

								heir[j].terceiro_filho = heir[j].segundo_filho;
								heir[j].segundo_filho = i;
							}

							else{
								heir[j].terceiro_filho = i;
							}
						}
					}
				}
			} 
		}
	}

	/*printf("\ncounter = %d\n", *counter );*/

	Pecorre_Arvore( heir, 0, counter); /* percorre toda arvore fazendo os prints, começando no Rei( indice 0) */
	printf("\n");
	
return 0;

}

/**/
/*  gcc lab14.c -o lab14 -Wall -Werror -ansi -pedantic    */