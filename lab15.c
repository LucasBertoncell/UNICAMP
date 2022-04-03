/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada:

saida:


2
################################
#                      #       #
#  X     #      #              #
##########      ########       #
#    #          #  #           #
#    #          #  #   #########
#    #########  #  #           #
#    #          #  #           #
#    #    #######  #########   #
#    #             #      #    #
#    #      #   #  #      #    #
#  ###   ########  #           #
#               #  #########   #
##############  #              #
#       A       #  #      B    #
################################
################################
#        #              #      #
#        #      #              #
##########      ########       #
#    #          #  #           #
#  A #          #  #   #########
####################      #    #
#    #    B     #              #
#    #    #######  ###  ###    #
#    #             #      ## ###
#    #      #   #  #           #
#  ###   ###########      #    #
#               #  ## ##########
# ###############        #     #
#               #  #     #     #
################################
################################
#        #              #      #
#        #      #              #
### ######      ########       #
#    #          #  #           #
#    #          #  #   #########
#    ######## ######      #    #
#    #          #              #
#    ############  ###  ###    #
#    #             #      ## ###
#    #      #   #  #           E
#  ###   ###########      #    #
#               #  ## ##########
# ###############        #     #
#               #  #     #     #
################################
Terreo: Saida Encontrada

Andar 1: Passagem B

Andar 2: Passagem A

*/



#include <stdio.h>


void Acha_coord_letra(int letra, int* point_linha, int* point_coluna, char labirinto[16][32]){

	int i, j;

	for( i = 0; i < 16; i++){

		for( j = 0; j < 32; j++){

			if (labirinto[i][j] == letra){

				*point_linha = i;
				*point_coluna = j;

			}
		}
	}
}

void limpa_copia(char copia[30][16][32], char labirinto[30][16][32] ){

	int level, linha, coluna;
	for(level = 0; level < 30; level++){

		for(linha = 0; linha < 16; linha++){ /*TODA CHAMADA DEVE TER A COPIA LIMPA*/

			for(coluna = 0; coluna < 32; coluna++){

				copia[level][linha][coluna] = labirinto[level][linha][coluna];
			}	
		}
	}
}



int Existe_caminho_para_letra(char letra, int linhaAtual, int colunaAtual, char labirinto[16][32], char copia_labirinto[16][32]){/*passo copia do labirinto  retorna 1 se tem     retorna 0 se nao */
	
	int possivel = 0;



	if(labirinto[linhaAtual][colunaAtual] == letra){

		possivel = 1;

	}

	else {


		copia_labirinto[linhaAtual][colunaAtual] = 's';

		if(linhaAtual+1 < 16){

			if(labirinto[linhaAtual+1][colunaAtual] != '#' && copia_labirinto[linhaAtual+1][colunaAtual] != 's'){  /*ao acertar parede, o ramo para, retornando 1 para aquele ramo*/

				possivel = Existe_caminho_para_letra(letra, linhaAtual+1, colunaAtual, labirinto, copia_labirinto);
			}		
		}


		if(possivel == 0 && linhaAtual-1 >= 0){

			if(labirinto[linhaAtual-1][colunaAtual] != '#' && copia_labirinto[linhaAtual-1][colunaAtual] != 's'){  /*ao acertar parede, o ramo para, retornando 1 para aquele ramo*/

				possivel = Existe_caminho_para_letra(letra, linhaAtual-1, colunaAtual, labirinto, copia_labirinto);
			}
		}


		if(possivel == 0 && colunaAtual+1 < 32){
			if(labirinto[linhaAtual][colunaAtual+1] != '#' && copia_labirinto[linhaAtual][colunaAtual+1] != 's'){  /*ao acertar parede, o ramo para, retornando 1 para aquele ramo*/

				possivel = Existe_caminho_para_letra(letra, linhaAtual, colunaAtual+1, labirinto, copia_labirinto);
			}
		}

		if(possivel ==0 && colunaAtual-1 >= 0){
			if(labirinto[linhaAtual][colunaAtual-1] != '#' && copia_labirinto[linhaAtual][colunaAtual-1] != 's'){  /*ao acertar parede, o ramo para, retornando 1 para aquele ramo*/

				possivel = Existe_caminho_para_letra(letra, linhaAtual, colunaAtual-1, labirinto, copia_labirinto);
			}
		}

	}

return possivel;
}



int Printando_Passagens(char labirinto[30][16][32],char copia[30][16][32], int n, int i, int linha, int coluna){/* i é sempre o andar onde estou */

	int possivel = 0, *linhaA, *colunaA, *linhaB, *colunaB, linA, linB, colB, colA;

	linhaA = &linA;
	colunaA = &colA;
	linhaB = &linB;
	colunaB = &colB;


	/*limpa_copia(copia, labirinto);

	printf("andar: %d-----linha %d  coluna %d    existe E---%d\n",i, linha, coluna, Existe_caminho_para_letra('E', linha, coluna, labirinto[i], copia[i]));*/

	limpa_copia(copia, labirinto);

	if(i == 0 && Existe_caminho_para_letra('E', linha, coluna, labirinto[i], copia[i])){ /* SE ESTA NO TERREO E EXISTE CAMINHO DE ONDE ESTA PARA E */
	
		printf("Terreo: Saida Encontrada\n");

		return 1;

	}

	limpa_copia(copia, labirinto);

	/*printf("andar: %d-----linha %d  coluna %d    existe A---%d\n",i, linha, coluna, Existe_caminho_para_letra('A', linha, coluna, labirinto[i], copia[i]));

	limpa_copia(copia, labirinto);

	printf("andar: %d-----linha %d  coluna %d    existe B---%d\n",i, linha, coluna, Existe_caminho_para_letra('B', linha, coluna, labirinto[i], copia[i]));

	limpa_copia(copia, labirinto);*/

	if (Existe_caminho_para_letra('A', linha, coluna, labirinto[i], copia[i]) == 1){
		
		/*printf("a---------------loop\n");*/

		Acha_coord_letra('A', linhaA, colunaA, labirinto[i]); /* altera linhaA e colunaA por referencia para onde estiver A*/
		
		if (Printando_Passagens(labirinto, copia, n, i-1, *linhaA, *colunaA) == 1){


			printf("Andar %d: Passagem A\n", i);

			return 1;
		}
	}

	if (possivel == 0){ /* Nao achou caminho por A */
		/*printf("b---------------loop\n");*/

		limpa_copia(copia, labirinto);

		/*printf("limpa copia B\n");*/

		if (Existe_caminho_para_letra('B', linha, coluna, labirinto[i], copia[i]) == 1){
			
			/*printf("existe caminho B\n");*/

			Acha_coord_letra('B', linhaB, colunaB, labirinto[i]);

			/*printf("acha coord B\n");*/

			if (Printando_Passagens(labirinto, copia, n, i-1, *linhaB, *colunaB) == 1){

				printf("Andar %d: Passagem B\n", i);

				return 1;

			}
		} 
	}

/* SE ESTA NO TERREO  não acha E---> nao vai achar A ou B ---> retorna possivel = 0*/

return possivel;
}


int main (){ /*--------------------------------------------------------------------------------------------------------------------------------------------*/

	
	int n, level,linha,coluna, linhaAtual, colunaAtual;
	int inicio;
	char andares[30][16][32], copia_andares[30][16][32];

	scanf("%d", &n);

	inicio = n;

	for(level = n; level >=0; level--){

		for(linha = 0; linha < 16; linha++){

			scanf(" ");

			for(coluna = 0; coluna < 32; coluna++){

				scanf("%c", &andares[level][linha][coluna]);
				copia_andares[level][linha][coluna] = andares[level][linha][coluna];
			}	
		}
	}

	/*
	printf("\n");
	for(level = 0; level < n+1; level++){

		for(linha = 0; linha < 16; linha++){

			for(coluna = 0; coluna < 32; coluna++){

				printf("%c", andares[level][linha][coluna]);
			}

			printf("\n");
		}
		printf("\n");
	}
	*/

	

	Acha_coord_letra('X', &linhaAtual, &colunaAtual, andares[n]);

	/*printf("\n-------linha  %d    coluna %d\n", linhaAtual, colunaAtual );
	
	printf("------%d\n", Existe_caminho_para_letra('A', linhaAtual, colunaAtual, andares[n], copia_andares[n]) );*/


	Printando_Passagens(andares, copia_andares, n, inicio, linhaAtual, colunaAtual );
	
return 0;
}

/**/
/*   gcc lab15.c -o lab15 -Wall -Werror -ansi -pedantic    */