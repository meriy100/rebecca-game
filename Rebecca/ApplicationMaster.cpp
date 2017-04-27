#include "ApplicationMaster.hpp"
#include <iostream>

#include "DrawFuncs.hpp"

#include "Unit.hpp"
#include "UnitRenderer.hpp"

ApplicationMaster::ApplicationMaster() {
    for(int i = 0; i < 4; i++) {
        units.push_back(new Unit);
    }
    time_count = 0;
    std::random_device rd;
    //std::mt19937 mt(rd());
}

void ApplicationMaster::perform() {
    time_count++;
    for(auto itr = units.begin(); itr != units.end(); ++itr) {
        (*itr)->perform(this);
    }
}
void ApplicationMaster::disp() {
    UnitRenderer* renderer;
    for(auto itr = units.begin(); itr != units.end(); ++itr) {
        renderer = new UnitRenderer(*itr);
        renderer->render();
    }
}

int ApplicationMaster::random() {
    return rd();
    
}
