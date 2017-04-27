#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#include <math.h>

#include "ApplicationMaster.hpp"

#define Pai 3.1415926

#define WIDTH 400
#define HEIGHT 320

void Point(int x,int y,float size){
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2i(x , y);
    glEnd();
}

void Line2D(int x1,int y1,int x2, int y2,float size){
    glLineWidth(size);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();
}



void idle(void)
{
    glutPostRedisplay();
}

ApplicationMaster* applicationMaster = new ApplicationMaster;

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
    applicationMaster->move();
    glutTimerFunc(1000/60 , timer , 0);
}

int main(int argc, char *argv[])
{
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("Rebecca");
    glutDisplayFunc(display);
    Init();
    glutTimerFunc(1000 , timer , 0);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

