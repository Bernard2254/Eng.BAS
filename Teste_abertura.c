#include "SOIL/SOIL.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

int x, y, a, c;
GLuint texturaFundo;
char v[50]="M", string[50]="Mascotinho e Cica gamees, apresenta...";
void atualiza() {
    glutPostRedisplay();
}


void init(void)
{
    x=10;
    y=50;
    a=0;
    c=1;
    glClearColor (0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    texturaFundo = SOIL_load_OGL_texture(
        "fundo.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glutSwapBuffers();
}

void escreveTexto(void * font, char *s, float x, float y){
    int i;
    glRasterPos2f(x, y);

    for (i=0; i < strlen(s); i++){
       glutBitmapCharacter(font, s[i]);
     }
}

void escreve(int u){
  int i;
  for(i=0; i<=u; i++)
    v[i]=string[i];
  v[i]='\0';
}

void seleciona(int x, int y){
  if(x>=40)
    {
      glColor3f(1,1,1);
      glBegin(GL_POINTS);
      glPointSize(50);
      glVertex3f(35, 50, 0);
      glEnd();
      glutSwapBuffers();
    }
}

void fundomenu(){
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
  glEnable(GL_TEXTURE_2D | GL_BLEND);
  glBindTexture(GL_TEXTURE_2D, texturaFundo);
  glColor4f(1.0, 1.0, 0, 0);
  glBegin(GL_QUADS);

      glTexCoord2f(0, 0); glVertex3f(-5, -5, 0);
      glTexCoord2f(1, 0); glVertex3f(105, -5, 0);
      glTexCoord2f(1, 1); glVertex3f(105, 105, 0);
      glTexCoord2f(0, 1); glVertex3f(-5, 105, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D | GL_BLEND);
  glutSwapBuffers();
}
void escrevemenu(){
  glColor3f(0,0,0);
  escreveTexto(GLUT_BITMAP_HELVETICA_18, "Jogar", 40, 50);
  glutSwapBuffers();
}

void desenha(void)
{ printf("a = %d\n", a);
  if(a==0){
      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(1,1,1);
      escreveTexto(GLUT_BITMAP_9_BY_15, v, x, y);
      if(strcmp(string,v)==0)
        a++;
    }
  if(a==1){
      fundomenu();
      escrevemenu();
      a++;
  }
}

void redimensiona(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 100, 0, 100, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
    }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(300, 1200);

   glutCreateWindow("Engenharíadas");
   init();
   glutReshapeFunc(redimensiona);
   glutDisplayFunc(desenha);
   glutKeyboardFunc(teclado);
   if(a==0){
     glutTimerFunc(2000, escreve, c);
     glutIdleFunc(atualiza);
     c++;
  }

   glutMainLoop();
   return 0;
}
