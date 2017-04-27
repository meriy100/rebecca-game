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


UnitRenderer::UnitRenderer(Unit* m_unit) {
    unit = m_unit;
}

void UnitRenderer::render() {
    Circle2DFill(10, unit->x, unit->y);
}
