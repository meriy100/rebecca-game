#include "DrawFuncs.hpp"

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#include <math.h>
#include <iostream>
#include "defines.h"

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
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f( x1+x, y1+y );
        glVertex2f( x2+x, y2+y );
        glEnd();
    }
}

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

void Circle2DFill(float radius,int x,int y)
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
        
        glBegin(GL_TRIANGLES);
        glVertex2f( x, y );
        glVertex2f( x1+x, y1+y );
        glVertex2f( x2+x, y2+y );
        glEnd();
    } 
}
