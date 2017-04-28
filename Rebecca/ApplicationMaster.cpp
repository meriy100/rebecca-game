#include "ApplicationMaster.hpp"
#include <iostream>

#include "DrawFuncs.hpp"

#include "Unit.hpp"
#include "UnitRenderer.hpp"

// TODO
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>


ApplicationMaster::ApplicationMaster() {
    for(int i = 0; i < 4; i++) {
        units.push_back(new Unit);
    }
    time_count = 0;
    std::random_device rd;
    for(int x = 0; x < 120; x++) {
        for(int y = 0; y < 80; y++) {
            tile[x][y] = (rd() % 100) / 10.0f ;
        }
    }
    //std::mt19937 mt(rd()); // TODO
}

void ApplicationMaster::perform() {
    time_count++;
    for(auto itr = units.begin(); itr != units.end(); ++itr) {
        (*itr)->perform(this);
    }
}
void ApplicationMaster::disp() {
    for(int x = 0; x < 120; x++) {
        for(int y = 0; y < 80; y++) {
            glColor4f(tile[x][y] / 10.0f, 1.0f, tile[x][y] / 10.0f, 1.0f);
            SquareFill2D(x * 10, y * 10, x * 10 + 10, y * 10 + 10);
        }
    }
    UnitRenderer* renderer;
    for(auto itr = units.begin(); itr != units.end(); ++itr) {
        renderer = new UnitRenderer(*itr);
        renderer->render();
    }
}

int ApplicationMaster::random() {
    return rd();
    
}
