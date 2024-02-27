#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <conio2.h>
#define COL 102
#define LIN 22
#define UP 72
#define RIGHT 77
#define DOWN 80
#define LEFT 75
#define ENTER 13
#define ESC 27
#define AAA 4
#define ALTURA_DO_PULO 10
#define REX_NORMAL 11
#define REX_ABAIXADO 8
#define TREX 'W'
#define BORDA '#'
#define CHAO 'X'
#define FUNDO 'Z'
#define OBSTACULO 'Y'
#define TEMPO_ABAIXADO 30
#define TAM_HIGHSCORES 10

typedef struct
    {
        int pts;
        char nome[AAA];
    }SCORE;

void carrega_mapa(char map[LIN][COL],char filename[50])//carrega um mapa de um arq txt em uma matriz bidimensional
    {
        int i,j;
        FILE *arq;
        if ((arq = fopen(filename,"r")) == NULL)
        {
            printf("nao foi possivel ler o mapa");
        }
        else
        {
            for(i=0;i<LIN;i++)
                for(j=0;j<COL;j++)
                {
            fscanf(arq," %c ",& (map[i][j]));
                }
            fclose(arq);
        }
    }

void imprime_jogo(char map[LIN][COL])//imprime o mapa com suas determinadas estruturas
    {
        int i,j;
        clrscr();
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if (map [i][j] == BORDA) // borda
                {
                    textbackground(RED);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                if (map [i][j] == FUNDO) // fundo
                {
                    textbackground(BLACK);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                if (map [i][j] == TREX) // trex
                {
                    textbackground(WHITE);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                 if (map [i][j] == CHAO) // chao
                {
                    textbackground(RED);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                else if(map [i][j] != BORDA && map [i][j] != FUNDO && map [i][j] != TREX && map [i][j] != CHAO)
                {
                    textbackground(BLUE);
                    putchxy(j+1, i+1, map[i][j]);
                    textbackground(BLACK);
                }
            }
    }

void imprime_menu(char menu[LIN][COL]) // imprime menu na tela
    {
        int i, j, cont;
        clrscr();
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if(menu[i][j] == '#') // borda
                {
                    textbackground(RED);
                    putchxy(j+1, i+1, ' ');
                    textbackground(BLACK);
                }
                else if(menu[i][j] == 'X') // fundo
                {
                    textbackground(BLACK);
                    putchxy(j+1, i+1, ' ');
                    textbackground(BLACK);
                }
                else
                {
                    textbackground(BLACK);
                    putchxy(j+1, i+1, menu[i][j]);
                    textbackground(BLACK);
                }
            }
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if(menu[i][j] == '1')
                {
                    putchxy(j+1, i+1, ' ');
                    textbackground(BLUE);
                    for(cont=2; cont<9;cont++)
                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                    textbackground(BLACK);
                }
                else if(menu[i][j] == '2' || menu[i][j] == '3' || menu[i][j] == '4' || menu[i][j] == '5')
                {
                    putchxy(j+1, i+1, ' ');
                }
            }
    }

void escolhe_menu(char menu[LIN][COL], int *local, char *tecla, int *select, int *gameover) // seleciona a opcao do menu
    {
        int i, j, cont;
        (*gameover)=0;
        *tecla = getch();
        if (*tecla == -32)
            {
            *tecla = getch();
            switch(*tecla)
            {
            case UP: // caso clique pra cima
                {
                    if(*local==4)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '4')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<8;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '3')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(BLUE);
                                    for(cont=2; cont<9;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=3;
                                    }
                            }
                        }
                    }
                    else if(*local==3)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '3')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<9;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '2')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(BLUE);
                                    for(cont=2; cont<9;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=2;
                                    }
                            }
                        }
                    }
                    else if(*local==2)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '2')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<9;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '1')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(BLUE);
                                    for(cont=2; cont<9;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=1;
                                    }
                            }
                        }
                    }
                }
            break;
            case DOWN: // caso clique pra baixo
                {
                    if(*local==1)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '1')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<9;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '2')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(BLUE);
                                    for(cont=2; cont<9;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=2;
                                    }
                            }
                        }
                    }
                    else if(*local==2)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '2')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<9;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '3')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(BLUE);
                                    for(cont=2; cont<9;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=3;
                                    }
                            }
                        }
                    }
                    else if(*local==3)
                    {
                    for(i=0; i<LIN; i++)
                        for(j=0; j<COL; j++)
                        {
                            if(menu[i][j] == '3')
                            {
                                putchxy(j+1, i+1, ' ');
                                textbackground(BLACK);
                                for(cont=2; cont<9;cont++)
                                putchxy(j+cont, i+1, menu[i][j+cont-1]);

                                for(i=0; i<LIN; i++)
                                    for(j=0; j<COL; j++)
                                if(menu[i][j] == '4')
                                    {
                                    putchxy(j+1, i+1, ' ');
                                    textbackground(RED);
                                    for(cont=2; cont<8;cont++)
                                    putchxy(j+cont, i+1, menu[i][j+cont-1]);
                                    textbackground(BLACK);
                                    *local=4;
                                    }
                            }
                        }
                    }
                }
            break;
            }
        }
        else if(*tecla==ENTER) // seleciona a opcao do menu
        {
            *select=0;
        }
    }

void trex_retorna(char map[LIN][COL]) // retorna o trex para a posi��o base
    {
        int i,j;
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if(map[i][j] == TREX)
                    {
                        map[i][j] = FUNDO;
                        //textbackground(RED);
                        putchxy(21, 17, ' ');
                        putchxy(22, 17, ' ');
                        putchxy(23, 17, ' ');
                        //textbackground(BLACK);
                    }
            }

        textbackground(WHITE);
        map[14][19] = TREX;
        putchxy(20, 15, ' ');
        map[14][20] = TREX;
        putchxy(21, 15, ' ');
        map[14][21] = TREX;
        putchxy(22, 15, ' ');
        map[15][17] = TREX;
        putchxy(18, 16, ' ');
        map[15][18] = TREX;
        putchxy(19, 16, ' ');
        map[15][19] = TREX;
        putchxy(20, 16, ' ');
        map[16][17] = TREX;
        putchxy(18, 17, ' ');
        map[16][18] = TREX;
        putchxy(19, 17, ' ');
        map[16][19] = TREX;
        putchxy(20, 17, ' ');
        map[17][17] = TREX;
        putchxy(18, 18, ' ');
        map[17][19] = TREX;
        putchxy(20, 18, ' ');
        //map[18][7] = 'X';
        //map[18][8] = 'X';
        //map[18][9] = 'X';
        //map[18][10] = 'X';
        //map[18][11] = 'X';

        textbackground(BLACK);
    }

void verifica_trex(char map[LIN][COL]) // verifica se o trex esta dentro do chao (arruma um provavel bug)
    {
        int i,j;
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if(map[i][j] == TREX && map[i][j+20] == CHAO)
                    {
                        trex_retorna(map);
                    }
            }
    }

void input_teclado(char map[LIN][COL], char *moverex, int *pulando, int *abaixando, int *pos, int *acoes, int *selec) // detecta o teclado
    {
        int i,j,cont=0;
        if (*pulando == 0) {
            if(_kbhit())
            {
                    *moverex = _getch();

                    if (*moverex == -32)
                        {
                            *moverex = _getch();
                            switch(*moverex)
                                {
                                case UP: // pula rex
                                    {
                                        (*pulando)++;
                                    }
                                break;
                                case DOWN: // abaixa rex
                                    {
                                            (*abaixando)=1;
                                    }
                                break;
                                default:
                                    {
                                        (*abaixando)=0;
                                        //trex_retorna(map);
                                    }
                                }
                        }
                    else if(*moverex == ESC) // sai do jogo e volta para o menu
                        {
                             clrscr();
                             *pos=1;
                             *acoes=1;
                             *selec=1;
                        }
            }
        }
    }

void pular(char map[LIN][COL], int *pulando, int *abaixando) // faz o rex subir ate a posicao ALTURA_DO_PULO
    {
        int i,j;


        putchxy(21, 17, ' ');
        putchxy(22, 17, ' ');
        putchxy(23, 17, ' ');


        if (*pulando > 0 && *pulando <= ALTURA_DO_PULO)
            {
            for(i=0; i<LIN; i++)
                for(j=0; j<COL; j++)
                {
                    if(map[i][j] == TREX)
                    {
                        textbackground(BLACK);
                        putchxy(j+1,i+1,' '); //apaga
                        textbackground(WHITE);
                        putchxy(j+1,i,' '); // desenha
                        textbackground(BLACK);
                        map[i][j] = FUNDO;
                        map[i-1][j] = TREX;
                    }
                }
            (*pulando)++;
            }
    }

void descer(char map[LIN][COL], int *pulando, int *abaixando) // quando o rex chegar na ALTURA_DO_PULO ele come�a a descer
    {
        int i,j;
        if (*pulando < -1)
            {
                for(i=LIN; i>0; i--)
                    for(j=COL; j>0; j--)
                    {
                        if(map[i][j] == TREX)
                        {
                            textbackground(BLACK);
                            putchxy(j+1,i+1,' '); // apaga
                            textbackground(WHITE);
                            putchxy(j+1,i+2,' '); // desenha
                            textbackground(BLACK);
                            map[i][j] = FUNDO;
                            map[i+1][j] = TREX;
                        }
                    }
                (*pulando)++;
                if(*pulando == -1)
                    {
                        (*pulando)=0;
                        verifica_trex(map);
                    }

            }
    }

void abaixar(char map[LIN][COL], int *abaixando, int *pulando) // abaixa o rex
    {
        int lin=15, col=18;

                textbackground(BLACK);
                /*
                map[15][20] = FUNDO;
                map[15][21] = FUNDO;
                map[15][22] = FUNDO;
                map[16][18] = FUNDO;
                map[16][19] = FUNDO;
                map[16][20] = FUNDO;
                map[17][18] = TREX;
                map[17][19] = TREX;
                map[17][20] = TREX;
                map[17][21] = TREX;
                map[17][22] = TREX;
                map[17][23] = TREX;
                map[18][18] = TREX;
                map[18][20] = TREX;
                */

                if(map[lin][col+2]!=OBSTACULO)
                    putchxy(col+2, lin, ' ');
                if(map[lin][col+3]!=OBSTACULO)
                    putchxy(col+3, lin, ' ');
                if(map[lin][col+4]!=OBSTACULO)
                    putchxy(col+4, lin, ' ');
                if(map[lin+1][col]!=OBSTACULO)
                    putchxy(col, lin+1, ' ');
                if(map[lin+1][col+1]!=OBSTACULO)
                    putchxy(col+1, lin+1, ' ');
                if(map[lin+1][col+2]!=OBSTACULO)
                    putchxy(col+2, lin+1, ' ');

                textbackground(BLACK);

            if((*pulando)==0)
                {
                    textbackground(WHITE);
                    putchxy(18, 17, ' ');
                    putchxy(19, 17, ' ');
                    putchxy(20, 17, ' ');
                    putchxy(21, 17, ' ');
                    putchxy(22, 17, ' ');
                    putchxy(23, 17, ' ');
                    putchxy(18, 18, ' ');
                    putchxy(20, 18, ' ');
                    textbackground(BLACK);
                }
        (*abaixando)++;
    }

void imprime_highscore(char score[LIN][COL])//imprime as 10 melhores pontuacoes
    {
        int i, j, cont;
        clrscr();
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if (score[i][j] == '#') // borda
                {
                    textbackground(RED);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                else if (score[i][j] == 'X') // fundo
                {
                    textbackground(BLACK);
                    putchxy(j+1,i+1,' ');
                    textbackground(BLACK);
                }
                else if(score[i][j] == score[i][j])
                {
                    textbackground(BLACK);
                    putchxy(j+1,i+1,score[i][j]);
                    textbackground(BLACK);
                }
            }
    }

void verifica_obstaculo(char map[LIN][COL]) // apaga qualquer obstaculo que esteja impresso na tela
    {
        int i,j;
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
            {
                if(map[i][j]==OBSTACULO)
                {
                    //textbackground(RED);
                    putchxy(j, i, ' ');
                    map[i][j]=FUNDO;
                    //textbackground(BLACK);
                }
            }
    }

void imprime_map_jog(char map[LIN][COL]) // abre a tela de ler o nome do jogador
    {
        int i,j;
        for(i=0; i<LIN; i++)
            for(j=0; j<COL; j++)
                {
                    if(map[i][j] == BORDA)
                        {
                            textbackground(RED);
                            putchxy(j+1, i+1, ' ');
                            textbackground(BLACK);
                        }
                        else if(map[i][j] == CHAO)
                            {
                                putchxy(j+1, i+1, ' ');
                            }
                            else
                                {
                                    putchxy(j+1, i+1, map[i][j]);
                                }
                }
    }

void le_jogador(char map[LIN][COL], SCORE *jogador, int *pontos) // le o nome do jogador (3 letras)
    {
        int x_ini=50, y_ini=14;

        gotoxy(x_ini, y_ini);
        scanf("%s", jogador->nome);

        jogador->pts = *pontos;
    }

void le_highscores(SCORE high_scores[TAM_HIGHSCORES]) // funcao que le os top 10 do arquivos txt
    {
        FILE *highscores;
        int cont, cont2=0;
        char stringao[100];
        char *pontos, *nome;
        int pontos_jog;

        if((highscores = fopen("highscores.txt","r")) == NULL)
            {
                for (cont=0;cont<TAM_HIGHSCORES;cont++)
                    {
                        high_scores[cont].pts = 0;
                        strcpy(high_scores[cont].nome , "AAA");
                    }
            }
            else
            {

                while(!feof)
                    {
                        fgets(stringao, 100, highscores);
                        clrscr();
                        printf("%s", stringao);
                        system("pause");
                        nome = strtok(stringao, "#");
                        pontos = strtok(NULL, "#");

                        strcpy(high_scores[cont2].nome, nome);
                        pontos_jog = atoi(pontos);
                        high_scores[cont2].pts = pontos_jog;

                        cont2++;
                    }
            }
    }

void colisao(char map[LIN][COL], int *gameover, int *abaixando, int *acoes, int *vidas) // testa se houve colisao
    {
        int i,j, contaREX=0, contaREXabaixado=0;


        if((*abaixando)!=0)
            {
                for(i=0; i<LIN; i++)
                    for(j=0; j<COL; j++)
                        {
                            if(map[i][j] == TREX)
                                    {
                                        contaREXabaixado++;
                                    }
                        }
            }
            else if((*abaixando)==0)
            {
                for(i=0; i<LIN; i++)
                    for(j=0; j<COL; j++)
                    {
                        if(map[i][j] == TREX)
                            {
                                contaREX++;
                            }
                    }

            }

        if(contaREX==REX_NORMAL) // testa se a quantidade de caracteres do trex na tela � igual ao que deveria ter
            {
                (*gameover)=0;
            }
            else if((*abaixando)==0) // se nao tiver a quantidade de caracteres do trex correta perde uma vida
                {
                    //if((*vidas)==0)
                        {
                             (*gameover)=1;
                            printf("\t\t");
                            textbackground(MAGENTA);
                            printf("GAME OVER!!!");
                            textbackground(BLACK);
                            printf("\t");
                            system("pause");
                            (*acoes)=5;
                        }
                        //else
                        {
                            //(*vidas)--;
                        }
                }
    }

void random_objeto(char map[LIN][COL], int *inicializa, int *obstaculo) // inicializa um obstaculo aleatorio na tela
    {
        int i,j, i2,j2, altura;
        int ini_linha_1 = 15, ini_coluna_1 = 99;
        int ini_linha_2 = 15, ini_coluna_2 = 94;
        int ini_linha_3 = 15, ini_coluna_3 = 94;
        int ini_linha_4 = 14, ini_coluna_4 = 93;
        int ja_tem_obstaculo=0;
        *obstaculo = rand()%4;
        altura = rand()%3;
        switch(*obstaculo)
            {
            case 0: // inicializa obstaculo terrestre pequeno
                {
                    for(j=0;j<3;j++)
                        for(i=0;i<4;i++)
                            {
                                (*inicializa)=1;
                                map[ini_linha_1+i][ini_coluna_1+j] = OBSTACULO;
                                textbackground(GREEN);
                                putchxy(j+ini_coluna_1, i+ini_linha_1, ' ');
                                textbackground(BLACK);
                            }
                }
            break;
            case 1: // inicializa obstaculo terrestre grande
                {
                    (*inicializa)=1;
                    for(j=0;j<7;j++)
                            {
                                if(j==2 || j==3 || j==4)
                                    {
                                        for(i=0;i<4;i++)
                                        {
                                            if(i==0)
                                            {
                                                map[ini_linha_2+i][ini_coluna_2+j] = FUNDO;
                                                putchxy(j+ini_coluna_2, i+ini_linha_2, ' ');
                                            }
                                                else if(i==1 || i==2 || i==3)
                                                    {
                                                        textbackground(GREEN);
                                                        map[ini_linha_2+i][ini_coluna_2+j] = OBSTACULO;
                                                        putchxy(j+ini_coluna_2, i+ini_linha_2, ' ');
                                                        textbackground(BLACK);
                                                    }
                                        }
                                    }
                                    else if(j==0 || j==1 || j==5 || j==6)
                                        {
                                            for(i=0;i<4;i++)
                                            {
                                                if(i==2 || i==3)
                                                    {
                                                        map[ini_linha_2+i][ini_coluna_2+j] = FUNDO;
                                                        putchxy(j+ini_coluna_2, i+ini_linha_2, ' ');
                                                    }
                                                    else if(i==0 || i==1)
                                                        {
                                                            textbackground(GREEN);
                                                            map[ini_linha_2+i][ini_coluna_2+j] = OBSTACULO;
                                                            putchxy(j+ini_coluna_2, i+ini_linha_2, ' ');
                                                            textbackground(BLACK);
                                                        }
                                            }
                                        }
                            }
                }
            break;
            case 2: // inicializa obstaculo aereo pequeno
                {
                    (*inicializa)=1;
                    switch(altura) // gera uma altura aleatoria para o obstaculo
                    {
                    case 0:
                        {
                            for(j=0;j<7;j++)
                                for(i=0;i<2;i++)
                                    {
                                        map[ini_linha_3+i][ini_coluna_3+j] = OBSTACULO;
                                        textbackground(GREEN);
                                        putchxy(j+ini_coluna_3, i+ini_linha_3, ' ');
                                        textbackground(BLACK);
                                    }
                        }
                    break;
                    case 1:
                        {
                            for(j=0;j<7;j++)
                                for(i=0;i<2;i++)
                                    {
                                        map[ini_linha_3+i-1][ini_coluna_3+j] = OBSTACULO;
                                        textbackground(GREEN);
                                        putchxy(j+ini_coluna_3, i+ini_linha_3-1, ' ');
                                        textbackground(BLACK);
                                    }

                        }
                    break;
                    case 2:
                        {
                             for(j=0;j<7;j++)
                                for(i=0;i<2;i++)
                                    {
                                        map[ini_linha_3+i-2][ini_coluna_3+j] = OBSTACULO;
                                        textbackground(GREEN);
                                        putchxy(j+ini_coluna_3, i+ini_linha_3-2, ' ');
                                        textbackground(BLACK);
                                    }
                        }
                    }
                }
            break;
            case 3: // inicializa obstaculo aereo grande
                {
                (*inicializa)=1;
                switch(altura) // gera uma altura aleatoria para o obstaculo
                {
                    case 0:
                        {
                            for(i=0;i<3;i++)
                                {
                                    if(i==0 || i==2)
                                        {
                                            for(j=0;j<7;j++)
                                                {
                                                    if(j==0)
                                                    {
                                                        map[ini_linha_4+i][ini_coluna_4+j] = FUNDO;
                                                        putchxy(ini_coluna_4+j, ini_linha_4+i, ' ');
                                                    }
                                                        else
                                                            {
                                                                textbackground(GREEN);
                                                                map[ini_linha_4+i][ini_coluna_4+j] = OBSTACULO;
                                                                putchxy(ini_coluna_4+j, ini_linha_4+i, ' ');
                                                                textbackground(BLACK);
                                                            }
                                                }
                                        }
                                        else
                                            {
                                                for(j=0;j<7;j++)
                                                    {
                                                        if(j==6)
                                                            {
                                                                map[ini_linha_4+i][ini_coluna_4+j] = FUNDO;
                                                                putchxy(ini_coluna_4+j, ini_linha_4+i, ' ');
                                                            }
                                                            else
                                                                {
                                                                    textbackground(GREEN);
                                                                    map[ini_linha_4+i][ini_coluna_4+j] = OBSTACULO;
                                                                    putchxy(ini_coluna_4+j, ini_linha_4+i, ' ');
                                                                    textbackground(BLACK);
                                                                }
                                                    }
                                            }
                                }
                        }
                    break;
                    case 1:
                        {
                            for(i=0;i<3;i++)
                                {
                                    if(i==0 || i==2)
                                        {
                                            for(j=0;j<7;j++)
                                                {
                                                    if(j==0)
                                                    {
                                                        map[ini_linha_4+i-1][ini_coluna_4+j] = FUNDO;
                                                        putchxy(ini_coluna_4+j, ini_linha_4+i-1, ' ');
                                                    }
                                                        else
                                                            {
                                                                textbackground(GREEN);
                                                                map[ini_linha_4+i-1][ini_coluna_4+j] = OBSTACULO;
                                                                putchxy(ini_coluna_4+j, ini_linha_4+i-1, ' ');
                                                                textbackground(BLACK);
                                                            }
                                                }
                                        }
                                        else
                                            {
                                                for(j=0;j<7;j++)
                                                    {
                                                        if(j==6)
                                                            {
                                                                map[ini_linha_4+i-1][ini_coluna_4+j] = FUNDO;
                                                                putchxy(ini_coluna_4+j, ini_linha_4+i-1, ' ');
                                                            }
                                                            else
                                                                {
                                                                    textbackground(GREEN);
                                                                    map[ini_linha_4+i-1][ini_coluna_4+j] = OBSTACULO;
                                                                    putchxy(ini_coluna_4+j, ini_linha_4+i-1, ' ');
                                                                    textbackground(BLACK);
                                                                }
                                                    }
                                            }
                                }
                        }
                    break;
                    case 2:
                        {
                            for(i=0;i<3;i++)
                        {
                            if(i==0 || i==2)
                                {
                                    for(j=0;j<7;j++)
                                        {
                                            if(j==0)
                                            {
                                                map[ini_linha_4+i-2][ini_coluna_4+j] = FUNDO;
                                                putchxy(ini_coluna_4+j, ini_linha_4+i-2, ' ');
                                            }
                                                else
                                                    {
                                                        textbackground(GREEN);
                                                        map[ini_linha_4+i-2][ini_coluna_4+j] = OBSTACULO;
                                                        putchxy(ini_coluna_4+j, ini_linha_4+i-2, ' ');
                                                        textbackground(BLACK);
                                                    }
                                        }
                                }
                                else
                                    {
                                        for(j=0;j<7;j++)
                                            {
                                                if(j==6)
                                                    {
                                                        map[ini_linha_4+i-2][ini_coluna_4+j] = FUNDO;
                                                        putchxy(ini_coluna_4+j, ini_linha_4+i-2, ' ');
                                                    }
                                                    else
                                                        {
                                                            textbackground(GREEN);
                                                            map[ini_linha_4+i-2][ini_coluna_4+j] = OBSTACULO;
                                                            putchxy(ini_coluna_4+j, ini_linha_4+i-2, ' ');
                                                            textbackground(BLACK);
                                                        }
                                            }
                                    }
                        }
                        }
                    break;
                }
                }
            }
    }

void movimenta_objeto(char map[LIN][COL], int *pos_obstaculo, int *inicializa, int *pontos, int *nivel, int *acoes, int *pos, int *selec, int *gameover, int *abaixando, int *pulando, int *vidas) // faz a movimentacao do obstaculo
    {
        int i,j;
        {
                if(*pos_obstaculo<=90 && *pos_obstaculo>=0) // move obstaculo para a esquerda
                    {
                        colisao(map, gameover, abaixando, acoes, vidas);
                        for(i=0;i<LIN;i++)
                            for(j=0;j<COL;j++)
                                {
                                    if(map[i][j] == OBSTACULO)
                                        {
                                            textbackground(BLACK);
                                            putchxy(j, i, ' ');
                                            textbackground(GREEN);
                                            putchxy(j-1, i, ' ');
                                            textbackground(BLACK);
                                            map[i][j] = FUNDO;
                                            map[i][j-1] = OBSTACULO;
                                        }
                                }
                        (*pos_obstaculo)++;
                    }
                    else if(*pos_obstaculo==91) // apaga o obstaculo, pois ele chegou ao seu limite
                        {
                            verifica_obstaculo(map);
                            (*pos_obstaculo)=0;
                            (*inicializa)=0;
                            verifica_trex(map);

                            for(i=0;i<LIN;i++)
                                for(j=0;j<COL;j++)
                                {
                                    if(map[i][j] == OBSTACULO)
                                    {
                                        map[i][j] == FUNDO;
                                        putchxy(j, i, ' ');
                                    }
                                }
                        }
                if(*pos_obstaculo==91) // soma pontos e/ou nivel
                {
                    *pontos = *pontos + 10;

                    for(i=0;i<LIN;i++)
                            for(j=0;j<COL;j++)
                            {
                                if(map[i][j] == '0')
                                    {
                                        textbackground(BLUE);
                                        gotoxy(j+1,i+1);
                                        printf("%d", *pontos);
                                        textbackground(BLACK);
                                    }
                                    else if(map[i][j] == 'L')
                                        {
                                            if((*pontos%100)==0)
                                                {
                                                    textbackground(BLUE);
                                                    (*nivel)++;
                                                    gotoxy(j+3, i+1);
                                                    printf("%d", *nivel);
                                                    textbackground(BLACK);
                                                }
                                                else if(map[i][j] == 'A')
                                                    {
                                                        if((*pontos%500)==0)
                                                            {
                                                                textbackground(BLUE);
                                                                (*vidas)++;
                                                                gotoxy(j+5, i+1);
                                                                printf("%d", *vidas);
                                                                textbackground(BLACK);
                                                            }
                                                    }
                                        }
                            }
                }
            }
    }

int main()
    {
        int acoes=1, pos=1, selec=1, fim=0, pulando = 0, abaixando=0, inicializa_obstaculo=0, obstaculo, pos_obstaculo=0, pontos=0, nivel=1, vidas=3, gameover=0;
        int vel=1;
        char map[LIN][COL], input, imput_highscore;
        SCORE jogador, highscores[TAM_HIGHSCORES];
        char mapa_jogo[50] = {"mapa.txt"};
        char mapa_menu[50] = {"menu.txt"};
        char mapa_score[50] = {"score.txt"};
        char mapa_jogador[50] = {"jogador.txt"};
        while(fim!=1)
        {

            switch(acoes)
            {
            case 1: // roda o menu
                    carrega_mapa(map, mapa_menu);
                    imprime_menu(map);
                    while(selec!=0)
                    {
                        escolhe_menu(map, &pos, &input, &selec, &gameover);
                    }
                    if(pos==1)
                        {
                            acoes=2;
                            pontos=0;
                            nivel=1;
                        }
                        else if(pos==2)
                            {
                                acoes=2;
                            }
                            else if(pos==3)
                                {
                                    acoes=4;
                                }
                                    else if(pos==4)
                                                {
                                                    acoes=6;
                                                }
            break;
            case 2: // roda o jogo
                    carrega_mapa(map, mapa_jogo);
                    imprime_jogo(map);
                    acoes=3;
            break;
            case 3: verifica_trex(map); // testa se trex esta na posicao correta
                    input_teclado(map, &input, &pulando, &abaixando, &pos, &acoes, &selec);
                    if(pulando == ALTURA_DO_PULO)
                        {
                            pulando *= -1; // pulando = -5
                        }
                        else if(pulando > 0)
                            {
                                pular(map, &pulando, &abaixando);
                            }
                            else if(pulando < 0)
                                {
                                    descer(map, &pulando, &abaixando);
                                }
                                else if(abaixando<TEMPO_ABAIXADO && abaixando>0)
                                    {
                                        abaixar(map, &abaixando, &pulando);
                                        if(abaixando==TEMPO_ABAIXADO)
                                        {
                                            abaixando=0;
                                            trex_retorna(map);
                                        }
                                    }
                        vel = (nivel/10)+vel; // aumenta a velocidade do jogo
                        Sleep(30/vel);
                        if(inicializa_obstaculo==0)
                            {
                                random_objeto(map, &inicializa_obstaculo, &obstaculo); // lembrar de igualar a variavel "inicializa_obstaculo" a zero quando o obstaculo chegar no limite !!!
                            }
                            else if(inicializa_obstaculo==1)
                            {
                                movimenta_objeto(map, &pos_obstaculo, &inicializa_obstaculo, &pontos, &nivel, &acoes, &pos, &selec, &gameover, &abaixando, &pulando, &vidas);
                            }
            break;
            case 4: // funcoes para visualizar os highscores e voltar ao menu com a tecla esc
                    clrscr();
                    carrega_mapa(map,mapa_score);
                    imprime_highscore(map);
                    imput_highscore=0;
                    while(imput_highscore!=ESC)
                        {
                            if(_kbhit())
                            {
                                if(_kbhit())
                                imput_highscore = _getch();
                            }
                        }
                    clrscr();
                    pos=1;
                    acoes=1;
                    selec=1;

            break;
            case 5: // funcoes que fazem a leitura do nome do jogador e verifica se ele ficou no top 10 e, caso fique, coloca na posicao correta do ranking
                {
                    clrscr();
                    carrega_mapa(map, mapa_jogador);
                    imprime_map_jog(map);
                    le_jogador(map, &jogador, &pontos);
                    le_highscores(highscores);
                    //mostra(highscores);
                    //system("pause");
                    clrscr();
                    pos=1;
                    acoes=1;
                    selec=1;
                }
            break;
            case 6: // encerra o programa
                        fim=1;
                        printf("\n\n\n ");
            break;
            }
        }

        printf("\n\n\n\n\n");
        return 0;
    }
