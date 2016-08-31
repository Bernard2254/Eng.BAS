char string[50]="Mascotinho e Cica games, apresentam...";
char v[50];
int tamx=700, tamy=500, dimensaox=100, dimensaoy=100, teste1, teste2;

int global,b, c;
float posy, posx, diferencax_menu,diferencay_menu, posxSubMenu, posySubMenu, diferencay_SubMenu;
double cor, cor2, cor3, alfa, cor4, cor5, cor6;
GLuint texturaFundoMenu, texturaBotao, texturaBotaoPressionado, texturaJogar,
texturaInstrucoes, texturaOpcoes, texturaSair, texturaVoltar, textura1Jogador, textura2Jogadores;


void atualiza(){
  glutPostRedisplay();
}
