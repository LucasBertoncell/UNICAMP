/*
Lucas Bertoncello de Oliveira
ra: 182381
mc102 V

entrada: 10*10*10 chars do cubo
         n rotaçoes
         n linhas com as rotaçoes
         palavra

saida: "'palavra' entre 'index da primeira letra (profund, linha, coluna)' e 'index da segunda()' \n"


GKCRIMSRYX IJUAWHJRXS MPCJSEUPRG IOLHORBWJP RACQQVOBIQ KXAUEOPSTK JFHGXGKEZL MOUEVSQIAN KNDMIZXHPR CLLJCHKXLQ

OPEARLNTQY ZPPJFEEOLE FOZLXKTSWD QXFNUCABPJ VPXVXGHAAI GCSVHCQKNW NSZQWCIWIM SNHUEBYUYV XAODMDMGIO ZXNIDHFAOL

OUEWQOIBQF ONBDUAVZGM CMVPWRGYQW WCHMXMXPRU WXHGZZGUUQ WHODOOWGZP TYDGMAPSGW MMZAHAQELX BNUBSCOLDK YRMLQDTXOF

GUYHFRWOVP KHQUWIKWGO MHQBNAPSVF INNFDNXZJA JFZVSCYNRG DCAYAFJYTR PWRLPUTYSD IBTDMZZKHW QGVYOFCROX MXZXNAIAED

LKFMTSKGXO VCMBNSUYIG UYOQFKHALD AVVGJBCUYR SYORUYBIJA HLNQZDMDAB HKEYZWDNPX UHCRFNWXYU QMFPRTOMYL UEIYIWZIKO

EQFWUSXTFY BQWLVIZYHK OUBQERVCVL WNBGRLHKFA AICQSIRPHL KDVUYGNLIS WBNLAFEKBI LLDTBPXJWR WFXQDMWFOB ZPRHVTTXEK

PIERVCDFIE EQUVPKCRZD PIMBRRMBQD JCRYDVVYAA OYMLECBFMG PREUYYZUPW GUDUKGGXBD FUDKYFTLYW DKEAYVUKOB VZAKZSQSRH

LRHPQBAOMO XGCLYTFHGC VNTNLUCZJR NQYBMRLVOS YDRUNQRJKW TFDFDMGDBK SFWMLDYNWT USPBBQCQED RPJPUXUNGQ DGGCLBZLJI

EZTTAXQQCQ RSPXKYEELU XKCSQQIGJC KSBPAHSFNK CICSBJQJXR PBWOMDNCBK YULVPKEOKQ MVOAYVINGA HUCKIPBQHS MYBYDEQQOF

XIBNXKDUOX IPNWPPPBVC SARIDWZGJU LKVKMKFDPU BJNAXFZTII FQQLOERQYE DQKZCTFLCN SBUPQBTLIN WCHDWYYGDU NGVVFVNSLD

4

ACCW

ACCW

ACCW

ACCW

GOOGLEPLEX


GOOGLEPLEX entre (0,0,0) e (9,0,0)
*/


#include <stdio.h>

/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente a uma placa do cubo
   Saida:    Nao ha

   Objetivo: Rotacionar a placa 90 graus no sentido Horario      */

void rotate_board_CCW(char* board){ /* RESOLVO ESSA PLACA GIRANDO SENTIDO HORARIO PARA RESOLVER AS OUTRAS FUNÇOES */

  int i, j, p=0;
  char aux[101];  /*placa vazia------------*/

  for ( i = 0; i < 100; i+=10) { /*CADA LINHA */

    for ( j = 0; j < 10; j++) { /* CADA CHAR DA LINHA */
  
      *(aux+i+j) = *(board+(9-p)+10*j);

    }
    p +=1;
  }

  p = 0;

  for ( i = 0; i < 100; i+=10) { /*GUARDANDO NO BOARD*/

    for ( j = 0; j < 10; j++) { 

      *(board+i+j) = *(aux+i+j);
      

    }
    p +=1;
  }
}


/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente a uma placa do cubo
   Saida:    Nao ha

   Objetivo: Rotacionar a placa 90 graus no sentido Anti-Horario */

void rotate_board_CW(char* board){ /* ROTACIONAR 3 VEZES = ROTACIONAR ANTIHORARIO */

  rotate_board_CCW( board );
  rotate_board_CCW( board );
  rotate_board_CCW( board );

}

/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente ao cubo
   Saida:    Nao ha

   Objetivo: Rotacionar todas as placas 90 graus no sentido
             Horario                                             */
void rotate_all_CW(char* cube){
  int i;

  for (i = 0; i < 10; i++) {
    rotate_board_CW(cube+i*100);
  }

}

/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente ao cubo
   Saida:    Nao ha

   Objetivo: Rotacionar todas as placas 90 graus no sentido
             anti-Horario                                        */
void rotate_all_CCW(char* cube){
  int i;

  for (i = 0; i < 10; i++) {
	rotate_board_CW(cube+i*100);
	rotate_board_CW(cube+i*100);
	rotate_board_CW(cube+i*100);
  }

}


int main(){ /*---------------------------------------------------------------------------------------------------------------------*/
  int n = 0, profund, linha, coluna, qualPlaca;
  int i,k, tamanhoPalav, encontrada = 0;
  int ProfundInicial, ProfundFinal, LinhaInicial, LinhaFinal, ColunaInicial, ColunaFinal;
  char cube[1001], *cubo_linearizado = &cube[0], palavra[11];
  char sempreW, sempreC, sentido, AouP;


  for ( profund = 0; profund < 1000; profund+=100) {

    for ( linha = 0; linha < 100; linha+=10) {

      for ( coluna = 0; coluna < 10; coluna++) {

        scanf(" %c", ( cube+(coluna+linha+profund) )); /*  " %c" --> desconsidera espaços e enters */

      }
    }
  }
  /*
  for ( profund = 0; profund < 1000; profund+=100) {

    for ( linha = 0; linha < 100; linha+=10) {

      for ( coluna = 0; coluna < 10; coluna++) {
        printf("%c", *(cube+coluna+linha+profund)  );
      }
      printf("\n");
    }
    printf("\n");
  }
  */
  
  scanf("%d", &n);
  
  /*printf("  n = %d\n", n);*/

  for ( k = 0; k < n; k++) {

    scanf(" %c", &AouP); /* LENDO POSIÇAO 0*/

    if(AouP == 'A'){

      scanf("%c%c", &sempreC, &sentido);

      if(sentido == 'C'){ /* ACCW*/

        scanf("%c", &sempreW);

        rotate_all_CCW(cubo_linearizado);

        /*printf("----%c%c%c\n",AouP,sempreC,sentido );*/
      }

      else if(sentido == 'W'){ /* ACW*/

        rotate_all_CW(cubo_linearizado);

        /*printf("----%c%c%c\n",AouP,sempreC,sentido );*/

      }
    }



    else if(AouP == 'P'){

      scanf("%c%c", &sempreC, &sentido);

      if(sentido == 'C'){ /* PCCW*/

        scanf("%c", &sempreW);

        scanf("%d", &qualPlaca);

        /* printf("----qualplaca=%d\n",qualPlaca );*/

        /* printf("----placa aponta para %c\n", *(cube+(qualPlaca)*100) );*/

        rotate_board_CCW(cubo_linearizado+(qualPlaca)*100);
      }

      else if(sentido == 'W'){ /* PCW*/

        scanf("%d", &qualPlaca);

        /*printf("----qualplaca=%d\n",qualPlaca ); */

        /* printf("----placa aponta para %c\n", *(cube+(qualPlaca)*100) );*/
        rotate_board_CW(cubo_linearizado+(qualPlaca)*100);

      }

    }

  }

  for(i = 0; i < 11; i++){
    *(palavra+i) = '\0';
  }

  scanf(" %s", palavra);

  for (i = 0; i < 11; i++) {  /* encotrando tamanhoPalav */

  	/*printf("%c",*(palavra+i));*/

  	if( *(palavra+i) == '\0'){
      tamanhoPalav = i;
      i=11;
    }
  }

   /*printf("---tamanhoPalav = %d\n", tamanhoPalav );

  

  for ( profund = 0; profund < 1000; profund+=100) {

    for ( linha = 0; linha < 100; linha+=10) {

      for ( coluna = 0; coluna < 10; coluna++) {
        printf("%c", *(cube+coluna+linha+profund)  );
      }
      printf("\n");
    }
    printf("\n");
  }
*/
  

  /* PROCURO A PALAVRA NO CUBO---> +1 OU +10 OU +100*/

  for ( profund = 0; profund < 1000; profund+=100) {
    if(encontrada == 1){ /* se palavra foi encontrada, saio do loop*/
      profund = 1001;
    }

    for ( linha = 0; linha < 100; linha+=10) {
      if(encontrada == 1){
        linha = 101;
      }

      for ( coluna = 0; coluna < 10; coluna++) {

        if (encontrada == 0){
          for (i = 0; i < tamanhoPalav; i++) {/*------------ checando A DIREITA*/

            if(*(palavra+i) != *(cube +coluna +linha +profund +i) ){/* palavra nao esta a direita--->saio do for sem fazer encontrada = 1*/
              i = 11;
            }

            else if(i == (tamanhoPalav - 1)){ /* palavra encontrada */
              encontrada = 1;

              ProfundInicial = profund/100;
              ProfundFinal = profund/100;

              LinhaInicial = linha/10;
              LinhaFinal = linha/10;

              ColunaInicial = coluna;
              ColunaFinal = coluna+i; 

            }
          }
        }



        if (encontrada == 0){
          for (i = 0; i < tamanhoPalav; i++) {/*---------- ABAIXO*/

            if(*(palavra+i) != *(cube +coluna +linha +profund + (10*i)) ){
              i = 11;
            }

            else if(i == (tamanhoPalav - 1)){
              encontrada = 1;

              ProfundInicial = profund/100;
              ProfundFinal = profund/100;

              LinhaInicial = linha/10;
              LinhaFinal = i;

              ColunaInicial = coluna;
              ColunaFinal = coluna; 

            }
          }
        }



        if (encontrada == 0){
          for (i = 0; i < tamanhoPalav; i++) { /*------------- DENTRO*/
          
            if(*(palavra+i) != *(cube+coluna+linha+profund + (100*i)) ){
              i = 11;
            }

            else if(i == (tamanhoPalav - 1)){
              encontrada = 1;

              ProfundInicial = profund/100;
              ProfundFinal = i+ProfundInicial;

              LinhaInicial = linha/10;
              LinhaFinal = linha/10;

              ColunaInicial = coluna;
              ColunaFinal = coluna; 

            }
          }
        }
      }
    }
  }
  
  printf("%s entre (%d,%d,%d) e (%d,%d,%d)\n", palavra,ProfundInicial,LinhaInicial,ColunaInicial,ProfundFinal,LinhaFinal,ColunaFinal );

  return 0;
}
/*   gcc lab12.c -o lab12 -Wall -Werror -ansi -pedantic    */
