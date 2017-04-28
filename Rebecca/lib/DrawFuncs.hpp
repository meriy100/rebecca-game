#ifndef DrawFuncs_hpp
#define DrawFuncs_hpp

#include <stdio.h>

void Point(int x,int y,float size);
void Line2D(int x1,int y1,int x2, int y2,float size);
void Circle2D(float radius,int x,int y);
void Circle2DFill(float radius,int x,int y);

void SquareFill2D(int x1,int y1,int x2, int y2);

#endif /* DrawFuncs_hpp */
