
void sai(){
  exit(0);
}

void carregaVetor(GLuint textura, GLuint *vetor, int i){
  int u=0;
  for( ; u<i; ){
    u++;
  }
  vetor[u]=textura;
}

void retornaMenu(){
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  desenhaTextura(0,0);
  global=2;
}

void copiaVetorTextura(GLuint *momento, GLuint *original){
  int i=0;
  for( ; i<4; i++){
    momento[i]=original[i];
  }
}

void mousePress(int button, int state,int x, int y){
  switch(global){
  case 2:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=(((posx+(0.1*dimensaox))*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.07*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.07*dimensaoy))*tamy)/dimensaoy)){
          global=3;
        }
      else if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posx+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posy-(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
        global=4;
      }
      else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.07*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.07*dimensaoy))*tamy)/dimensaoy)){
        global=5;
      }
      else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) &&  y>=((((dimensaoy-posy-(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
        glutTimerFunc(300, sai, 0);
      }
    }
    atualiza();
  break;
  case 3:
      if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
          retornaMenu();
      }
      else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=(((dimensaoy-posySubMenu-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posySubMenu+(0.05*dimensaoy))*tamy)/dimensaoy)){
        global=6;
        primeiroPersonagem=NULL;
        QUANTIDADE_PLAYERS=1;
        criaListaPersonagens();
      }
      else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(1*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(1*diferencay_SubMenu))*tamy)/dimensaoy)){
        global=6;
        primeiroPersonagem=NULL;
        QUANTIDADE_PLAYERS=2;
        criaListaPersonagens();
      }
      atualiza();
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
  case 6:
  if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
      if(x>=(0.32*tamx)-(0.12*tamx) && x<=(0.32*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
          global=3;
      }
      else if(x>=(0.72*tamx)-(0.12*tamx) && x<=(0.72*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
          Player1.textura=TEXTURA_PLAYER_1=(*personagemMomento).textura;
          if(Player1.textura==texturaCefet1){
          carregaVetor(texturaCefet1, Player1.vetor, 0);
          carregaVetor(texturaCefet2, Player1.vetor, 1);
          carregaVetor(texturaCefet3, Player1.vetor, 2);
          carregaVetor(texturaCefet4, Player1.vetor, 3);
        }
        else if(Player1.textura==texturaPuc1){
          carregaVetor(texturaPuc1, Player1.vetor, 0);
          carregaVetor(texturaPuc2, Player1.vetor, 1);
          carregaVetor(texturaPuc3, Player1.vetor, 2);
          carregaVetor(texturaPuc4, Player1.vetor, 3);
        }
        else if(Player1.textura==texturaUfop1){
          carregaVetor(texturaUfop1, Player1.vetor, 0);
          carregaVetor(texturaUfop2, Player1.vetor, 1);
          carregaVetor(texturaUfop3, Player1.vetor, 2);
          carregaVetor(texturaUfop4, Player1.vetor, 3);
        }
          retiraPersonagem((*personagemMomento).textura);
          personagemMomento=primeiroPersonagem;
          global=7;
      }
      else if(x>=(0.8*tamx)-(0.12*tamx) && x<=(0.8*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
        if((*personagemMomento).proximo!=NULL){
          personagemMomento=(*personagemMomento).proximo;
        }
        else{
          personagemMomento=primeiroPersonagem;
        }
      }
        else if(x>=(0.2*tamx)-(0.12*tamx) && x<=(0.2*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
          if((*personagemMomento).anterior!=NULL){
            personagemMomento=(*personagemMomento).anterior;
          }
          else{
            while((*personagemMomento).proximo!=NULL)
              personagemMomento=(*personagemMomento).proximo;
          }
          }
      atualiza();
    }
  break;
  case 7:
  if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
      if(x>=(0.32*tamx)-(0.12*tamx) && x<=(0.32*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
          global=6;
          primeiroPersonagem=NULL;
          criaListaPersonagens();
          atualiza();
      }
    }
    else if(x>=(0.72*tamx)-(0.12*tamx) && x<=(0.72*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
        Player2.textura=TEXTURA_PLAYER_2=(*personagemMomento).textura;
        if(Player2.textura==texturaCefet1){
        carregaVetor(texturaCefet1, Player2.vetor, 0);
        carregaVetor(texturaCefet2, Player2.vetor, 1);
        carregaVetor(texturaCefet3, Player2.vetor, 2);
        carregaVetor(texturaCefet4, Player2.vetor, 3);
      }
      else if(Player2.textura==texturaPuc1){
        carregaVetor(texturaPuc1, Player2.vetor, 0);
        carregaVetor(texturaPuc2, Player2.vetor, 1);
        carregaVetor(texturaPuc3, Player2.vetor, 2);
        carregaVetor(texturaPuc4, Player2.vetor, 3);
      }
      else if(Player2.textura==texturaUfop1){
        carregaVetor(texturaUfop1, Player2.vetor, 0);
        carregaVetor(texturaUfop2, Player2.vetor, 1);
        carregaVetor(texturaUfop3, Player2.vetor, 2);
        carregaVetor(texturaUfop4, Player2.vetor, 3);
      }
        global=8;
        atualiza();
    }
    else if(x>=(0.8*tamx)-(0.12*tamx) && x<=(0.8*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
      if((*personagemMomento).proximo!=NULL){
        personagemMomento=(*personagemMomento).proximo;
      }
      else{
        personagemMomento=primeiroPersonagem;
      }
    }
      else if(x>=(0.2*tamx)-(0.12*tamx) && x<=(0.2*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
        if((*personagemMomento).anterior!=NULL){
          personagemMomento=(*personagemMomento).anterior;
        }
        else{
          while((*personagemMomento).proximo!=NULL)
            personagemMomento=(*personagemMomento).proximo;
        }
        }
    atualiza();
  break;
  case 8:
    if(button==GLUT_LEFT_BUTTON && state == GLUT_UP){
        if(x>=(0.42*tamx)-(0.07*tamx) && x<=(0.42*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && TelaSair==1){
            global=2;
            setup();
            TelaSair=0;
            glutTimerFunc(300, atualiza, 0);
          }
        else if(x>=(0.58*tamx)-(0.07*tamx) && x<=(0.58*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && TelaSair==1){
          TelaSair=0;
          glutTimerFunc(300, atualiza, 0);
        }
        else if(x>=(0.42*tamx)-(0.07*tamx) && x<=(0.42*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && TelaReiniciar==1){
            setup();
            TelaReiniciar=0;
            glutTimerFunc(300, atualiza, 0);
          }
        else if(x>=(0.58*tamx)-(0.07*tamx) && x<=(0.58*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && TelaReiniciar==1){
          TelaReiniciar=0;
          glutTimerFunc(300, atualiza, 0);
        }
      }
  break;

}
}

void sub_Menu(int x, int y){
  if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=(((dimensaoy-posySubMenu-(0.05*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posySubMenu+(0.05*dimensaoy))*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu);
    colocaTextoBotao(textura1Jogador,posxSubMenu-(0.02*dimensaox),posySubMenu+(0.01*dimensaoy),0,0);
    glutSwapBuffers();
  }
  else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+diferencay_SubMenu)*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+diferencay_SubMenu)*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu-diferencay_SubMenu);
    colocaTextoBotao(textura2Jogadores,posxSubMenu-(0.02*dimensaox),(posySubMenu-diferencay_SubMenu)+(0.01*dimensaoy),0,0);
    glutSwapBuffers();
}
  else if(x>=(((posxSubMenu-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posxSubMenu+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posySubMenu-(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy) && y<=((((dimensaoy-posySubMenu+(0.05*dimensaoy))+(2*diferencay_SubMenu))*tamy)/dimensaoy)){
    posicionaBotao(texturaBotaoPressionado,posxSubMenu,posySubMenu-(2*diferencay_SubMenu));
    colocaTextoBotao(texturaVoltar,posxSubMenu-(0.01*dimensaox),(posySubMenu-(2*diferencay_SubMenu))+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
    glutSwapBuffers();
}
  else{
      glutPostRedisplay();
  }
}

void movimentoMouse(int x, int y){
/*printf("posy = %f\nposx = %f\n",tamy-(0.45*tamy), (posx*tamx)/dimensaox);
printf("y : %d\nx : %d\n", y, x);*/
  switch (global) {
    case 2:
        if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=(((posx+(0.1*dimensaox))*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.07*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.07*dimensaoy))*tamy)/dimensaoy)){
          //printf("Passou\n");
          posicionaBotao(texturaBotaoPressionado,posx,posy);
          colocaTextoBotao(texturaJogar,posx-(0.01*dimensaox), posy+(0.01*dimensaoy),0,0);
          glutSwapBuffers();
        }
        else if(x>=(((posx-(0.14*dimensaox))*tamx)/dimensaox) && x<=((posx+(0.1*dimensaox))*tamx/dimensaox) && y>=((((dimensaoy-posy-(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx,posy-diferencay_menu);
          colocaTextoBotao(texturaOpcoes, posx-(0.01*dimensaox), (posy-diferencay_menu)+(0.01*dimensaoy),0,0);
          glutSwapBuffers();
        }
        else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) && y>=(((dimensaoy-posy-(0.07*dimensaoy))*tamy)/dimensaoy) && y<=(((dimensaoy-posy+(0.07*dimensaoy))*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx+diferencax_menu,posy);
          colocaTextoBotao(texturaInstrucoes, posx+diferencax_menu-(0.01*dimensaox), posy+(0.01*dimensaoy),0,0);
          glutSwapBuffers();
        }
        else if(x>=((((posx-(0.14*dimensaox))+diferencax_menu)*tamx)/dimensaox) && x<=((((posx+(0.1*dimensaox))+diferencax_menu)*tamx)/dimensaox) &&  y>=((((dimensaoy-posy-(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy) && y<=((((dimensaoy-posy+(0.07*dimensaoy))+diferencay_menu)*tamy)/dimensaoy)){
          posicionaBotao(texturaBotaoPressionado,posx+diferencax_menu,posy-diferencay_menu);
          colocaTextoBotao(texturaSair, posx+diferencax_menu-(0.01*dimensaox), (posy-diferencay_menu)+(0.01*dimensaoy),0,0);
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
    case 6:
    case 7:
        //printf("posx : %f\n posx2: %f\nposy : %f\n posy2: %f\n",(0.52*tamx)-(0.12*tamx),(0.52*tamx)+(0.12*tamx),(0.91*tamy)+(0.07*tamy),(0.91*tamy)-(0.07*tamy));
        if(x>=(0.2*tamx)-(0.12*tamx) && x<=(0.2*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
          posicionaBotao(texturaBotaoPressionado,0.2*dimensaox,0.3*dimensaoy);
          colocaTextoBotao(texturaSeta,0.18*dimensaox, 0.315*dimensaoy,-0.05*dimensaox, 0.04*dimensaoy);
          glutSwapBuffers();
        }
        else if(x>=(0.8*tamx)-(0.12*tamx) && x<=(0.8*tamx)+(0.1*tamx) && y<=(0.7*tamy)+(0.05*tamy) && y>=(0.7*tamy)-(0.07*tamy)){
          posicionaBotao(texturaBotaoPressionado, 0.8*dimensaox, 0.3*dimensaoy);
          colocaTextoBotao(texturaSeta,0.8*dimensaox, 0.315*dimensaoy,0.05*dimensaox, 0.04*dimensaoy);
          glutSwapBuffers();
        }
        else if(x>=(0.32*tamx)-(0.12*tamx) && x<=(0.32*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
          posicionaBotao(texturaBotaoPressionado,0.32*dimensaox, 0.06*dimensaoy);
          colocaTextoBotao(texturaVoltar,0.32*dimensaox-(0.01*dimensaox),(0.06*dimensaoy)+(0.01*dimensaoy),0.07*dimensaox,0.03*dimensaoy);
          glutSwapBuffers();
        }
        else if(x>=(0.72*tamx)-(0.12*tamx) && x<=(0.72*tamx)+(0.1*tamx) && y<=(0.94*tamy)+(0.05*tamy) && y>=(0.94*tamy)-(0.07*tamy)){
          posicionaBotao(texturaBotaoPressionado,0.72*dimensaox, 0.06*dimensaoy);
          colocaTextoBotao(texturaContinuar,0.72*dimensaox-(0.01*dimensaox),(0.06*dimensaoy)+(0.01*dimensaoy),0.08*dimensaox,0.03*dimensaoy);
          glutSwapBuffers();
        }
        else
          atualiza();
    break;
    case 8:
        if(x>=(0.42*tamx)-(0.07*tamx) && x<=(0.42*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && (TelaSair==1 || TelaReiniciar==1)){
            alfa=0.1;
            colocaTextoBotao(texturaBotaoPressionado, 0.42*dimensaox, 0.38*dimensaoy, 0.15*dimensaox,0.10*dimensaoy);
            colocaTextoBotao(texturaSim, 0.41*dimensaox, 0.39*dimensaoy,0.04*dimensaox,0.02*dimensaoy);
            glutSwapBuffers();
            alfa=1;
          }
        else if(x>=(0.58*tamx)-(0.07*tamx) && x<=(0.58*tamx)+(0.06*tamx) && y>=(0.62*tamy)-(0.04*tamy) && y<=(0.62*tamy)+(0.03*tamy) && (TelaSair==1 || TelaReiniciar==1)){
          alfa=0.1;
          colocaTextoBotao(texturaBotaoPressionado, 0.58*dimensaox, 0.38*dimensaoy, 0.15*dimensaox,0.10*dimensaoy);
          colocaTextoBotao(texturaNao, 0.57*dimensaox, 0.39*dimensaoy,0.04*dimensaox,0.02*dimensaoy);
          glutSwapBuffers();
          alfa=1;
        }


        else if(TelaSair==1 || TelaReiniciar==1 || TelaPause==1){
          glutPostRedisplay();
        }



    break;
    }
  }
