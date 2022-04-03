/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: K, M, MENSAGEM, P, Palav Conhecida

saida:     if   Pal == pal na linha P: PRINTF [MENSAGEM DECIFRADA]
			else printf ''Chave Incorreta''
exemplo:
GSK

3

PMHDJWAKNOMWFQWMFTPVGZTYWARWOVKSRVIUPHHZMDDZJGSNUXKZLBFFOJLTQZQMGNWHCKUCYQGEQISBRNVB

YHPNPHXITFUUZMVNNXLVMJWHJO

XFXKNFBREZKTEEMEIWT

1

INGLATERRA

A SUA MAJESTADE REAL REI GEORGE SEXTO O SAUDA PELA QUEBRA DESTA MENSAGEM

DEUS SALVE A INGLATERRA

DEUS SALVE O REI

obs:
 Dear Mr.

 O Comité de Segurança de Estado da URSS aprecia os esforços para resolver este problema.

 Nossa inteligência diz que a função: strlen (), strstr () e strchr () biblioteca string.h pode fazer uma grande diferença.

 Saudações e boa sorte

 XX = espaço
 Numeros = por extenso

*/

#include <stdio.h> 
#include <string.h>

int main(){
	char k[4], msg[101][151], Rd[27]="JAMTUDFRVENWBCLHOXYQIPKZGS",Rc[27]="RWOPEJTLYBCNQGAIHVMSFXKDZU";
	char Rf[27] = "QYHOGNECVPUZTFDJAXWMKISRBL", al[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", Pal[151], Re[27]="TJKAOZUMFHIGNVCSLYBDPQEWRX";
	char primeiro;
	int i, j, h, m, p, tamanho, primeiro1, primeiro2, primeiro3;
	int posRd, posRc, posRe, TamPartindoL1, TamPartindoL2, TamPartindoL3;

	scanf("%s", k);
	scanf("%d", &m);

/*
COLOCAR ROTORES NA POSIÇÃO DA CHAVE
ROTORES SEMPRE COMEÇAM EM AAA == 000
*/

	TamPartindoL1 = strlen(strchr(al, k[2]));    /*exemplo: se L1=C, TamPartindo1 = 24(26 - A - B = 24), posRd = 2 ----> CAA == 200 */
	posRd = 26 - TamPartindoL1;
/*DEVO RODAR 'PosRd' VEZES O Rd, 'PosRc' VEZES O Rc ETC  ---> OBTENHO OS ROTORES NAS POSIÇOES [L1 L2 L3]*/	
	for(j = 0; j < posRd; j++){
		primeiro = Rd[0];

		for(i = 0; i < 25; i++){
				Rd[i] = Rd[i+1];
			}

		Rd[25] = primeiro;
	}

	TamPartindoL2 = strlen(strchr(al, k[1]));
	posRc = 26 - TamPartindoL2;
	for(j = 0; j < posRc; j++){
		primeiro = Rc[0];

		for(i = 0; i < 25; i++){
				Rc[i] = Rc[i+1];
			}

		Rc[25] = primeiro;
	}

	TamPartindoL3 = strlen(strchr(al, k[0]));
	posRe = 26 - TamPartindoL3;
	for(j = 0; j < posRe; j++){
		primeiro = Re[0];

		for(i = 0; i < 25; i++){
				Re[i] = Re[i+1];
			}

		Re[25] = primeiro;
	}
/*
GUARDAR m LINHAS COM ATÉ 150 CHARS CADA
*/
	for(i = 0; i < m; i++){
		scanf("%s", msg[i]);
	}
/*
TEMOS msg[m][até 150chars codificados]
*/
	for(i = 0; i < m; i++){

		tamanho = strlen(msg[i]);

		for(j = 0; j < tamanho; j++){
		/* RODAR O ROTOR/ROTORES
		Caso RD esteja na letra Q(DEPOIS VEM O I) quando for rodar, RC também gira uma posição.
		De forma similar, caso RC esteja na letra V(DEPOIS VEM O M) quando for rodar, RE também gira uma posição.
		 */
				primeiro1 = Rd[0];
				for(h = 0; h < 25; h++){
					Rd[h] = Rd[h+1];
				}
				Rd[25] = primeiro1;

				if ( Rd[0] == 'X'){

					primeiro2 = Rc[0];
					for(h = 0; h < 25; h++){
						Rc[h] = Rc[h+1];
					}
					Rc[25] = primeiro2;

					if ( Rc[0] == 'K'){

						primeiro3 = Re[0];
						for(h = 0; h < 25; h++){
							Re[h] = Re[h+1];
						}
						Re[25] = primeiro3;
					}
				}
				
			/*ENCONTRO PARA CADA LETRA DA MSG SEU NUMERO CORRESPONDENTE EM AL(de 0 a 25)*/
			msg[i][j] = Rd[(26 - strlen(strchr(al, msg[i][j])))];
		/*passei por Rd*/
			
			msg[i][j] = Rc[(26 - strlen(strchr(al, msg[i][j])))];
		/*por Rc*/
		
			msg[i][j] = Re[(26 - strlen(strchr(al, msg[i][j])))];
		/*por Re*/
		
			msg[i][j] = Rf[(26 - strlen(strchr(al, msg[i][j])))];
		/*pelo Rf*/
		
			msg[i][j] = al[(26 - strlen(strchr(Re, msg[i][j])))];
		/*por Re de novo*/
		
			msg[i][j] = al[(26 - strlen(strchr(Rc, msg[i][j])))];
		/*por Rc de novo*/
		
			msg[i][j] = al[(26 - strlen(strchr(Rd, msg[i][j])))];
		/*por Rd de novo
		OBS: na volta,TROQUEI al e Rc por ser a volta*/	
		}
	}
/*
AGORA TENHO MSG[ATÉ 150 CHARS] COM A MSG DESCIFRADA, COM XX NO LUGAR DOS ESPAÇOS
*/	
	scanf("%d", &p);
	scanf("%s", Pal);

	if (strstr(msg[p], Pal) != NULL){

		tamanho = strlen(msg[p]);

		for (j = 0; j < m; j++){

			tamanho = strlen (msg[j]);

			for (i = 0; i < tamanho; i++){

				if (msg[j][i] == msg[j][i+1] && msg[j][i] == 'X'){
					printf(" ");
					i += 1;
				}

				else
					printf("%c", msg[j][i]);
			}
			printf("\n");
		}
	}
	else
		printf("Chave Incorreta\n");
	
	

return 0;
}


/*   gcc lab07.c -o lab07 -Wall -Werror -ansi -pedantic    */