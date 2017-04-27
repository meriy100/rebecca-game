#ifndef ApplicationMaster_hpp
#define ApplicationMaster_hpp

#include <random>
#include <list>
class Unit;
class ApplicationMaster {
    std::random_device rd;
public:
    int time_count;
    Unit* unit[4];
    std::list<Unit*> units;
    std::mt19937 mt;
    ApplicationMaster();
    void perform();
    void disp();
    int random();
};


#endif /* ApplicationMaster_hpp */
