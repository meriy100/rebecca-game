#ifndef ApplicationMaster_hpp
#define ApplicationMaster_hpp

#include <random>
#include <list>
#include "defines.h"
#define MAP_HEIGHT HEIGHT / 10
#define MAP_WIDTH WIDTH / 10
class Unit;
class ApplicationMaster {
  std::random_device rd;
  //std::mt19937 mt;
  public:
  int time_count;
  int tile[MAP_WIDTH][MAP_HEIGHT];
  std::list<Unit*> units;
  ApplicationMaster();
  void perform(Mouse);
  void disp();
  int random();
};


#endif /* ApplicationMaster_hpp */
