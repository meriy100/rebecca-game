#ifndef ApplicationMaster_hpp
#define ApplicationMaster_hpp

#include <random>
#include <list>
class Unit;
class ApplicationMaster {
  std::random_device rd;
  //std::mt19937 mt;
  public:
  int time_count;
  Unit* unit[4];
  int tile[120][80];
  std::list<Unit*> units;
  ApplicationMaster();
  void perform();
  void disp();
  int random();
};


#endif /* ApplicationMaster_hpp */
