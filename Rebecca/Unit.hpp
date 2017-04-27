#ifndef Unit_hpp
#define Unit_hpp

#include <math.h>
class ApplicationMaster;
class Unit {
public:
    float x;
    float y;
    float v;
    float direction;
    
    Unit();
    void perform(ApplicationMaster* applicationMaster);
};

#endif /* Unit_hpp */
