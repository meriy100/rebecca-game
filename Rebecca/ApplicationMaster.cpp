#include "ApplicationMaster.hpp"
#include <iostream>

#include "DrawFuncs.hpp"

#include "Unit.hpp"
#include "UnitRenderer.hpp"

ApplicationMaster::ApplicationMaster() {
    for(int i = 0; i < 4; i++) {
        unit[i] = new Unit;
    }
    time_count = 0;
    std::random_device rd;
    std::mt19937 mt(rd());
}

void ApplicationMaster::perform() {
    time_count++;
    for(int i = 0; i<4; i++) {
        unit[i]->perform(this);
    }
}
void ApplicationMaster::disp() {
    UnitRenderer* renderer;
    for(int i = 0; i<4; i++) {
        renderer = new UnitRenderer(unit[i]);
        renderer->render();
    }
}

int ApplicationMaster::random() {
    return mt();
    
}
