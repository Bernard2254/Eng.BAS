#include "SOIL/SOIL.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "Eng.BAS.h"
#include "Eng.BAS.Apresentacao.h"
#include "Eng.BAS.Texturas.h"

/*
GLOBAL
0 -> Apresentacao
1 -> Transição
2 -> Menu
3 -> Jogar
4 -> Opções
5 -> Instruções

*/

void init(){
  posy=0.65*dimensaoy;
  posxSubMenu=0.50*dimensaox;
  posySubMenu=0.50*dimensaoy;
  diferencay_SubMenu=0.2*dimensaoy;
  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);
  global=c=cor=cor2=cor3=alfa=0;
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


void retornaMenu(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  desenhaTextura(0,0);
  global=2;
  glutTimerFunc(150, atualiza, 0);
}

void sai(){
  exit(0);
}


void mousePress(int button, int state,int x, int y){
  switch(global){
  case 2:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=(((posx+(0.1*dimensaox))*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.05*dimensaoy))*tamy)/dimensaoy)){
          global=3;
        }
      else if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posx+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posy-(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
        global=4;
      }
      else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.05*dimensaoy))*tamy)/dimensaoy)){
        global=5;
      }
      else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) &&  y>=((((dimensaoy-posy-(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
        glutTimerFunc(300, sai, 0);
      }
    }
    glutTimerFunc(300, atualiza, 0);
  break;
  case 3:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
          retornaMenu();
      }
    }
  break;
  case 4:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
            retornaMenu();
        }
      }


  break;

  case 5:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
            retornaMenu();
        }
      }
  break;

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
        desenhaTextura(0,0);
        y=posySubMenu;
        for(b=0; b<4; b++){
          posicionaBotao(texturaBotao,posxSubMenu, y);
          y=y-diferencay_SubMenu;
        }

          colocaTextoBotao(texturaJogar,posxSubMenu,0.8*dimensaoy,0.2*dimensaox,0.15*dimensaoy);
          colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
          colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
          colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
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
        colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
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
        colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
        glutSwapBuffers();
    break;
  }
}

void sub_Menu(int x, int y){
  if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=(((dimensaoy-posySubMenu-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posySubMenu+(0.05*dimensaoy))*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu);
  }
  else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+diferencay_SubMenu)*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+diferencay_SubMenu)*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu-diferencay_SubMenu);
  }
  else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu-(2*diferencay_SubMenu));
  }
  else{
    glutPostRedisplay();
  }
  switch(global){
    case 3:
        colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
        glutTimerFunc(150, timer, 0);
    break;
    case 4:
        colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
        glutTimerFunc(150, timer, 0);
    break;
    case 5:
        colocaTextoBotao(textura1Jogador,posxSubMenu-2,posySubMenu+1,0,0);
        colocaTextoBotao(textura2Jogadores,posxSubMenu-2,(posySubMenu-diferencay_SubMenu)+1,0,0);
        colocaTextoBotao(texturaVoltar,posxSubMenu-1,(posySubMenu-(2*diferencay_SubMenu))+1,0.07*dimensaox,0.03*dimensaoy);
        glutTimerFunc(150, timer, 0);
    break;
  }
}

void movimentoMouse(int x, int y){
  //printf("x = %d e y = %d\n", x, y);
  switch (global) {
    case 2:
        if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=(((posx+(0.1*dimensaox))*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.05*dimensaoy))*tamy)/dimensaoy)){
          //printf("Passou\n");
          posicionaBotao(texturaBotaoPressionado,posx,posy);
          colocaTextoBotao(texturaJogar,posx-1, posy+1,0,0);
          glutSwapBuffers();
        }
        else if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posx+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posy-(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx,posy-diferencay_menu);
          colocaTextoBotao(texturaOpcoes, posx-1, (posy-diferencay_menu)+1,0,0);
          glutSwapBuffers();
        }
        else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.05*dimensaoy))*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx+diferencax_menu,posy);
          colocaTextoBotao(texturaInstrucoes, posx+diferencax_menu-1, posy+1,0,0);
          glutSwapBuffers();
        }
        else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) &&  y>=((((dimensaoy-posy-(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.05*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx+diferencax_menu,posy-diferencay_menu);
          colocaTextoBotao(texturaSair, posx+diferencax_menu-1, (posy-diferencay_menu)+1,0,0);
          glutSwapBuffers();
        }
        else{
          glClear(GL_COLOR_BUFFER_BIT);
          desenhaTextura(0,0);
          menu();
        }
    break;
    case 3:
    case 4:
    case 5:
        sub_Menu(x,y);
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
        switch (key) {
          case 27:
            exit(0);
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
