#include "SOIL/SOIL.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Eng.BAS.h"
#include "Eng.BAS.Apresentacao.h"
#include "Eng.BAS.Texturas.h"
#include "Eng.BAS.Personagens.h"
#include "Eng.BAS.Mouse.h"

/*
GLOBAL
0 -> Apresentacao
1 -> Transição
2 -> Menu
3 -> Jogar
4 -> Opções
5 -> Instruções
6 -> 1Player
7 -> 2Player

*/

void init(){
  posy=0.45*dimensaoy;
  posxSubMenu=0.5*dimensaox;
  posySubMenu=0.5*dimensaoy;
  diferencay_SubMenu=0.2*dimensaoy;
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  c=cor=cor2=cor3=alfa=0;
  //alfa=1;
  global=0;
  Player1.posx=0.1*dimensaox;
  Player1.posy=0.2*dimensaoy;
  Player1.direcao=0;
  Player1.bebado=1;
  Player2.posx=0.9*dimensaox;
  Player2.posy=0.2*dimensaoy;
  Player2.direcao=1;
  Player2.bebado=1;
  Player1.vidas=3;
  Player2.vidas=3;
  TelaSeta=0;
  tempo=1;
  velocidade=1.57;
  def=-1;
  srand(time(0));
  angle=rand()%90;
  TelaCheat=TelaForca=0;
  compensa=0;
  forca=0;
}

void timer(int n){
  switch(global){
    case 0:
      mudacor();
      glutTimerFunc(150, timer, 0);
      break;
    case 1:
      atualiza();
      glutTimerFunc(15, timer, 0);
      break;
    case 3:
    case 4:
    case 5:
      glutSwapBuffers();
    break;
    }
}


void desenhaJogadores(GLuint textura){
  glClear(GL_COLOR_BUFFER_BIT);
  desenhaTextura(0,0);
  posicionaBotao(texturaBotao,0.2*dimensaox,0.3*dimensaoy);
  colocaTextoBotao(texturaSeta,0.18*dimensaox, 0.315*dimensaoy,-0.05*dimensaox, 0.04*dimensaoy);
  posicionaBotao(texturaBotao,0.8*dimensaox,0.3*dimensaoy);
  colocaTextoBotao(texturaSeta,0.8*dimensaox, 0.315*dimensaoy,0.05*dimensaox, 0.04*dimensaoy);
  if(textura==texturaJogador1)
    colocaTextoBotao(textura,posxSubMenu,0.8*dimensaoy,0.2*dimensaox,0.15*dimensaoy);
  else
    colocaTextoBotao(textura,posxSubMenu,0.8*dimensaoy,0.21*dimensaox,0.15*dimensaoy);
  posicionaBotao(texturaBotao, 0.32*dimensaox, 0.06*dimensaoy);
  colocaTextoBotao(texturaVoltar,0.32*dimensaox-(0.01*dimensaox),(0.06*dimensaoy)+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
  posicionaBotao(texturaBotao,0.72*dimensaox, 0.06*dimensaoy);
  colocaTextoBotao(texturaContinuar,0.72*dimensaox-(0.01*dimensaox),(0.06*dimensaoy)+(0.01*dimensaoy),0.08*dimensaox,0.03*dimensaoy);
  colocaTextoBotao((*personagemMomento).textura,0.5*dimensaox, 0.4*dimensaoy, 0.1*dimensaox, 0.2*dimensaoy);
  glutSwapBuffers();

}

void posicionaTela(GLuint textura){
  colocaTextoBotao(textura, 0.5*dimensaox, 0.5*dimensaoy,0.20*dimensaox,0.20*dimensaoy);
  colocaTextoBotao(texturaBotao, 0.42*dimensaox, 0.38*dimensaoy, 0.15*dimensaox,0.10*dimensaoy);
  colocaTextoBotao(texturaBotao, 0.58*dimensaox, 0.38*dimensaoy, 0.15*dimensaox,0.10*dimensaoy);
  colocaTextoBotao(texturaSim, 0.41*dimensaox, 0.39*dimensaoy,0.04*dimensaox,0.02*dimensaoy);
  colocaTextoBotao(texturaNao, 0.57*dimensaox, 0.39*dimensaoy,0.04*dimensaox,0.02*dimensaoy);
}

void colocaPlayer(GLuint textura, int x, int opcao){
  if(opcao==0)
    colocaTextoBotao(textura, x, 26, 3, 6);
  else
    colocaTextoBotao(textura, x, 26, -3, 6);
}

void HUT(GLuint texturaP1, int vidasP1, int bebadoP1,GLuint texturaP2, int vidasP2, int bebadoP2){
    int i=0;

    if(Player2.bebado>=50 || Player1.bebado>=50){
      TelaVencedor=1;
        if(Player1.bebado>=50){
          if(Player1.textura==texturaCefet1)
            colocaTextoBotao(texturaZoaCefet,0.5*dimensaox,0.5*dimensaoy,50,20);
          else if(Player1.textura==texturaPuc1)
            colocaTextoBotao(texturaZoaPuc,0.5*dimensaox,0.5*dimensaoy,50,20);
          else if(Player1.textura==texturaUfop1)
            colocaTextoBotao(texturaZoaUFOP,0.5*dimensaox,0.5*dimensaoy,50,20);
          colocaTextoBotao(Player2.textura, 0.63*dimensaox, 0.45*dimensaoy, 10,10);
        }
        else{
          if(Player2.textura==texturaCefet1)
            colocaTextoBotao(texturaZoaCefet,0.5*dimensaox,0.5*dimensaoy,50,20);
          else if(Player2.textura==texturaPuc1)
            colocaTextoBotao(texturaZoaPuc,0.5*dimensaox,0.5*dimensaoy,50,20);
          else if(Player2.textura==texturaUfop1)
            colocaTextoBotao(texturaZoaUFOP,0.5*dimensaox,0.5*dimensaoy,50,20);
          colocaTextoBotao(Player1.textura, 0.63*dimensaox, 0.45*dimensaoy, 10,10);
        }
    }
    else{

    if(TelaSeta==1 || TelaForca==1){
      colocaTextoBotao(Projetil.textura, 0.5*dimensaox, 0.9*dimensaoy,6,6);
    }

    if(bebadoP1<10){
      colocaTextoBotao(texturaVomito1,Player1.posx,0.1*dimensaoy,6,6);
      glColor4f(0,1,0,1);
      if(bebadoP1>5){
        g=9-bebadoP1;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=5-bebadoP1;
        g=g/4;
        g=(g*0.02);
      }
    }
    else if(bebadoP1<20){
      colocaTextoBotao(texturaVomito2,Player1.posx,0.10*dimensaoy,6,6);
      glColor4f(0,0,1,1);
      if(bebadoP1>15){
        g=19-bebadoP1;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=15-bebadoP1;
        g=g/5;
        g=(g*0.02);
      }
    }
    else if(bebadoP1<30){
      colocaTextoBotao(texturaVomito3,Player1.posx,0.10*dimensaoy,6,6);
      glColor4f(0.5,0.5,0,1);
      if(bebadoP1>25){
        g=29-bebadoP1;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=25-bebadoP1;
        g=g/5;
        g=(g*0.02);
      }
    }
    else if(bebadoP1<40){
      colocaTextoBotao(texturaVomito4,Player1.posx,0.10*dimensaoy,6,6);
      glColor4f(0.7,0.3,0,1);
      if(bebadoP1>35){
        g=39-bebadoP1;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=35-bebadoP1;
        g=g/5;
        g=(g*0.02);
      }
    }
    else{
      colocaTextoBotao(texturaVomito5,Player1.posx,0.10*dimensaoy,6,6);
      glColor4f(1,0,0,1);
      if(bebadoP1>45){
        g=49-bebadoP1;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=45-bebadoP1;
        g=g/5;
        g=(g*0.02);
      }
    }
      glBegin(GL_LINE_STRIP);
        glVertex3f(Player1.posx-(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player1.posx-(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player1.posx+(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player1.posx+(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player1.posx-(0.02*dimensaox),0.03*dimensaoy,0);
      glEnd();
      if(bebadoP1==1 || bebadoP1==10 || bebadoP1==20 || bebadoP1==30|| bebadoP1==40){
        g=0.02;
      }

      glBegin(GL_POLYGON);
        glVertex3f(Player1.posx-(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player1.posx-(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player1.posx+(g*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player1.posx+(g*dimensaox),0.03*dimensaoy,0);
      glEnd();

    if(bebadoP2<10){
      colocaTextoBotao(texturaVomito1,Player2.posx,0.10*dimensaoy,6,6);
      glColor4f(0,1,0,1);
      if(bebadoP2>5){
        g=9-bebadoP2;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=5-bebadoP2;
        g=g/4;
        g=(g*0.02);
      }
    }
    else if(bebadoP2<20){
      colocaTextoBotao(texturaVomito2,Player2.posx,0.10*dimensaoy,6,6);
      glColor4f(0,0,1,1);
      if(bebadoP2>15){
        g=19-bebadoP2;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=15-bebadoP2;
        g=g/5;
        g=(g*0.02);
      }
    }
    else if(bebadoP2<30){
      colocaTextoBotao(texturaVomito3,Player2.posx,0.10*dimensaoy,6,6);
      glColor4f(0.5,0.5,0,1);
      if(bebadoP2>25){
        g=29-bebadoP2;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=25-bebadoP2;
        g=g/5;
        g=(g*0.02);
      }
    }
    else if(bebadoP2<40){
      colocaTextoBotao(texturaVomito4,Player2.posx,0.10*dimensaoy,6,6);
      glColor4f(0.7,0.3,0,1);
      if(bebadoP2>35){
        g=39-bebadoP2;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=35-bebadoP2;
        g=g/5;
        g=(g*0.02);
      }
    }
    else{
      colocaTextoBotao(texturaVomito5,Player2.posx,0.10*dimensaoy,6,6);
      glColor4f(1,0,0,1);
      if(bebadoP2>45){
        g=49-bebadoP2;
        g=g/4;
        g=1-g;
        g=-(g*0.02);
      }
      else{
        g=45-bebadoP2;
        g=g/5;
        g=(g*0.02);
      }
    }
      glBegin(GL_LINE_STRIP);
        glVertex3f(Player2.posx-(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player2.posx-(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player2.posx+(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player2.posx+(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player2.posx-(0.02*dimensaox),0.03*dimensaoy,0);
      glEnd();

      glBegin(GL_POLYGON);
        glVertex3f(Player2.posx-(0.02*dimensaox),0.03*dimensaoy,0);
        glVertex3f(Player2.posx-(0.02*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player2.posx+(g*dimensaox),0.04*dimensaoy,0);
        glVertex3f(Player2.posx+(g*dimensaox),0.03*dimensaoy,0);
      glEnd();

    //  printf("Player1.bebado = %d\nPlayer2.bebado = %d\n",bebadoP1,bebadoP2);
    }
}
void animacaoTaca(int opcao){
  if(PlayerMomento%2==0){
    if(opcao==1)
      Player2.textura=Player2.vetor[2];
    else if(opcao==2)
      Player2.textura=Player2.vetor[3];
    else if(opcao==3)
      Player2.textura=Player2.vetor[0];
  }
  else{
    if(opcao==1)
      Player1.textura=Player1.vetor[2];
    else if(opcao==2)
      Player1.textura=Player1.vetor[3];
    else if(opcao==3)
      Player1.textura=Player1.vetor[0];
  }
}

void desenha(){
int y;
  switch (global) {
    case 0:
      escreve();
      glClearColor(cor, cor2, cor3, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      escreveTexto(GLUT_BITMAP_9_BY_15, v, 25, 50);
      glutSwapBuffers();
      if(strcmp(string, v)==0){
       global++;
       glClear(GL_COLOR_BUFFER_BIT);
      }
      c++;
      glutTimerFunc(185, atualiza, 0);
    break;

    case 1:
      desenhaTextura(0,0);
      glutSwapBuffers();
      alfa=alfa+0.0004;
      glClearColor(cor, cor, cor,0);
      cor=cor-0.01;
      if(alfa>0.02)
        alfa=alfa+0.01;
      if(alfa>1){
        global++;
        glutTimerFunc(15, atualiza, 0);
      }
    break;

    case 2:
      menu();
    break;

    case 3:
	glClear(GL_COLOR_BUFFER_BIT);
        desenhaTextura(0,0);
        y=posySubMenu;
        for(b=0; b<4; b++){
          posicionaBotao(texturaBotao,posxSubMenu, y);
          y=y-diferencay_SubMenu;
        }

          colocaTextoBotao(texturaJogar,posxSubMenu,0.8*dimensaoy,0.2*dimensaox,0.15*dimensaoy);
          colocaTextoBotao(textura1Jogador,posxSubMenu-(0.02*dimensaox),posySubMenu+(0.01*dimensaoy),0,0);
          colocaTextoBotao(textura2Jogadores,posxSubMenu-(0.02*dimensaox),(posySubMenu-diferencay_SubMenu)+(0.01*dimensaoy),0,0);
          colocaTextoBotao(texturaVoltar,posxSubMenu-(0.01*dimensaox),(posySubMenu-(2*diferencay_SubMenu))+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
        glutSwapBuffers();
    break;
    case 4:
        desenhaTextura(0,0);
        y=posySubMenu;
        for(b=0; b<4; b++){
          posicionaBotao(texturaBotao,posxSubMenu, y);
          y=y-diferencay_SubMenu;
        }

        colocaTextoBotao(texturaOpcoes,posxSubMenu,0.8*dimensaoy,0.2*dimensaox,0.15*dimensaoy);
        colocaTextoBotao(textura1Jogador,posxSubMenu-(0.02*dimensaox),posySubMenu+(0.01*dimensaoy),0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-(0.02*dimensaox),(posySubMenu-diferencay_SubMenu)+(0.01*dimensaoy),0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-(0.01*dimensaox),(posySubMenu-(2*diferencay_SubMenu))+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
        glutSwapBuffers();
    break;

    case 5:
        desenhaTextura(0,0);
        y=posySubMenu;
        for(b=0; b<4; b++){
          posicionaBotao(texturaBotao,posxSubMenu, y);
          y=y-diferencay_SubMenu;
        }

        colocaTextoBotao(texturaInstrucoes,posxSubMenu,0.8*dimensaoy,0.2*dimensaox,0.15*dimensaoy);
        colocaTextoBotao(textura1Jogador,posxSubMenu-(0.02*dimensaox),posySubMenu+(0.01*dimensaoy),0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-(0.02*dimensaox),(posySubMenu-diferencay_SubMenu)+(0.01*dimensaoy),0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-(0.01*dimensaox),(posySubMenu-(2*diferencay_SubMenu))+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
        glutSwapBuffers();
    break;
    case 6:
        desenhaJogadores(texturaJogador1);
    break;
    case 7:
        desenhaJogadores(texturaJogador2);
    break;
    case 8:
    if(TelaSeta==0 && TelaProjetil==0 && TelaForca==0 && TelaAndando==1){
      if(PlayerMomento%2==0)
          PlayerJogando=Player1;
        else
          PlayerJogando=Player2;

        if(PlayerJogando.posx==Player2.posx && DoisJogadores==0){
          numero=rand()%20;
          //printf("numero = %d\n", numero);
          if(rand()%2==0){
            do{
            if(contador>=numero){
              TelaSeta=1;
              TelaAndando=0;
            }
              condicao1=0.98*dimensaox;
              condicao2=1;
            if(PlayerJogando.posx<condicao1 || PlayerJogando.direcao==condicao2){
            if(PlayerJogando.direcao==1){
              PlayerJogando.direcao=0;
            }
            else{
            if(variavel==1){
                PlayerJogando.textura=PlayerJogando.vetor[0];
                variavel=0;
            }
            else{
                PlayerJogando.textura=PlayerJogando.vetor[1];
                variavel=1;
            }
                PlayerJogando.posx=PlayerJogando.posx+0.005*dimensaox;
                contador++;
            }
          }
          else{
            contador=numero;
          }
          Player2=PlayerJogando;
          colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
          colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
          colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
          glutSwapBuffers();
          //printf("Contador = %d\n", contador);
          }while(contador!=numero);
          contador=0;
          TelaAndando=0;
          TelaSeta=1;
          Player2.direcao=PlayerJogando.direcao=1;
          }
          else{
            do{
            if(contador>=numero){
              TelaSeta=1;
              TelaAndando=0;
            }
            condicao1=(dimensaox/2)+0.15*dimensaox;
            condicao2=0;
            if(PlayerJogando.posx>condicao1 || PlayerJogando.direcao==condicao2){
            if(PlayerJogando.direcao==0){
              PlayerJogando.direcao=1;
            }
            else{
            if(variavel==1){
                PlayerJogando.textura=PlayerJogando.vetor[0];
                variavel=0;
            }
            else{
                PlayerJogando.textura=PlayerJogando.vetor[1];
                variavel=1;
            }
                PlayerJogando.posx=PlayerJogando.posx-0.005*dimensaox;
                contador++;
            }
          }
          else{
            contador=numero;
          }
          Player2=PlayerJogando;
          colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
          colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
          colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
          glutSwapBuffers();
          //printf("Contador = %d\n", contador);
          }while(contador!=numero);
          contador=0;
          TelaAndando=0;
          TelaSeta=1;
          Player2.direcao=PlayerJogando.direcao=1;
          }
          if(rand()%2==0)
            Projetil.textura=texturaCerveja;
          else
            Projetil.textura=texturaCachaca;
          }
          colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
          colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
          colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
        }

    else if(TelaSeta==1 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0 || TelaForca==1){
      float soma=0, soma2=0;
      if(PlayerJogando.posx==Player1.posx)
        define=1;
      else
        define=-1;

      colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
      glPushMatrix();
          glTranslatef((PlayerJogando.posx),(PlayerJogando.posy+0.13*dimensaoy),0);
            glRotatef(angle, 0, 0, 1);
          glTranslatef(-(PlayerJogando.posx),-(PlayerJogando.posy+0.13*dimensaoy),0);
          colocaTextoBotao(texturaSeta,PlayerJogando.posx+(0.03*dimensaox*define),PlayerJogando.posy+0.13*dimensaoy,define*0.03*dimensaox,0.03*dimensaoy);
      glPopMatrix();
      colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
      colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
      if(TelaCheat==1){
      if(PlayerJogando.posx==Player2.posx){
      velocidadey=-sin((angle*pi)/180)*velocidade;
      velocidadex=-cos((angle*pi)/180)*velocidade;
      }
      else{
        velocidadey=sin((angle*pi)/180)*velocidade;
        velocidadex=cos((angle*pi)/180)*velocidade;
      }
      glColor4f(0,0,0,1);
      glLineWidth(1.5);
      glBegin(GL_LINE_STRIP);
      Projetil.posx=PlayerJogando.posx;
      Projetil.posy=PlayerJogando.posy+0.13*dimensaoy;
        for(teste1=1,soma=Projetil.posx, soma2=Projetil.posy; teste1<100 ;teste1=teste1+0.05){
          if(teste1<=velocidadey/10){
            def=1;
          }
          else{
            def=-1;
          }
          glVertex3f(soma,soma2,0);
          soma=soma+(velocidadex*teste1);
          soma2=soma2+((velocidadey*teste1)+(0.4*def*pow(teste1,2)));
        }
      glEnd();
    }

    if(define==-1 && DoisJogadores==0){
      velocidadey=-sin((angle*pi)/180)*velocidade;
      velocidadex=-cos((angle*pi)/180)*velocidade;
      Projetil.posx=PlayerJogando.posx;
      Projetil.posy=PlayerJogando.posy+0.13*dimensaoy;
          for(teste1=1,soma=Projetil.posx, soma2=Projetil.posy; teste1<100 ;teste1=teste1+0.05){
            if(teste1<=velocidadey/10){
              def=1;
            }
            else{
              def=-1;
            }
            soma=soma+(velocidadex*teste1);
            soma2=soma2+((velocidadey*teste1)+(0.4*def*pow(teste1,2)));
            if(soma<=Player1.posx+3 && soma>=Player1.posx-3 && soma2<=Player1.posy+6 && soma2>=Player1.posy-6){
              TelaSeta=0;
              TelaForca=1;
              var=0;
            }
          }
          if(TelaSeta==1){
            if(angle>-90){
              angle--;
          }
          else{
            var=3;
          }
          if(var==3){
            angle=angle+2;
          }
          glutTimerFunc(50, atualiza, 0);

    }

    }
  }
    else if(TelaProjetil==1 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0){
      colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
      colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
      colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
      glPushMatrix();
          glTranslatef(Projetil.posx,Projetil.posy,0);
            glRotatef(soma, 0, 0, 1);
          glTranslatef(-Projetil.posx,-Projetil.posy,0);
          colocaTextoBotao(Projetil.textura, Projetil.posx, Projetil.posy, 3,3);
      glPopMatrix();

      if(PlayerJogando.bebado<20)
        loucura=4;
      else if(PlayerJogando.bebado<30)
        loucura=7;
      else if(PlayerJogando.bebado<40)
        loucura=13;
      else loucura=20;
      if(PlayerJogando.bebado<10)
        erro=0;
      else{
        erro=PlayerJogando.bebado%loucura;
      }
        if(PlayerJogando.bebado%2==0){
          t=1;
        }
        else{
          t=-1;
        }
        /*printf("Player.bebado = %d\n", PlayerJogando.bebado);
        printf("erro = %d\n",PlayerJogando.bebado%loucura*t);*/
      if(PlayerJogando.posx==Player2.posx){
      velocidadey=-sin(((angle+(PlayerJogando.bebado%loucura*t))*pi)/180)*velocidade;
      velocidadex=-cos(((angle+(PlayerJogando.bebado%loucura*t))*pi)/180)*velocidade;
      }
      else{
        velocidadey=sin(((angle+(PlayerJogando.bebado%loucura*t))*pi)/180)*velocidade;
        velocidadex=cos(((angle+(PlayerJogando.bebado%loucura*t))*pi)/180)*velocidade;
      }
      //printf("velocidadex = %f\nvelocidadey = %f\n", velocidadex, velocidadey);
      if(tempo<=velocidadey/10){
        def=1;
      }
      else{
        def=-1;
      }
      soma+=7;
      Projetil.posx=Projetil.posx +(velocidadex*tempo);
      Projetil.posy=Projetil.posy+((velocidadey*tempo)+(0.4*def*pow(tempo,2)));
      tempo+=0.05;
      if(Projetil.posy<=PlayerJogando.posy){
        tempo=1;
        TelaProjetil=0;
        global=9;
        velocidade=1.57;
        srand(time(0));
        angle=(-define)*rand()%90;
      }
      if(PlayerJogando.posx==Player1.posx){
        if(Projetil.posx>=Player2.posx-0.015*dimensaox && Projetil.posx<=Player2.posx+0.015*dimensaox){
        if(Projetil.posy>=Player2.posy-0.09*dimensaoy && Projetil.posy<=Player2.posy+0.12*dimensaoy){
          tempo=1;
          global=9;
          velocidade=1.57;
          glutTimerFunc(0,animacaoTaca,2);
          colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
          colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
          colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);
          glutTimerFunc(200,animacaoTaca,3);
          //printf("Minimo em x: %f\nMaximo em x: %f\nMinimo em y: %f\nMaximo em y: %f\n",Player2.posx-0.015*dimensaox,Player2.posx+0.015*dimensaox,Player2.posy-0.06*dimensaoy,Player2.posy+0.06*dimensaoy);
          //printf("Posx: %f\nPosy: %f\n",Projetil.posx, Projetil.posy);
          TelaProjetil=0;
          srand(time(0));
          angle=(-define)*rand()%90;
          if(Projetil.textura==texturaCerveja)
            Player2.bebado=Player2.bebado+(rand()%3+1);
          else
            Player2.bebado=Player2.bebado+(rand()%3+3);
        //  printf("Player Bebado = %d\n", Player2.bebado);
        }
      }
      }
      else{
        if(Projetil.posx>=Player1.posx-0.015*dimensaox && Projetil.posx<=Player1.posx+0.015*dimensaox){
        if(Projetil.posy>=Player1.posy-0.09*dimensaoy && Projetil.posy<=Player1.posy+0.12*dimensaoy){
          tempo=1;
          global=9;
          velocidade=1.57;
          glutTimerFunc(0,animacaoTaca,2);
          glutSwapBuffers();
          glutTimerFunc(200,animacaoTaca,3);
          //printf("Minimo em x: %f\nMaximo em x: %f\nMinimo em y: %f\nMaximo em y: %f\n",Player2.posx-0.015*dimensaox,Player2.posx+0.015*dimensaox,Player2.posy-0.06*dimensaoy,Player2.posy+0.06*dimensaoy);
          //printf("Posx: %f\nPosy: %f\n",Projetil.posx, Projetil.posy);
          TelaProjetil=0;
          srand(time(0));
          angle=(-define)*rand()%90;
          if(Projetil.textura==texturaCerveja)
            Player1.bebado=Player1.bebado+(rand()%3+1);
          else
            Player1.bebado=Player1.bebado+(rand()%3+3);
        }
      }
      }
        glutTimerFunc(100,atualiza,0);
    }
     if(TelaForca==1 && TelaVencedor==0){
      /*colocaTextoBotao(texturaFundoJogo,0.5*dimensaox,0.5*dimensaoy,dimensaox/2,dimensaoy/2);
      colocaPlayer(Player1.textura, Player1.posx, Player1.direcao);
      colocaPlayer(Player2.textura, Player2.posx, Player2.direcao);*/
      glColor4f(0,0,0,1);
      glBegin(GL_LINE_STRIP);
        glVertex3f(0.5*dimensaox-0.1*dimensaox, 0.10*dimensaoy-0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox-0.1*dimensaox, 0.10*dimensaoy+0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox+0.1*dimensaox, 0.10*dimensaoy+0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox+0.1*dimensaox, 0.10*dimensaoy-0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox-0.1*dimensaox, 0.10*dimensaoy-0.05*dimensaoy, 0);
      glEnd();
      glBegin(GL_POLYGON);
        glVertex3f(0.5*dimensaox-0.1*dimensaox, 0.10*dimensaoy-0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox-0.1*dimensaox, 0.10*dimensaoy+0.05*dimensaoy, 0);
        glVertex3f(0.5*dimensaox-0.1*dimensaox+(forca*dimensaox),0.1*dimensaoy+0.05*dimensaoy,0);
        glVertex3f(0.5*dimensaox-0.1*dimensaox+(forca*dimensaox),0.1*dimensaoy-0.05*dimensaoy,0);
      glEnd();
      if(TelaPause==0 && TelaSair==0 && TelaReiniciar==0){
      if(forca>=0.2){
        compensa=1;
      }
      if(compensa!=1 && PlayerJogando.bebado<40){
        forca=forca+0.005;
      }
      else if(compensa!=1 && PlayerJogando.bebado>=40)
        forca+=0.01;
      if(compensa==1 && PlayerJogando.bebado<40){
        forca=forca-0.005;
        if(forca<=0.01){
          compensa=0;
        }
      }
      else if(compensa==1 && PlayerJogando.bebado>=40){
        forca=forca-0.01;
        if(forca<=0.01){
          compensa=0;
        }
  }
  velocidade=(forca*0.7/0.2)+1;
  if(PlayerMomento%2==1 && DoisJogadores==0){
    if(PlayerJogando.bebado<20)
      loucura=4;
    else if(PlayerJogando.bebado<30)
      loucura=7;
    else if(PlayerJogando.bebado<40)
      loucura=13;
    else loucura=20;
    if(PlayerJogando.bebado<10)
      erro=0;
    else{
      erro=PlayerJogando.bebado%loucura;
    }
      if(PlayerJogando.bebado%2==0){
        t=1;
      }
      else{
        t=-1;
      }
      velocidadey=-sin(((angle*pi)/180))*velocidade;
      velocidadex=-cos(((angle*pi)/180))*velocidade;
      for(teste1=1,s1=Projetil.posx, s2=Projetil.posy; teste1<200 ;teste1=teste1+0.05){
        if(teste1<=velocidadey/10){
          def=1;
        }
        else{
          def=-1;
        }
        s1=s1+(velocidadex*teste1);
        s2=s2+((velocidadey*teste1)+(0.4*def*pow(teste1,2)));
        if(s1<=Player1.posx+1.5 && s1>=Player1.posx-1.5 && s2<=Player1.posy+6 && s2>=Player1.posy-6){
          printf("oi\n");
          TelaProjetil=1;
          TelaForca=0;
          PlayerMomento++;
          break;
        }
      }
  }
    }

      glutTimerFunc(30, atualiza, 0);
    }
    if(TelaSair==1){
      alfa=0.8;
      posicionaTela(texturaTelaSair);
    }
    else if(TelaReiniciar==1){
      alfa=0.8;
      posicionaTela(texturaTelaReiniciar);
    }
    else if(TelaPause==1){
      alfa=0.8;
      colocaTextoBotao(texturaTelaPause, 0.5*dimensaox, 0.5*dimensaoy,0.20*dimensaox,0.20*dimensaoy);
    }
    alfa=1;
    HUT(Player1.textura,Player1.vidas,Player1.bebado,Player2.textura,Player2.vidas,Player2.bebado);
    glutSwapBuffers();
    if(TelaProjetil==1 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0)
      glutTimerFunc(30,atualiza,0);
    break;
    case 9:
          TelaAndando=1;
          global=8;
    break;
  }
}

void redimensiona(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, dimensaox, 0, dimensaoy, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void teclado(unsigned char key, int x, int y)
{
   switch (global) {
     case 0:
        if(key>0)
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
          global++;
        break;
      case 2:
        switch (key) {
          case 27:
            exit(0);
        }
        break;
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
        switch (key) {
          case 27:
            exit(0);
        }
      case 8:
        switch (key){
          case 27:
              if(TelaReiniciar==0 && TelaPause==0 && TelaVencedor==0){
                if(TelaSair==0){
                TelaSair=1;
                glutPostRedisplay();
              }

              else{
                TelaSair=0;
                glutPostRedisplay();
              }
            }
            else if(TelaVencedor==1){
              setup();
              global=2;
              glutPostRedisplay();
            }
          break;
          case 'c':
          case 'C':
              if(TelaSeta==1 && TelaSair==0 && TelaReiniciar==0 && TelaPause==0 || TelaForca==1){
                if(TelaCheat==0){
                  TelaCheat=1;
                }
                else
                  TelaCheat=0;
                  glutTimerFunc(30, atualiza, 0);

              }
          break;
          case 'r':
          case 'R':
                if(TelaSair==0 && TelaPause==0 && TelaVencedor==0){
                  if(TelaReiniciar==0){
                  TelaReiniciar=1;
                  glutPostRedisplay();
                }

                else{
                  TelaReiniciar=0;
                  glutPostRedisplay();
                }
              }
          break;
          case 'p':
          case 'P':
                if(TelaReiniciar==0 && TelaSair==0 && TelaVencedor==0){
                if(TelaPause==0){
                  TelaPause=1;
                }
                else{
                  TelaPause=0;
                }
                glutPostRedisplay();
              }
          break;
          case 'k':
          case 'K':
              if(TelaPause==0 && TelaSair==0 && TelaReiniciar==0 && TelaProjetil==0 && TelaVencedor==0 && DoisJogadores==1 || DoisJogadores==0 && PlayerMomento%2==0 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0 && TelaProjetil==0 && TelaVencedor==0){
                if(TelaSeta==1 ){
                  TelaSeta=0;
                  Projetil.posx=PlayerJogando.posx;
                  Projetil.posy=PlayerJogando.posy+0.13*dimensaoy;
                  TelaForca=1;
                  contador=0;
                  //angle=(-define)*rand()%90;
                  //PlayerMomento++;
                }
                else if(TelaForca==1){
                  TelaForca=0;
                  TelaProjetil=1;
                  glutTimerFunc(100,animacaoTaca,1);
                  glutTimerFunc(200,animacaoTaca,2);
                  glutTimerFunc(300,animacaoTaca,3);
                  PlayerMomento++;
                }
                else if (TelaAndando==1){
                  srand(time(0));
                  if(rand()%2==0)
                    Projetil.textura=texturaCerveja;
                  else
                    Projetil.textura=texturaCachaca;
                  if(PlayerMomento%2==0)
                    Player1.direcao=0;
                  else
                    Player2.direcao=1;
                contador=0;
                TelaSeta=1;
                TelaAndando=0;
              }
              glutPostRedisplay();
              }
          break;
          case 'd':
          case 'D':
          if(TelaPause==0 && TelaSair==0 && TelaReiniciar==0 && DoisJogadores==1 && TelaSeta==0 && TelaProjetil==0 && TelaForca==0 && TelaAndando==1 && TelaVencedor==0 || DoisJogadores==0 && PlayerMomento%2==0 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0 && TelaSeta==0 && TelaProjetil==0 && TelaForca==0 && TelaAndando==1 && TelaVencedor==0){
            if(contador>=20){
              if(PlayerJogando.posx==Player2.posx){
                Player2.direcao=PlayerJogando.direcao=-1;
              }
              contador=0;
              TelaSeta=1;
              TelaAndando=0;
              srand(time(0));
              if(rand()%2==0)
                Projetil.textura=texturaCerveja;
              else
                Projetil.textura=texturaCachaca;
            }
            if(PlayerMomento%2==0){
              PlayerJogando=Player1;
            }
            else
              PlayerJogando=Player2;
            if(PlayerJogando.posx==Player1.posx){
              condicao1=(dimensaox/2)-0.15*dimensaox;
              condicao2=1;
            }
            else{
              condicao1=0.98*dimensaox;
              condicao2=1;
            }
            if(PlayerJogando.posx<condicao1 || PlayerJogando.direcao==condicao2){
            if(PlayerJogando.direcao==1){
              PlayerJogando.direcao=0;
            }
            else{
              if(PlayerMomento%2!=0)
                if(PlayerJogando.direcao==-1)
                  PlayerJogando.direcao=1;
            if(variavel==1){
                PlayerJogando.textura=PlayerJogando.vetor[0];
                variavel=0;
            }
            else{
                PlayerJogando.textura=PlayerJogando.vetor[1];
                variavel=1;
            }
                PlayerJogando.posx=PlayerJogando.posx+0.005*dimensaox;
                contador++;
            }
            if(PlayerMomento%2==0){
              Player1=PlayerJogando;
            }
            else{
              Player2=PlayerJogando;
            }
          }
                glutPostRedisplay();
          }
          else if(TelaSeta==1 && TelaSair==0 &&  DoisJogadores==1 && TelaPause==0 && TelaReiniciar==0 && TelaForca==0 && TelaVencedor==0 || DoisJogadores==0 && PlayerMomento%2==0 && TelaSeta==1 && TelaSair==0 && TelaPause==0 && TelaReiniciar==0 && TelaForca==0 && TelaVencedor==0){
            if(PlayerJogando.posx==Player1.posx){
              if(angle>0)
                angle=angle-1;
              glutPostRedisplay();
          }
          else{
            if(angle>-90)
              angle=angle-1;
            glutPostRedisplay();
          }
          }
          break;
          case 'a':
          case 'A':
          if(TelaPause==0 && TelaSair==0 &&  DoisJogadores==1 && TelaReiniciar==0 && TelaSeta==0 && TelaProjetil==0 && TelaForca==0 && TelaAndando==1 && TelaVencedor==0 || DoisJogadores==0 && PlayerMomento%2==0 && TelaPause==0 && TelaSair==0 && TelaReiniciar==0 && TelaSeta==0 && TelaProjetil==0 && TelaForca==0 && TelaAndando==1 && TelaVencedor==0){
            if(contador>=20){
              if(PlayerJogando.posx==Player1.posx){
                  Player1.direcao=PlayerJogando.direcao=-1;
              }
              contador=0;
              TelaSeta=1;
              TelaAndando=0;
              srand(time(0));
              if(rand()%2==0)
                Projetil.textura=texturaCerveja;
              else
                Projetil.textura=texturaCachaca;
            }
            if(PlayerMomento%2==0){
              PlayerJogando=Player1;
            }
            else
              PlayerJogando=Player2;
            if(PlayerJogando.posx==Player1.posx){
              condicao1=0.02*dimensaox;
              condicao2=0;
            }
            else{
              condicao1=(dimensaox/2)+0.15*dimensaox;
              condicao2=0;
            }
            if(PlayerJogando.posx>condicao1 || PlayerJogando.direcao==condicao2){
            if(PlayerJogando.direcao==0){
              PlayerJogando.direcao=1;
            }
            else{
              if(PlayerMomento%2==0)
                if(PlayerJogando.direcao==-1)
                  PlayerJogando.direcao=0;
            if(variavel==1){
                PlayerJogando.textura=PlayerJogando.vetor[0];
                variavel=0;
            }
            else{
                PlayerJogando.textura=PlayerJogando.vetor[1];
                variavel=1;
            }
                PlayerJogando.posx=PlayerJogando.posx-0.005*dimensaox;
                contador++;
            }
            if(PlayerMomento%2==0){
              Player1=PlayerJogando;
            }
            else{
              Player2=PlayerJogando;
            }
          }

                glutPostRedisplay();
              }
            else if (TelaSeta==1 && TelaSair==0 && DoisJogadores==1 && TelaPause==0 && TelaReiniciar==0 && TelaForca==0 && TelaVencedor==0 || DoisJogadores==0 && PlayerMomento%2==0 && TelaSeta==1 && TelaSair==0 && TelaPause==0 && TelaReiniciar==0 && TelaForca==0 && TelaVencedor==0){
              if(PlayerJogando.posx==Player1.posx){
                if(angle<90)
                  angle=angle+1;
                glutPostRedisplay();
            }
            else{
              if(angle<0)
                angle=angle+1;
              glutPostRedisplay();
            }
            }
          break;
        }
    }
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(tamx,tamy);
   glutInitWindowPosition(300, 1200);

   glutCreateWindow("Engenharíadas");
   init();
   InitTexturas();
   glutTimerFunc(0, timer, 0);
   glutReshapeFunc(redimensiona);
   glutDisplayFunc(desenha);
   glutKeyboardFunc(teclado);
   glutPassiveMotionFunc(movimentoMouse);
   glutMouseFunc(mousePress);
   glutMainLoop();
   return 0;
}
