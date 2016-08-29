void InitTexturas(){
  texturaFundoMenu = SOIL_load_OGL_texture(
      "Fundo.jpg",
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
  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  glutSwapBuffers();
}

void posicionaBotao(GLuint textura,float x, float y){
  glEnable(GL_TEXTURE_2D);
    glColor4f(1,1,1,1);
    glBindTexture(GL_TEXTURE_2D, textura);
      glBegin(GL_QUADS);
          glTexCoord2f(0, 0); glVertex3f(x-25, y-17, 0);
          glTexCoord2f(1, 0); glVertex3f(x+25, y-17, 0);
          glTexCoord2f(1, 1); glVertex3f(x+25, y+17, 0);
          glTexCoord2f(0, 1); glVertex3f(x-25, y+17, 0);
      glEnd();
  glDisable(GL_TEXTURE_2D);
}
void colocaTextoBotao(GLuint textura,float x,float y){
  int define=8, define2=4;
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


void desenhaTextura(float x, float y){
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
}

void desenhaBotoes(){
  colocaTextoBotao(texturaJogar,49,76);
  colocaTextoBotao(texturaOpcoes,49,56);
  colocaTextoBotao(texturaInstrucoes,49,36);
  colocaTextoBotao(texturaSair,49,16);
}

void menu(){
  float y=75;
  for(b=0; b<4; b++){
    posicionaBotao(texturaBotao,50, y);
    y=y-20;
  }
  desenhaBotoes();
  glutSwapBuffers();
}
