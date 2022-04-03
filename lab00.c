//Lucas Bertoncello de Oliveira
//ra:182381
//Programa de soma de inteiros

#include <stdio.h>
//bibliotecas contendo funções

int main(){
	int numero1, numero2, resultado;
	//declaração de variaveis do tipo int(inteiros)
	printf("\nSoma de dois inteiros\nDigite os dois inteiros \n(digite um, tecle enter e entao o outro, ou, digite um, tecle space e entao o outro:");
	//o que sera mostrado na tela ate
	scanf("%d %d",   &numero1,   &numero2);
	//em seguida o que o computador espera ser scaneado, dois inteiros (%d)
	resultado = numero1 + numero2;
	//dou um valor ao inteiro 'resultado'
	printf("%d + %d = %d\n",numero1, numero2, resultado);
	//mostro a soma contendo os 3 inteiros

}
