#ifndef Unit_hpp
#define Unit_hpp

#include <math.h>
#include "defines.h"
class ApplicationMaster;
class Unit {
public:
    float x;
    float y;
    float v;
    float r;
    float direction;

    Unit(float, float, float, float);
    void perform(ApplicationMaster* applicationMaster);
    float wallCollision(float nextx, float nexty);
};

#endif /* Unit_hpp */
