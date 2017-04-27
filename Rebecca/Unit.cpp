
#include "Unit.hpp"

#define Pai 3.1415926
#include <iostream>
#include <random>
#include "ApplicationMaster.hpp"

Unit::Unit() {
    x = 50.0f;
    y = 50.0f;
    v = 1.0f;
    direction = 0.0;
}

void Unit::perform(ApplicationMaster* applicationMaster) {
    float vx = v * cos(direction / 180.0 * Pai);
    float vy = v * sin(direction / 180.0 * Pai);
    x += vx;
    y += vy;
    if ( applicationMaster->time_count % 60 == 0 ) {
        direction += applicationMaster->random() % 360;
    }
}
