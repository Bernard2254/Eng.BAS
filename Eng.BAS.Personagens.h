void retiraPersonagem(GLuint textura){
  personagens *PERSONAGEM=primeiroPersonagem, *aux;

  while((*PERSONAGEM).textura!=textura){
    aux=PERSONAGEM;
    PERSONAGEM=(*PERSONAGEM).proximo;
  }
  if(PERSONAGEM==primeiroPersonagem){
    aux=(*primeiroPersonagem).proximo;
    primeiroPersonagem=aux;
    (*aux).anterior=NULL;
  }
  else if((*PERSONAGEM).proximo==NULL){
    (*(*PERSONAGEM).anterior).proximo=NULL;
  }
  else{
  (*aux).proximo=(*PERSONAGEM).proximo;
  if((*aux).proximo!=NULL)
    (*(*PERSONAGEM).proximo).anterior=aux;
}
  TEXTURA_PLAYER_1=(*PERSONAGEM).textura;
}

void cadastraPersonagem(GLuint textura){
  personagens *PERSONAGEM, *aux;
  PERSONAGEM = (personagens *) malloc(sizeof(personagens));
  (*PERSONAGEM).proximo=NULL;
  (*PERSONAGEM).textura=textura;
  if(primeiroPersonagem==NULL){
    (*PERSONAGEM).anterior=NULL;
    primeiroPersonagem=personagemMomento=PERSONAGEM;
  }
  else{
    aux=primeiroPersonagem;
      while((*aux).proximo!=NULL){
        aux=(*aux).proximo;
      }
    (*PERSONAGEM).anterior=aux;
    (*aux).proximo=PERSONAGEM;
  }
}


void setup(){
  srand(time(0));
  Player1.posx=0.1*dimensaox;
  Player1.posy=0.2*dimensaoy;
  Player1.direcao=0;
  Player1.textura=TEXTURA_PLAYER_1;
  Player1.bebado=1;
  Player1.vidas=3;
  Player2.posx=0.9*dimensaox;
  Player2.posy=0.2*dimensaoy;
  Player2.direcao=1;
  Player2.textura=TEXTURA_PLAYER_2;
  Player2.bebado=1;
  Player2.vidas=3;
  TelaSeta=TelaProjetil=0;
  PlayerMomento=2;
  angle=rand()%90;
  TelaCheat=TelaForca=compensa=forca=0;
  TelaAndando=1;
  TelaVencedor=0;
  velocidade=1.57;
  k=0;
}

void criaListaPersonagens(){
    cadastraPersonagem(texturaCefet1);
    cadastraPersonagem(texturaPuc1);
    cadastraPersonagem(texturaUfop1);
  //  cadastraPersonagem(textura1Jogador);
}
