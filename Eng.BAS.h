typedef struct Personagens{
  GLuint textura;
  struct Personagens *proximo;
  struct Personagens *anterior;
}personagens;
typedef struct Jogadores{
  float posx;
  float posy;
  int direcao;
  int bebado;
  int vidas;
  GLuint textura;
  GLuint vetor[10];

}player;

char string[50]="Mascotinho e Cica games, apresentam...";
char v[50];
GLuint cefetAndando[10];
int tamx=800, tamy=500, dimensaox=200, dimensaoy=100, teste2, variavel, contador=2, PlayerMomento=2, condicao1, condicao2, TelaCheat,
TelaAndando=1, DoisJogadores,TelaSeta, angle=0, define, TelaProjetil=0, TelaVencedor=0, var=0, numero;
personagens *primeiroPersonagem=NULL, *personagemMomento;
player Player1, Player2, PlayerJogando, Projetil;
int global,b, c, QUANTIDADE_PLAYERS, TelaSair=0, TelaReiniciar=0, TelaPause=0, inicio=0, soma=0, TelaForca=0, compensa, loucura, t;
float posy, posx, diferencax_menu,diferencay_menu, posxSubMenu, posySubMenu, diferencay_SubMenu, pi=3.14, teste1, forca, erro;
double cor, cor2, cor3, alfa, cor4, cor5, cor6, velocidadex, velocidadey, def, velocidade, tempo,g, s1, s2;
GLuint texturaFundoMenu, texturaBotao, texturaBotaoPressionado, texturaJogar,
texturaInstrucoes, texturaOpcoes, texturaSair, texturaVoltar, textura1Jogador, textura2Jogadores,
texturaJogador1, texturaJogador2, texturaCefet1, texturaCefet2, texturaContinuar, texturaSeta, TEXTURA_PLAYER_1,
TEXTURA_PLAYER_2, texturaCefet3, texturaCefet4, texturaEngenhariadas, texturaJesus, texturaFundoJogo, texturaTelaSair,
texturaSim, texturaNao, texturaTelaReiniciar, texturaTelaPause, texturaPuc1, texturaPuc2, texturaPuc3, texturaPuc4,
texturaUfop1, texturaUfop2, texturaUfop3, texturaUfop4, texturaCerveja, texturaCachaca, texturaVomito1, texturaVomito2, texturaVomito3,
texturaVomito4,texturaVomito5, texturaZoaPuc, texturaZoaUFOP, texturaZoaCefet;



void atualiza(){
  switch(global){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      glutPostRedisplay();
    break;
    case 10:
      global=2;
    break;
}
}
