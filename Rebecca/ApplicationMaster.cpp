//
//  ApplicationMaster.cpp
//  Rebecca
//
//  Created by 苅宿航太 on 2017/04/27.
//  Copyright © 2017年 meriy100. All rights reserved.
//

#include "ApplicationMaster.hpp"
#include <iostream>

#include "DrawFuncs.hpp"


ApplicationMaster::ApplicationMaster() {
    x = 10;
    y = 10;
    unit = new Unit;
}

void ApplicationMaster::move() {
    unit->perform();
}
void ApplicationMaster::disp() {
    UnitRenderer* renderer = new UnitRenderer(unit);
    renderer->render();
}
