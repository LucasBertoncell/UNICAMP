/*
Lucas Bertoncello de Oliveria
ra: 182381
mc102 V

entrada: 4 fios de cores P,L,A,V
saida: cortar (C) ou nao (N) of fios na ordem que foram dados

condições:
Todo fio Azul deve ser cortado, se o quarto fio não for Laranja ou Preto;
Se o primeiro fio for Vermelho, corte-o se o terceiro fio for Azul ou Preto;
Se a sequência de cores for um palíndromo, corte o primeiro fio;
Se não houver fios Pretos, corte o segundo fio;
Se ou o quarto ou o terceiro fios forem Vermelhos, corte o segundo fio;
Se o primeiro fio não for Azul nem Laranja, corte o terceiro fio.
*/

#include <stdio.h>

int main() {

	char f1, f2, f3, f4,/*fs comparativos,CONDICOES, carregando os APLV dados*/ fi1,fi2,fi3,fi4 /*fs para o printf, carregando C ou N*/;
	scanf("%c%c%c%c", &f1, &f2, &f3, &f4);

	if (f1==f4 && f2==f3)
		{fi1 = 'C';}

/*cond 1*/

	if (f1 == 'A' && f4!='L' && f4!='P')
		{fi1 = 'C';}
	if (f2 == 'A' && f4!='L' && f4!='P')
		{fi2 = 'C';}
	if (f3 == 'A' && f4!='L' && f4!='P')
		{fi3 = 'C';}
	if (f4 == 'A' && f4!='L' && f4!='P')
		{fi4 = 'C';}

/*fim da cond 1*/

	if (f1=='V' && (f3=='P'|| f3=='A'))
		{fi1 = 'C';}

	if (f1!='P' && f2!='P' && f3!='P' && f4!='P')
		{fi2 = 'C';}

	if (f4=='V' || f3=='V')
		{fi2 = 'C';}

	if (f1!='A' && f1!='L')
		{fi3 = 'C';}


	if (fi1 != 'C')
		{fi1 = 'N';}
	if (fi2 != 'C')
		{fi2 = 'N';}
	if (fi3 != 'C')
		{fi3 = 'N';}
	if (fi4 != 'C')
		{fi4 = 'N';}

	printf("%c%c%c%c\n", fi1,fi2,fi3,fi4);
	return 0;

}