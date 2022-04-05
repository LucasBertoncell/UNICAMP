/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

as seguintes n linhas, cada uma, estão no formato i p m h1, h2, ..., hm, tal que i é o número identificador da habilidade, p é o nível de pré-requisito, m é o número 
de filhos da habilidade i, e h1, ..., hm são as m habilidades filhas de i; a linha seguinte contém o número na ≤ n de habilidades alvo,
 seguida de na linhas, cada uma no formato ia pa, tal que ia é o identificador da habilidade alvo, e pa, o nível alvo da habilidade ia.
Seu programa deve imprimir o nível final mínimo de cada habilidade, em ordem de identificador, e o total de níveis necessários para atingir a proficiência desejada 
nas habilidades alvo. Considere que todas as habilidades começam no nível 0. 

entrada: n<= 100 numero de habilidades
		 n linhas com    i id_habilidade
		 				 p nv_prereq
		 				 m n_filhos
		 				 h1, h2, ..., hm filhos
		 na <= n habilidades alvo
		 na linhas com   ia id_alvo
		 				 pa nivel_alvo 

saida: nivel final minimo de cada n habilidade na ordem dada
	   n_total para atingir id_alvo no nivel_alvo



6

1 0 2 2 3

2 4 1 4

3 3 2 5 6

4 1 0

5 2 0

6 3 0

2

4 3

6 2

ID: 1    Niv: 4

ID: 2    Niv: 1

ID: 3    Niv: 3

ID: 4    Niv: 3

ID: 5    Niv: 0

ID: 6    Niv: 2

TOTAL: 13



A impressão dos atributos pedidos pode ser feita pelo comando printf("ID: %d\tNiv: %d\n", arvore[i].id, arvore[i].nivel);, para a i-ésima habilidade do vetor arvore.


*/

#include <stdio.h>

typedef struct habilidade {

    int id;
    int nivel;
    int habilidade_pre_req; /* NAO SERA SCANEADO, é baseado nos m filhos*/
    int nivel_pre_req;
    int n_filhos;
    int filhos[5];

} habilidade; /* definindo 'struct habilidade' como só 'habilidade' */ 



int index_do_pai(habilidade arvore[],int numeroDaArvFilho, int n ){ /* com o []index de uma habilidade filho---> acha o pai
*/

	int localPai = 0 , i, j;

	for(i = 0; i < n; i++){

		if (arvore[i].n_filhos != 0){/* verifico cada filho*/

			for(j = 0; j < arvore[i].n_filhos; j++){

				if (arvore[i].filhos[j] == arvore[numeroDaArvFilho].id){

					localPai = arvore[i].id;
					j = 101;
					i = 101;
				}

			}

		}

	}

	return localPai;
}


int main (){ /*-------------------------------------------------------------------------------------------------*/

	habilidade arvore[100];
	int n, na, i, j, k, qual_hab, qual_nivel, total = 0;
	int filho, pai;


	scanf("%d", &n);

	/* INICIALIZO OS n STRUCTS CERTOS TERMOS COM ZEROS*/

	for(i = 0; i < n; i++){

		arvore[i].nivel = 0;
		arvore[i].habilidade_pre_req = 0;
		arvore[i].nivel_pre_req = 0;

	}


	printf("---n = %d\n", n);

	for(i = 0; i < n; i++){
		
		scanf("%d %d %d ", &arvore[i].id, &arvore[i].nivel_pre_req, &arvore[i].n_filhos);
		printf("-----%d %d %d\n", arvore[i].id, arvore[i].nivel_pre_req, arvore[i].n_filhos );

		if (arvore[i].n_filhos != 0){
		
			for (k = 0; k < arvore[i].n_filhos; k++){

				scanf( "%d", &arvore[i].filhos[k]);	

				printf(" ----arvore[i].filhos[k] = %d\n",arvore[i].filhos[k] );
			}
		}
	}

	/*busco qual id esta em cada arvore[i].filhos[k]  -- > essa habilidade tera habilidade_pre_req = arvore[i].id*/

	for(i = 0; i < n; i++){ /* percorro cada arvore*/

		if(arvore[i].n_filhos != 0){ /* vejo se tem ao menos 1 filho*/

			for (k = 0; k < arvore[i].n_filhos; k++){ /* percorro cada filho da arvore*/

				for(j = 0; j < n; j++){ /* percorro todos ids buscando qual é = ao filho */

					if( arvore[j].id == arvore[i].filhos[k] ){

						arvore[j].habilidade_pre_req = arvore[i].id; /* por ser FILHO DE ALGUMA HABILIDADE --> tem habilidade pre req >0 */

					}
				}
			}
		}
	}

	scanf("%d", &na);/*----------------HABILIDADES ALVO*/

		for (i = 0; i < na; i++){

			scanf("%d %d", &qual_hab, &qual_nivel);

			for(j = 0; j < n; j++){ /* busco qual habilidade é*/

				if (arvore[j].id == qual_hab){

					arvore[j].nivel = qual_nivel; 

					printf(" ---arvore[j].nivel = %d \n",arvore[j].nivel );
					/*
					marco aquela habilidade como estando no nivel alvo
					AGORA PRECISO AUMENTAR TAMBEM CADA HABILIDADE PAI RELACIONADA A arvore[j] até que arvore[x].nivelprereq == 0(habilidade raiz) 
					*/

					filho = j; 

					for (k = 0; k < n; k++){/* j--> posição do filho icialmente*/

						pai = index_do_pai( arvore, filho, n);

						if (arvore[pai].nivel < arvore[filho].nivel_pre_req){/* se isso não acontecer */

							arvore[pai].nivel = arvore[j].nivel_pre_req;

							filho = pai; /* agora verificamos os filhos do pai*/
						}
					
						/* continuo até achar uma habilidade com nivel_pre_req == o*/
						else if(arvore[filho].nivel_pre_req == 0){

							k = 101;
						}
					}
				}
			}
		}

	/*----------AGORA TENHO AS ARVORES PREENCHIDAS + AS HABILIDADES ALVO NO NIVEL DESEJADO
	--------------PRECISO UPAR a HABILIDADE PAI DE CADA FILHO ATÉ NIVEL nivel_pre_req

	for(i = 0; i < n; i++){  percorro cada arvore----i é o filho e idpai me dara o id do pai

		if (arvore[i].n_filhos != 0){ 


		}
	
	}
	*/




	/*somar todos os niveis pra saber o total necessario*/

	for(i = 0; i < n; i++){

		total += arvore[i].nivel;
	}


	for(i = 0; i < n; i++){

		printf("ID: %d\tNiv: %d\n", arvore[i].id, arvore[i].nivel);

	}

	printf("TOTAL: %d\n", total );

return 0;
}


/*   gcc lab13.c -o lab13 -Wall -Werror -ansi -pedantic    */