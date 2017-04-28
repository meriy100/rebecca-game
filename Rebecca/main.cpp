#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>

#include "ApplicationMaster.hpp"
#include "defines.h"

ApplicationMaster* applicationMaster = new ApplicationMaster;

Mouse mouse;

void idle(void)
{
  glutPostRedisplay();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor4f(0.0f,0.0f,0.0f,1.0f);
  applicationMaster->disp();
  glFlush();
}

void Init(){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
}


void timer(int value) {
  printf("left : %d\n", mouse.left);
  applicationMaster->perform(mouse);
  if(mouse.left > 0) {
    mouse.left++;
  }
  if(mouse.right > 0) {
    mouse.right++;
  }
  if(mouse.middle > 0) {
    mouse.middle++;
  }
  glutTimerFunc(WAIT_TIME, timer , 0);
}


//マウス(クリック)
void mouseClick(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    mouse.left = 1;
  }else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
  {
    mouse.left = 0;
  }
  if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {
    mouse.right = 1;
  }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
  {
    mouse.right = 0;
  }
  if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
  {
    mouse.middle = 1;
  }else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
  {
    mouse.middle = 0;
  }
}

//ドラッグ
void drag(int x, int y)
{
  mouse.x=x;
  mouse.y=y;
}

//パッシブ
void passive(int x, int y)
{
  mouse.x=x;
  mouse.y=y;
}


int main(int argc, char *argv[])
{
  glutInitWindowPosition(POSITION_X, POSITION_Y);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow("Rebecca");
  glutDisplayFunc(display);
  Init();
  glutTimerFunc(1000 , timer , 0);
  glutIdleFunc(idle);


  glutDisplayFunc(display);
  glutMouseFunc(mouseClick);
  glutMotionFunc(drag);
  glutPassiveMotionFunc(passive);

  glutMainLoop();
  return 0;
}
