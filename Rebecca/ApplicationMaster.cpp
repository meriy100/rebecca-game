//
//  ApplicationMaster.cpp
//  Rebecca
//
//  Created by 苅宿航太 on 2017/04/27.
//  Copyright © 2017年 meriy100. All rights reserved.
//

#include "ApplicationMaster.hpp"

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#include <math.h>
#include <iostream>
#define Pai 3.1415926

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

ApplicationMaster::ApplicationMaster() {
    x = 10;
    y = 10;
}

void ApplicationMaster::move() {
    x++;
}
void ApplicationMaster::disp() {
    Circle2D(10, x, y);
}
