#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#include <math.h>

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

void Circle2D(float radius,int x,int y)
{
    for (float th1 = 0.0;  th1 <= 360.0;  th1 = th1 + 1.0)
    {
        float th2 = th1 + 10.0;
        float th1_rad = th1 / 180.0 * Pai;
        float th2_rad = th2 / 180.0 * Pai;
        
        float x1 = radius * cos(th1_rad);
        float y1 = radius * sin(th1_rad);
        float x2 = radius * cos(th2_rad);
        float y2 = radius * sin(th2_rad);
        
        glBegin(GL_LINES);
        glVertex2f( x1+x, y1+y );
        glVertex2f( x2+x, y2+y );
        glEnd();
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(0.0f,0.0f,1.0f,1.0f);
    Point(50,50,2.0);
    glColor4f(1.0f,0.0f,0.0f,1.0f);
    Point(250,150,10.0);
    glColor4f(0.0f,0.0f,0.0f,1.0f);
    Line2D(20,40,200,180,1.0);
    Circle2D(40.0f,50,50);
    glFlush();
}
void Init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
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
    glutMainLoop();
    return 0;
}

