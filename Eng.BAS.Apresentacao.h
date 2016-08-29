void escreveTexto(void * font, char *s, float x, float y){
    int i;
    glRasterPos2f(x, y);

    for (i=0; i < strlen(s); i++){
       glutBitmapCharacter(font, s[i]);
     }
}
void escreve(){
  int i;
  for(i=0; i<=c; i++)
    v[i]=string[i];
  v[i]='\0';
}
void mudacor(){
  cor=cor2=cor3=cor+0.0000008;
}
