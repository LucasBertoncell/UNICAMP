/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: -numero inteiro representando nº n de peças presentes
		 -NAS PROXIMAS n LINHAS: 1) letra de A a H (linhas) 
								 2) numero 1 a 8 (colunas) 
								 3) letra da peça
								 COM ESPAÇO ENTRE CADA LETRA/NUMERO
♔ Rei	    R	r
♛ Dama   	D	d
♝ Bispos	B	b
♞ Cavalos	C	c
♜ Torres	T	t
♟ Peões	    P	p

saida: \n, tabuleiro com as peças e ESPAÇOS ENTRE ELAS E: . QUADRADOS BRANCOS
														  * QUADRADOS PRETOS

. d . * . b . * 
p . * . * . * . 
. * . * . * . * 
* . * . * . * . 
. * . * . * . * 
* . * . * . * . 
. * . P . * . * 
* . * . * . * T 

*/

#include <stdio.h>

int main (){

	int i=0, n=0;

	char A1='.', A2='*', A3='.', A4='*', A5='.', A6='*', A7='.', A8='*',
	B1='*',B2='.',B3='*',B4='.',B5='*',B6='.',B7='*',B8='.',
	C1='.',C2='*',C3='.',C4='*',C5='.',C6='*',C7='.',C8='*',
	D1='*',D2='.',D3='*',D4='.',D5='*',D6='.',D7='*',D8='.',
	E1='.',E2='*',E3='.',E4='*',E5='.',E6='*',E7='.',E8='*',
	F1='*',F2='.',F3='*',F4='.',F5='*',F6='.',F7='*',F8='.',
	G1='.',G2='*',G3='.',G4='*',G5='.',G6='*',G7='.',G8='*',
	H1='*',H2='.',H3='*',H4='.',H5='*',H6='.',H7='*',H8='.';


	scanf( "%d", &n);
	/*   n *= 2;    */

	for (i = 0; i < n; i++){

		int colunas;
		char linhas, p;
 		scanf ( " %c %d %c", &linhas, &colunas, &p );

		if ( linhas == 'A'){
			if (colunas == 1){
				A1 = p;
			}
			if (colunas == 2){
				A2 = p;
			}
			if (colunas == 3){
				A3 = p;
			}
			if (colunas == 4){
				A4 = p;
			}
			if (colunas == 5){
				A5 = p;
			}
			if (colunas == 6){
				A6 = p;
			}
			if (colunas == 7){
				A7 = p;
			}
			if (colunas == 8){
				A8 = p;
			}
		}


		else if ( linhas == 'B'){
			if (colunas == 1){
				B1 = p;
			}
			if (colunas == 2){
				B2 = p;
			}
			if (colunas == 3){
				B3 = p;
			}
			if (colunas == 4){
				B4 = p;
			}
			if (colunas == 5){
				B5 = p;
			}
			if (colunas == 6){
				B6 = p;
			}
			if (colunas == 7){
				B7 = p;
			}
			if (colunas == 8){
				B8 = p;
		    }
		}

		else if ( linhas == 'C'){
			if (colunas == 1){
				C1 = p;
			}
			if (colunas == 2){
				C2 = p;
			}
			if (colunas == 3){
				C3 = p;
			}
			if (colunas == 4){
				C4 = p;
			}
			if (colunas == 5){
				C5 = p;
			}
			if (colunas == 6){
				C6 = p;
			}
			if (colunas == 7){
				C7 = p;
			}
			if (colunas == 8){
				C8 = p;
		    }
		}

		else if ( linhas == 'D'){
			if (colunas == 1){
				D1 = p;
			}
			if (colunas == 2){
				D2 = p;
			}
			if (colunas == 3){
				D3 = p;
			}
			if (colunas == 4){
				D4 = p;
			}
			if (colunas == 5){
				D5 = p;
			}
			if (colunas == 6){
				D6 = p;
			}
			if (colunas == 7){
				D7 = p;
			}
			if (colunas == 8){
				D8 = p;
		    }
		}

		else if ( linhas == 'E'){
			if (colunas == 1){
				E1 = p;
			}
			if (colunas == 2){
				E2 = p;
			}
			if (colunas == 3){
				E3 = p;
			}
			if (colunas == 4){
				E4 = p;
			}
			if (colunas == 5){
				E5 = p;
			}
			if (colunas == 6){
				E6 = p;
			}
			if (colunas == 7){
				E7 = p;
			}
			if (colunas == 8){
				E8 = p;
		    }
		}

		else if ( linhas == 'F'){
			if (colunas == 1){
				F1 = p;
			}
			if (colunas == 2){
				F2 = p;
			}
			if (colunas == 3){
				F3 = p;
			}
			if (colunas == 4){
				F4 = p;
			}
			if (colunas == 5){
				F5 = p;
			}
			if (colunas == 6){
				F6 = p;
			}
			if (colunas == 7){
				F7 = p;
			}
			if (colunas == 8){
				F8 = p;
		    }
		}

		else if ( linhas == 'G'){
			if (colunas == 1){
				G1 = p;
			}
			if (colunas == 2){
				G2 = p;
			}
			if (colunas == 3){
				G3 = p;
			}
			if (colunas == 4){
				G4 = p;
			}
			if (colunas == 5){
				G5 = p;
			}
			if (colunas == 6){
				G6 = p;
			}
			if (colunas == 7){
				G7 = p;
			}
			if (colunas == 8){
				G8 = p;
		    }
		}

		else if ( linhas == 'H'){
			if (colunas == 1){
				H1 = p;
			}
			if (colunas == 2){
				H2 = p;
			}
			if (colunas == 3){
				H3 = p;
			}
			if (colunas == 4){
				H4 = p;
			}
			if (colunas == 5){
				H5 = p;
			}
			if (colunas == 6){
				H6 = p;
			}
			if (colunas == 7){
				H7 = p;
			}
			if (colunas == 8){
				H8 = p;
		    }
		}
	}

	printf("%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n%c %c %c %c %c %c %c %c \n",
	A1,A2,A3,A4,A5,A6,A7,A8,
	B1,B2,B3,B4,B5,B6,B7,B8,
	C1,C2,C3,C4,C5,C6,C7,C8,
	D1,D2,D3,D4,D5,D6,D7,D8,
	E1,E2,E3,E4,E5,E6,E7,E8,
	F1,F2,F3,F4,F5,F6,F7,F8,
	G1,G2,G3,G4,G5,G6,G7,G8,
	H1,H2,H3,H4,H5,H6,H7,H8);
	
return 0;
}


/*   gcc lab04.c -o lab04 -Wall -Werror -ansi -pedantic   */