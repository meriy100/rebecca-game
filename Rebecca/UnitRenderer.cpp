//
//  UnitRenderer.cpp
//  Rebecca
//
//  Created by 苅宿航太 on 2017/04/27.
//  Copyright © 2017年 meriy100. All rights reserved.
//

#include "UnitRenderer.hpp"

#include "DrawFuncs.hpp"
#include "Unit.hpp"

// TODO
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>


UnitRenderer::UnitRenderer(Unit* m_unit) {
  unit = m_unit;
}

void UnitRenderer::render() {
  glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
  Circle2DFill(unit->r, unit->x, unit->y);
}
