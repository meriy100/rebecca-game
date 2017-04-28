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
  int nutrition;

  Unit(float, float, float, float);
  void perform(ApplicationMaster* applicationMaster);
  float wallCollision(float nextx, float nexty);

  bool isAlive();
private:
  bool alive;

  void absorption(int*);
  Unit* birth();
};

#endif /* Unit_hpp */
