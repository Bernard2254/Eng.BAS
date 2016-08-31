 void InitTexturas(){
  texturaFundoMenu = SOIL_load_OGL_texture(
      "Barril.png",
      SOIL_LOAD_AUTO,
      SOIL_CREATE_NEW_ID,
  SOIL_FLAG_INVERT_Y
);
texturaBotao = SOIL_load_OGL_texture(
    "Botão.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaBotaoPressionado = SOIL_load_OGL_texture(
    "Botão_Pressionado.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaJogar = SOIL_load_OGL_texture(
    "Jogar.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaInstrucoes = SOIL_load_OGL_texture(
    "Instruções.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaOpcoes = SOIL_load_OGL_texture(
    "Opções.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaSair = SOIL_load_OGL_texture(
    "Sair.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
texturaVoltar = SOIL_load_OGL_texture(
    "Voltar.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
textura1Jogador = SOIL_load_OGL_texture(
    "1Jogador.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
textura2Jogadores = SOIL_load_OGL_texture(
    "2Jogadores.png",
    SOIL_LOAD_AUTO,
    SOIL_CREATE_NEW_ID,
SOIL_FLAG_INVERT_Y
);
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  glutSwapBuffers();
}

void posicionaBotao(GLuint textura,float x, float y){
  glEnable(GL_TEXTURE_2D);
    glColor4f(1,1,1,1);
    glBindTexture(GL_TEXTURE_2D, textura);
      glBegin(GL_QUADS);
          glTexCoord2f(0, 0); glVertex3f(x-(0.25*dimensaox), y-(0.17*dimensaoy), 0);
          glTexCoord2f(1, 0); glVertex3f(x+(0.25*dimensaox), y-(0.17*dimensaoy), 0);
          glTexCoord2f(1, 1); glVertex3f(x+(0.25*dimensaox), y+(0.17*dimensaoy), 0);
          glTexCoord2f(0, 1); glVertex3f(x-(0.25*dimensaox), y+(0.17*dimensaoy), 0);
      glEnd();
  glDisable(GL_TEXTURE_2D);
}
void colocaTextoBotao(GLuint textura,float x,float y,float define, float define2){
  if(define==0 && define2==0){
   define=0.08*dimensaox; define2=0.04*dimensaoy;
 }
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x-define, y-define2, 0);
        glTexCoord2f(1, 0); glVertex3f(x+define, y-define2, 0);
        glTexCoord2f(1, 1); glVertex3f(x+define, y+define2, 0);
        glTexCoord2f(0, 1); glVertex3f(x-define, y+define2, 0);
    glEnd();
  glDisable(GL_TEXTURE_2D );
}


/*void desenhaTextura(float x, float y){
  glEnable(GL_TEXTURE_2D);
  int i;
      glColor4f(1,1,1,alfa);
      glBindTexture(GL_TEXTURE_2D, texturaFundoMenu);
      glBegin(GL_QUADS);
          glTexCoord2f(0, 0); glVertex3f(-5, -5, 0);
          glTexCoord2f(1, 0); glVertex3f(105, -5, 0);
          glTexCoord2f(1, 1); glVertex3f(105, 105, 0);
          glTexCoord2f(0, 1); glVertex3f(-5, 105, 0);
      glEnd();
    glDisable(GL_TEXTURE_2D );
}*/

void desenhaTextura(float x, float y){
  glEnable(GL_TEXTURE_2D);
  int i=10, o;
      glClear(GL_COLOR_BUFFER_BIT);
      glColor4f(1,1,1,alfa);
      glBindTexture(GL_TEXTURE_2D, texturaFundoMenu);
    for(i=5; i<=dimensaox; i=i+5)
      for(o=5; o<=dimensaoy; o=o+5){
      glBegin(GL_QUADS);
          glTexCoord2f(0, 0); glVertex3f(i-5, o-5, 0);
          glTexCoord2f(1, 0); glVertex3f(i, o-5, 0);
          glTexCoord2f(1, 1); glVertex3f(i, o, 0);
          glTexCoord2f(0, 1); glVertex3f(i-5, o, 0);
      glEnd();
    }
    glDisable(GL_TEXTURE_2D );
}

void desenhaBotoes(){
  colocaTextoBotao(texturaJogar,posx-1,posy+1,0,0);
  colocaTextoBotao(texturaOpcoes,posx-1,posy-(diferencay_menu-1),0,0);
  colocaTextoBotao(texturaInstrucoes,posx+(-1+diferencax_menu),posy+1,0,0);
  colocaTextoBotao(texturaSair,posx+(-1+diferencax_menu),posy-(diferencay_menu-1),0,0);
}

void menu(){
  diferencax_menu=0.3*dimensaox;
  diferencay_menu=0.2*dimensaoy;
  posx=0.35*dimensaox;
  for(b=0; b<2; b++){
    for(posy=0.45*dimensaoy; posy>=0.25*dimensaoy; posy=posy-diferencay_menu)
    posicionaBotao(texturaBotao,posx+(b*diferencax_menu), posy);
  }
  posy=0.45*dimensaoy;
  desenhaBotoes();
  glutSwapBuffers();
}
